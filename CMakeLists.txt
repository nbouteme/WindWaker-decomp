project(windwaker)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wno-parentheses  -Wno-unused-but-set-variable -ggdb3 -Wall -Wextra -Werror -Wfatal-errors -Wno-unused-variable -Wno-write-strings -Wno-unused-parameter -Wextra -fpermissive -fno-exceptions")

include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src/linux_sdk)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")

include(FindPkgConfig)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GL REQUIRED gl)
pkg_search_module(GLEW REQUIRED glew)
pkg_search_module(X11 REQUIRED x11)

find_package(Threads REQUIRED)

set( RC_DEPENDS "" )

function( add_resource input target)
    string( MAKE_C_IDENTIFIER ${input} input_identifier )
    string( MAKE_C_IDENTIFIER ${PROJECT_SOURCE_DIR}/src/linux_sdk/${input} fc_input_identifier )
    message(STATUS "make identifier: ${input} ${input_identifier}")
    set( output "${PROJECT_BINARY_DIR}/${input_identifier}.o" )
    target_link_libraries( ${target} ${output} )

    add_custom_command(
        OUTPUT ${output}
        COMMAND ${CMAKE_LINKER} --relocatable --format binary --output ${output} ${PROJECT_SOURCE_DIR}/src/linux_sdk/${input}
        COMMAND ${CMAKE_OBJCOPY} 
            --redefine-sym _binary_${fc_input_identifier}_start=b_${input_identifier}_start
            --redefine-sym _binary_${fc_input_identifier}_end=b_${input_identifier}_end
            --redefine-sym _binary_${fc_input_identifier}_size=b_${input_identifier}_size
            ${output}
        DEPENDS ${PROJECT_SOURCE_DIR}/src/linux_sdk/${input}
    )

    set( RC_DEPENDS ${RC_DEPENDS} ${output} PARENT_SCOPE )
endfunction()

#add_executable(infer_c_struct_from_uniform 
#${PROJECT_SOURCE_DIR}/tools/infer.cpp
#${PROJECT_SOURCE_DIR}/src/linux_sdk/ubershader.cpp
#)
#
#target_link_libraries(
#    infer_c_struct_from_uniform
#    ${GLFW_LIBRARIES}
#    ${GL_LIBRARIES}
#    ${X11_LIBRARIES}
#    ${GLEW_LIBRARIES} Threads::Threads)

#add_custom_command(
#    PRE_BUILD
#    OUTPUT  ${PROJECT_SOURCE_DIR}/src/linux_sdk/gx_state_gen.h
#    COMMAND infer_c_struct_from_uniform ${PROJECT_SOURCE_DIR}/src/linux_sdk/shaders/gxstate.glsl ${PROJECT_SOURCE_DIR}/src/linux_sdk/gx_state_gen.h
#    DEPENDS infer_c_struct_from_uniform ${PROJECT_SOURCE_DIR}/src/linux_sdk/shaders/gxstate.glsl
#)

add_executable(${PROJECT_NAME} ${sources} ${PROJECT_SOURCE_DIR}/src/linux_sdk/gx_state_gen.h)

add_resource(shaders/main.ms ${PROJECT_NAME})
add_resource(shaders/main.fs ${PROJECT_NAME})
add_resource(shaders/test.vs ${PROJECT_NAME})
add_resource(shaders/gxstate.glsl ${PROJECT_NAME})

#add_resource(shaders/main.ms infer_c_struct_from_uniform)
#add_resource(shaders/main.fs infer_c_struct_from_uniform)
#add_resource(shaders/test.vs infer_c_struct_from_uniform)
#add_resource(shaders/gxstate.glsl infer_c_struct_from_uniform)

add_custom_target(rc ALL DEPENDS ${RC_DEPENDS})

add_dependencies(${PROJECT_NAME} rc)
#add_dependencies(infer_c_struct_from_uniform rc)

target_link_libraries(
    ${PROJECT_NAME} 
    ${GLFW_LIBRARIES}
    ${GL_LIBRARIES}
    ${X11_LIBRARIES}
    ${GLEW_LIBRARIES} Threads::Threads)
add_subdirectory(rels)

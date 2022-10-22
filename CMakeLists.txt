project(windwaker)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17  -g -Wall -Wfatal-errors -Wno-unused-variable -Wno-write-strings -Wno-unused-parameter -Wextra -fpermissive -fno-exceptions")

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")

include(FindPkgConfig)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GL REQUIRED gl)
pkg_search_module(GLEW REQUIRED glew)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(
    ${PROJECT_NAME} 
    ${GLFW_LIBRARIES}
    ${GL_LIBRARIES}
    ${GLEW_LIBRARIES} Threads::Threads)
add_subdirectory(rels)

project(windwaker)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wfatal-errors -Wextra -fpermissive -fno-exceptions")

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")


add_executable(${PROJECT_NAME} ${sources})

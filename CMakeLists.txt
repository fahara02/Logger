# MCU-agnostic Logger CMake configuration
# Add this directory as a library target in your project

cmake_minimum_required(VERSION 3.10)
project(Logger LANGUAGES CXX)

option(LOGGER_BUILD_TEST "Build logger test executable" OFF)

add_library(Logger INTERFACE)
target_include_directories(Logger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(LOGGER_BUILD_TEST)
    add_executable(logger_test test/test.cpp)
    target_include_directories(logger_test PRIVATE test examples/PC_Host src)
    target_link_libraries(logger_test Logger)
    set_target_properties(logger_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)
else()
    # Example/PC Host build
    add_executable(pc_host_example examples/PC_Host/main.cpp)
    target_include_directories(pc_host_example PRIVATE examples/PC_Host src)
    target_link_libraries(pc_host_example Logger)
endif()

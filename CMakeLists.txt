# MCU-agnostic Logger CMake configuration
# Add this directory as a library target in your project

add_library(Logger INTERFACE)
target_include_directories(Logger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)




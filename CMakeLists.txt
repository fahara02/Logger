# MCU-agnostic Logger CMake configuration
# Add this directory as a library target in your project

add_library(Logger INTERFACE)
target_include_directories(Logger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Optionally, you can add compile options or definitions here if needed for your platform:
# target_compile_options(Logger INTERFACE ...)
# target_compile_definitions(Logger INTERFACE ...)


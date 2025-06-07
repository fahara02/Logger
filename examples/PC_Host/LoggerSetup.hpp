// LoggerSetup.hpp for PC Host Example
// This setup header configures the logger to output to standard output (stdout)
// using printf. Use this in desktop or unit-test environments.
#pragma once

#include "Logger.hpp"
#include <cstdio> // for printf

// Output callback for PC host (stdout)
inline void logger_pc_output(const char* msg) {
    std::printf("%s", msg);
}

// Call this in your main() before using any libraries that depend on logging
inline void setup_logger() {
    LOG::SETUP(logger_pc_output);
    LOG::ENABLE();
    LOG::ENABLE_TIMESTAMPS();
}

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
// Portable PC host timestamp function
#include <chrono>
inline unsigned long pc_millis() {
    using namespace std::chrono;
    static auto start = steady_clock::now();
    return (unsigned long)duration_cast<milliseconds>(steady_clock::now() - start).count();
}

inline void setup_logger() {
    LOG::SETUP(logger_pc_output);
    LOG::SETUP_TIMESTAMP(pc_millis); // Use portable millis for PC
    LOG::ENABLE();
    LOG::ENABLE_TIMESTAMPS();
}

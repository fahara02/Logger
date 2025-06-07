// LoggerSetup.hpp
#pragma once

#include "Logger.hpp"

inline void logger_serial_output(const char* msg) {
    Serial.print(msg);
}

// Call this in your main setup() before using any libraries that depend on logging
inline void setup_logger() {
    LOG::SETUP(logger_serial_output);
    LOG::SETUP_TIMESTAMP(millis); // Use Arduino millis() for timestamps
    LOG::ENABLE();
    LOG::ENABLE_TIMESTAMPS();
}

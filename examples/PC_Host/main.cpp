// main.cpp for PC Host Logger Example
// Demonstrates using the logger on a desktop/host system with stdout output.

#include "LoggerSetup.hpp"
// #include "MySensorLib.hpp" // Example: include any library using the logger

int main() {
    setup_logger(); // Set up logger for PC host (stdout)
    // MySensorLib::begin(); // Example: library can log without worrying about output

    // Simulate a loop with log events
    for (int i = 0; i < 5; ++i) {
        LOG::DEBUG("Loop", "Iteration %d", i);
        LOG::INFO("Running on PC host");
    }
    LOG::SUCCESS("Done", "All iterations complete");
    return 0;
}

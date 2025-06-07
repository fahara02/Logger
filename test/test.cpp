// test.cpp - PC Host Logger Test
#include "../examples/PC_Host/LoggerSetup.hpp"
#include <thread>
#include <chrono>

int main() {
    setup_logger();
    LOG::DEBUG("Test", "This is a DEBUG log");
    LOG::TRACE("Test", "This is a TRACE log");
    LOG::INFO("Test", "This is an INFO log");
    LOG::SUCCESS("Test", "This is a SUCCESS log");
    LOG::WARNING("Test", "This is a WARNING log");
    LOG::ERROR("Test", "This is an ERROR log");
    // Untagged
    LOG::DEBUG("This is an untagged DEBUG log");
    LOG::TRACE("This is an untagged TRACE log");
    LOG::INFO("This is an untagged INFO log");
    LOG::SUCCESS("This is an untagged SUCCESS log");
    LOG::WARNING("This is an untagged WARNING log");
    LOG::ERROR("This is an untagged ERROR log");

    // INFO color toggle test
    LOG::Logger::getInstance().setInfoAlternateColor("\033[1;33m"); // yellow
    for (int i = 0; i < 4; ++i) {
        LOG::INFO("INFO color toggle #%d", i);
        // Toggle color each time
        LOG::Logger::getInstance().setInfoAlternateColor(i % 2 ? "\033[1;36m" : "\033[1;33m");
    }

    // Binary format tests
    uint32_t value = 0b10101010;
    LOG::DEBUG("Binary", "Value as binary: %b", value);
    LOG::DEBUG("Binary", "Value as binary (upper): %B", value);

    // Hex format test
    LOG::DEBUG("Hex", "Value as hex: 0x%X", value);
    LOG::DEBUG("Hex", "Value as hex (lower): 0x%x", value);

    // Simulate a delay
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return 0;
}

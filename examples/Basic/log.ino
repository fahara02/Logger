#include "Logger.hpp"

void setup() {
  Serial.begin(115200);
  LOG::ENABLE();            // Enable logging
  LOG::ENABLE_TIMESTAMPS(); // Add timestamps
}

void loop() {
  LOG::DEBUG("Loop", "Starting loop at %lu ms", millis());
  LOG::INFO("Running...");
  LOG::SUCCESS("Loop", "Loop finished");
  delay(1000);
}
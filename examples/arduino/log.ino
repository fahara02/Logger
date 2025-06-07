#include "LoggerSetup.hpp"
#include "MySensorLib.hpp" // Example of another library using the logger

void setup() {
  Serial.begin(115200);
  setup_logger(); // Set up logger for all libraries

  MySensorLib::begin(); // Library can log without worrying about output
}

void loop() {
  LOG::DEBUG("Loop", "Starting loop at %lu ms", millis());
  LOG::INFO("Running...");
  LOG::SUCCESS("Loop", "Loop finished");
  delay(1000);
}
}
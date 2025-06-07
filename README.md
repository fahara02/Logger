# MCU-Agnostic Logger Library

A flexible, portable logging utility for Arduino, MCUs, and PC host projects. Provides log levels, tags, timestamps, colored output, binary/hex formatting, and MCU-agnostic report/file logging. Works seamlessly on embedded and desktop systems.

## Features

- **Log Levels**: DEBUG, TRACE, INFO, SUCCESS, WARNING, ERROR (no TEST, avoids GTest conflicts)
- **Tags**: Categorize log messages with custom tags
- **Timestamps**: Add timestamps to log entries (optional, user callback)
- **Colored Output**: ANSI color codes for visually distinct log levels (PC/Unix terminals)
- **Binary/Hex Formatting**: Log binary values with `%b`/`%B`, hex with `%x`/`%X`
- **MCU-Agnostic Report/File Logging**: Log to SD card, flash, or any storage via a callback—no STL required
- **Control Functions**: Enable/disable logging, set minimum level, block/unblock tags
- **Minimal STL Bloat**: Only core C++ headers used
- **PC Host and Arduino/MCU Support**: Example setups for both

## Installation

- **Arduino/MCU**: Copy to your libraries directory, or use PlatformIO.
- **PC Host/Unit Test**: Add as a subdirectory or include in your CMake project.

## Usage

Include the logger in your sketch or project:

```cpp
#include "Logger.hpp"
```

### Logging Messages

```cpp
LOG::DEBUG("MyTag", "Debug message with tag");
LOG::INFO("Simple info message");
LOG::SUCCESS("MyTag", "Operation succeeded");
LOG::WARNING("Potential issue detected");
LOG::ERROR("MyTag", "Critical error: %d", errorCode);

// Format specifiers: %d, %s, %b (binary), %B (binary upper), %x/%X (hex)
uint8_t value = 0b10101010;
LOG::INFO("Binary value: %b", value); // Outputs: Binary value: 0b10101010
LOG::INFO("Hex value: 0x%X", value); // Outputs: Hex value: 0xAA
```

### Timestamps
- Provide a callback returning milliseconds (or your preferred unit).
- Enable timestamps:
```cpp
LOG::SETUP_TIMESTAMP(my_millis_callback);
LOG::ENABLE_TIMESTAMPS();
```

### Colored Output
- Colors are enabled by default for PC/Unix terminals.
- INFO lines can alternate color (see setInfoAlternateColor).

### MCU-Agnostic Report/File Logging

Send all logs to SD card, flash, or any custom storage with a single callback.
```cpp
void my_writer(const char* message); // message is a null-terminated log line (with newline)
LOG::ENABLE_REPORT(my_writer); // All logs will also be sent to your callback
LOG::DISABLE_REPORT();
```

#### Example: Write logs to Serial (Arduino)
```cpp
void my_serial_logger(const char* msg) {
  Serial.print(msg);
}

void setup() {
  Serial.begin(115200);
  LOG::SETUP(my_serial_logger);
  LOG::ENABLE();
}
```

#### Example: Write logs to SD card (Arduino SD library)
```cpp
#include <SD.h>
void my_writer(const char* msg) {
  File logFile = SD.open("/report.log", FILE_WRITE);
  if (logFile) {
    logFile.print(msg);
    logFile.close();
  }
}
```

#### Example: PC Host Setup
```cpp
#include "examples/PC_Host/LoggerSetup.hpp"
setup_logger(); // Sets up stdout output and portable timestamp
```

## Building and Testing on PC Host

- **CMake/Ninja Build**
  - To build the logger library and example:
    ```sh
    cmake -S . -B build
    cmake --build build
    ./build/examples/PC_Host/pc_host_example
    ```
  - To build and run the test suite:
    ```sh
    bash test/build.sh
    # or
    ./test/build.sh
    ```
  - The test covers all log levels, color toggling, binary/hex formatting, and timestamp output.

- **CMake Option**: `LOGGER_BUILD_TEST=ON` builds the test runner instead of the example.

## Buffer Size
- Set with the macro `LOG_REPORT_BUFFER_SIZE` (default: 256).
- Override before including the logger if you need longer log lines.

## Minimal User Burden
- Only provide output/timestamp/report callbacks. No STL or platform code in logger core.
- If no callback is set, logging/reporting is safely disabled.

## License
MIT. See LICENSE file.

// Logging Messages
// Log messages with or without tags using the provided functions:

LOG::DEBUG("MyTag", "Debug message with tag");
LOG::INFO("Simple info message");
LOG::SUCCESS("MyTag", "Operation succeeded");
LOG::WARNING("Potential issue detected");
LOG::ERROR("MyTag", "Critical error: %d", errorCode);

// Use format specifiers like %d, %s, or %b for dynamic content:

uint8_t value = 0b10101010;
LOG::INFO("Binary value: %b", value); // Outputs: Binary value: 0b10101010

// ---

### MCU-Agnostic Report/File Logging

Send all logs to SD card, flash, or any custom storage with a single callback. No STL required!

**Callback Signature:**
```cpp
void my_writer(const char* message); // message is a null-terminated log line (with newline)
```

**Enable report logging:**
```cpp
LOG::ENABLE_REPORT(my_writer); // All logs will also be sent to your callback
```
**Disable report logging:**
```cpp
LOG::DISABLE_REPORT();
```

**Example: Write logs to Serial (for demonstration)**
```cpp
void my_serial_logger(const char* msg) {
  Serial.print(msg);
}

void setup() {
  Serial.begin(115200);
  LOG::SETUP(my_serial_logger); // All log output goes through this callback
  LOG::ENABLE();
}
```

**Example: Write logs to SD card (Arduino SD library)**
```cpp
#include <SD.h>
void my_writer(const char* msg) {
  File logFile = SD.open("/report.log", FILE_WRITE);
  if (logFile) {
    logFile.print(msg);
    logFile.close();
  }
}
```

**Buffer size:**
- The log buffer size is set with the macro `LOG_REPORT_BUFFER_SIZE` (default: 256).
- You can override it before including the logger if you need longer log lines.

**Minimal User Burden:**
- You only need to provide a single callback. The library handles all formatting and buffer management internally.
- If no callback is set, report logging is safely disabled.
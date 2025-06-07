# Arduino Logger Library

A flexible and powerful logging utility for Arduino projects. This library provides multiple log levels, optional tags for categorization, timestamps, colored output in the serial monitor, and support for binary formatting. It’s ideal for debugging and monitoring your Arduino sketches.

## Features

- **Log Levels**: DEBUG, TEST, INFO, SUCCESS, WARNING, ERROR
- **Tags**: Categorize log messages with custom tags
- **Timestamps**: Add timestamps to log entries (optional)
- **Colored Output**: Visually distinguish log levels with ANSI color codes
- **Binary Formatting**: Log binary values using `%b` (lowercase) or `%B` (uppercase) format specifiers
- **MCU-Agnostic Report/File Logging**: Log to SD card, flash, or any storage via a simple callback—no STL or PC dependencies
- **Control Functions**: Enable/disable logging, set minimum log levels, block/unblock tags

## Installation

1. **Manual Installation**:
   - Download the library from the [GitHub repository](https://github.com/fahara02/Logger) 
   - Extract the folder to your Arduino `libraries` directory (e.g., `~/Documents/Arduino/libraries/`).
   - Rename the folder to `Logger` if necessary.
   - Restart the Arduino IDE.

2. **Library Manager** (if published):
   - Open the Arduino IDE, go to `Sketch > Include Library > Manage Libraries`.
   - Search for "Arduino Logger Library" and click "Install".

## Usage

Include the library in your Arduino or MCU sketch:

```cpp
#include "Logger.hpp"

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
void my_writer(const char* msg) {
  Serial.print("[REPORT] ");
  Serial.print(msg);
}

void setup() {
  Serial.begin(115200);
  LOG::ENABLE();
  LOG::ENABLE_REPORT(my_writer);
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
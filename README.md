# Arduino Logger Library

A flexible and powerful logging utility for Arduino projects. This library provides multiple log levels, optional tags for categorization, timestamps, colored output in the serial monitor, and support for binary formatting. It’s ideal for debugging and monitoring your Arduino sketches.

## Features

- **Log Levels**: DEBUG, TEST, INFO, SUCCESS, WARNING, ERROR
- **Tags**: Categorize log messages with custom tags
- **Timestamps**: Add timestamps to log entries (optional)
- **Colored Output**: Visually distinguish log levels with ANSI color codes
- **Binary Formatting**: Log binary values using `%b` (lowercase) or `%B` (uppercase) format specifiers
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

Include the library in your Arduino sketch:

```cpp
#include "Logger.hpp"

//Logging Messages
//Log messages with or without tags using the provided functions:

LOG::DEBUG("MyTag", "Debug message with tag");
LOG::INFO("Simple info message");
LOG::SUCCESS("MyTag", "Operation succeeded");
LOG::WARNING("Potential issue detected");
LOG::ERROR("MyTag", "Critical error: %d", errorCode);

//Use format specifiers like %d, %s, or %b for dynamic content:

uint8_t value = 0b10101010;
LOG::INFO("Binary value: %b", value); // Outputs: Binary value: 0b10101010
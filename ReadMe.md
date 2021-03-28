# NullSerial
Serial like library which throwing away input/outupt.

## Usage
### Include

```cpp
#include <NullSerial.h>
```

A header file will be included automatically when you use "include the library" in Arduino IDE.

### Instance

A instance **NullSerial** is defined in the library.

### Initialize

NullSerial does not need to initialize(call .begin() member function).
You can call it, too. begin() does not do anything.

## Example

```cpp
#define DEBUG
#define VERBOSE

#if defined(DEBUG)
# define SerialDebug   Serial
# deinfe SerialVerbose Serial
#elif defined(VERBOSE)
# include <NullSerial.h>
# define SerialDebug   NullSerial
# define SerialVerbose Serial
#else
# include <NullSerial.h>
# define SerialDebug   NullSerial
# define SerialVerbose NullSerial
#endif

// your sketch starts below
// ...

```
## License
LGPLv3

## References
- [HardwareSerial.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/cores/arduino/HardwareSerial.h)
- [SoftwareSerial.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/libraries/SoftwareSerial/src/SoftwareSerial.h)

## ToDo
- Test using NullSerial instead of SerialUSB


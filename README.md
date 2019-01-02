# Arduino DTH_I2CRelay library
I2C_Relay is a library that provides control relay functionality for Arduino.
This library uses a 8-relays module  and a PCF8574 module.
## Functionality
The functions available in the library include
```c
begin(address)      // start I2C_Relay with an address.
readRelayState(num)  // read a relay state with a relay number. 
turnOnRelay(bitwise)    // Turn on a relay with a bitwise.
turnOnAllRelay()   // Turn on 8 relays.
turnOffRelay(bitwise)  // Turn off a relay with a bitwise.  
turnOffAllRelay()  // Turn off 8 relays.
controlRelay(value, num)  // control a relay with a value and a relay number.
```
## Examples
The DTH_I2CRelay directory contains the I2C-Relay library and an example sketches
illustrating how the library can be used with various relay sources:
- `control_relays.ino`- example of using i2c relay.  

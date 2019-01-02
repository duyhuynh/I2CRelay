#include "DTH_I2CRelay.h"
#include "DTH_I2CKeypad.h"

#define KEYPAD_ADDRESS    0x20
#define ROWS 4
#define COLS 4

#define RELAY_ADDRESS  0x21

const char keyMaps_4_4[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
DTH_I2CKeypad keys(&keyMaps_4_4[0][0], ROWS, COLS);
DTH_I2CRelay relays;

void setup() {
  // put your setup code here, to run once:  
  int error;
  Serial.begin(115200);
  Serial.println("Test I2C Relay by Duy Huynh");  
  Wire.begin();
  Wire.beginTransmission(RELAY_ADDRESS);
  error = Wire.endTransmission(); 
  if (error == 0) 
  {
    Serial.println("I2C relay found.");
    relays.begin(RELAY_ADDRESS);
    keys.begin(KEYPAD_ADDRESS);  
    relays.turnOffAllRelay(); 
  } 
  else 
  {
    Serial.println("I2C relay not found.");
  }   
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keys.readKeyPressed();
  uint8_t val = 0; 
  
  if(key != '\0')
  {
    Serial.println(key);
    switch (key)
    {
      case '0':
        val = relays.readRelayState(0);
        relays.controlRelay(!val, 0);        
        break;
      case '1':
        val = relays.readRelayState(1);
        relays.controlRelay(!val, 1);   
        break;
      case '2':
        val = relays.readRelayState(2);
        relays.controlRelay(!val, 2);   
        break;
      case '3':
        val = relays.readRelayState(3);
        relays.controlRelay(!val, 3);   
        break;
      case '4':
        val = relays.readRelayState(4);
        relays.controlRelay(!val, 4);    
        break;
      case '5':
        val = relays.readRelayState(5);
        relays.controlRelay(!val, 5);   
        break;      
      case '6':
        val = relays.readRelayState(6);
        relays.controlRelay(!val, 6);   
        break;  
      case '7':
        val = relays.readRelayState(7);
        relays.controlRelay(!val, 7);    
        break;
      case 'A':
        relays.turnOnAllRelay();;
        break;
      case 'B':
        relays.turnOffAllRelay();;
        break;
       default:
        break;      
    }
  }
}


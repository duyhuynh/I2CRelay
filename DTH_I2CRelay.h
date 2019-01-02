/*
 *  I2C Relay library.
 *
 *  Copyright (C) 2018 Duy Huynh
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Version 0.1
 *  Author: Duy Huynh
 *  Email: duytel@gmail.com
 */
 
#ifndef DTH_I2C_RELAY_H_
#define DTH_I2C_RELAY_H_
/*------------------------------------------------------------------*
 *                           Includes                               *
 *------------------------------------------------------------------*/ 
#include "Arduino.h"
#include <Wire.h>

/*------------------------------------------------------------------*
 *                          Define macro                            *
 *------------------------------------------------------------------*/
#define I2CRelay_0 (1<<0)
#define I2CRelay_1 (1<<1)
#define I2CRelay_2 (1<<2)
#define I2CRelay_3 (1<<3)
#define I2CRelay_4 (1<<4)
#define I2CRelay_5 (1<<5)
#define I2CRelay_6 (1<<6)
#define I2CRelay_7 (1<<7)
 
/*------------------------------------------------------------------*
 *                        Class declaration                         *
 *------------------------------------------------------------------*/
class DTH_I2CRelay {
	
	public:
		DTH_I2CRelay();
		DTH_I2CRelay(uint8_t address);     
		~DTH_I2CRelay();    
		uint8_t readRelayState(uint8_t num);
		void turnOnRelay(uint8_t bitwise);
		void turnOnAllRelay();
		void turnOffAllRelay();
		void turnOffRelay(uint8_t bitwise);
		void controlRelay(uint8_t value, uint8_t num);
		void begin(uint8_t address);	    

	private:
		void writeDataToPCF8574(uint8_t address, uint8_t data);
		int readDataFromPCF8574(uint8_t address);    
		
	protected:		
		/* I2C address of PCF5784 */
		uint8_t _i2c_addr;	    
		uint8_t _relay_state;
};

#endif //DTH_I2C_RELAY_H_

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

#include "DTH_I2CRelay.h"


DTH_I2CRelay::DTH_I2CRelay()
{
	on_value = ON_VALUE;
	if(on_value == 0)
		_relay_state = 0xFF;	
	else
		_relay_state = 0x00;
}

DTH_I2CRelay::DTH_I2CRelay(uint8_t addr)
{	
	_i2c_addr = addr;	
	on_value = ON_VALUE;
	if(on_value == 0)
		_relay_state = 0xFF;	
	else
		_relay_state = 0x00;	
	begin(addr);
}


DTH_I2CRelay::~DTH_I2CRelay()
{
  
}

void DTH_I2CRelay::begin(uint8_t address)
{
	_i2c_addr = address;
	/* turn off all relays */
	turnOffAllRelay();	
}


uint8_t DTH_I2CRelay::readRelayState(uint8_t num)
{
	uint8_t val = 0;	
  	
	val = _relay_state & (0x01 << num);
	return !!val;
}

void DTH_I2CRelay::turnOnRelay(uint8_t bitwise)
{	
	if(on_value == 0)
		_relay_state &= ~bitwise;
	else
		_relay_state |= bitwise;
	writeDataToPCF8574(_i2c_addr, _relay_state);
}

void DTH_I2CRelay::turnOffRelay(uint8_t bitwise)
{	
	if(on_value == 0)
		_relay_state |= bitwise;
	else
		_relay_state &= ~bitwise;
	writeDataToPCF8574(_i2c_addr, _relay_state);
}

void DTH_I2CRelay::turnOnAllRelay()
{	
	if(on_value != 0)
		_relay_state = 0xFF;	
	else
		_relay_state = 0x00;
	writeDataToPCF8574(_i2c_addr, _relay_state);
}



void DTH_I2CRelay::turnOffAllRelay()
{
	if(on_value == 0)
		_relay_state = 0xFF;	
	else
		_relay_state = 0x00;
	writeDataToPCF8574(_i2c_addr, _relay_state);
}

void DTH_I2CRelay::controlRelay(uint8_t value, uint8_t num)
{
	uint8_t val = 0;  

	val = (0x01 << num); 
	if(value)
	{
		turnOnRelay(val); 
	}
	else
	{
		turnOffRelay(val); 
	}
}

void DTH_I2CRelay::writeDataToPCF8574(uint8_t address, uint8_t data)
{
	Wire.beginTransmission(address);
	Wire.write(data);
	Wire.endTransmission();
}

int DTH_I2CRelay::readDataFromPCF8574(uint8_t address)
{
	Wire.requestFrom(address, (uint8_t)1);
	return Wire.read();
}


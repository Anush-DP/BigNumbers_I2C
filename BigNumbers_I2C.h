/*
  BigNumbers_I2C.h - Library for displaying large numbers on LCD displays with I2C using the HD44780 driver.
 
  Copyright (C) 2019 Anush DP
 
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BigNumbers_I2C_h
#define BigNumbers_I2C_h

#include "Arduino.h"
#include "LiquidCrystal_I2C.h"

class BigNumbers_I2C
{
  public:
    BigNumbers_I2C(LiquidCrystal_I2C*);
	void begin();
    void clearLargeNumber(byte, byte);
    void displayLargeNumber(byte, byte, byte);
	void displayLargeInt(int, byte, byte, byte, bool);
  private:
    LiquidCrystal_I2C* _lcd;
};

#endif

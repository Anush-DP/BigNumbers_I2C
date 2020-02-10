/*
  BigNumbers_I2C.cpp - Library for displaying large numbers on LCD displays with I2C using the HD44780 driver.
 
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

#include "BigNumbers_I2C.h"

byte leftSide[8] = 
{
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111
};
byte upperBar[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte rightSide[8] =
{
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100
};
byte leftEnd[8] =
{
  B01111,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00111
};
byte lowerBar[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte rightEnd[8] =
{
  B11110,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11100
};
byte middleBar[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte lowerEnd[8] = 
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B01111
};

// Creates BigNumbers_I2C object
// LiquidCrystal_I2C* lcd: LiquidCrystal object to use
BigNumbers_I2C::BigNumbers_I2C(LiquidCrystal_I2C* lcd)
{
  _lcd = lcd;
}

void BigNumbers_I2C::begin()
{
  // create custom characters
  _lcd->createChar(0, leftSide);
  _lcd->createChar(1, upperBar);
  _lcd->createChar(2, rightSide);
  _lcd->createChar(3, leftEnd);
  _lcd->createChar(4, lowerBar);
  _lcd->createChar(5, rightEnd);
  _lcd->createChar(6, middleBar);
  _lcd->createChar(7, lowerEnd);
}

// prints an integer to the display using large characters
// Parameters: n - the integer to display
//             x - column of upper left corner of first large character
//             digits - number of digits of the integer (specifying this allows the digit positions to remain constant when printing out ints of various lengths)
//             leading - sets if leading zeros are printed or not (false = no, true = yes)
void BigNumbers_I2C::displayLargeInt(int n, byte x, byte y, byte digits, bool leading)
{
  boolean isNegative = false;
  if(n < 0)
  {
    isNegative = true;
    n = abs(n);
  }
  byte numString[digits];
  byte index = digits - 1;
  while(index)
  {
    numString[index] = n % 10;
	n /= 10;
	index--;
  }
  numString[0] = n % 10;
  
  for (int i = 0; i < digits; i++)
  {
    if(numString[i] == 0 && !leading && i < digits - 1)
    {
      clearLargeNumber((i * 3) + x, y);
    }
    else
    {
	  displayLargeNumber(numString[i], (i * 3) + x, y);
      leading = true;
    }
  }
}

void BigNumbers_I2C::clearLargeNumber(byte x, byte y) /* x is column of upper left corner for large character y is row of upper left corner for large character */
{
  _lcd->setCursor(x,y);
  _lcd->print(F("   "));
  _lcd->setCursor(x,y+1); 
  _lcd->print(F("   "));
}

void BigNumbers_I2C::displayLargeNumber(byte n, byte x, byte y) /* n is number to display, x is column of upper left corner for large character
y is row of upper left corner for large character */
{
  switch (n)
  {
    case 0:
    {
      _lcd->setCursor(x,y);
      _lcd->write(byte(0));
      _lcd->write(1);
      _lcd->write(2);
      _lcd->setCursor(x, y+1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 1:
    {
      _lcd->setCursor(x,y);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      _lcd->setCursor(x,y+1);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      break;
    }
    case 2:
    {
      _lcd->setCursor(x,y);
      _lcd->write(3);
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, y+1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(4);
      break;
    }
    case 3:
    {
      _lcd->setCursor(x,y);
      _lcd->write(3);
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, y+1);
      _lcd->write(7);
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 4:
    {
      _lcd->setCursor(x,y);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      _lcd->setCursor(x, y+1);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      break;
    }
    case 5:
    {
      _lcd->setCursor(x,y);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(5);
      _lcd->setCursor(x, y+1);
      _lcd->write(7);
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 6:
    {
      _lcd->setCursor(x,y);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(5);
      _lcd->setCursor(x, y+1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 7:
    {
      _lcd->setCursor(x,y);
      _lcd->write(1);
      _lcd->write(1);
      _lcd->write(2);
      _lcd->setCursor(x, y+1);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      break;
    }
    case 8:
    {
      _lcd->setCursor(x,y);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, y+1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 9:
    {
      _lcd->setCursor(x,y);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, y+1);
      _lcd->write(7);
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
  }
}

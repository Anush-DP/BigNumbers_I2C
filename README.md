# BigNumbers_I2C
I2C version of <a href="https://github.com/seanauff/BigNumbers">BigNumbers.h</a>.<br>
Display large numbers on LCD with I2C using Arduino (or any <a href="https://www.arduino.cc/en/guide/cores">board</a> compatible with Arduino IDE).
<br><img src="https://i.imgur.com/6BtQfYY.jpg">

# Example video
[![](http://img.youtube.com/vi/P3EDweeOi98/0.jpg)](http://www.youtube.com/watch?v=P3EDweeOi98 "Example video showing usage of this library")


# Syntax
#### clearLargeNumber(x, y);
x is column of upper left corner for large character & y is row of upper left corner for large character, i.e.,<br>
x -> column<br>
y -> row<br>
#### displayLargeNumber(num, x, y);
num -> Any number between 0 - 9<br>
x -> column<br>
y -> row<br>
#### displayLargeInt(lnum, x, y, dig, leading);
lnum -> Any integer number (Ex: 452, 23442, etc)<br>
x -> column<br>
y -> row<br>
dig -> number of digits of the integer (specifying this allows the digit positions to remain constant when printing out ints of various lengths)<br>
leading -> sets if leading zeros are printed or not (false = no, true = yes)<br>

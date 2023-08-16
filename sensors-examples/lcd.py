#!/usr/bin/env python
#
# GrovePi Example for using the Grove - LCD RGB Backlight (http://www.seeedstudio.com/wiki/Grove_-_LCD_RGB_Backlight)
#
# The GrovePi connects the Raspberry Pi and Grove sensors.  You can learn more about GrovePi here:  http://www.dexterindustries.com/GrovePi
#
# Have a question about this example?  Ask on the forums here:  http://forum.dexterindustries.com/c/grovepi
#
# PUT on I2C

from grove_rgb_lcd import *

setText("Hello world\nLCD test")
setRGB(0,128,64)

# Slowly change the colors every 0.01 seconds.
for c in range(0,255):
    setRGB(c,255-c,0)
    time.sleep(0.01)


setText("will t es beau, deff ton exam")

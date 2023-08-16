#!/usr/bin/env python
#
'''
SIMPLE SCRIPT TO PUT MSG on the screen  

args : text and if text == null -> shut down the screen 


'''
# GrovePi Example for using the Grove - LCD RGB Backlight (http://www.seeedstudio.com/wiki/Grove_-_LCD_RGB_Backlight)
#
# The GrovePi connects the Raspberry Pi and Grove sensors.  You can learn more about GrovePi here:  http://www.dexterindustries.com/GrovePi
#
# Have a question about this example?  Ask on the forums here:  http://forum.dexterindustries.com/c/grovepi
#
# PUT on I2C

import sys
from grove_rgb_lcd import *

def main(arg) : 

    if arg == 'null':
        setText("          ")
        setRGB(0,0,0)
    else :
        setText("LOADING")
        setRGB(0,128,64)

        for c in range(0,255):
            setRGB(c,255-c,0)
            time.sleep(0.01)
        #print(arg)
        setText(arg)

if __name__ == "__main__":
   main(sys.argv[1])

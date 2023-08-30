#Fixing Git
#!/usr/bin/env python

# GrovePi LED blink Example for the Grove LED Socket (http://www.seeedstudio.com/wiki/Grove_-_LED_Socket_Kit)
#
# The GrovePi connects the Raspberry Pi and Grove sensors.  You can learn more about GrovePi here:  http://www.dexterindustries.com/GrovePi
#
# Have a question about this example?  Ask on the forums here:  http://forum.dexterindustries.com/c/grovepi
#
'''

'''
import time
from grovepi import *

# Connect the Grove LED to digital port D4
led = 6

def main(arg) : 
    pinMode(led,"OUTPUT")

    if arg == 'on':
        digitalWrite(led,1)
        time.sleep(1)	
    else :
        digitalWrite(led,0)
        time.sleep(1)	

if __name__ == "__main__":
   main(sys.argv[1])


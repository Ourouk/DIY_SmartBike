#!/usr/bin/env python
#
# GrovePi Example for using the Grove Relay (http://www.seeedstudio.com/wiki/Grove_-_Relay)
#
# The GrovePi connects the Raspberry Pi and Grove sensors.  You can learn more about GrovePi here:  http://www.dexterindustries.com/GrovePi
#
# Have a question about this example?  Ask on the forums here:  http://forum.dexterindustries.com/c/grovepi
#
# NOTE: Relay is normally open. LED will illuminate when closed and you will hear a definitive click sound
import time
import sys
import grovepi

# Connect the Grove Relay to digital port D5
# SIG,NC,VCC,GND
relay = 5


def main(arg) : 
    grovepi.pinMode(relay,"OUTPUT")

    if arg == 'on':
        grovepi.digitalWrite(relay,1)
        time.sleep(5)	
    else :
        grovepi.digitalWrite(relay,0)
        time.sleep(5)	

if __name__ == "__main__":
   main(sys.argv[1])


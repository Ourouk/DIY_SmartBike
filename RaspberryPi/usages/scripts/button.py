#Fixing Git
#!/usr/bin/env python
#
# GrovePi Example for using the Grove Button (http://www.seeedstudio.com/wiki/Grove_-_Button)
#
# The GrovePi connects the Raspberry Pi and Grove sensors.  You can learn more about GrovePi here:  http://www.dexterindustries.com/GrovePi
#
# Have a question about this example?  Ask on the forums here:  http://forum.dexterindustries.com/c/grovepi
#
'''
## License

The MIT License (MIT)
'''

import time
import grovepi

# Connect the Grove Button to digital port D3
button = 3

grovepi.pinMode(button,"INPUT")


print(grovepi.digitalRead(button) , end="")
time.sleep(.5)



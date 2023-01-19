
'''

'''

import time
import grovepi
#PARAMS
#PINS
light_sensor = 0 # A0
relay = 4        # D4   

# Turn on LED once sensor exceeds threshold resistance
threshold = 20

grovepi.pinMode(light_sensor,"INPUT")
grovepi.pinMode(relay,"OUTPUT")

while True:
    try:
        # Get sensor value
        sensor_value = grovepi.analogRead(light_sensor)

        if sensor_value < threshold:
            # Send HIGH to switch on LED
            grovepi.digitalWrite(relay,1)
        else:
            # Send LOW to switch off LED
            grovepi.digitalWrite(relay,0)

        print("sensor_value = %d " %(sensor_value))
        time.sleep(.5)

    except IOError:
        print ("Error")

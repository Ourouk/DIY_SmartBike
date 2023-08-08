##### MUST SUDO for WORK
#PIN SERIAL 

import serial
import time
#from grovepi import*

ser=serial.Serial('/dev/ttyS0',baudrate=9600,timeout=1)
ser.flush()
card=''
while True:
    c=''
    c= ser.read()
    card=card+ str(c).removeprefix('b\'').removesuffix('\'').replace('\\x','').replace('0','')

    print(card)
    if len(card)>=15:
        card=card[5:11]
        print(card)
    #    print('sep')
     #   print(int(card,base=16))
        card=''

        
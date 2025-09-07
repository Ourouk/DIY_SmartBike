##### MUST SUDO for WORK
#PIN SERIAL 

import serial
import time
#from grovepi import*

accept = ["227E9124C93","F9DE9D1326A","E9D1324BAE44","932AEC6683" ,"2AEC6683","26ACF9DE9D13","24BAE443899","AE443899324"]


ser=serial.Serial('/dev/ttyAMA0',baudrate=9600,timeout=1)
ser.flush()
card=''
t_end = time.time() + 5 # 5 secondes 
while time.time() < t_end:
    c=''
    c= ser.read()
    card=card+ str(c).removeprefix('b\'').removesuffix('\'').replace('\\x','').replace('0','')

    #print(card)
    if len(card)>=15:
    #    card=card[5:11]
    #    print(card)
    #    print('sep')
    #   print(int(card,base=16))
        card=''
    if any(accepted_card in card for accepted_card in accept):
        card = ''
        print("true", end ='')
        break
        



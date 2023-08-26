from LSM6DS3 import LSM6DS3
import json
import sys
from grove_rgb_lcd import *

a = LSM6DS3()

#print("rotation")
#print(a.getXRotation()) 
#print(a.getYRotation())
#print(a.getZRotation())
#print("---")
#print("acceleration")
#print(a.readRawAccelX())
#print(a.getYRotation())
#print(a.readRawAccelZ())
#print("------")

while 1 :
    time.sleep(5)
    gyroscope = {
        "gyroscope":{
            "Rotation" :{
            "X":a.getXRotation(),
            "Y":a.getYRotation(),
            "Z":a.getZRotation()
            },
            "acceleration" :{
                "X": a.readRawAccelX(),
                "Y": a.readRawAccelY(),
                "Z": a.readRawAccelZ()
            }
        }
    }
        
    y = json.dumps(gyroscope)
    print(gyroscope)

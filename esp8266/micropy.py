import esp
esp.osdebug(None)
import uos, machine
machine.freq()
machine.freq(80000000) # set the CPU frequency to 80 MHz earn battery
import network
wlan = network.WLAN(network.STA_IF) # create station interface
wlan.active(True) 
# wlan.scan()
# wlan.isconnected()   
wlan.connect('msi', 'fuckisnotmypswd')
# wlan.isconnected() 
ap = network.WLAN(network.AP_IF)
ap.active(False)            #esacivate acess point wifi
from machine import Pin
p15 = Pin(15, Pin.OUT)  
#p15.on()
#p15.off()
# RELAY set vcc on 5v & GND  on GND , put sig on p 15 # open and close with on off function.
adc = machine.ADC(0)
adc.read()
# connect  set vcc on 5v & GND  on GND and sig to adc 


#todo next steps : -do  send data of light level with mqtt and send in function of a defined luminosity level activate or not the relay




#
#
#
#
#       GROVE PI PART 2
#
sudo apt install arduino
pip install python-periphery
pip install wiringpi
curl -kL dexterindustries.com/update_grovepi 5 | bash
#cd Dexter/GrovePi/Software/Python
#wget https://github.com/DexterInd/RFR_Tools/blob/master/miscellaneous/di_i2c.py?raw=true
#wget https://github.com/DexterInd/RFR_Tools/blob/master/miscellaneous/di_mutex.py?raw=true
#(then run the same wget command but for the file named “di_mutex.py?raw=true”)
#sudo mv di_i2c.py?raw=true di_i2c.py
#sudo mv di_mutex.py?raw=true di_mutex.py
#python grove_led_blink.py ##check if working with LED connected to D4 on GrovePi

#
#       LORA /GPS HAT v 1.4 
cd /tmp
wget https://github.com/WiringPi/WiringPi/releases/download/2.61-1/wiringpi-2.61-1-armhf.deb
sudo dpkg -i wiringpi-2.61-1-armhf.deb
# vnc 
sudo apt-get install tightvncserver -y
# tightvncserver
# todo : add  vncserver :1 when rpi is starting

#
#   MQTT
#
sudo apt install -y mosquitto
sudo apt install -y mosquitto-clients -y 
#
#
#test.mosquitto.org
#mosquitto_pub -h test.mosquitto.org -t DIY-bike/sensor/temp -m 22.5
#mosquitto_sub -h test.mosquitto.org -t DIY-bike/sensor/temp
#sudo systemctl enable mosquitto.service
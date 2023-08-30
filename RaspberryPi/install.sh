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


#### BLUETOOTH
#sudo apt-get install pi-bluetooth
#sudo apt-get install bluetooth bluez blueman
#sudo apt install bluez bluez-tools
# https://www.theengineeringprojects.com/2023/07/control-home-appliances-with-rpi4-ble.html nope 
#sudo apt-get --purge remove bluez -y 
#cd ~; wget http://www.kernel.org/pub/linux/bluetooth/bluez-5.50.tar.xz
#tar xvf bluez-5.50.tar.xz
#sudo apt-get update
#sudo apt-get install -y libusb-dev libreadline-dev libglib2.0-dev libudev-dev libdbus-1-dev libical-dev
#cd bluez-5.50
#./configure --enable-library
#make -j4
# fix bug add 1 include in a file  2 files in tools dir  thx to jaui
#sudo make install
# check btmon -v 
# https://www.instructables.com/Control-Bluetooth-LE-Devices-From-A-Raspberry-Pi/ nope
#export LDFLAGS=-lrt
#sudo cp attrib/gatttool /usr/bin/
# https://dikuw.wordpress.com/2019/12/05/setting-up-raspberry-pi-as-a-bluetooth-low-energy-peripheral/  nope
#sudo apt-get install nodejs
#sudo npm install bleno
#sudo npm install onoff
#sudo apt install libudev-dev

# sudo npm install -g n
# sudo n 8.9.0
#sudo npm install bluetooth-hci-socket 

#
#sudo apt-get install bluez
#hciconfig
#sudo hciconfig hci0 up



# node red

node-red-pi --max-old-space-size=256
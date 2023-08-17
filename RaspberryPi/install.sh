#
#
sudo apt install arduino
pip install python-periphery
pip install wiringpi
curl -kL dexterindustries.com/update_grovepi 5 | bash
cd Dexter/GrovePi/Software/Python
wget https://github.com/DexterInd/RFR_Tools/blob/master/miscellaneous/di_i2c.py?raw=true
wget https://github.com/DexterInd/RFR_Tools/blob/master/miscellaneous/di_mutex.py?raw=true
#(then run the same wget command but for the file named “di_mutex.py?raw=true”)
sudo mv di_i2c.py?raw=true di_i2c.py
sudo mv di_mutex.py?raw=true di_mutex.py
python grove_led_blink.py ##check if working with LED connected to D4 on GrovePi
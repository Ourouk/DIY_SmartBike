 # DIY_SmartBike
## Description
This project is about providing all the innovations (and more) of the modern smart bike industry to people who doesn't have the money to buy these expensive ones.
## Features Summary 

-  Crash Detection and optionally dashcam

-  Unlock your bike with RFID

-  Theft detection (wrong rfid or force opening the locker)

-  GPS tracker : update the localization of your bike on a map when you are not near 

-  Automatic Light : use a light sensor to adapt your lighting to the exterior conditions.

-  Backup all the available information on dedicated cloud.

-  Android Dashboard providing useful information to the user.
## Design Information
 ![image](https://github.com/Ourouk/DIY_SmartBike/raw/master/IOT.drawio.svg)
### Layer 1 - Hardware Interaction
Our Interactions with the hardware are going to be made using red-node and some python code. See below :
- Camera
- Accelerometer
- GPS
- RFID sensor
- Buzzer
- Light
- Relay
- Light Sensor
- Lora Hat
- LCD Screen
- Raspberry Pi 3b+
    - Bluetooth
    - Wi-Fi
### Layer 2 - Interact with the smart device
For that purpose, we will use Bluetooth to enable communication between the Raspberry Pi and android smartphone.
When the smartphone isn't near the bike, the bike switch to a lost mode, that use Lora to communicate its coordinates to our servers.
 #### BLE


#### LORA 


### Layer 2.5
Our servers will communicate to the Android Smartphone and the Pi (via Lora).
They are storing all the localization and different data of the users to provide them with a map of their journey with their bike.
 #### Server Architecture
 Rocky Linux was chosen as the distribution of Linux that we will use. And for the different service, we will encapsulate them inside  dockers to provide a microservice design.
### Layer 3 Update/Customer Service
Remote access is done via a Wi-Fi connection with the Raspberry Pi which is disabled by default and can be enabled by the user if they need to. (aka help mode)
### Layer 4 External API Calls
The Android application will need to use external services to provide the user with accurate and useful data through their journeys.
## Post-Note
This project is made for a school project and is totally free to use.
And will not be maintained after this project end.

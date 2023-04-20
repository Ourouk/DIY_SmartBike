# dragino lora testing
# Single lora testing app

default: main.cpp
	gcc -Wall -o main main.cpp -lwiringPi -lwiringPiDev -lstdc++
reference: mainb.cpp
	gcc -Wall -o main mainb.cpp -lwiringPi -lwiringPiDev
deploy: default
	cp main /opt/diy_smartbike/sensor-loragps

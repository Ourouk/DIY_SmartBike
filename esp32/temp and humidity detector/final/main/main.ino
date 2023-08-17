// https://randomnerdtutorials.com/ttgo-lora32-sx1276-arduino-ide/


/////////////////////////////////////////////////////
//////////////////////LIBRAIRIES TO ADD///////////////
//////////////////////////////////////////////////////
// libs add adafruit ssd 1306 
// gfx  by adafruit
// lora by sandeep m
//
// tinygpsplus by mikal hart
// axp202x by lewis he 
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

#include <SPI.h>
#include <LoRa.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Libs for GPS 
#include <TinyGPS++.h>
#include <axp20x.h>


//define the pins used by the LoRa transceiver module
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26


//866E6 for Europe   //915E6 for North America  //433E6 for Asia
#define BAND 868.1E6

//OLED pins
#define OLED_SDA 4
#define OLED_SCL 15 
#define OLED_RST 16
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// GPS PINS 
#define RXD2 5
#define TXD2 4

// GPS VARS
TinyGPSPlus gps;
HardwareSerial GPS(1);
AXP20X_Class axp;


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

void setup() {
  //initialize Serial Monitor
   Serial.begin(9600);

  //reset OLED display via software
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  //initialize OLED
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Address 0x3C for 128x32
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  //initialize GPS
  Wire.begin(21, 22);
  axp.setPowerOutPut(AXP192_LDO2, AXP202_ON);
  axp.setPowerOutPut(AXP192_LDO3, AXP202_ON);
  axp.setPowerOutPut(AXP192_DCDC2, AXP202_ON);
  axp.setPowerOutPut(AXP192_EXTEN, AXP202_ON);
  axp.setPowerOutPut(AXP192_DCDC1, AXP202_ON);
  GPS.begin(9600, SERIAL_8N1, RXD2, TXD2); 

// OLED SCREEN
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LORA SENDER ");
  display.display();
  
//  Serial.println("LoRa Sender Test");

  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  
  if (!LoRa.begin(BAND)) {
//   Serial.println("Starting LoRa failed!");
    while (1);
  }
//  Serial.println("LoRa Initializing OK!");
  display.setCursor(0,10);
  display.print("LoRa Initializing OK!");
  display.display();
  delay(1000);
}

void loop() {
   
  //Serial.print("Sending packet: ");
  //Serial.println(counter);

  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print("{satellites:");
  LoRa.print( gps.satellites.value());
  LoRa.print(",time:");
  LoRa.print(  (gps.time.hour()+2)%24  );
  LoRa.print("/");
  LoRa.print(gps.time.minute());
  
  LoRa.print(",lng:");
  LoRa.print(gps.location.lng());
  LoRa.print(",lat:");
  LoRa.print(gps.location.lat());
  LoRa.print(",alt:");
  LoRa.print( gps.altitude.feet() / 3.2808);
  LoRa.print(",speed:");
  LoRa.print(gps.speed.kmph());
  LoRa.print("}");
  LoRa.endPacket();
  

  Serial.print("Time      : ");
  Serial.print(gps.time.hour());
  Serial.print(":");
  Serial.print(gps.time.minute());
  Serial.print(":");
  Serial.println(gps.time.second());
  Serial.print("Satellites: ");
  Serial.println(gps.satellites.value());


  display.clearDisplay();
  display.setCursor(0,0);
  display.println("NBR GPS");
  display.print( gps.satellites.value());
  display.setCursor(0,20);
  display.setTextSize(1);
  display.print("LoRa packet sent.");
  display.setCursor(0,30);
  //display.print("Counter:");
  //display.setCursor(50,30); 
  display.display();
  
  smartDelay(1000);
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (GPS.available())
      gps.encode(GPS.read());
  } while (millis() - start < ms);
}


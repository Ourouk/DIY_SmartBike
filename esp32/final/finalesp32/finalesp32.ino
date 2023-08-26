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
#define RXD2 16  // 4  // BREAK OLED it s normal
#define TXD2 17  // 5

//CRC 
#define CRC_POLYNOMIAL 0x3185 // CRC-16 CCITT polynomial

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
uint16_t calculate_crc(const char *data, size_t length);
void loop() {
   
  //Serial.print("Sending packet: ");
  //Serial.println(counter);

  //Send LoRa packet to receiver
  std::string buff;char buffer[20];
  buff.append("{name:");
  buff.append("Rpi");
  buff.append(",satel:");
  std::sprintf(buffer, "%u", gps.satellites.value());
  buff.append(buffer);
  buff.append(",lon:");
  std::sprintf(buffer, "%u", gps.location.lng());
  buff.append(buffer);
  buff.append(",lat:");
  std::sprintf(buffer, "%u", gps.location.lat());
  buff.append(buffer);
  buff.append(",speed:");
  std::sprintf(buffer, "%u",gps.speed.kmph()/3.6);
  buff.append(buffer);
  buff.append(",heading:");
  std::sprintf(buffer, "%u", gps.course.deg());
  buff.append(buffer);
  buff.append("}");
  uint16_t crc = calculate_crc(buff.c_str(), buff.size());
  std::sprintf(buffer, "%u", crc);
  buff.append(buffer);

  Serial.println(buff.c_str());
  LoRa.beginPacket();
  LoRa.print(buff.c_str());
  LoRa.endPacket();

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

uint16_t calculate_crc(const char *data, size_t length) {
    uint16_t crc = 0xFFFF;
    
    for (size_t i = 0; i < length; i++) {
        crc ^= (uint16_t)data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ CRC_POLYNOMIAL;
            } else {  
                crc >>= 1;
            }
        }
    }
    
    return crc;
}


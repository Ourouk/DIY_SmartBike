
/*
  * source humidity  https://esp32io.com/tutorials/esp32-temperature-humidity-sensor
  * source lora code  https://randomnerdtutorials.com/ttgo-lora32-sx1276-arduino-ide/
  *  libs add 
  *  adafruit ssd 1306 
  *  gfx  by adafruit
  *  lora by sandeep m
  *  DHT sensor library by adafruit
*/


#include <SPI.h>
#include <LoRa.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
///humidity
#include <DHT.h>
#define DHT_SENSOR_PIN  21 // ESP32 pin GIOP21 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11

//define the pins used by the LoRa transceiver module
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

//433E6 for Asia
//866E6 for Europe
//915E6 for North America
#define BAND 868.1E6

//OLED pins
#define OLED_SDA 4
#define OLED_SCL 15 
#define OLED_RST 16
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels




DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);


void setup() {
  Serial.begin(9600);
  dht_sensor.begin(); // initialize the DHT sensor
  Serial.print("end begin");

  //reset OLED display via software
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  //initialize OLED
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0,0);
  display.display();
  
  Serial.println("LoRa Sender Test");

  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Initializing OK!");
  display.setCursor(0,10);
  display.print("LoRa Initializing OK!");
  display.display();
  delay(2000);

}

void loop() {
  
  
  // read humidity
  float humi  = dht_sensor.readHumidity();
  // read temperature in Celsius
  float tempC = dht_sensor.readTemperature();


  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("NO DATA RECEIVE");
    display.display();
  } else {
    Serial.println("");
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");
    Serial.print("  |  ");
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("C");
    //Send LoRa packet to receiver
    LoRa.beginPacket();
    LoRa.print("{humi:");
    LoRa.print(humi);
    LoRa.print(",tempC:");
    LoRa.print(tempC);
    LoRa.print("}");
    LoRa.endPacket(); 
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("humidity: ");
    display.setCursor(55,0);    
    display.print(humi);
    display.setCursor(0,20);
    display.setTextSize(1);
    display.print(" ");
    display.setCursor(0,30);
    display.print("Temp: ");
    display.setCursor(50,30);
    display.print(tempC);      
    display.display();


  }

  

  // wait a 5 seconds between readings
  delay(5000);

  

}











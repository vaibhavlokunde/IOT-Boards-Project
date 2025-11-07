#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include "ThingSpeak.h"
#include "DHT.h"
#define DHTTYPE DHT22 
#define DHTPIN  4
DHT dht(DHTPIN, DHTTYPE);


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


const int LED_PIN = 13;
const char* WIFI_NAME="Wokwi-GUEST";
const char* WIFI_PASSWORD="";
const int myChannelNumber= 3152732;
const char* myApiKey= "CH8LC9T1T7BX0BH4";
const char* server="api.thingspeak.com";

WiFiClient client;

void setup(){
  Serial.begin(115200);
  Serial.print("DHT22 ESP32");
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("DHT22");
  display.setCursor(0,30);
  display.print("ESP32");
  delay(2000);

  pinMode(LED_PIN, OUTPUT);
  dht.begin();

  display.clearDisplay();
  display.setCursor(0,10);
  display.print("Check WiFi");
  display.display();
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while(WiFi.status()!=WL_CONNECTED){
    delay(1000);
    Serial.println("WiFi Not Connected");
  }

  display.setCursor(0,30);
  display.println("Connected !");
  display.display();
  Serial.println("WiFi Connected !");
  Serial.print("Local IP: "+ String(WiFi.localIP()));
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop(){
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  //LED status ON
  if(humidity>80 || temperature>40) digitalWrite(LED_PIN, 1);
  else digitalWrite(LED_PIN, 0);

  //display data
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,10);
  display.print("Temp=");
  display.print(temperature);
  display.setCursor(0,30);
  display.print("Humidity=");
  display.print(humidity);
  display.display();

  //send data
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  int x = ThingSpeak.writeFields(myChannelNumber, myApiKey);

  Serial.println("Temp: " + String(temperature, 2) + "°C");
  Serial.println("Humidity: " + String(humidity, 1) + "%");

  if (x == 200) {
    Serial.println("Data pushed successful!");
  } 
  else {
    Serial.println("Push error " + String(x));
  }

  Serial.println("---");
  delay(20000);
}

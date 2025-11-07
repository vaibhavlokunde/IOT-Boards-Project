#define BLYNK_TEMPLATE_ID "TMPL3kA--9aOh"
#define BLYNK_TEMPLATE_NAME "iotDHT22"
#define BLYNK_AUTH_TOKEN ""

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

void sendSensorData() {
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  float hum = dht.readHumidity();

  if (isnan(tempC) || isnan(tempF) || isnan(hum)) {
    Serial.println("Failed to read from DHT22 sensor!");
    return;
  }

  Serial.print("Temp: "); Serial.print(tempC); Serial.print(" °C | ");
  Serial.print(tempF); Serial.print(" °F | ");
  Serial.print("Hum: "); Serial.print(hum); Serial.println(" %");

  Blynk.virtualWrite(V0, tempC);
  Blynk.virtualWrite(V1, tempF);
  Blynk.virtualWrite(V2, hum);
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}


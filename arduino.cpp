#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // try 0x3F if needed
Servo flap;

const int moisturePin = A0;
const int servoPin    = 9;

// Tune this after you see the live value on Serial Monitor
int WET_DRY_THRESHOLD = 500; // >500 = Dry, <=500 = Wet

void setup() {
  Serial.begin(9600);

  // LCD
  lcd.init();          // or lcd.begin(16,2) if your lib prefers
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waste Segregator");
  lcd.setCursor(0, 1);
  lcd.print("Init...");
  
  // Servo
  flap.attach(servoPin);
  flap.write(90); // neutral

  delay(1500);
  lcd.clear();
}

void loop() {
  int moisture = analogRead(moisturePin);
  Serial.print("Moisture: ");
  Serial.println(moisture);

  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisture);
  lcd.print("   "); // clear tail

  lcd.setCursor(0, 1);
  if (moisture > WET_DRY_THRESHOLD) {     // dryer reading = higher value
    lcd.print("Type: DRY Waste  ");
    flap.write(0);                         // move flap to DRY side
  } else {
    lcd.print("Type: WET Waste  ");
    flap.write(180);                       // move flap to WET side
  }

  delay(1500);
}

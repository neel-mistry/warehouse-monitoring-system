#include <LiquidCrystal.h>
int buzzerPin = 9;
int buttonPin = 7;
const int redLedPin = 13;
const int greenLedPin = 12;

// Initialize the LCD display
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Ready to receive data");
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(2, OUTPUT);     // Configure pin 2 as an output pin
  digitalWrite(2, HIGH);  // Set pin 2 to HIGH to enable HC-05 communication

  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Serial.begin(9600);  // HC-05 default speed in AT command mode
}

void loop() {

  if (Serial.available()) {
    char receivedChar = Serial.read();
    if (receivedChar == 'A') {
      lcd.print("Normal Temp");
      delay(2000);
      lcd.clear();
      Serial.println("Normal Temperature");
      
      digitalWrite(buzzerPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      delay(2000);
    } else if (receivedChar == 'B') {
      Serial.println("WARNING! TEMPERATURE INCREASED!!");
      lcd.print("Thermal Warning!!");
      digitalWrite(greenLedPin, LOW);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(redLedPin, LOW);
      delay(500);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(redLedPin, LOW);
      delay(500);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(redLedPin, LOW);
      delay(2000);
      lcd.clear();
    } else if (receivedChar == 'C') {
      Serial.println("WARNING! HUMIDITY INCREASED!!");
      lcd.print("Humidity Warning!!");
      digitalWrite(greenLedPin, LOW);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(redLedPin, LOW);
      delay(500);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(redLedPin, LOW);
      delay(500);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(redLedPin, LOW);
      delay(2000);
      lcd.clear();
    } 
  }else{
    lcd.setCursor(4, 0);
    lcd.print("NO DATA!");
    delay(500);
    lcd.clear();
  }
}

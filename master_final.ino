#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11

// Initialize the LCD display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(38400);
  dht.begin();
  // Serial.begin(9600);
  Serial.println("Sending temperature and humidity data to HC-05 module");

  pinMode(3, OUTPUT);     // Configure pin 3 as an output pin
  digitalWrite(3, HIGH);  // Set pin 3 to HIGH to enable HC-05 communication

  Serial.begin(9600);    // HC-05 default speed in AT command mode
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

}

void loop() {
  Serial.println("----------");
  // Reading temperature and humidity data from the DHT11 sensor
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.println("Temp: " + String(temp));
  Serial.println("Humidity: " + String(hum));
  Serial.println("----------");
  Serial.println("");
 
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(hum);
  lcd.print(" %");
  delay(2000);
  lcd.clear();

  if (temp<30){
    if(hum<70){
      Serial.write('A');
    }else if(hum>69){
      Serial.write('C');
    }
  }else if(temp>29){
    Serial.write('B');
  }
  // if(temp < 33 && hum < 60){
  //   Serial.write('A');
  // }else if(temp >= 33 && hum >= 60){
  //   Serial.write('B');
  // }
  else{
    Serial.write('n');
  }
  delay(2000);  // Wait for 2 seconds before sending again
}
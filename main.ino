#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;

const int rs = 2,
          en = 3,
          d4 = 8,
          d5 = 9,
          d6 = 10,
          d7 = 11;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define DHT11_PIN 7
int photocell_pin = A2;
int current = 0;
void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  int val = analogRead(photocell_pin);

  int light = val / 1023.0 * 100;

  int chk = DHT.read11(DHT11_PIN);

  String lines[] = {
    "Temp: " + String(DHT.temperature) + "C",
    "Humid: " + String(DHT.humidity) + "%",
    "Light: " + String(light) + "%"
  };

  lcd.print(lines[current % 3]);
  lcd.setCursor(0, 1);
  lcd.print(lines[(current + 1) % 3]);

  current++;
  delay(5000);
}

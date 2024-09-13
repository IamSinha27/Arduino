#include <LiquidCrystal_I2C.h>
const int red = 7;
const int green = 9;
const int trig = 3; // Adjusted trig pin
const int echo = 2; // Adjusted echo pin
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(trig, OUTPUT);  // Adjusted to OUTPUT for trigger
  pinMode(echo, INPUT);
  Serial.begin(9600);
    lcd.begin(16, 2);

  // Print a welcome message
  lcd.print("Distance Monitor");
  delay(2000); // Display for 2 seconds
  lcd.clear(); // Clear the display
}

void loop() {
  long duration, distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(15); // Adjusted trigger pulse duration
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;
  
  

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 50) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  } else {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }

  delay(500); // Adjusted delay for readability
}

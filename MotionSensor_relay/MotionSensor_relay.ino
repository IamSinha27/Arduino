#include <SoftwareSerial.h>

const int relayPin = 2;
const int pirPin = 3; // PIR sensor output connected to digital pin 3
const int ldr=4;

unsigned long lastMotionTime = 0; // Variable to store the time of the last motion detection
const unsigned long motionDelay = 20000; // Delay for turning off the relay (20 seconds)

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  pinMode(pirPin, INPUT);

  pinMode(ldr, INPUT);

  // Start serial communication with USB
  Serial.begin(9600);

}

void loop() {
  // Check for motion
  int motion = digitalRead(pirPin);
  int dark= digitalRead(ldr);

  if (motion == HIGH) {
    // Motion detected
    if (digitalRead(relayPin) == HIGH && dark==HIGH){
      // If the relay is off, turn it on
      digitalWrite(relayPin, LOW);
      lastMotionTime = millis(); // Update the last motion time
      Serial.println("Motion detected! Light turned on.");
    } 
    else if (digitalRead(relayPin) == LOW) {
      // If the relay is off, turn it on
      digitalWrite(relayPin, LOW);
      lastMotionTime = millis(); // Update the last motion time
      Serial.println("Time extended!.");
    } 
  }
  else {
      // If the relay is already on, check if it's time to turn it off
      unsigned long currentTime = millis();
      Serial.println(currentTime-lastMotionTime);
      if (currentTime - lastMotionTime >= motionDelay) {
        digitalWrite(relayPin, HIGH);
        Serial.println("No motion within the delay period. Light turned off.");
      }
    }

  delay(100);
}



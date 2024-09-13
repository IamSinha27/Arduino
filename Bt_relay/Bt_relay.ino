#include <SoftwareSerial.h>

const int relayPin = 2;
char val;

// Define SoftwareSerial object for Bluetooth communication
SoftwareSerial bluetoothSerial(10, 11); // RX (D10) and TX (D11) pins

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  // Start serial communication with USB
  Serial.begin(9600);

  // Start serial communication with Bluetooth module
  bluetoothSerial.begin(9600);
}

void loop() {
  // Check for commands from Bluetooth
  if (bluetoothSerial.available()) {
    val = bluetoothSerial.read();
    
    // Check conditions and toggle relay state accordingly
    if (val == '1' && digitalRead(relayPin) == HIGH) {
      digitalWrite(relayPin, LOW);
    } else if (val == '0' && digitalRead(relayPin) == LOW) {
      digitalWrite(relayPin, HIGH);
    }
  }

  delay(100);
}

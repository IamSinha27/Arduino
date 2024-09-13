#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10  // Set the SS pin for RFID module
#define RST_PIN 9  // Set the RST pin for RFID module

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create an MFRC522 instance

Servo myservo;  // Create a Servo instance
int servoPin = 5;  // Set the PWM pin for the servo motor

bool tagPresent = false;  // Flag to track if the RFID tag is present

void setup() {
  SPI.begin();      // Initiate SPI communication
  mfrc522.PCD_Init();  // Initiate RFID module

  myservo.attach(servoPin);  // Attach the servo to the specified pin
  moveServo(0);  // Move the servo to the initial position (0 degrees)
}

void loop() {
  // Look for new RFID cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Check if the RFID tag is authorized
    if (isAuthorizedTag()) {
      if (!tagPresent) {
        moveServo(180);  // Move the servo to 180 degrees if the tag was not present before
        tagPresent = true;  // Set the flag to indicate the tag is present
      } else {
        moveServo(0);  // Move the servo back to 0 degrees if the tag was already present
        tagPresent = false;  // Reset the flag
      }
    }

    mfrc522.PICC_HaltA();  // Halt PICC
  }
}

bool isAuthorizedTag() {
  // Define the UID of the authorized RFID tag
  byte authorizedTag[] = {0x9A, 0x1B, 0x72, 0x15};

  // Compare the UID of the detected tag with the authorized tag
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] != authorizedTag[i]) {
      return false;  // Tag is not authorized
    }
  }

  return true;  // Tag is authorized
}

void moveServo(int angle) {
  // Move the servo to the specified angle
  myservo.write(angle);
  delay(500);  // Add a delay for the servo to reach the target position
}

#include <Servo.h>

Servo myServo;
int x = A0;  // Connect X-axis of joystick to A0
int y = A1;  // Connect Y-axis of joystick to A1
int buttonPin = 5;


void setup() {
  myServo.attach(12); // Attach the servo to digital pin 9
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as INPUT with internal pull-up resistor

}


void loop() {
  // put your main code here, to run repeatedly:
int xval=analogRead(x);
int yval=analogRead(y);
int click=digitalRead(buttonPin);

int yangle=map(yval,0,1023,0,180);
myServo.write(yangle);
delay(15);

if(click==LOW)
{
   for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle); // Set servo position
                    // Wait for the servo to reach the position
         // Wait for the servo to reach the position
  }

  delay(500); // Pause for 1 second at the end position

  // Sweep the servo back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle); // Set servo position
                        // Wait for the servo to reach the position
   // Wait for the servo to reach the position
  }
}



}

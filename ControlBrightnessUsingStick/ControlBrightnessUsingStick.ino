#include <Servo.h>
Servo myServo;

const int xAxisPin = A0;   // Connect VRx to A0
const int yAxisPin = A1;   // Connect VRy to A1
const int buttonPin = 5;   // Connect SW to D2
const int green=7;
const int yellow=8;
const int red=9;
const int pr=2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  myServo.attach(12);
}

void loop() {
  // put your main code here, to run repeatedly:
 int xAxisValue = analogRead(xAxisPin);
  int yAxisValue = analogRead(yAxisPin);
  int buttonState = digitalRead(buttonPin);
  Serial.print("X-Axis: ");
  Serial.print(xAxisValue);
  Serial.print("\tY-Axis: ");
  Serial.print(yAxisValue);
  Serial.print("\tButton: ");
  Serial.print(buttonState == LOW ? "Pressed" : "Released");

  int brightness=map(xAxisValue,504,1023,0,255);

 
  Serial.print("\tBrightNess: ");
  Serial.println(brightness);
  analogWrite(green,brightness);




  int prval=digitalRead(pr);

  if(prval==HIGH || buttonState==LOW)
  {
    digitalWrite(green,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,HIGH);
    myServo.write(180);
    delay(1000);
  }
  else if(prval==LOW)
  {
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    myServo.write(0);
    delay(1000);
  }
 


  // delay(1000);  // Adjust delay for smoother serial output
}

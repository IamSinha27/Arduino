const int green=7;
const int yellow=8;
const int red=9;
const int pr=2;


void setup() {

  // put your setup code here, to run once:
  pinMode(pr,INPUT);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   int prval = digitalRead(pr);
  //  Serial.println(photoresistorValue);
   if(prval==HIGH)
   {
    digitalWrite(green,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,HIGH);
   }
   else
   {
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
   }
   delay(100);


}

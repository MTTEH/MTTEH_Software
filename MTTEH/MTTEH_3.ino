#include <Arduino.h>

const byte Triggerpin= 1;
const byte Echopin = 0;

const float Measuretimeout = 000267F;
const float LumSpeed = 299792458.0/1000;

void setup(){
  Serial.begin(115200);

  pinMode(Triggerpin, OUTPUT);
  digitalWrite(Triggerpin, LOW);
  pinMode(Echopin, INPUT);
}
void loop(){
  digitalWrite(Triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Triggerpin, LOW);
  long measure = pulseIn(Echopin, HIGH, Measuretimeout);
  float distance_cm = measure / 2.0 * LumSpeed;
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println("cm");
  delay(200);
}

#include <Arduino.h>
#include <mtteh.h>

byte vitesse1 = 100;
byte vitesse2 = 100;

long randNumber;

byte sensorPin = 12;
byte indicator = 13;

void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  Serial.begin(9600);
}
void Arret(){
  analogWrite(MAvD1, 0);
  analogWrite(MArD1, 0);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
  analogWrite(MAvG1, 0);
  analogWrite(MArG1, 0);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
  delay(20);
}
void Marcheavant(){
  Arret();
  analogWrite(MAvD1, vitesse1);
  analogWrite(MArD1, vitesse1);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
  analogWrite(MAvG1, vitesse2);
  analogWrite(MArG1, vitesse2);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
}
void Tournerdroite(){
  Arret();
  analogWrite(MAvD1, 0);
  analogWrite(MArD1, 0);
  analogWrite(MAvD2, vitesse1);
  analogWrite(MArD2, vitesse1);
  analogWrite(MAvG1, vitesse2);
  analogWrite(MArG1, vitesse2);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
}
void Tournergauche(){
  Arret();
  analogWrite(MAvD1, vitesse1);
  analogWrite(MArD1, vitesse1);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
  analogWrite(MAvG1, 0);
  analogWrite(MArG1, 0);
  analogWrite(MAvD2, vitesse2);
  analogWrite(MArD2, vitesse2);
  delay(20);
}
void loop()
{
  delay(2000);
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  delay(1000);
    if (state == 1){
    randNumber = random(2);
    while (randNumber == 0 and state == 1){
      Arret();
      Tournerdroite();
      randNumber = random(5, 20);
      delay(randNumber);
      Arret();
      byte state = digitalRead(sensorPin);
      digitalWrite(indicator,state);
      delay(1000);
    }
    while (randNumber == 1 and state == 1){
      Arret();
      Tournergauche();
      randNumber = random(5, 20);
      delay(randNumber);
      Arret();
      byte state = digitalRead(sensorPin);
      digitalWrite(indicator,state);
      delay(1000);
    }
  }
  else{
    Marcheavant();
  }
}

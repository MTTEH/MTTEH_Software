#include <Arduino.h>
#include <MTTEH.h>

byte vitesse1 = 100;
byte vitesse2 = 100;

long randNumber;

const byte TriggerPin= 10;
const byte EchoPin = 11;

const unsigned long MeasureTimeout = 25000UL;
const float SoundSpeed = 340.0/1000;

void setup(){
  Serial.begin(115200);

  pinMode(TriggerPin, OUTPUT);
  digitalWrite(TriggerPin, LOW);
  pinMode(EchoPin, INPUT);
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
}

void loop() {
  Marcheavant();
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  long measure = pulseIn(EchoPin, HIGH, MeasureTimeout);
  float distance_c m= measure / 2.0 * SoundSpeed / 10.0;
  delay(200);
  if (distance_cm <= 50){
    randNumber = random(2);
    while (randNumber == 0 and distance_cm <= 50){
      Arret();
      Tournerdroite();
      randNumber = random(5, 20);
      delay(randNumber);
      Arret();
      digitalWrite(TriggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(TriggerPin, LOW);
      long measure = pulseIn(EchoPin, HIGH, MeasureTimeout);
      float distance_cm = measure / 2.0 * SoundSpeed / 10.0;
      delay(200);  
    }
    while (randNumber == 1 and distance_cm <= 50){
      Arret();
      Tournergauche();
      randNumber = random(5, 20);
      delay(randNumber);
      Arret();
      digitalWrite(TriggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(TriggerPin, LOW);
      long measure = pulseIn(EchoPin, HIGH, MeasureTimeout);
      float distance_cm = measure / 2.0 * SoundSpeed / 10.0;
      delay(200);
    }
  }
  else{
    Marcheavant();
  }
}

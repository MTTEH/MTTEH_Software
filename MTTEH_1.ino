const int MAvD1 = 2;
const int MAvD2 = 3;
const int MAvG1 = 4;
const int MAvG2 = 5;
const int MArD1 = 6;
const int MArD2 = 7;
const int MArG1 = 8;
const int MArG2 = 9;

byte vitesse1;
byte vitesse2;


void setup() {
  pinMode(MAvD1, OUTPUT);
  pinMode(MAvD2, OUTPUT);
  pinMode(MAvD1, OUTPUT);
  pinMode(MAvD1, OUTPUT);
  pinMode(MAvD1, OUTPUT);
  pinMode(MAvD1, OUTPUT);
  pinMode(MAvD1, OUTPUT);
  pinMode(MAvD1, OUTPUT);

  MarcheAvant();
  MarcheArriere();
  TournerDroite();
  TournerGauche();
  arret();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void MarcheAvant(){
  arret();
  analogWrite(MAvD1, vitesse1);
  analogWrite(MArD1, vitesse1);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
  analogWrite(MAvG1, vitesse2);
  analogWrite(MArG1, vitesse2);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
}
void MarcheArriere(){
  arret();
  analogWrite(MAvD1, 0);
  analogWrite(MArD1, 0);
  analogWrite(MAvD2, vitesse1);
  analogWrite(MArD2, vitesse1);
  analogWrite(MAvG1, 0);
  analogWrite(MArG1, 0);
  analogWrite(MAvD2, vitesse2);
  analogWrite(MArD2, vitesse2);
}
void TournerDroite(){
  arret();
  analogWrite(MAvD1, 0);
  analogWrite(MArD1, 0);
  analogWrite(MAvD2, vitesse1);
  analogWrite(MArD2, vitesse1);
  analogWrite(MAvG1, vitesse2);
  analogWrite(MArG1, vitesse2);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
}
void TournerGauche(){
  arret();
  analogWrite(MAvD1, vitesse1);
  analogWrite(MArD1, vitesse1);
  analogWrite(MAvD2, 0);
  analogWrite(MArD2, 0);
  analogWrite(MAvG1, 0);
  analogWrite(MArG1, 0);
  analogWrite(MAvD2, vitesse2);
  analogWrite(MArD2, vitesse2);
}
void arret(){
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

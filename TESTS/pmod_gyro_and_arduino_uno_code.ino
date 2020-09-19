/************************************************************************
*
* Test of the Pmod
*
*************************************************************************
* Description: Pmod_GYRO
* The 3 components X, Y, and Z of the gyroscope
* are displayed in the serial monitor
*
* Material
* 1. Arduino Uno
* 2. Pmod GYRO
*
************************************************************************/

// Déclaration des adresses du module
#define L3G4200D_Adresse 0x69 // adress of L3G4200D
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define REGISTRE_MSB_X 0x29 // MSB axe X
#define REGISTRE_LSB_X 0x28 // LSB axe X
#define REGISTRE_MSB_Y 0x2B // MSB axe Y
#define REGISTRE_LSB_Y 0x2A // LSB axe Y
#define REGISTRE_MSB_Z 0x2D // MSB axe Z
#define REGISTRE_LSB_Z 0x2C // LSB axe Z

// call library
#include "MTTEH_Project.h"

int composante_X;
int composante_Y;
int composante_Z;

byte composante_MSB_X;
byte composante_LSB_X;
byte composante_MSB_Y;
byte composante_LSB_Y;
byte composante_MSB_Z;
byte composante_LSB_Z;

void setup(void)
{
 Serial.begin(115200);
 Wire.begin();
 Init_L3G4200D(2000);
 delay(1000);
}

void loop()
{
    Lecture_Module();

    Serial.print("X="); // Display of components in the serial monitor
    Serial.println(composante_X);
    Serial.print("Y=");
    Serial.println(composante_Y);
    Serial.print("Z=");
    Serial.println(composante_Z);
    Serial.println("");
    
    delay(500);
}

// initialization of L3G4200D
void Init_L3G4200D(int echelle)
{
    Wire.beginTransmission(L3G4200D_Adresse);
    Wire.write(CTRL_REG1);
    Wire.write(0b00001111);
    Wire.endTransmission();
    Wire.beginTransmission(L3G4200D_Adresse);
    Wire.write(CTRL_REG2);
    Wire.write(0b00000000);
    Wire.endTransmission();
    Wire.beginTransmission(L3G4200D_Adresse);
    Wire.write(CTRL_REG3);
    Wire.write(0b00001000);
    Wire.endTransmission();
    if (echelle==250) {
        Wire.beginTransmission(L3G4200D_Adresse);
        Wire.write(CTRL_REG4);
        Wire.write(0b00000000);
        Wire.endTransmission();
    }
    if (echelle==500) {
        Wire.beginTransmission(L3G4200D_Adresse);
        Wire.write(CTRL_REG4);
        Wire.write(0b00010000);
        Wire.endTransmission();
    } else {
        Wire.beginTransmission(L3G4200D_Adresse);
        Wire.write(CTRL_REG4);
        Wire.write(0b00110000);
        Wire.endTransmission();
    }
    Wire.beginTransmission(L3G4200D_Adresse);
    Wire.write(CTRL_REG5);
    Wire.write(0b00000000);
    Wire.endTransmission();
}

// Reading values X, Y et Z
void Lecture_Module()
{
    composante_MSB_X = Lecture_Registre(REGISTRE_MSB_X); // lecture MSB_X
    composante_LSB_X = Lecture_Registre(REGISTRE_LSB_X); // lecture LSB_X
    composante_X = ((composante_MSB_X << 8) | composante_LSB_X); // Component  reconstruction_X
    composante_MSB_Y = Lecture_Registre(REGISTRE_MSB_Y); // lecture MSB_Y
    composante_LSB_Y = Lecture_Registre(REGISTRE_LSB_Y); // lecture LSB_Y
    composante_Y = ((composante_MSB_Y << 8) | composante_LSB_Y); // Component  reconstruction_Y
    composante_MSB_Z = Lecture_Registre(REGISTRE_MSB_Z); // lecture MSB_Z
    composante_LSB_Z = Lecture_Registre(REGISTRE_LSB_Z); // lecture LSB_Z
    composante_Z = ((composante_MSB_Z << 8) | composante_LSB_Z); // Component reconstruction_Z
}

// Reading a register from the module L3G4200D
int Lecture_Registre(byte registre)
{
    int v;
    Wire.beginTransmission(L3G4200D_Adresse);
    Wire.write(registre);
    Wire.endTransmission();
    Wire.requestFrom(L3G4200D_Adresse, 1);
    wait_for(Wire.available());
    v = Wire.read();
    return v;
}

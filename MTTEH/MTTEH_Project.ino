/*
** MTTEH Main Software
** https://github.com/MTTEH/MTTEH_Software
** 
** Authors :
**  - Narutarded (https://github.com/narutarder).
**  - Kiradae (https://github.com/Kiradae).
**  - GGLinnk (https://github.com/GGLinnk) <gglinnk@protonmail.com>.
**  - Wabia (https://github.com/wabia).
** 
** Licence GPLv3
**
** Lycée Frédéric Ozanam | Cesson-Sévigné | 2018-2019
** Personal Project      | World          | 2018-2020
** 
**/

#include "MTTEH_Project.h"

void trigger()
{
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
}

void setup() {
    Serial.begin(115200);

    pinMode(MAvD1, OUTPUT);
    pinMode(MAvD2, OUTPUT);
    pinMode(MAvG1, OUTPUT);
    pinMode(MAvG1, OUTPUT);
    pinMode(MArD1, OUTPUT);
    pinMode(MArD1, OUTPUT);
    pinMode(MArG1, OUTPUT);
    pinMode(MArG1, OUTPUT);

    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(SENSOR_PIN, INPUT);
    pinMode(INDICATOR_PIN, OUTPUT);

    digitalWrite(TRIGGER_PIN, LOW);
}

void loop() {

}
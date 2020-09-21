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

#include "MTTEH_Project.hpp"

const unsigned long timeout_measure = 25000UL;
const float sound_speed = 340.0 / 1000;

void trigger()
{
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
}

void setup()
{
    Serial.begin(115200);

    pinMode(RIGHT_FRONT_MOTOR_CR, OUTPUT);
    pinMode(RIGHT_FRONT_MOTOR_ACR, OUTPUT);
    pinMode(LEFT_FRONT_MOTOR_CR, OUTPUT);
    pinMode(LEFT_FRONT_MOTOR_CR, OUTPUT);
    pinMode(RIGHT_BACK_MOTOR_CR, OUTPUT);
    pinMode(RIGHT_BACK_MOTOR_CR, OUTPUT);
    pinMode(LEFT_BACK_MOTOR_CR, OUTPUT);
    pinMode(LEFT_BACK_MOTOR_CR, OUTPUT);

    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(SENSOR_PIN, INPUT);
    pinMode(INDICATOR_PIN, OUTPUT);

    digitalWrite(TRIGGER_PIN, LOW);

    randomSeed(analogRead(0));
}

void loop()
{
    
}
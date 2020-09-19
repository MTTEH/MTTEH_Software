#include "MTTEH_Project.h"

void setup()
{
    Serial.begin(115200);

    pinMode(SENSOR_PIN, INPUT);
    pinMode(INDICATOR_PIN, OUTPUT);
}

void loop()
{
    static long randNumber = 0;
    delay(2000);
    byte state = digitalRead(SENSOR_PIN);
    digitalWrite(INDICATOR_PIN,state);
    delay(1000);
        if (state == 1){
            randNumber = random(2);
            while ((randNumber == 0) && (state == 1)){
            turn_right();
            randNumber = random(5, 20);
            delay(randNumber);
            stop_moving();
            byte state = digitalRead(SENSOR_PIN);
            digitalWrite(INDICATOR_PIN,state);
            delay(1000);
        }
        while ((randNumber == 1) && (state == 1)){
            turn_left();
            randNumber = random(5, 20);
            delay(randNumber);
            stop_moving();
            byte state = digitalRead(SENSOR_PIN);
            digitalWrite(INDICATOR_PIN,state);
            delay(1000);
        }
    } else
        move_ahead();
}

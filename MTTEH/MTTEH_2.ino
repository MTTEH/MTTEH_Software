#include "MTTEH_Project.h"

const unsigned long timeout_measure = 25000UL;
const float sound_speed = 340.0/1000;

void loop() {
    static long randNumber = 0;

    move_ahead();
    trigger();
    long measure = pulseIn(ECHO_PIN, HIGH, timeout_measure);
    float distance_cm = measure / 2.0 * sound_speed / 10.0;
    delay(200);
    if (distance_cm <= 50){
        randNumber = random(2);
        while ((randNumber == 0) && (distance_cm <= 50)){
            turn_right();
            randNumber = random(5, 20);
            delay(randNumber);
            stop_moving();
            trigger();
            long measure = pulseIn(ECHO_PIN, HIGH, timeout_measure);
            float distance_cm = measure / 2.0 * sound_speed / 10.0;
            delay(200);  
        }
        while ((randNumber == 1) && (distance_cm <= 50)){
            turn_left();
            randNumber = random(5, 20);
            delay(randNumber);
            stop_moving();
            trigger();
            long measure = pulseIn(ECHO_PIN, HIGH, timeout_measure);
            float distance_cm = measure / 2.0 * sound_speed / 10.0;
            delay(200);
        }
    } else
        move_ahead();
}

#include "MTTEH_Project.hpp"

void loop()
{
    MTTEH mtteh = MTTEH();
    mtteh.movement = Move();
    static long randNumber = 0;
    byte state = 0;

    delay(2000);
    state = digitalRead(SENSOR_PIN);
    digitalWrite(INDICATOR_PIN, state);
    delay(1000);
    if (state == 1) {
        randNumber = random(2);
        while ((randNumber == 0) && (state == 1)) {
            mtteh.movement.right();
            randNumber = random(5, 20);
            delay(randNumber);
            mtteh.movement.stop();
            state = digitalRead(SENSOR_PIN);
            digitalWrite(INDICATOR_PIN, state);
            delay(1000);
        }
        while ((randNumber == 1) && (state == 1)) {
            mtteh.movement.left();
            randNumber = random(5, 20);
            delay(randNumber);
            mtteh.movement.stop();
            state = digitalRead(SENSOR_PIN);
            digitalWrite(INDICATOR_PIN, state);
            delay(1000);
        }
    } else
        mtteh.movement.forward();
}

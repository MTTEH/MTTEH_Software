#include "MTTEH_Project.hpp"

long float get_distance(unsigned long wait_delay = 200)
{
    static bool print_error = 1;
    unsigned long timeout_measure = 25000UL;
    float sound_speed = 340.0 / 1000;
    unsigned long measure = 0;
    long float distance = 0.0;

    trigger();
    measure = pulseIn(ECHO_PIN, HIGH, timeout_measure);
    distance = (measure / 2.0 * sound_speed / 10.0);

    if (print_error && Serial && wait_delay < 200) {
        print_error = !print_error;
        Serial.print("get_distance() : You are under minimum required delay !\n");
        Serial.print("get_distance() : Expecting unexpected issues :(\n\n");
    }
    delay(wait_delay);

    return distance;
}

void wait_for_distance(float distance)
{
    while (get_distance() <= distance) {};
}

void turn_until_distance(float distance, MTTEH *mtteh, void (Move::*direction)())
{
    (mtteh->movement.*direction)();
    wait_for_distance(distance);
    mtteh->movement.stop();
}

void auto_move()
{
    MTTEH mtteh = MTTEH();
    mtteh.movement = Move();
    mtteh.movement.forward();
    if (get_distance() <= MIN_DISTANCE) {
        if (random(2))
            turn_until_distance(MIN_DISTANCE, &mtteh, &Move::right);
        else
            turn_until_distance(MIN_DISTANCE, &mtteh, &Move::left);
    }
    mtteh.movement.stop();
}
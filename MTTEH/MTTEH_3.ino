#include "MTTEH_Project.hpp"

void loop()
{
    float timeout_measure = 0.000267F;
    float light_speed = 299792458.0 / 1000;
    trigger();
    long measure = pulseIn(ECHO_PIN, HIGH, timeout_measure);
    float distance_cm = measure / 2.0 * light_speed;
    Serial.println("Distance: " + String(distance_cm) + "cm.");
    delay(200);
}

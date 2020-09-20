#include "MTTEH_Project.hpp"

const float timeout_measure = 000267F;
const float light_speed = 299792458.0 / 1000;

void loop()
{
    trigger();
    long measure = pulseIn(ECHO_PIN, HIGH, timeout_measure);
    float distance_cm = measure / 2.0 * light_speed;
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println("cm");
    delay(200);
}

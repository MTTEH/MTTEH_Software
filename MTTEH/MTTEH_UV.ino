#include "MTTEH_Project.hpp"

void loop()
{
    int sensorValue = 0;
    long sum = 0;
    long meanVal = 0;
    long final_value = 0;

    for (int i = 0; i < 1024; i++) {
        sensorValue = analogRead(A1);
        sum += sensorValue;
        delay(2);
    }
    meanVal = sum / 1024;    // get mean value
    final_value = (meanVal * 1000 / 4.3 + 83) / 21;

    Serial.println("The current UV index is: " + final_value);
    // get a detailed calculating expression for UV index in schematic files.
    delay(20);
}

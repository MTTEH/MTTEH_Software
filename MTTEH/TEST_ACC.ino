#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>

mma = Adafruit_MMA8451();
mma.begin()
  if (! mma.begin()) {
    Serial.println("Couldnt start")
    while (1);
  }
  Serial.println("MMA8451 found!");
  mma.setRange(MMA8451_RANGE_2_G);
  mma.setRange(MMA8451_RANGE_4_G);
  mma.setRange(MMA8451_RANGE_8_G);
  mma.getRange()
  mma.read();
  sensors_event_t event; 
  mma.getEvent(&event);
  mma.getOrientation();

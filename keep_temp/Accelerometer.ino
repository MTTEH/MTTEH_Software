/**************************************************************************/
/*!
    @file     Adafruit_MMA8451.h
    @author   K. Townsend (Adafruit Industries)
    @license  BSD (see license.txt)

    This is an example for the Adafruit MMA8451 Accel breakout board
    ----> https://www.adafruit.com/products/2019

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v1.0  - First release
*/
/**************************************************************************/

#include <Adafruit_MMA8451.h>
#include <Arduino.h>
#include <MTTEH.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  wait_for(Serial);
  init_MMA8451();
}

void loop() {
    read_MMA8451();
    print_all_MMA8451();
    get_event_MMA8451();
    print_all_event_MMA8451();
    uint8_t orientation = get_orientation_MMA8451();
  
    switch (orientation) {
        case MMA8451_PL_PUF: 
            Serial.println("Portrait Up Front");
            break;
        case MMA8451_PL_PUB: 
            Serial.println("Portrait Up Back");
            break;    
        case MMA8451_PL_PDF: 
            Serial.println("Portrait Down Front");
            break;
        case MMA8451_PL_PDB: 
            Serial.println("Portrait Down Back");
            break;
        case MMA8451_PL_LRF: 
            Serial.println("Landscape Right Front");
            break;
        case MMA8451_PL_LRB: 
            Serial.println("Landscape Right Back");
            break;
        case MMA8451_PL_LLF: 
            Serial.println("Landscape Left Front");
            break;
        case MMA8451_PL_LLB: 
            Serial.println("Landscape Left Back");
            break;
        }
    Serial.println("");

    delay(500);
}

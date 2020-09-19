/*
** [MTTEH] W.I.P. PRODUCTION CODE SK_Exemple
**/

#include <Arduino.h>
#include <MTTEH.h>
#include <Wire.h>

void setup() {
    Serial.begin(115200);
    wait_for(Serial);

    init_SGP30();
    init_MCP9808();
}

void loop() {
    static int counter = 0;
    static float temp_c = 0.0;
    static float temp_f = 0.0;
    static uint16_t TVOC_base = 0;
    static uint16_t eCO2_base = 0;

    /*TEMP*/ {
        wake_MCP9808();
        get_resolution_MCP9808();
        temp_c = get_temperature_C_MCP9808();
        temp_f = get_temperature_F_MCP9808();
        Serial.println("Temp: "); 
        Serial.print(temp_c, 4);
        Serial.println("°C."); 
        Serial.print(temp_f, 4);
        Serial.println("°F.");
        
        delay(2000);
        stop_MCP9808();
        Serial.println("");
        delay(200);
    }

    /*GAZ */ {
        if (check_SGP30())
            return;

        Serial.print("TVOC : ");
        Serial.print(get_TVOC_SGP30());
        Serial.println(" ppb.");

        Serial.print("eCO2 : ");
        Serial.print(get_eCO2_SGP30());
        Serial.println(" ppm.");

        delay(1000);

        counter++;
        if (counter == 30) {
            counter = 0;
            if (!getIAQBaseline_SGP30(&eCO2_base, &TVOC_base)) {
                Serial.println("Failed to get baseline readings");
                return;
            }
            Serial.print("****Baseline values: eCO2: 0x");
            Serial.print(eCO2_base, HEX);
            Serial.print(" & TVOC: 0x");
            Serial.println(TVOC_base, HEX);
        }
    }
}

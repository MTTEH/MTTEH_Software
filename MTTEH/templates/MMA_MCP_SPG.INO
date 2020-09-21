/*
** [MTTEH] W.I.P. PRODUCTION CODE
**/

#include "MTTEH_Project.hpp"

void setup()
{
    Serial.begin(115200);
    wait_for(Serial);

    MMA8451().init();
    init_SGP30();
    init_MCP9808();
}

void loop()
{
    MTTEH mtteh = MTTEH();
    mtteh.mma8451 = MMA8451();
    static int counter = 0;
    static float temp_c = 0.0;
    static float temp_f = 0.0;
    static uint16_t TVOC_base = 0;
    static uint16_t eCO2_base = 0;
    static uint8_t orientation = 0;

    /* MMA (Gyroscope/Accelerometer) */ {
        mtteh.mma8451.sensor.read();
        mtteh.mma8451.show_X();
        mtteh.mma8451.show_Y();
        mtteh.mma8451.show_Z();
        Serial.println("");
        mtteh.mma8451.event.get_event();
        mtteh.mma8451.event.show_X();
        mtteh.mma8451.event.show_Y();
        mtteh.mma8451.event.show_Z();
        orientation = mtteh.mma8451.get_orientation();

        switch (orientation) {
            case MMA8451_PL_PUF:
                Serial.println("Portrait Up Front");
            case MMA8451_PL_PUB:
                Serial.println("Portrait Up Back");
            case MMA8451_PL_PDF:
                Serial.println("Portrait Down Front");
            case MMA8451_PL_PDB:
                Serial.println("Portrait Down Back");
            case MMA8451_PL_LRF:
                Serial.println("Landscape Right Front");
            case MMA8451_PL_LRB:
                Serial.println("Landscape Right Back");
            case MMA8451_PL_LLF:
                Serial.println("Landscape Left Front");
            case MMA8451_PL_LLB:
                Serial.println("Landscape Left Back");
        }
    }

    Serial.println("");
    delay(100);

    /* MCP (TEMP) */ {
        wake_MCP9808();
        get_resolution_MCP9808();
        temp_c = get_temperature_C_MCP9808();
        temp_f = get_temperature_F_MCP9808();
        Serial.println("Temp: " + String(temp_c, 4) + "°C.");
        Serial.println("Temp: " + String(temp_f, 4) + "°F.");
        delay(2000);
        stop_MCP9808();
    }

    Serial.println("");
    delay(100);

    /* SGP (GAS) */ {
        if (check_SGP30())
            return;

        Serial.println("TVOC : " + String(get_TVOC_SGP30()) + " ppb.");
        Serial.println("eCO2 : " + String(get_eCO2_SGP30()) + " ppm.");

        delay(1000);

        counter++;
        if (counter == 30) {
            counter = 0;
            if (!getIAQBaseline_SGP30(&eCO2_base, &TVOC_base)) {
                Serial.println("Failed to get baseline readings");
                return;
            }
            Serial.println("****Baseline values: eCO2: 0x" + String(eCO2_base, HEX) + " & TVOC: 0x" + String(TVOC_base, HEX));
        }
    }

    Serial.println("End of the round !\n");
    delay(100);
}

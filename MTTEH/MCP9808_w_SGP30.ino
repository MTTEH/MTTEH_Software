/*
 * [MTTEH] W.I.P. PRODUCTION CODE SK_Exemple
 * 
 * 
 * 
 */
#include <Wire.h>
#include "Adafruit_SGP30.h"
#include "Adafruit_MCP9808.h"

Adafruit_SGP30 sgp;
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();


int counter = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("MCP9808 demo");
  Serial.println("SGP30 test");

  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    while (1);
  }
  if (! sgp.begin()){
    Serial.println("Gaz sensor not found :(");
    while (1);
  }

  Serial.println("Found MCP9808!");
  Serial.print("Found SGP30 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);
  
  //sgp.setIAQBaseline(0x8E68, 0x8F41);
  
  tempsensor.setResolution(3);
}

void loop() {
  /*TEMP*/ Serial.println("Waking up MCP9808.... ");
  /*TEMP*/ tempsensor.wake();

  /*TEMP*/ Serial.print("Resolution in mode: ");
  /*TEMP*/ Serial.println (tempsensor.getResolution());
  /*TEMP*/ float c = tempsensor.readTempC();
  /*TEMP*/ float f = tempsensor.readTempF();
  /*TEMP*/ Serial.print("Temp: "); 
  /*TEMP*/ Serial.print(c, 4); Serial.print("*C\t and "); 
  /*TEMP*/ Serial.print(f, 4); Serial.println("*F.");
  
  /*TEMP*/ delay(2000);
  /*TEMP*/ Serial.println("Shutdown MCP9808.... ");
  /*TEMP*/ tempsensor.shutdown_wake(1); // shutdown MSP9808 - power consumption ~0.1 mikro Ampere, stops temperature sampling
  /*TEMP*/ Serial.println("");
  /*TEMP*/ delay(200);

  /*GAZ */ if (! sgp.IAQmeasure()) {
  /*GAZ */   Serial.println("Measurement failed");
  /*GAZ */   return;
  /*GAZ */ }
  /*GAZ */ Serial.print("TVOC "); Serial.print(sgp.TVOC); Serial.print(" ppb\t");
  /*GAZ */ Serial.print("eCO2 "); Serial.print(sgp.eCO2); Serial.println(" ppm");
  /*GAZ */ delay(1000);

  /*GAZ */ counter++;
  /*GAZ */ if (counter == 30) {
  /*GAZ */   counter = 0;
  /*GAZ */   uint16_t TVOC_base, eCO2_base;
  /*GAZ */   if (! sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
  /*GAZ */     Serial.println("Failed to get baseline readings");
  /*GAZ */     return;
  /*GAZ */   }
  /*GAZ */   Serial.print("****Baseline values: eCO2: 0x"); Serial.print(eCO2_base, HEX);
  /*GAZ */   Serial.print(" & TVOC: 0x"); Serial.println(TVOC_base, HEX);
  /*GAZ */ }
}

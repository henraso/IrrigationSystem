#pragma once
#include <Arduino.h>

/*
--------------------------------------
-      IrrigationSystem class        -
--------------------------------------
*/

class IrrigationSystem {
  public:
    IrrigationSystem(int moisturePin, int pumpPin, int moistureThreshold);
    void readMoisture();
    void waterPlant(int seconds);
    void setMoistureThreshold(int moistureThreshold);
    int getMoistureThreshold();
    int getMoisture();
  private:
    int _moisturePin;
    int _pumpPin;
    int _moistureThreshold;
    int _moisture;
};


/*
-------------------------------------
-          Other functions          -
-------------------------------------
*/

void checkPlant(IrrigationSystem plant, int seconds);

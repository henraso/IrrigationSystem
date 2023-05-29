#pragma once
#include <Arduino.h>

/*
--------------------------------------
-      IrrigationSystem class        -
--------------------------------------
*/

class IrrigationSystem {
  public:
    IrrigationSystem(int moisturePin, int pumpPin, int moistureThreshold, int wateringTime);
    void readMoisture();
    void waterPlant();
    void setMoistureThreshold(int moistureThreshold);
    int getMoistureThreshold();
    int getMoisture();
  private:
    int _moisturePin;
    int _pumpPin;
    int _moistureThreshold;
    int _moisture;
    int _wateringTime;
};


/*
-------------------------------------
-          Other functions          -
-------------------------------------
*/

void checkPlant(IrrigationSystem plant);

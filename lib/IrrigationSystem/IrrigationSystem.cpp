#include "IrrigationSystem.h"

/*
--------------------------------------
-  IrrigationSystem class functions  -
--------------------------------------
*/

//Constructor for the IrrigationSystem class
IrrigationSystem::IrrigationSystem(int moisturePin, int pumpPin, int moistureThreshold) {
  _moisturePin = moisturePin;
  _pumpPin = pumpPin;
  _moistureThreshold = moistureThreshold;
}

//function to read the moisture level
void IrrigationSystem::readMoisture() {
  _moisture = map(analogRead(_moisturePin), 0, 4095, 0, 100);
}

//function to water the plant
void IrrigationSystem::waterPlant() {
  digitalWrite(_pumpPin, HIGH);
  delay(5000);
  digitalWrite(_pumpPin, LOW);
}

//function to set the moisture threshold
void IrrigationSystem::setMoistureThreshold(int moistureThreshold) {
  _moistureThreshold = moistureThreshold;
}

//function to get the moisture threshold
int IrrigationSystem::getMoistureThreshold() {
  return _moistureThreshold;
}

//function to get the moisture level
int IrrigationSystem::getMoisture() {
  return _moisture;
}

/*
-------------------------------------
-          Other functions          -
-------------------------------------
*/

//function to check if the plant needs water
void checkPlant(IrrigationSystem plant) {
  plant.readMoisture();
  if (plant.getMoisture() < plant.getMoistureThreshold()) {
    plant.waterPlant();
  }
}

#include "IrrigationSystem.h"

// Plant setup
#pragma region Plant1 setup
//create input pins for plant1
const int moisturePin = 34;
const int pumpPin = 35;

//set the moisture threshold and watering time for plant1
int moistureThreshold = 50; // 50%
int wateringTime = 5; // 5 seconds

//create an instance of the IrrigationSystem class for each plant
IrrigationSystem plant1(moisturePin, pumpPin, moistureThreshold, wateringTime);

#pragma endregion

// Sleep setup
#pragma region Sleep Setup

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  300      /* Time ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;

#pragma endregion

/* Setup function runs once when the microcontroller is powered on or reset */
void setup() {
  Serial.begin(115200);

  // Initialize the pins
  pinMode(moisturePin, INPUT);
  pinMode(pumpPin, OUTPUT);

  // Increment boot number and print it every reboot
  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));

  // Check if the plant needs water, if true, water it for "wateringTime" seconds
  checkPlant(plant1);

  // Configure the timer to wake us up!
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");

  // Go to sleep now
  Serial.println("Going to sleep now");
  delay(1000);
  Serial.flush(); // Flush the serial buffer before going to sleep
  esp_deep_sleep_start();
  Serial.println("This will never be printed");
}

void loop() {
  // This will never run, device goes to sleep by the end of setup()
}

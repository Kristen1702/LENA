#include <Wire.h>
#include <Adafruit_LIS2MDL.h>

Adafruit_LIS2MDL mag = Adafruit_LIS2MDL();

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for serial monitor
// Initialize the magnetometer
  if (!mag.begin()) {
    Serial.println("LIS2MDL not found. Check wiring.");
    while (1);
  }

  Serial.println("LIS2MDL Initialized. Ready to log magnetic field.");
}

void loop() {
  sensors_event_t event;
  mag.getEvent(&event);

  // Print magnetic field in microteslas (µT)
  Serial.print("X: "); Serial.print(event.magnetic.x); Serial.print(" µT, ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print(" µT, ");
  Serial.print("Z: "); Serial.print(event.magnetic.z); Serial.println(" µT");

  delay(2); // Log every 2ms (adjust as needed)
}

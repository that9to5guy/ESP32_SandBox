#include <Arduino.h>
#include <Wire.h>

void setup() {
  Wire.begin(); // default: SDA = 21, SCL = 22 on ESP32
  Serial.begin(115200);
  while (!Serial); // wait for serial monitor

  Serial.println("I2C Scanner");

  byte error, address;
  int nDevices = 0;

  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("Done\n");
}

void loop() {
  // nothing to do here
}

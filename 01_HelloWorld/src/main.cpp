#include <Arduino.h>

#define LED_BUILTIN 2

void setup() {
  // Start serial communication at 115200 baud rate
  Serial.begin(115200);
  
  // Set the built-in LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Blink the LED every second
  digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on
  delay(500);                     // Wait for 500 milliseconds
  Serial.println("Hello ESP32 !!!"); // Print to serial monitor
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
  delay(500);                     // Wait for 500 milliseconds
}

#include <Arduino.h>

#define LED_BUILTIN 2

void setup() {
  // Start serial communication at 115200 baud rate
  Serial.begin(115200);

  // Set the built-in LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // Wait for the serial port to initialize
  while (!Serial);

  // Print some general information about the ESP32 chip
  Serial.println("");
  Serial.println("ESP32 Hardware Information:");

  // Chip Model
  Serial.print("Chip Model: ");
  Serial.println(ESP.getChipModel());  // Prints the chip model (e.g., ESP32, ESP32-S2, etc.)

  // Chip Revision
  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());  // Chip revision (e.g., 1, 2)

  // CPU Frequency (in MHz)
  Serial.print("CPU Frequency (MHz): ");
  Serial.println(ESP.getCpuFreqMHz());  // Frequency of the CPU in MHz

  // Chip Cores
  Serial.print("Number of CPU Cores: ");
  Serial.println(ESP.getChipCores());  // Number of CPU cores (usually 2 for ESP32)

  // Flash Size (in MB)
  uint32_t flash_size = ESP.getFlashChipSize();  // Get flash size in bytes
  Serial.print("Flash Size: ");
  Serial.print(flash_size / (1024 * 1024));  // Convert to MB
  Serial.println(" MB");

  // Flash Speed (in MHz)
  uint32_t flash_speed = ESP.getFlashChipSpeed();  // Get flash speed in Hz
  Serial.print("Flash Speed: ");
  Serial.print(flash_speed / 1000000);  // Convert to MHz
  Serial.println(" MHz");

  // Flash Mode
  FlashMode_t flash_mode = ESP.getFlashChipMode();
  Serial.print("Flash Mode: ");
  switch (flash_mode) {
    case FM_DIO: Serial.println("DIO"); break;
    case FM_QIO: Serial.println("QIO"); break;
    case FM_DOUT: Serial.println("DOUT"); break;
    case FM_QOUT: Serial.println("QOUT"); break;
    default: Serial.println("Unknown");
  }

  // Free Heap Size (in bytes)
  Serial.print("Free Heap Size: ");
  Serial.print(ESP.getFreeHeap());  // Free heap memory in bytes
  Serial.println(" bytes");

  // Min Free Heap Size (in bytes)
  Serial.print("Min Free Heap Size: ");
  Serial.print(ESP.getMinFreeHeap());  // Minimum free heap size
  Serial.println(" bytes");

  // Max Alloc Heap (largest allocable block in bytes)
  Serial.print("Max Alloc Heap Size: ");
  Serial.print(ESP.getMaxAllocHeap());
  Serial.println(" bytes");

  // SPI RAM Size (in bytes)
  uint32_t psram_size = ESP.getPsramSize();
  Serial.print("SPI RAM Size: ");
  Serial.print(psram_size / (1024 * 1024));  // Convert to MB
  Serial.println(" MB");

  // Free SPI RAM (in bytes)
  Serial.print("Free SPI RAM: ");
  Serial.print(ESP.getFreePsram());  // Free SPI RAM in bytes
  Serial.println(" bytes");

  // Min Free SPI RAM (in bytes)
  Serial.print("Min Free SPI RAM: ");
  Serial.print(ESP.getMinFreePsram());  // Minimum free SPI RAM
  Serial.println(" bytes");

  // Max Alloc SPI RAM (largest allocable block in bytes)
  Serial.print("Max Alloc SPI RAM Size: ");
  Serial.print(ESP.getMaxAllocPsram());
  Serial.println(" bytes");

  // SDK Version
  Serial.print("SDK Version: ");
  Serial.println(ESP.getSdkVersion());

  // Sketch Size (in KB)
  Serial.print("Sketch Size: ");
  Serial.print(ESP.getSketchSize() / 1024);  // Size of the sketch (in KB)
  Serial.println(" KB");

  // Sketch MD5
  Serial.print("Sketch MD5: ");
  Serial.println(ESP.getSketchMD5());

  // Free Sketch Space (remaining flash space for the sketch)
  Serial.print("Free Sketch Space: ");
  Serial.print(ESP.getFreeSketchSpace());
  Serial.println(" bytes");

  // Cycle Count (CPU cycles)
  Serial.print("Cycle Count: ");
  Serial.println(ESP.getCycleCount());  // CPU cycle count

  // EFUSE MAC Address
  uint64_t macAddress = ESP.getEfuseMac();  // Get MAC address from eFuse
  Serial.print("MAC Address: ");
  Serial.print((macAddress >> 40) & 0xFF, HEX);  // High byte of MAC address
  Serial.print(":");
  Serial.print((macAddress >> 32) & 0xFF, HEX);  // Second byte
  Serial.print(":");
  Serial.print((macAddress >> 24) & 0xFF, HEX);  // Third byte
  Serial.print(":");
  Serial.print((macAddress >> 16) & 0xFF, HEX);  // Fourth byte
  Serial.print(":");
  Serial.print((macAddress >> 8) & 0xFF, HEX);   // Fifth byte
  Serial.print(":");
  Serial.println(macAddress & 0xFF, HEX);        // Sixth byte
}

void loop() {
  // Blink the LED every second
  digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on
  delay(250);                     // Wait for 500 milliseconds
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
  delay(250);                     // Wait for 500 milliseconds
}

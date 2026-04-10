#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// I2C Addresses
#define LM75_ADDR 0x48   // LM75AD with A0, A1, A2 to GND
#define OLED_ADDR 0x3C   // Standard 0.96" OLED address

// OLED Settings
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Timing variables for the 1-minute interval
unsigned long lastUpdate = 0;
const unsigned long interval = 60000; // 60 seconds in milliseconds

void setup() {
  Serial.begin(115200);
  Wire.begin(); // Standard I2C pins for Xiao RP2040

  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("OLED failed to initialize"));
    for(;;); 
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  
  // Show an initial reading immediately on startup
  updateSensorAndDisplay();
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if 60 seconds have passed since the last update
  if (currentMillis - lastUpdate >= interval) {
    lastUpdate = currentMillis;
    updateSensorAndDisplay();
  }
}

void updateSensorAndDisplay() {
  float tempC = readLM75();
  
  // Convert Celsius to Fahrenheit: (C * 1.8) + 32
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  // Update OLED
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("CURRENT TEMP");

  // Large display for the Fahrenheit reading
  display.setTextSize(3); 
  display.setCursor(0, 25);
  display.print(tempF, 1); // Display with one decimal point
  
  display.setTextSize(2);
  display.print(" F");
  
  display.display();
}

float readLM75() {
  // Point to Temperature Register
  Wire.beginTransmission(LM75_ADDR);
  Wire.write(0x00); 
  Wire.endTransmission(false); // Keep connection open for request

  // Request 2 bytes of temperature data
  Wire.requestFrom(LM75_ADDR, 2);

  if (Wire.available() == 2) {
    int8_t msb = Wire.read(); // Most Significant Byte
    int8_t lsb = Wire.read(); // Least Significant Byte
    
    // Combine bytes and shift right by 5 (LM75 is 11-bit data)
    int16_t raw = (msb << 8) | lsb;
    return (raw >> 5) * 0.125; // Multiply by resolution (0.125C per bit)
  }
  return 0.0;
}
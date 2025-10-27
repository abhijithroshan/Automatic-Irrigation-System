#include <Arduino.h>

int sensorPin = A0;     // Soil moisture sensor connected to analog pin A0
int motorPin = 8;       // Relay or motor control connected to digital pin 8
int sensorValue = 0;    // To store sensor reading
int threshold = 500;    // Threshold for dry/wet soil

void setup() {
  Serial.begin(9600);   // For debugging and monitoring
  pinMode(sensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW); // Motor OFF initially
}

void loop() {
  sensorValue = analogRead(sensorPin);   // Read moisture level
  Serial.print("Soil Moisture Value: ");
  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    digitalWrite(motorPin, HIGH);        // Turn ON water pump
    Serial.println("Soil is Dry → Pump ON");
  } 
  else {
    digitalWrite(motorPin, LOW);         // Turn OFF water pump
    Serial.println("Soil is Wet → Pump OFF");
  }

  delay(2000); // Wait 2 seconds before next reading
}

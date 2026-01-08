#include <DHT.h>

#define DHTPIN 2        // Pin connected to DHT sensor
#define DHTTYPE DHT22   // DHT 22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

const int voltagePin = A0; // Pin connected to voltage divider
const float R1 = 10010.0;       // Your measured Top Resistor
const float R2 = 9900.0;        // Your measured Bottom Resistor
const float arduinoVcc = 5.051; // Your measured Arduino 5V pin

// Changed to 1000ms (1 second) for smoother Live Dashboard updates
const long interval = 1000;    
unsigned long previousTime = 0;

const int voltageSamples = 1000; // Take 1000 readings to smooth out noise

void setup() {
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    long totalRaw = 0;
    for(int i = 0; i < voltageSamples; i++) {
      totalRaw += analogRead(voltagePin);
    }
    float avgRaw = totalRaw / (float)voltageSamples;
    
    float pinVoltage = avgRaw * (arduinoVcc / 1023.0);
    float batteryVoltage = pinVoltage * ((R1 + R2) / R2);
    
    float humidity = dht.readHumidity();
    float temp = dht.readTemperature(); // Celsius
    
    if (isnan(humidity) || isnan(temp)) {
      humidity = 0;
      temp = 0;
    }

    Serial.print(batteryVoltage, 2); 
    Serial.print(",");
    Serial.print(humidity, 1);       
    Serial.print(",");
    Serial.println(temp, 1);         
  }
}

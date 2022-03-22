#include "Adafruit_DHT.h"

#define DHTPIN 2 // Data pin number 2

#define DHTTYPE DHT11 // Sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(30000);

  // Get temperature in celsius
  float t = dht.getTempCelcius();

  String temp = String(t);

  // If statemnt for nan
  if (t != t)
  {
    // action A
    Serial.println("nan");
  }
  else
  {
    // action B
    Particle.publish("temp", temp, PRIVATE);
  }
}
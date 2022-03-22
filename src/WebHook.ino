#include "Adafruit_DHT.h"

int led = D7; // The on-board LED

#define DHTPIN 2 // what pin we're connected to

#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop()
{
  delay(10000);

  float t = dht.getTempCelcius();

  Serial.print("Temp: ");
  Serial.println(t);

  String temp = String(t);

  // if ( != 0 )
  // {
  //   // action A
  // }
  // else
  // {
  //   // action B
  // }
  Particle.publish("temp", temp, PRIVATE);
}
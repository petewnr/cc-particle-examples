/*
 * Project cc-particle-examples
 * Description: sample to use and publish sensor value
 * Author: PeteW
 * Date: 15 January 2018
 */

/// ***** variables for the light dependent resistor
int ldrPin = A0;
int ldrReading = 0;

// ***** variables for managing time
const long readingInterval = 30000;
unsigned long previousMillis = 0;

void setup()
{
  pinMode(ldrPin, INPUT);
  Particle.variable("light", ldrReading);

  Serial.begin(9600);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > readingInterval)
  {
    previousMillis = currentMillis;

    ldrReading = analogRead(ldrPin);
    Particle.publish("light reading", String(ldrReading));

    Serial.print("green_wombat light reading: ");
    Serial.println(ldrReading);
  }
}

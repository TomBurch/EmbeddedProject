#include "Arduino.h"
#include "PedLight.h"

void PedLight::setup(int pinRed, int pinGre) {
  this->pinRed = pinRed;
  this->pinGre = pinGre;
}

void PedLight::setLights(int stage) {
  if (stage == 0) {
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinGre, LOW);
  } else {
    digitalWrite(pinRed, LOW);
    digitalWrite(pinGre, HIGH);
  }
  outState();
}

void PedLight::setTraffic(bool mode) {
  if (mode == true) {
    setLights(1);
  } else {
    flashGreen();
    setLights(0);
  }
}

void PedLight::flashGreen() {
  for (int i =  0; i < 5; i++) {
    digitalWrite(pinGre, HIGH);
    delay(200);
    digitalWrite(pinGre, LOW);
    delay(200);
  }
}

void PedLight::outState() {
	String redState = (digitalRead(pinRed) == 0) ? "OFF" : "ON";
	String greState = (digitalRead(pinGre) == 0) ? "OFF" : "ON";
	Serial.println("PLight1 - Red : " + redState + ", Gre : " + greState);
}
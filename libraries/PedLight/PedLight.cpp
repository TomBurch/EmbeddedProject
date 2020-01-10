#include "Arduino.h"
#include "PedLight.h"

void PedLight::setup(int pinRed, int pinGre, String name) {
  this->pinRed = pinRed;
  this->pinGre = pinGre;
  this->name = name;
}

void PedLight::setLights(int stage) {
  if (stage == 0) { //Red light
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinGre, LOW);
  } else { //Green light
    digitalWrite(pinRed, LOW);
    digitalWrite(pinGre, HIGH);
  }
  outState();
}

void PedLight::setTraffic(bool mode) {
  if (mode == true) {
    setLights(1); //Green light
  } else {
    flashGreen();
    setLights(0); //Red light
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
	Serial.println(name + " - Red : " + redState + ", Gre : " + greState);
}


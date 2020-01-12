#include "Arduino.h"
#include "TrafficLight.h"

void TrafficLight::setup(int pinRed, int pinYel, int pinGre, String name) {
  this->pinRed = pinRed;
  this->pinYel = pinYel;
  this->pinGre = pinGre;
  this->name = name;
};

/*Set lights based on 4-stage traffic light*/
void TrafficLight::setLights(int stage) {
  clearLights();
  switch (stage) {
    case 1 :  digitalWrite(pinRed, HIGH);
			  break;
				
    case 2 :  digitalWrite(pinRed, HIGH);
			  digitalWrite(pinYel, HIGH);
			  break;
				
    case 3 :  digitalWrite(pinGre, HIGH);
			  break;
				
    case 4 :  digitalWrite(pinYel, HIGH);
			  break;
  }
  outState();
}

/*Change lights to stop/allow traffic based on mode
false = green->red, true = red->green*/
void TrafficLight::setTraffic(bool mode) {
  if (mode == false) { //Gre -> Yel -> Red
    setLights(3);
    delay(1000);
    setLights(4);
    delay(1000);
    setLights(1);
  } else { //Red -> Red + Yel -> Gre
    setLights(1);
    delay(1000);
    setLights(2);
    delay(1000);
    setLights(3);
  }
}

/*Switch off all lights to prepare for next stage*/
void TrafficLight::clearLights() {
  digitalWrite(pinRed, LOW);
  digitalWrite(pinYel, LOW);
  digitalWrite(pinGre, LOW);
}

void TrafficLight::outState() {
	String redState = (digitalRead(pinRed) == 0) ? "OFF" : "ON";
	String yelState = (digitalRead(pinYel) == 0) ? "OFF" : "ON";
	String greState = (digitalRead(pinGre) == 0) ? "OFF" : "ON";
	Serial.println(name + " - Red : " + redState + ", Yel : " + yelState + ", Gre : " + greState);
}


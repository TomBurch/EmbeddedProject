#include "Arduino.h"
#include "Crossing.h"
#include "TrafficLight.h"
#include "PedLight.h"

void Crossing::setup(PedLight pedLight, TrafficLight light1, TrafficLight light2) {
  this->light1 = light1;
  this->light2 = light2;
  this->pedLight = pedLight;

  pedLight.setLights(0);
  light1.setLights(3);
  light2.setLights(3);
}

void Crossing::setTraffic(bool mode) {
  if (mode == true) {
    //pedLight.flashGreen();
    pedLight.setTraffic(false);
    delay(500);
    light1.setLights(2);
    light2.setLights(2);
    delay(1000);
    light1.setLights(3);
    light2.setLights(3);
  } else {
    light1.setLights(4);
    light2.setLights(4);
    delay(1000);
    light1.setLights(1);
    light2.setLights(1);
    delay(500);
    pedLight.setTraffic(true);
  }
}
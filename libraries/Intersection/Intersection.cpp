#include "Arduino.h"
#include "Intersection.h"
#include "TrafficLight.h"

void Intersection::setup(TrafficLight light1, TrafficLight light2) { 
  this->light1 = light1;
  this->light2 = light2;

  light1.setLights(3); //Green
  light2.setLights(1); //Red
};

void Intersection::change(bool mode) {
  if (mode == false) {
    light1.setTraffic(false);
    light2.setTraffic(true);
  } else {
    light2.setTraffic(false);
    light1.setTraffic(true);
  }
}

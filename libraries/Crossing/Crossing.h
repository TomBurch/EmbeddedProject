#ifndef Crossing_h
#define Crossing_h

#include "Arduino.h"
#include "TrafficLight.h"
#include "PedLight.h"

class Crossing {
  private:
    PedLight pedLight;
    TrafficLight light1;
    TrafficLight light2;

  public:
    void setup(PedLight pedLight, TrafficLight light1, TrafficLight light2);
    void setTraffic(bool mode);   
};

#endif


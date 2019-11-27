#ifndef Intersection_h
#define Intersection_h

#include "Arduino.h"
#include "TrafficLight.h"

class Intersection {
  private:
    TrafficLight light1;
    TrafficLight light2;
  
  public:
    void setup(TrafficLight light1, TrafficLight light2);
    void change(bool mode);
};

#endif
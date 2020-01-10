#ifndef TrafficLight_h
#define TrafficLight_h

#include "Arduino.h"

class TrafficLight {
  private:
    int pinRed; 
    int pinYel; 
    int pinGre;
	String name;

  public:  
    void setup(int pinRed, int pinYel, int pinGre, String name);
	void setLights(int stage);
    void setTraffic(bool mode);
    void clearLights();
	void outState();
};

#endif


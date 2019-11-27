//#include <TrafficLight.h>
#include <Intersection.h>

TrafficLight light1;
TrafficLight light2;
Intersection intersect;

void setup() {
  Serial.begin(9600);
  
  pinMode(13, OUTPUT); //Red
  pinMode(12, OUTPUT); //Yellow
  pinMode(11, OUTPUT); //Green
  
  pinMode(10, OUTPUT); //Red
  pinMode(9, OUTPUT); //Yellow
  pinMode(8, OUTPUT); //Green
  
  light1.setup(13, 12, 11, "TLight1");
  light2.setup(10, 9, 8, "TLight2");
  intersect.setup(light1, light2);
}

void loop() {
  intersect.change(false);
  delay(1000);
  intersect.change(true);
  delay(1000);
}

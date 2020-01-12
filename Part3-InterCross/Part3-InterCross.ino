//#include <TrafficLight.h> //Included through Intersection.h
#include <PedLight.h>
#include <Intersection.h>

TrafficLight light1;
TrafficLight light2;
Intersection intersect;
PedLight pedLight;

char command;

void setup() {
  //Enable serial input
  Serial.begin(9600);
  
  //TLight1 pins
  pinMode(13, OUTPUT); //Red
  pinMode(12, OUTPUT); //Yellow
  pinMode(11, OUTPUT); //Green
  
  //TLight2 pins
  pinMode(10, OUTPUT); //Red
  pinMode(9, OUTPUT); //Yellow
  pinMode(8, OUTPUT); //Green

  //PedLight pins
  pinMode(6, OUTPUT); //Red
  pinMode(5, OUTPUT); //Green
  
  //Setup objects
  light1.setup(13, 12, 11, "TLight1");
  light2.setup(10, 9, 8, "TLight2");
  pedLight.setup(6, 5, "PedLight");
  intersect.setup(light1, light2);

  //Set PedLight to red
  pedLight.setLights(0);
}

void loop() {
  //Keep changing intersection until input
  while (!Serial.available()) {
    intersect.change(false);
    delay(1000);
    intersect.change(true);
    delay(1000);
  }
  command = Serial.read();
  if (command == 'c') {
    pedLight.setTraffic(true); //Red->Green
    delay(2000);
    pedLight.setTraffic(false); //Green->Red
    delay(2000);
  }
  command = '\0';
}

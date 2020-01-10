//#include <TrafficLight.h> //Included through Crossing.h
#include <Crossing.h>

PedLight pedLight;
TrafficLight light1;
TrafficLight light2;
Crossing cross;

char command;

void setup() {
  Serial.begin(9600); //Enable serial input
  
  //TLight1 pins
  pinMode(13, OUTPUT); //Red
  pinMode(12, OUTPUT); //Yellow
  pinMode(11, OUTPUT); //Green
  
  //TLight2 pins
  pinMode(10, OUTPUT); //Red
  pinMode(9, OUTPUT); //Yellow
  pinMode(8, OUTPUT); //Green

  //PedLight pins
  pinMode(7, OUTPUT); //Red
  pinMode(6, OUTPUT); //Green

  //Setup objects
  pedLight.setup(6, 5, "PLight");
  light1.setup(13, 12, 11, "TLight1");
  light2.setup(10, 9, 8, "TLight2");
  cross.setup(pedLight, light1, light2);
}

void loop() {
  while(!Serial.available()) {} //Wait for serial input
  command = Serial.read(); //Read input
  if (command == 'c') {
    cross.setTraffic(false); //PedLight on, TLights off
    delay(2000);
    cross.setTraffic(true); //PedLight off, TLights on
    delay(2000);
  }
  command = '\0'; //Empty character
}

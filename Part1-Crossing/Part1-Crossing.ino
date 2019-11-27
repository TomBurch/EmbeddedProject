//#include <TrafficLight.h>
#include <Crossing.h>

PedLight pedLight;
TrafficLight light1;
TrafficLight light2;
Crossing cross;

char command;

void setup() {
  Serial.begin(9600);
  
  pinMode(13, OUTPUT); //Red
  pinMode(12, OUTPUT); //Yellow
  pinMode(11, OUTPUT); //Green
  
  pinMode(10, OUTPUT); //Red
  pinMode(9, OUTPUT); //Yellow
  pinMode(8, OUTPUT); //Green

  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  pedLight.setup(6, 5);
  light1.setup(13, 12, 11, "TLight1");
  light2.setup(10, 9, 8, "TLight2");
  cross.setup(pedLight, light1, light2);
}

void loop() {
  while(!Serial.available()) {} 
  command = Serial.read();
  if (command == 'c') {
    cross.setTraffic(false);
    delay(2000);
    cross.setTraffic(true);
    delay(2000);
  }
  command = '\0';
}

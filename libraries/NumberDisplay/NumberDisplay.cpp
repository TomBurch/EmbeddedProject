#include "Arduino.h"
#include "NumberDisplay.h"

void NumberDisplay::setup(int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7) {
  this->displayBits[0] = b0;
  this->displayBits[1] = b1;
  this->displayBits[2] = b2;
  this->displayBits[3] = b3;
  this->displayBits[4] = b4;
  this->displayBits[5] = b5;
  this->displayBits[6] = b6;
  this->displayBits[7] = b7;
  
  this->length = 8;
}

//Convert int to binary and display on displayBits
void NumberDisplay::display(int num) {
  int val;
  clearDisplay();
  
  //Loop through each displayBit
  for (int i = 0; i < this->length; i++) {
	//Set light on/off depending on ith bit of num
    val = (bitRead(num, i) == 0) ? LOW : HIGH;
    digitalWrite(displayBits[i], val);
  }
}

//Loop through the displayBits and set each to LOW
void NumberDisplay::clearDisplay() {
  for (int i = 0; i < this->length; i++) {
    digitalWrite(displayBits[i], LOW); 
  }
}


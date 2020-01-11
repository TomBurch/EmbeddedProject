#include <NumberDisplay.h>
#include <Quicksort.h>

//Generate 50 random ints(0-255) and place them into randArray[]
void generateArray(int randArray[]) {
  for (int i = 0; i < 50; i++) {
    int randInt = random(0, 256);
    randArray[i] = randInt;
  }
}

//Loop through array[] and print each int
void outArray(int array[]) {
  for(int i = 0; i < 50; i++) {
    Serial.print(array[i]);
    Serial.print(", ");
  }
  Serial.print("\n");
}

int randArray[50];
char command;
NumberDisplay display;

void setup() {
  //Enable serial input
  Serial.begin(9600);
  
  //Create random seed
  randomSeed(analogRead(0));
  
  //Display pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  
  display.setup(5, 6, 8, 9, 10, 11, 12, 13);
}

void loop() {
  while(!Serial.available()) {}
  command = Serial.read();
  if (command == 'c') {
    generateArray(randArray);
  
    outArray(randArray);
    quicksort(randArray, 0, 49);
    outArray(randArray);
  
    display.display(randArray[0]);
    delay(3000);
    display.display(randArray[49]);
    delay(3000);
	
    Serial.println();
  }
  command = '\0';
}

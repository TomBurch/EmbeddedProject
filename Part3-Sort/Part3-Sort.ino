#include <NumberDisplay.h>
#include <Quicksort.h>

void generateArray(int randArray[]) {
  for (int i = 0; i < 50; i++) {
    int randInt = random(0, 256);
    randArray[i] = randInt;
  }
}

void outArray(int array[]) {
  for(int i = 0; i < 50; i++) {
    Serial.print(array[i]);
    Serial.print(", ");
  }
  Serial.print("\n");
}

int randArray[50];
NumberDisplay display;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //Red
  pinMode(12, OUTPUT); //Yellow
  pinMode(11, OUTPUT); //Green
  
  pinMode(10, OUTPUT); //Red
  pinMode(9, OUTPUT); //Yellow
  pinMode(8, OUTPUT); //Green
  
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  
  display.setup(5, 6, 8, 9, 10, 11, 12, 13);
}

void loop() {
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

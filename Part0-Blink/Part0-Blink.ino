char command;
int currentLight = 13;

/*Convert input to LED pin
  param command - input character
  return - pins int from input*/
int switchLight(char command) {
  switch(command) {
    case 'a' : return 13;
    case 'b' : return 12;
    case 'c' : return 11;
    default : return currentLight; //Invalid input, change nothing
  }
}

void setup() {
  Serial.begin(9600); //Setup serial input
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  //Keep blinking light until input
  while (!Serial.available()) {
    digitalWrite(currentLight, HIGH);
    delay(500);
    digitalWrite(currentLight, LOW);
    delay(500);    
  }
  command = Serial.read(); //Read input
  currentLight = switchLight(command); //Find new light from input
  command = '\0'; //Set to empty character
}

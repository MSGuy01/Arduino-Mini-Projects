/*
  This program lights up many different LED's in order.
  For this code to work, be sure to have all the digital
  inputs you use be consecutive with no breaks.
*/
void setup() {
  //change the for loop based on what digital inputs you are using
  //change the initial value to your lowest input, and the condition to your highest
  for (int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}
void loop() {
  //change the for loop based on what digital inputs you are using
  //change the initial value to your lowest input, and the condition to your highest
  for (int i = 0; i < 14; i++) {
    //change these values; set the if statement number to your lowest
    if (i == 0) {
      digitalWrite(13, LOW);
    }
    else{
      digitalWrite(i - 1, LOW);
    }
    digitalWrite(i, HIGH);
    delay(500);
  }
}

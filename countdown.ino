/*
This program counts down from 60 (or any number you choose) with one set of lights, then blinks fast
with another set once the countdown is over. Connect the countdown lights to digital 13, and the blinking
lights to digital 12.
*/
int ledPin = 13;
int ledPin2 = 12;
bool hasBlinked = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  for (int i = 0; i < 60; i++) {
    Serial.print(60 - i);
    Serial.println(" seconds");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  hasBlinked = true;
}

void loop() {
  if (hasBlinked) {
    digitalWrite(ledPin2, HIGH);
    delay(50);
    digitalWrite(ledPin2, LOW);
    delay(50);
  }
}


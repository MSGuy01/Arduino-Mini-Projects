/*
  This program senses which direction you are pointing the Arduino
  joystick with. Up = both lights on, down = both lights off, right = one light on, left = other light on,
  no direction = both lights alternating, press down on joystick = reset program. Directions are also printed in the serial monitor.
*/
/*
  Joystick inputs: connect GND to GND, +5V to 5V, VRx to A0, VRy to A1, and MS to Vin
  Light inputs: Connect one LED positive to digital 13, and the other to digital 12. Make both
  negative connected to a GND.
*/
int joyPin1 = 0;
int joyPin2 = 1;
int value1 = 0;
int value2 = 0;
int ledPin1 = 13;
int ledPin2 = 12;
bool isPressed = false;
String justPrinted = "";

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value1 = analogRead(joyPin1);
  value2 = analogRead(joyPin2);
  Serial.print("Ledpin analog read: ");
  Serial.println(analogRead(ledPin1));
  //right-up:
  if (value2 == 0) {
    isPressed = false;
    delay(50);
    if (value1 == 0) {
      Serial.println("rightup");
    }
    else {
      Serial.println("right");
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin1, LOW);
    }
  }
  //up-right
  if (value1 == 0) {
    isPressed = false;
    delay(50);
    if (value2 == 0) {
      Serial.println("rightup");
    }
    else {
      Serial.println("up");
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
    }
  }


  //right-down:
  if (value2 == 0) {
    isPressed = false;
    delay(50);
    if (value1 > 1000 && value2 < 1000) {
      Serial.println("rightdown");
    }
    else {
      Serial.println("right");
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin1, LOW);
    }
  }
  //down-right:
  if (value1 > 1000 && value2 < 1000) {
    isPressed = false;
    delay(50);
    if (value2 == 0) {
      Serial.println("rightdown");
    }
    else {
      Serial.println("down");
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }
  }


  //left-down:
  if (value2 > 1000 && value1 < 1000) {
    isPressed = false;
    delay(50);
    if (value1 > 1000 && value2 < 1000) {
      Serial.println("leftdown");
    }
    else {
      Serial.println("left");
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin1, HIGH);
    }
    for (int i = 0; i < 50; i++) {
      if (value1 > 1000 && value2 < 1000) {
        Serial.println("leftdown");
      }
      else {
        Serial.println("left");
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin1, HIGH);
      }
    }
  }
  //down-left:
  if (value1 > 1000 && value2 < 1000) {
    isPressed = false;
    delay(50);
    if (value2 > 1000 && value1 < 1000) {
      Serial.println("leftdown");
    }
    else {
      Serial.println("down");
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }
    for (int i = 0; i < 50; i++) {
      delay(1);
      if (value2 > 1000 && value1 < 1000) {
        Serial.println("leftdown");
      }
      else {
        Serial.println("down");
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
      }
    }
  }


  //left-up:
  if (value2 > 1000 && value1 < 1000) {
    isPressed = false;
    delay(50);
    if (value1 == 0) {
      Serial.println("leftup");
    }
    else {
      Serial.println("left");
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin1, HIGH);
    }
  }
  //up-left:
  if (value1 == 0) {
    isPressed = false;
    delay(50);
    if (value2 > 1000 && value1 < 1000) {
      Serial.println("leftup");
    }
    else {
      Serial.println("up");
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
    }
  }
  if (value1 > 0 && value1 < 1000 && value2 > 0 && value2 < 1000) {
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, HIGH);
    delay(250);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(250);
  }


}
void jjustPrinted(String dir) {
  justPrinted = dir;
}

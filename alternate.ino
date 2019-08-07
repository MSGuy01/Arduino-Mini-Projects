//simple program that alternates turning on different LED's
void setup() {
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT);
  pinMode(11, INPUT);
}

void loop() {
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH); 
  delay(500);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(500);
}

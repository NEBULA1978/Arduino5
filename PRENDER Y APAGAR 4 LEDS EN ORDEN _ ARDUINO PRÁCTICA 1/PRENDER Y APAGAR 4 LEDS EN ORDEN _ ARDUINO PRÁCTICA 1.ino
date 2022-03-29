void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(8, LOW);
  delay(500);

  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  delay(500);

  digitalWrite(6, HIGH);
  digitalWrite(4, LOW);
  delay(500);

  digitalWrite(8, HIGH);
  digitalWrite(6, LOW);
  delay(500);
}

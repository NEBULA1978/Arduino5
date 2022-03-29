

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String x2;
  x2 = "Ramon Pascual 98778€€€";
  bool x;
  bool x1;
  x = 3>6;
  x1 = 3<6;
  Serial.println(x);
  delay(1000);
  Serial.println(x1);
  delay(1000);
  Serial.println(x2);
  delay(1000);
}

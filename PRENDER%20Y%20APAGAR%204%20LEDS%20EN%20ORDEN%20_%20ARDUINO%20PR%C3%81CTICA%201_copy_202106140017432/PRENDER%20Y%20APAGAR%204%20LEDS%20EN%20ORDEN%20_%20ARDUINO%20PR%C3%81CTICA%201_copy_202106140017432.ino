int led = 2, ledAnterior = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //detectar si llega a 10

  //prender el led
  digitalWrite(led, HIGH);

  //apagar el led
  digitalWrite(ledAnterior, LOW);
 
 
// guardar el valorr del led ledAnterior
  ledAnterior = led;

  //sumamos dos a la variable led
  led += 2;

  //delay
  delay(500);

}


int pinLed = 10;
int pinPulsador = 8;
boolean estadoPulsador;
int brillo=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(pinPulsador, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoPulsador = digitalRead(pinPulsador);
  if(estadoPulsador==1){
    brillo=0;
  }
  Serial.print("Pulsador: ");
  Serial.print(estadoPulsador);
  Serial.println();
  for(brillo==0;brillo<=255;brillo++){
    Serial.print("Pulsador: ");
    Serial.print(estadoPulsador);
    Serial.println();
    analogWrite(pinLed, brillo);
    delay(20);
  }
}

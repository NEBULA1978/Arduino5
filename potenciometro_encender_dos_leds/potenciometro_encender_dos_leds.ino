int potenciometro=A0;
int valor_pot=0;
int x=500;
int led_verde=7;
int led_rojo=6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_verde,OUTPUT);
  pinMode(led_rojo,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor_pot=analogRead(potenciometro);
  Serial.println(valor_pot);
  if(x==valor_pot){
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_rojo, LOW);
}
else{
  digitalWrite(led_rojo,HIGH);
  digitalWrite(led_verde,LOW);
}
delay(300);

}

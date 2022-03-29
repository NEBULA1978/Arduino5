//estructura de control do while : si en while es falso vuelve a ejecutarse desde el do

//pulsador1
int pinLed = 13;
int pinPulsador = 2;
boolean estadoPulsador;

//pulsador2
int pinLed2 = 12;
int pinPulsador2 = 3;
boolean estadoPulsador2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pulsador y led
  pinMode(pinLed, OUTPUT);
  pinMode(pinPulsador, INPUT);

  //pulsador2 y led2
  pinMode(pinLed2, OUTPUT);
  pinMode(pinPulsador2, INPUT);
}

void loop() 
{
  loop1();
  loop2();

} 
void loop1() {
  do{
    digitalWrite(pinLed, LOW);
    estadoPulsador = digitalRead(pinPulsador);
    Serial.print("Pulsador: ");
    Serial.print(estadoPulsador);
    Serial.println();
  } while(estadoPulsador==0);//si es cero continua en do arriba, si es falsa ejecuta abajo
  digitalWrite(pinLed, HIGH);
 
  Serial.print("Pulsador: ");
  Serial.print(estadoPulsador);
  Serial.println();

}  

  void loop2() {
  do{
    digitalWrite(pinLed2, LOW);
    estadoPulsador2 = digitalRead(pinPulsador2);
    Serial.print("Pulsador2: ");
    Serial.print(estadoPulsador2);
    Serial.println();
  } while(estadoPulsador2==0);//si es cero continua en do arriba, si es falsa ejecuta abajo
  digitalWrite(pinLed2, HIGH);
 
  Serial.print("Pulsador2: ");
  Serial.print(estadoPulsador2);
  Serial.println();

}  
  
  
  
  

//secuencia con for para leds bueno
//defino array para los leds

int leds[]={7,8,9};
int pulsador = 10;
int timbre=11;
int n=0;

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<3;i++)
  {
    pinMode(leds[i],OUTPUT);
  }
  pinMode(pulsador,INPUT);
  pinMode(timbre,OUTPUT);
}

void loop() 
{
  
  if(digitalRead(pulsador)==LOW)
  {
    for (int i=0;i<3;i++)
  
  {
    digitalWrite(leds[i],HIGH);
    digitalWrite(timbre,HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);
    digitalWrite(timbre,LOW);
    delay(200);
 }
 
}}

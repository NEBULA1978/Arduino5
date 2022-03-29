//multitareas usando funciones para varias multitareas
int Delay=1000;
int inc=0;

void setup1() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}


void led6(){//variable global que va estar enmarcada 1segundo
  delay(Delay);
  inc=inc+1;
  if(inc==10){//esta funcion linea anterior la que esta aqui entre llaves
  digitalWrite(6, 1);
  delay(100);
  digitalWrite(6, 0);
  delay(100);
  inc=0; 
}}
void led7(){
  digitalWrite(7, 1);
  delay(100);
  digitalWrite(7, 0);
  delay(100); 
}
void led8(){
  digitalWrite(8, 1);
  delay(100);
  digitalWrite(8, 0);
  delay(100); 
}
void loop1() {
  // put your main code here, to run repeatedly:
  led6();
  led7();
  led8();
}

class AutoTimer
{
  private:
    unsigned long lastUpdate; // última a actualización
    boolean       inicialWait; //Ejecutar inmediatamente o esperar al primer timer 
    void          (*funcion)(void); //Función que Ejecuta el timer
    unsigned long delayTime; //Tiempo de retardo
     
  public:
    AutoTimer(void(*f)(void), unsigned long d) //Constructor
    {
      inicialWait = false;
      lastUpdate = millis();
      funcion = f;
      delayTime = d;  
    }
 
    AutoTimer(void(*f)(void), unsigned long d, boolean iW) //Constructor opción 2
    {
      inicialWait = iW;
      funcion = f;
      delayTime = d;
      if(inicialWait)
      {
        lastUpdate = delayTime + millis();
      }
      else
      {
       lastUpdate = millis(); 
      }
    }
 
    boolean evaluate(){
      if(lastUpdate > millis()) //Esto es en caso de que ocurra un desbordamiento de la función millis
      {
        lastUpdate = millis();
      }
       
      if(millis() - lastUpdate >= delayTime){
        (*funcion)();
        lastUpdate = millis();
        return true;
      }
 
      return false;
    }
     
};
 
void toggleLED(){
  Serial.begin(9600); 
  if(digitalRead(13))
  {
    digitalWrite(13, LOW);
    Serial.println(LOW);
  }
  else
  {
    digitalWrite(13, HIGH);
    Serial.println(HIGH);
  }
   
}
 
AutoTimer parpadeo(toggleLED, 1000, false);
 
void setup() {
  
  pinMode(13, OUTPUT);
   
}
 
void loop() {
   
  parpadeo.evaluate();
  
   
}

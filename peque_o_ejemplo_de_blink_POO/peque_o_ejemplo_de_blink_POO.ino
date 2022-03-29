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
  Serial.begin(9600);
  pinMode(13, OUTPUT);
   
}
 
void loop() {
   
  parpadeo.evaluate();
  
   
}


//Segunda clase copia anterior
class AutoTimer2
{
  private:
    unsigned long lastUpdate; // última a actualización
    boolean       inicialWait; //Ejecutar inmediatamente o esperar al primer timer 
    void          (*funcion)(void); //Función que Ejecuta el timer
    unsigned long delayTime; //Tiempo de retardo
     
  public:
    AutoTimer2(void(*f)(void), unsigned long d) //Constructor
    {
      inicialWait = false;
      lastUpdate = millis();
      funcion = f;
      delayTime = d;  
    }
 
    AutoTimer2(void(*f)(void), unsigned long d, boolean iW) //Constructor opción 2
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
 
void toggleLED2(){
  Serial.begin(9600); 
  if(digitalRead(12))
  {
    digitalWrite(12, LOW);
    
    Serial.println(LOW);
    Serial.println("Led 12 apagado");
  }
  else
  {
    digitalWrite(12, HIGH);
    
    Serial.println(HIGH);
    Serial.println("Led 12 encendido");
  }
   
}
 
AutoTimer2 parpadeo2(toggleLED2, 1000, false);
 
void setup2() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
   
}
 
void loop2() {
   
  parpadeo2.evaluate();
  Serial.println(parpadeo2.evaluate());
  
   
}

class Encender{
  private:
  int led;

  public:

  void Modo(int led){
    pinMode(led, OUTPUT); 
    }
  void Encendido(int led){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
};

class Encender2{
  private:
  int led2;

  public:

  void Modo(int led2){
    pinMode(led2, OUTPUT); 
    }
  void Encendido2(int led2){
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
  }
};

class Encender3{
  private:
  int led3;

  public:

  void Modo(int led3){
    pinMode(led3, OUTPUT); 
    }
  void Encendido3(int led3){
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);
  }
};

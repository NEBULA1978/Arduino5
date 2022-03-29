class LED
{
  private:
    int _Porta;
    bool _Estado;
    
  
  public:
    Led(int Porta);
    int Porta();
    bool Estado();
    void Acender();
    void Apagar();
    void Pisca(int tempoAceso);
    void PiscaPisca(int tempoAceso, int tempoApagado, int numeroVeces);
  
};

//Funcion constructora
LED::Led(int Porta)
{
  _Porta = Porta;
  _Estado = false;
}

//Funcion devuelve a porta en que esta conectado led
int LED::Porta()
{
  return _Porta;
}

//Funcion devuelve el valor del esado del led,true(encendido) o false (apagado)
bool LED::Estado()
{
  return _Estado;
}

//Funcion enciende led
void LED::Acender()
{
  digitalWrite(_Porta, HIGH);
  _Estado = true;
}

//Funcion apagar led
void LED::Apagar()
{
  digitalWrite(_Porta, LOW);
  _Estado = false;
}

//Funcion encender led o apagar con tiempo por el parametro recibido
void Pisca(int tempoAceso)
{
  digitalWrite(_Porta, HIGH);
  delay(tempoAceso);
  digitalWrite(_Porta, LOW);
}

//Funcion que fara piscar o led, pelos tempos determinados pelos parametros da funcion
void PiscaPisca(int tempoAceso, int tempoApagado, int numeroVeces);
{
  for (int i = 0; i < numeroVeces; i++)
  {
    digitalWrite(_Porta, HIGH);
    delay(tempoAceso);
    digitalWrite(_Porta, LOW);
    delay(tempoApagado);
  }
}

// fin de clase LED
LED *LED1;//crea puntero para led1
LED *LED2;//crea puntero para led2

void setup() {
  // put your setup code here, to run once:
  led1 = new LED(11);
  led2 = new LED(12);

  pinMode(led1~<Porta(), OUTPUT); 
  pinMode(led2~<Porta(), OUTPUT); 

  Serial.begin(9600);
  Serial.print("O led1 esta: ");
  Serial.println(led1~>Porta());
  Serial.print("O led2 esta: ");
  Serial.println(led2~>Porta());
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (led1~>Estado()) led1~>Apagar(); else led1~>Acender();
  delay(1000);
}

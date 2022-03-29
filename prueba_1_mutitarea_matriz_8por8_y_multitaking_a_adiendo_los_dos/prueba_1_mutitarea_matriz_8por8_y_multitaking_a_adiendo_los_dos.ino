/*Copyright (C) 2017 Iván Rodríguez Méndez*/
 
#define LED_A 8
#define LED_B 7
#define LED_C 6
#define BOTON 5
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0 
 
//Tutorial 16: Simbolos en matriz de LEDS
 
 
 
#include "LedControlMS.h" 
 
 
 
LedControl lc=LedControl(12,11,10,1); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales
 
/* 12 para el DIN, 11 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/ 
 
 
 
//Corazón pequeño
 
byte Corazon_datos[] = {
 
B00000000,
 
B01100110,
 
B11111111,
 
B11111111,
 
B01111110,
 
B00111100,
 
B00011000,
 
B00000000};
 
 
 
byte Cara_datos[] = 
 
{B00111100,
 
B01000010,
 
B10100101,
 
B10000001,
 
B10100101,
 
B10011001,
 
B01000010,
 
B00111100};
 
 
 
byte Mensaje_datos[] = 
 
{B00000000,
 
B00000100,
 
B00000000,
 
B01010100,
 
B01110100,
 
B01010100,
 
B00000000,
 
B00000000};
 
 
 
void setup()
 
{
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(BOTON, INPUT);//por defecto esta asi
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
 
  lc.shutdown(0,false);
 
  lc.setIntensity(0,8);// La valores estan entre 1 y 15 
 
  lc.clearDisplay(0);
 
  
 
}
 
void loop()
 
{
  loop_led_a();
  loop_led_b();
  loop_led_c();
  Representar(Mensaje_datos,5000);
 
  trans();
 
  delay(500);
 
  Representar(Corazon_datos,5000);
 
  Representar(Cara_datos,3000);
 
  lc.clearDisplay(0);
 
}
 
 
 
// Funcion para representar una transicion animada
 
void loop_led_a()
{
  //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;

  long hora = millis();

  if (hora - ultimo_cambio >100){
      ultimo_cambio = hora;

      if(Estado_LED == ON){
          digitalWrite(LED_A, LOW);
          Estado_LED = OFF;
      }else{
         digitalWrite(LED_A, HIGH);
         Estado_LED = ON ;
      }
      
  }
}

void loop_led_b()
{
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;

  long hora = millis();

  if (hora - ultimo_cambio >250){
      ultimo_cambio = hora;

      Estado_LED = !Estado_LED;
      digitalWrite(LED_B, Estado_LED);

    //  if(Estado_LED == ON){
    //      digitalWrite(LED_B, LOW);
    //      Estado_LED = OFF;
    //  }else{
   //      digitalWrite(LED_B, HIGH);
    //     Estado_LED = ON ;
   //   }
      
      }
}

void loop_led_c()
{
  digitalWrite(LED_C, digitalRead(BOTON));
} 
 
void trans(){ //Funcion de transicion para llenar y vaciar la pantalla de puntos
 
  for (int row=0; row<8; row++)
 
  {
 
    for (int col=0; col<8; col++)
 
    {
 
      lc.setLed(0,col,row,true); // 
 
      delay(25);
 
    }
 
  }
 
 
 
  for (int row=0; row<8; row++)
 
  {
 
    for (int col=0; col<8; col++)
 
    {
 
      lc.setLed(0,col,row,false); // 
 
      delay(25);
 
    }
 
  }
 
}
 
 
 
// Definimos una funcion para representar las figuras
 
 
 
void Representar(byte *Datos,int retardo) //Funcion para la representacion de bytes de datos para una matriz de 8x8 
 
{
 
  for (int i = 0; i < 8; i++)  
 
  {
 
    lc.setColumn(0,i,Datos[7-i]);
 
  }
 
  delay(retardo);
 
}

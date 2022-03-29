#include"caseboton.h"
//##############   CODIGO BOTÓN DE CLASE  #############

const int PIN_LED_1 = 8;
const int PIN_LED_2 = 9;
const int PIN_LED_3 = 10;

Boton *b; //puntero al botón
Boton *b2; //puntero al botón

void setup() {
  b = new Boton(11, 100); //pino 11 , debounce time 100// debounce : rebote
  b2 = new Boton(12, 100); //pino 12 , debounce time 100
  Serial.begin(9600);
}

void loop() { 
  b->atualiza(); //lee el estado de los pines y actualiza las variables de control
  
  if ( b->presionado() ) {  led_1(); Serial.println("pressionou"); } //encender el led 1
  if ( b->nopresionado() )                   {  led_2(); Serial.println("soltou"); } //encender el led 2
  if ( b->tempo_presionado() > 3000 ) {  led_3(); Serial.println("3 segundos"); } //pitido del gatillo después de 3 segundos presionado
  
  
  b2->atualiza(); //lee el estado de los pines y actualiza las variables de control
  
  if ( b2->presionado() ) {  led_1(); Serial.println("pressionou"); } //encender el led 1
  if ( b2->nopresionado() )                   {  led_2(); Serial.println("soltou"); } //encender el led 2
  if ( b2->tempo_presionado() > 3000 ) {  led_3(); Serial.println("3 segundos"); } //pitido del gatillo después de 3 segundos presionado  
  
}

void led_1() { digitalWrite(PIN_LED_1, !digitalRead(PIN_LED_1)); }
void led_2() { digitalWrite(PIN_LED_2, !digitalRead(PIN_LED_2)); }
void led_3() { digitalWrite(PIN_LED_3, true); }

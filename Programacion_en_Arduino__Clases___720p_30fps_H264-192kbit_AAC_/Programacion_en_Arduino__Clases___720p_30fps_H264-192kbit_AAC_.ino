#include "Encender.h"


Encender encender;//llamado a mi clase
Encender2 encender2;//llamado a mi clase
Encender3 encender3;//llamado a mi clase

void setup() {
  // put your setup code here, to run once:
  encender.Modo(13);
  encender2.Modo(12);
  encender3.Modo(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  encender.Encendido(13);//variable encender hago llamar a mi metodo encendido
  encender2.Encendido2(12);//variable encender hago llamar a mi metodo encendido
  encender3.Encendido3(11);//variable encender hago llamar a mi metodo encendido
}

int contador;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  contador = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if( contador % 2 == 0 || contador % 3 == 0){
    Serial.print("contador = ");
    Serial.println(contador);
    
  }else{// si esta vacio no hace falta ponerlo
    
  }
  contador++;// contador = contador+1 es lo mismo contador++
  delay(1000);
}

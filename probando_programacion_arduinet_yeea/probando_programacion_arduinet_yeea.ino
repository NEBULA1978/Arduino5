int contador;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  contador = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if( contador % 2 == 0){
    Serial.println("contador : ");
    Serial.println(contador);
    
  }else{
    
  }
  contador++;// contador = contador+1 es lo mismo contador++
  delay(1000);
}

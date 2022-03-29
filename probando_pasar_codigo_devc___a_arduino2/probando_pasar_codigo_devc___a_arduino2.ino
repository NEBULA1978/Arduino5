void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int n1,n2, suma = 0, resta = 0, multiplicacion=0,division=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Digite un numero: ");
 Serial.println("Digite otro numero: "); 
 suma = n1 + n2;
  resta = n1 - n2;
  multiplicacion = n1 * n2;
  division = n1 / n2;
  
  cout<<"\nLa suma es: "<<suma<<endl;
  cout<<"La resta es: "<<resta<<endl;
  cout<<"La multiplicacion es: "<<multiplicacion<<endl;
  cout<<"La division es: "<<division<<endl;
}

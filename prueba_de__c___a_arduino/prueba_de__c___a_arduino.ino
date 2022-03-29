void setup() {
  // put your setup code here, to run once:
  int matriz[100][100],filas,columnas;
  int matriz2[100][100],dato=0;
  Serial.begin(9600);
  Serial.println<<"Digite el numero de filas: "; cin>>filas;
  Serial.println(9600);<<"Digite el numero de columnas: "; cin>>columnas;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
      dato = 1+rand()%(100); //numeros aleatorios de 1 a 100
      matriz[i][j] = dato;
    }
  }
}
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
      matriz2[i][j] = matriz[i][j];
    }
  }
    for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
      cout<<matriz2[i][j]<<"  ";
    }
    Serial.println<<"\n";
  }
  
  system("pause");

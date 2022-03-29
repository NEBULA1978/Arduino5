//definimos variables
int mizp=8;
int mizn=9;
int mdep=10;
int mden=11;

int btizq=2;
int btadel=3;
int btatras=6;
int btparar=5;
int btder=4; 

int datobtizq=0;//inicializo a 0 para evitar ruidos electromagneticos
int datobtadel=0;//inicializo a 0 para evitar ruidos electromagneticos
int datobtatras=0;//inicializo a 0 para evitar ruidos electromagneticos
int datobtparar=0;//inicializo a 0 para evitar ruidos electromagneticos
int datobtder=0; //inicializo a 0 para evitar ruidos electromagneticos

// configuracion de la tarjeta
void setup() 
{//empieza
  // actuadores son salidas
  pinMode(mizp, OUTPUT);//positivo motor iz
  pinMode(mizn, OUTPUT);
  pinMode(mdep, OUTPUT);//positivo motor derecha
  pinMode(mden, OUTPUT);

  pinMode(btizq,INPUT);//todos los sensores o pulsadores son entradas jeje
  pinMode(btadel,INPUT);
  pinMode(btatras,INPUT);
  pinMode(btparar,INPUT);
  pinMode(btder,INPUT);
  
  Serial.begin(9600);
}//termina

//subrutinas
void adelante(){
  digitalWrite(mizp, HIGH);//por el positivo enviamos 5v
  digitalWrite(mizn, LOW);//por el negativo enviamos 0v
  digitalWrite(mdep, HIGH);//por el positivo enviamos 5v
  digitalWrite(mden, LOW);//por el negativo enviamos 0v 
}

void detener(){
  digitalWrite(mizp, LOW);//por el positivo enviamos 5v
  digitalWrite(mizn, LOW);//por el negativo enviamos 0v
  digitalWrite(mdep, LOW);//por el positivo enviamos 5v
  digitalWrite(mden, LOW);//por el negativo enviamos 0v
}

void derecha(){
  digitalWrite(mizp, HIGH);//por el positivo enviamos 5v
  digitalWrite(mizn, LOW);//por el negativo enviamos 0v
  digitalWrite(mdep, LOW);//por el positivo enviamos 5v
  digitalWrite(mden, LOW);//por el negativo enviamos 0v
}

void izquierda(){
  digitalWrite(mizp, LOW);//por el positivo enviamos 5v
  digitalWrite(mizn, LOW);//por el negativo enviamos 0v
  digitalWrite(mdep, HIGH);//por el positivo enviamos 5v
  digitalWrite(mden, LOW);//por el negativo enviamos 0v
}

void atras(){
  digitalWrite(mizp, LOW);//por el positivo enviamos 5v
  digitalWrite(mizn, HIGH);//por el negativo enviamos 0v
  digitalWrite(mdep, LOW);//por el positivo enviamos 5v
  digitalWrite(mden, HIGH);//por el negativo enviamos 0v
}

//paso3 tarea principal
void loop() {//ciclo infinito
  // mover el carro con pulsadores
  datobtizq = digitalRead(btizq);//valor de lectura del pulsador se almacena aqui para leer
  Serial.print(datobtizq);

  datobtadel = digitalRead(btadel);//valor de lectura del pulsador se almacena aqui para leer
  Serial.println(datobtadel);

  if(datobtizq==1){
    izquierda();
  }
  if(datobtadel==1){
    adelante();
  }
   if(datobtder==1){
    derecha();
  }
   if(datobtparar==1){
    detener();
  }
  if(datobtatras==1){
    atras();
  }
//faltan 4pulsadores falta comprobar  
}//fin loop

//definimos variables
int mizp=8;
int mizn=9;
int mdep=10;
int mden=11;

// configuracion de la tarjeta
void setup() 
{//empieza
  // actuadores son salidas
  pinMode(mizp, OUTPUT);//positivo motor iz
  pinMode(mizn, OUTPUT);
  pinMode(mdep, OUTPUT);//positivo motor derecha
  pinMode(mden, OUTPUT);
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
  // los dos motores van hacia delante
  adelante();

  
}//fin loop

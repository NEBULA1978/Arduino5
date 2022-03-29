unsigned long tiempoactual = 0;
unsigned long tiempoactual2 = 0;

long mitiempo;
long inicio;
long final;

long mitiempo2;
long inicio2;
long final2;

int lecturaboton_old = 1;

int hour = 14;
int minute = 28;
int second = 25;

int encendido[] = {14, 28, 30};
int apagado[] = {14, 28, 40};

int encendido2[] = {14, 28, 45};
int apagado2[] = {14, 28, 50};

void setup() {
    Serial.begin(9600);
    pinMode(A5, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(6, INPUT_PULLUP);

    inicio = encendido[0]*100000 + encendido[1]*1000 + encendido[2]*10;
    final = apagado[0]*100000 + apagado[1]*1000 + apagado[2]*10;

    inicio2 = encendido2[0]*100000 + encendido2[1]*1000 + encendido2[2]*10;
    final2 = apagado2[0]*100000 + apagado2[1]*1000 + apagado2[2]*10;
}


void loop() {
    loop1();
    loop2();
}

//para encender led y apagar o encender con HIGH
void parpadeo(){
  int lecturaled = digitalRead(A5);
  digitalWrite(A5, !lecturaled);
}

//para hacer reloj
void tiempo(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
  
    if(minute == 60){
        minute = 0;
        hour++;
    }
  
    if(hour == 24){
      hour = 0;
    }
  
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}

//funcion del loop
void loop1() {
    int lecturaboton = digitalRead(6);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled13 = digitalRead(13);
            digitalWrite(13, !lecturaled13);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo);

    bool minimo = mitiempo > inicio;
    bool maximo = mitiempo < final;
    
    if( minimo && maximo ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo();
        }
    }else{
        digitalWrite(A5, 0);
    }
}

//segunda alarma

//funcion del loop
void loop2() {
    int lecturaboton = digitalRead(6);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled13 = digitalRead(13);
            digitalWrite(13, !lecturaled13);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo2 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo);

    bool minimo2 = mitiempo2 > inicio2;
    bool maximo2 = mitiempo2 < final2;
    
    if( minimo2 && maximo2 ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo2();
        }
    }else{
        digitalWrite(A5, 0);
    }
}

//para parpadeo y reloj
//para encender led y apagar o encender con HIGH
void parpadeo2(){
  int lecturaled = digitalRead(A5);
  digitalWrite(A5, !lecturaled);
}

//para hacer reloj
void tiempo2(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
  
    if(minute == 60){
        minute = 0;
        hour++;
    }
  
    if(hour == 24){
      hour = 0;
    }
  
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}

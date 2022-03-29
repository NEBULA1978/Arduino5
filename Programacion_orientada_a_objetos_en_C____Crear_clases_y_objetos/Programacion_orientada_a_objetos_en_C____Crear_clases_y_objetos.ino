//#include <iostream>
//#include <cstdlib>

using namespace std;

class operaciones{
//atributos
public:
int primero;
int segundo;
int resultado;
int resultado2; 
void sumar(){
Serial.begin(9600);
resultado2=primero+segundo;
//cout <<resultado<< endl;
}
void restar(){
Serial.begin(9600);
resultado2=primero-segundo;
}
operaciones(int,int);
};

operaciones::operaciones(int dato1,int dato2){//funciones de recepcion,constructor
primero=dato1;
segundo=dato2;  
}

int main(){//creamos objeto
operaciones objeto1(30,10);
objeto1.sumar();
objeto1.restar();//me resta no me suma aunque antes este sumar eje
operaciones objeto2(100,500);
objeto2.sumar();
Serial.println(objeto1.resultado);
Serial.println(objeto2.resultado);



system("pause");
return 0;
}

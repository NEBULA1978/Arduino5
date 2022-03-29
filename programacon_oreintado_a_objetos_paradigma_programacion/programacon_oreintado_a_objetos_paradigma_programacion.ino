//#include <iostream>
//#include <cstdlib>

using namespace std;

class operaciones{
//atributos
public:
int primero;
int segundo;
int resultado;
  
void sumar(){
Serial.begin(9600);
resultado=primero+segundo;
//cout <<resultado<< endl;
}
void restar(){
  Serial.begin(9600);
resultado=primero-segundo;
}
operaciones(int,int);
};

operaciones::operaciones(int dato1,int dato2){//funciones de recepcion,constructor
primero=dato1;
segundo=dato2;  
}

int main(){//creamos objeto
Serial.begin(9600);
operaciones objeto1(30,10);
objeto1.sumar();
objeto1.restar();//me resta no me suma aunque antes este sumar eje
operaciones objeto2(100,500);
objeto2.sumar();
//println(objeto1.resultado);//cout << objeto1.resultado << endl;
print(objeto2.resultado);//cout << objeto2.resultado << endl;



system("pause");
return 0;
}

//############  CODIGO BOTÓN DE CLASE  ################
class Boton {
  private:
    int _pino_boton;
    int _debounce_delay;
    int _lectura_actual;
    int _lectura_anterior_db;
    long _time_ultimo_debounce;//(rebote)
    long _debounce_ok;
    bool _presionado;
    bool _nopresionado;
  public:
    Boton(int pin, int debounce);
    void atualiza();
    bool presionado();
    bool nopresionado();
    long tempo_presionado();
};

Boton::Boton(int pin, int debounce){
  _presionado     = false;
  _nopresionado   = false;
  _pino_boton     = pin;
  _debounce_delay = debounce;
  pinMode(_pino_boton, INPUT);
}

void Boton::atualiza(){  
  int lectura_actual = digitalRead(_pino_boton);
  if (lectura_actual != _lectura_anterior_db   )
  { _time_ultimo_debounce = millis(); _debounce_ok = 0; }
  if (  (millis() - _time_ultimo_debounce) > _debounce_delay ) { _debounce_ok = 1;                                   }
  if (_debounce_ok == 1) { 
    _presionado  = (lectura_actual == 1 && _lectura_anterior_db == 0) ; 
    _nopresionado              = (lectura_actual == 0 && _lectura_anterior_db == 1) ;
    _lectura_anterior_db = lectura_actual; 
  }
  _lectura_anterior_db = lectura_actual;  
}

bool Boton::presionado()        {  return _presionado;  }
bool Boton::nopresionado()            {  return _nopresionado;      }
long Boton::tempo_presionado() {  
  if ( _lectura_anterior_db ) {
    return ( millis()-_time_ultimo_debounce );
  } else {
    return 0;
  }  
}

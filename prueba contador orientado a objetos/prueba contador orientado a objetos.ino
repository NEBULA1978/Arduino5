class Contador
   {  private:
         int N ;
 
      public:   
         Contador( ) ;              // Constructor
         Contador( int k ) ;        // Constructor
         void SetContador( int n) ;
         void Incrementar() ;
         int GetCont() ;
   } ;
 
Contador::Contador( )           // Constructor
    { N = 0 ; }       
Contador::Contador( int k)         // Constructor
    { N = k ; }   
 
Contador C1, C2(23) ;
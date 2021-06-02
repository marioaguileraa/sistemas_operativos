

double funcion(double x);

void dispatcher( int workpipe, int numwp, long ndiv);

void worker( int workpipe, int resultpipe);

void gatherer( int resultpipe);

struct args {
         int num_veces;
         double tam_div;
         double posicion_inicial;
};
  
 





#include <iostream>
#include <string.h>
#include "../include/funciones.hpp"
using namespace std;




int main()
{ 

  //creamos objetos personas -- p1 es una variable, un estructuras de tipo persona
    Persona p1 = persona("JOSEPH GUIVAR RIMAPA",732452,fecha(10,11,1663),direccion("San Antonio",3,2,'A',"1356"));
    
    cout << personaToString(p1)<< endl;

    int d,m,a;
    cout << "INGRESE UNA FECHA:  "<<endl;
    cin >> d >> m >> a;  

    FechaNacimiento f = fecha(d,m,a);
    if (fechaValidar(f))
    {
      cout << fechaToString(f) << endl;
    }
    else
    {
      cout << "La fecha ingresada es incorrecta" << endl;
    }
    

    return 0;
}


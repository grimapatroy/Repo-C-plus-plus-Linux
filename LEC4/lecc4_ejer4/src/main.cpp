#include <iostream>
#include "../include/TDA.hpp"
#include "../include/funciones.hpp"
using namespace std;


int main()
{   
    int i,j=0;
    string cadena ="Pedro,2-oct-1970,Argentino|Juan,9-dic-1985,Chileno|Pablo,14-ene-1992,Argentino";
    string porcion="";
    int tam = charCount(cadena,'|');
    int pos;
    for ( i = tam; i >0; i--)
    {
    // la posicion de  
        pos = indexOfN(cadena,'|',i);
        // obtener porciones de la cadena tokenizada
        porcion = substring(cadena,pos+1,length(cadena)-length(porcion));
        cout<<porcion<<endl;
    }
        porcion = substring(cadena,0,pos-1);
        cout<<porcion<<endl;

    return 0;
}
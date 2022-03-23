#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


int main()
{   
    string contenido,total="";
    int fil,colum;
    cout<<"Ingrese cadena de numeros: ";
    cin>>contenido;
    cout<<"Ingrese numeros de filas: ";
    cin>>fil;
    cout<<"Ingrese numeros de columnas: ";
    cin>>colum;

    Matriz miMatriz1= matriz(contenido,fil,colum);

    // Ejemplo: Si x="123456789012", n=3 y m=4, la matriz representada por este
    // conjunto de parámetros que estos parámetros están representando es la siguiente:
    // 1 2 3 4
    // 5 6 7 8
    // 9 0 1 2
    
    if (length(contenido)!=(fil*colum))
    {
        int faltante = (fil*colum)-length(contenido);
        total = contenido;
        for (int i = 0; i < faltante; i++)
        {
            total = total + "0";
        }
        
    }
    int i,j;
    for ( i = 0; i <=(fil*colum) ; i++)
    {
        
    }
    

    cout<<total;
    return 0;
}
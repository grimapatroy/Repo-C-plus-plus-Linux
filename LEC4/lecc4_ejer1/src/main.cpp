#include <iostream>
#include "../include/TDA.hpp"
#include "../include/strings.hpp"
using namespace std;


int main()
{   
    string cadena;

    cout<<"INGRESE CADENA DE LETRAS(sin espacios ,ni signos especiales): ";
    cin>>cadena;
a    cadena = toUpperCase(cadena);
    int i,sumValor=0;
    for ( i = 0; i < length(cadena); i++)
    {
        // sumValor += convertirValor(cadena[i]);
        sumValor += cadena[i] - 64;
    }

    if (length(intToString(sumValor))>3)
    {
        int sum=0;
        string v=intToString(sumValor);
        for ( i = 0; i<length(v); i++)
        {
            sum += charToInt(v[i]);
        }
        cout<<"El resultado es: "<<sum;
    }else
    {
        cout<<"El resultado es: "<<sumValor;
    }
    
    return 0;
}
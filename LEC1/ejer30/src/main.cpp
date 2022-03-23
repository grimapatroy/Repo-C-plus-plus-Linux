#include <iostream>
#include "../include/TDA.hpp"
#include "../include/strings.hpp"
#include "../include/funciones.hpp"
using namespace std;


int main()
{
    string seguidilla,totalSeguidilla="";
    string position="",totalElementos="";
    int pos=0,contSecuencial=0,posRel;
    cout<<"Ingrese valores: "<<endl;
    cin>>seguidilla;
    pos++;
    while (stringToInt(seguidilla)!=0)
    {
        totalSeguidilla+=seguidilla;
        if(validarSecuenciaAscendente(seguidilla))
        {
            contSecuencial++;
        }
        int cantElemen = validarCantElemn(seguidilla);
        position = position + intToString(pos) + "-";
        totalElementos = totalElementos + intToString(cantElemen) + "-";
        cout<<"Ingrese valores: "<<endl;
        cin>>seguidilla;
        pos++;
    }
    cout<<"Cantidad de elementos: "<<cantidadXseguidilla(totalElementos,position)<<endl;
    seguidillaMasLarga(totalSeguidilla,position);
    return 0;
}
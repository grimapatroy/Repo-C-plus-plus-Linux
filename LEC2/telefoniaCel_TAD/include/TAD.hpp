#ifndef _TADTelefonia_
#define _TADTelefonia_

#include <iostream>
#include <string.h>
#include "strings.hpp"
using namespace std;


struct Planes
{
    char arrayTipoAbono[5]={'A','B','C','D','E'};
    int arrayPrecio[5] = {1500,1000,700,500,350};
    int arrayCargoexedente[5]={1,3,5,7,10};
};


struct Datos
{
    int numCel;
    string nomAbonado;
    string direcAbonado;
    int timeUso;
    char tipoAbono;
};


int datosToMin(int m)
{
    int minutos;
    return minutos;
}



void datosExcedente(Datos d,Planes p, int &minutosExcedidos, double &importeAAbonar)
{

}







#endif


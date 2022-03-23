#ifndef _TADFecha_
#define _TADFecha_

#include <iostream>
#include "strings.hpp"
using namespace std;

struct Fecha
{
    int d;
    int m;
    int a;
};

Fecha fechaInicializada(int dia,int mes,int anio)
{
    return {dia,mes,anio};
}

void fechaMostrar(Fecha f)
{
    cout<< intToString(f.d)+"/"+intToString(f.m)+"/"+intToString(f.a)<<endl;
}


#endif
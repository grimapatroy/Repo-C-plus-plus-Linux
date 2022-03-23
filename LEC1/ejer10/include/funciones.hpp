#ifndef _FUNCIONES_
#define _FUNCIONES_

#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;

};

Fecha fechaInicializar(int d,int m,int a)
{
    return {d,m,a};
}

void fechaComprar( Fecha fActual, Fecha f1, Fecha f2){
    int fechaActual = fActual.anio + fActual.mes + fActual.dia; 
    int fecha1 = f1.anio + f1.mes + f1.dia; 
    int fecha2 = f2.anio + f2.mes + f2.dia; 

    int resta1 = fechaActual - fecha1;
    int resta2 = fechaActual - fecha2;
    
    if(resta1>resta2){
        cout<<"La FECHA 1 ES LA MAS CERCANA"<<endl;
    }else{
        cout<<"La FECHA 2 ES LA MAS CERCANA"<<endl;
    }
}

string fechaToString(){

    return "";
}



#endif
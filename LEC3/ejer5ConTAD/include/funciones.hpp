
#include <iostream>
#include <string.h>
using namespace std;


 
// int toMin(int timeUso); 

// void excedente(double precio, int minLibres, 
// double valorMinutoExcedente, int minutosUtilizados,
//  int& minutosExcedidos, double& importeAApagar );

struct TipoAbono
{
    char tipo;
    int precio;
    int minutos;
    int cargoMinExedentes;
};


struct ConsumoAbonados
{
    int numeroCelular;
    string nombreAbonado;
    string direccionAbonado;
    int timeUso;
    //char tipoAbono;
};


ConsumoAbonados consumoAbonados(int numeroCelular,
string nomAbonado, string direccAbonado,
int timeUso){

return {numeroCelular,nomAbonado,direccAbonado,timeUso};
}


string consumoAboToString(ConsumoAbonados ca){
    string numCel = to_string(ca.numeroCelular) ;
    string timeUso = to_string(ca.timeUso) ;
   // string tipoAbo = to_string(ca.tipoAbono) ;
    string nomAbono = ca.nombreAbonado;
    string direcAbono = ca.direccionAbonado;

    return numCel + " " + timeUso + " "+ nomAbono  + " " + direcAbono;
}

string tipoAbonoToString(TipoAbono ta){

}

// #TODO falta implementacion
void tipoAbonoPlan(char tipoAbono){
    
    tipoAbonoTablaPlan();
}

// #TODO falta implementacion
void tipoAbonoTablaPlan(TipoAbono abono){

}


//Funciones que me piden el problema

int toMin(int timeUso){
    int coversionMin;
    int horas, min, resto;
    horas = int (timeUso/100);
    min = timeUso % 100;
    coversionMin = (horas * 60) + min;
    return coversionMin;
}


// #TODO Falta implementacion
void excedente(double precio, int minLibres, 
double valorMinutoExcedente, int minutosUtilizados,
 int& minutosExcedidos, double& importeAApagar ){


}
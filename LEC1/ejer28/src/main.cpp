#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


int main()
{   
    // variables para conjuntos
    double promedioConj=0.0,porcentajePosiConj=0.0;
    int valor=0,valorMaxConj=0;
    int contvalorNegativo=0,contValorPositivo=0;

    // variables para lote
    int valorMinimoLote=0;
    double valorPromedioLote=0.0,porcentajeValorNegativoLote=0.0;

    int conjunto=0,contadorConjunto=0,cantValor=0;

    int contadorTotalNum=0;

    cout<<"Ingrese la cantidad de conjuntos: ";
    cin>>conjunto;
    while(contadorConjunto<conjunto)
    {
        cout<<"Ingrese cantidad de valores numericos: ";
        cin>>cantValor;
        contadorTotalNum+=cantValor;
        cout<<"Ingrese el numero: ";
        cin>>valor;
        valorMaxConj=valor;
        for ( int i = 1; i < cantValor; i++)
        {
            if (valorMaxConj<valor)
            {
                valorMaxConj=valor;
            }
            if (valorMinimoLote>valor)
            {
                valorMinimoLote=valor;
            }
            if(valor>0)
            {
                contValorPositivo++;
            }else{
                contvalorNegativo++;
            }
            cout<<"Ingrese el numero: ";
            cin>>valor;
            promedioConj+=valor;
        }
            promedioConj/=cantValor;
            porcentajePosiConj=(contValorPositivo*100)/cantValor;
        cout<<"************************************************"<<endl;
        cout<<"*********REPORTE POR CONJUNTO**********"<<endl;
        cout<<"EL MAXIMO VALOR ES: "<<valorMaxConj<<endl;
        cout<<"EL VALOR PROMEDIO ES: "<<promedioConj<<endl;
        cout<<"EL PORCENTAJE DE VALORES POSITIVOS: "<<porcentajePosiConj<<"%"<<endl;
        contValorPositivo=0;
        valorMaxConj=0;
    cout<<"************************************************"<<endl;
    valorPromedioLote+=promedioConj;
    contadorConjunto++;
    }
    valorPromedioLote/=conjunto;
    porcentajeValorNegativoLote=(contvalorNegativo*100)/contadorTotalNum;
    cout<<"************************************************"<<endl;
    cout<<"********REPORTE DEL LOTE DE DATOS*******"<<endl;
    cout<<"EL VALOR PROMEDIO DE TODO EL LOTE: "<<valorPromedioLote<<endl;
    cout<<"PORCENTAJE DE VALORES NEGATIVOS: "<<porcentajeValorNegativoLote<<"%"<<endl;
    cout<<" EL VALOR MINIMO ES :"<<valorMinimoLote<<endl;
    return 0;
}
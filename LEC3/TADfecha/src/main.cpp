#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


int main()
{   
    int dia,mes,anio;
    cout<<"ingrese dia: ";
    cin>>dia;
    cout<<"ingrese mes: ";
    cin>>mes;
    cout<<"ingrese anio: ";
    cin>>anio;

    Fecha f = fechaInicializada(dia,mes,anio);
    fechaMostrar(f);

    return 0;
}

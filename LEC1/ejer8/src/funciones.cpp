#include <iostream>
#include "../include/funciones.hpp"
using namespace std;

void descomFecha(int f,int& anio, int& mes, int& dia)
{
    anio = f/10000;
    mes  = (f%10000)/100;
    dia = (f%10000)%100;
}
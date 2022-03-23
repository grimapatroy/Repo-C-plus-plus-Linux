#include <iostream>
#include "../include/funciones.hpp"
using namespace std;


int main()
{   
    int f;
    int anio = 0, mes= 0, dia = 0;
    
    cout << "INGRESE FECHA DE 8 DIGITOS: ";
    cin >> f;

    descomFecha(f,anio,mes,dia);
    

    cout << "EL AÑO ES: " << anio << endl;
    cout << "EL MES ES: " << mes << endl;
    cout << "EL  ES: " << dia << endl;

    

    


    return 0;
}
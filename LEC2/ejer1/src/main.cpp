#include <iostream>
#include "../include/funciones.hpp"
using namespace std;


int main()
{   
    unsigned int valor;
    cout<<"INGRESE VALOR: ";
    cin>>valor;

    cout<<"----------------------------"<<endl;
    cout<<":::::::::::RESULTADO::::::::"<<endl;
    cout<<"----------------------------"<<endl;
    cout << factorial(valor)<<endl;

    return 0;
}
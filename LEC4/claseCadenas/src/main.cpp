#include <iostream>
#include "../include/funciones.hpp"
using namespace std;


int main()
{   
    string nombre="javier so\0to";
    cout << nombre;
    return 0;
}
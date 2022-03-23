#include <iostream>
#include "../include/funciones.hpp"
using namespace std;

int factorial(int n){
    double factorial = 1;
    for (int i = n ; i > 0; i--)
    {
        factorial= factorial * i; 
    }
    
return factorial;
}
#ifndef TDA_leccion3
#define TDA_leccion3

#include <iostream>
#include "strings.hpp"
#include<string.h>

using namespace std;

struct Francion
{
    int numerador;
    int denominador;
};

Francion fraccion(int a , int b)
{
    return {a,b};
}

string fraccionToString(Francion f )
{
    
    return intToString(f.numerador)+"/"+intToString(f.denominador)+";";
}



#endif
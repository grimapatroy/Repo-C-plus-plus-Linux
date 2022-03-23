#ifndef _TDAMatriz_
#define _TDAMatriz_

#include <iostream>
#include "strings.hpp"
using namespace std;

struct Matriz
{
    string m;
    int filas;
    int columnas;
};

Matriz matriz(int n, int m){
    return {"000",n,m};
}

Matriz matriz(string s,int n, int m){
    return {s,n,m};
}


#endif
#ifndef _TADPrueba_
#define _TADPrueba_

#include <iostream>
#include "strings.hpp"
#include "tokens.hpp"
using namespace std;

struct Collecion
{
    string s;
    char sep;
};

Collecion collCreate(){
    Collecion c;
    c.s = "";
    c.sep = '|';
    return c;
}

void colecionAddString(Collecion& c,string token){
    addToken(c.s,c.sep,token);
}

void colecionAddInt(Collecion& c,int token){
    addToken(c.s,c.sep,intToString(token));
}



int coleccionSize(Collecion c){
    return tokenCount(c.s,c.sep);
}

string coleccionGetStringAt(Collecion c,int pos){
    return getTokenAt(c.s,c.sep,pos);
}
int coleccionGetIntAt(Collecion c,int pos){
    return stringToInt(getTokenAt(c.s,c.sep,pos));
}




string coleccionMostrar(Collecion c){
    string s,tokenisada="";
    for (int i = 0; i < coleccionSize(c); i++)
    {
        s = coleccionGetStringAt(c,i);
        tokenisada = tokenisada+c.sep+s;
    }
    return tokenisada;
}

#endif
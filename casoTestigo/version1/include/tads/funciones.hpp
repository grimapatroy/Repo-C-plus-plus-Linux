#ifndef _FUNCIONES_TADS_
#define _FUNCIONES_TADS_


#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include "../tads/Coll.hpp"

// ----------------------------------------------------------------
// ----------------------------------------------------------------
struct Persona
{
    int dni;
    string nombre;
};
// ------##########FUNCIONES DEL TAD Struct PERSONA##################-------------------------

Persona persona(int a ,string n){
    return {a,n};
}
// ---------------------------------------------------------
string personaToString(Persona p){
    // devuelve addToken
    return intToString(p.dni) + "," + p.nombre;
}

Persona personaFromString(string a){
    Persona p;
    p.dni=stringToInt(getTokenAt(a,',',0));// destokenizar a
    p.nombre=getTokenAt(a,',',1);// tokenizar a
    return p;
}
// ------################################################-------------------------
// ------##########FUNCIONES DEL TAD String##################-------------------------
// ----------------------------------------------------------------
string stringFromString(string cadena){
return cadena;
}



// ----------------------------------------------------------------
// -------------funciones de comparacion--------------------------------------------

int cmpPersonaDNI(Persona p,int dni)
{
    return p.dni-dni;
}
// ------------------------------------
int cmpPersonaNombre(Persona p, string k){

    return p.nombre<k?-1:p.nombre>k?1:0;
}
// int cmpPersonaNombre2(Persona p1,Persona p2){
//    return p1.nombre<p2.nombre?-1:p1.nombre>p2.nombre?1:0;
// }

int cmpPersonasNomAsc(Persona p1,Persona p2)
{
    int i = p2.nombre<p1.nombre?-1:p2.nombre>p1.nombre?1:0;
    // int i =p1.nombre>p2.nombre?-1:p1.nombre<p2.nombre?1:0;
    // int i =p1.nombre<p2.nombre?1:p1.nombre<p2.nombre?-1:0;
    return i;
}

int cmpPersonasNomDesc(Persona p1,Persona p2)
{
    int i= p1.nombre<p2.nombre?-1:p1.nombre>p2.nombre?1:0;
    return i;
}

int cmpPersonasDNI(Persona p1,Persona p2)
{
return p1.dni-p2.dni;
}


// ----------------------------------------------------------------
// ascendente
int cmpInt (int a,int b){
    return b-a;
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------

// ------------------------funciones para coleccion de colecciones de tipo T----------------------------------
// TtoString

string collIntToString(Coll<int> x){
string r="";
collReset<int>(x);
while (collHasNext<int>(x))
{
    int i = collNext<int>(x,stringToInt);
    addToken(r,',',intToString(i));
}
return r;
}

// tFromString
Coll<int>  collIntFromString(string s){
Coll<int> x = coll<int>(',');  
for (int i = 0; i < tokenCount(s,','); i++)
{
    int token = stringToInt(getTokenAt(s,',',i));
    collAdd<int>(x,token,intToString);
}

return x;
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------


// Colecciones de estructuras que tienen colecciones
struct Conjunto
{
    string nombre;
    Coll<int>c;
};

// ----------------------------------------------------------------
// Funciones de Colecciones de estructuras que tienen colecciones


string conjuntoToString(Conjunto cjt){

string token=cjt.nombre+"#";
// collReset<int>(cjt.c);
// while (collHasNext<int>(cjt.c))
// {
// }
int size = collSize<int>(cjt.c);
for (int i = 0; i < size; i++)
{
    int subTokenInt = collGetAt<int>(cjt.c,i,stringToInt);
    token += intToString(subTokenInt)+(i<size-1?",":"");
}
return token;
}

Conjunto conjuntoFromString(string token){
Conjunto c;

c.nombre = getTokenAt(token,'#',0);

c.c = coll<int>(',');
string x = getTokenAt(token,'#',1);
for (int i = 0; i < tokenCount(x,','); i++)
{
    int subTokenInt = stringToInt(getTokenAt(x,',',i));
    collAdd<int>(c.c,subTokenInt,intToString);
}
return c;
}

void mostrarColeccion(Coll<Persona> c) 
{ 
collReset<Persona>(c); 
while( collHasNext<Persona>(c))
{
    Persona p = collNext<Persona>(c,personaFromString);
    cout<<personaToString(p)<<endl;
}
} 


#endif
// #include <string.h>
#include <stdio.h>
#include "../include/funciones/strings.hpp"
#include "../include/funciones/tokens.hpp"
#include "../include/funciones/files.hpp"
// #include "../include/funciones/testPropio.hpp"
#include "../include/tads/BitReader.hpp"
#include "../include/tads/BitWriter.hpp"
#include "../include/tads/Coll.hpp"
// #include "../include/tads/test.hpp"
using namespace std;


struct Persona
{
    int dni; // documento nacional de identidad
    string nombre;
};

Persona persona(int dni,string nombre){
    return{dni,nombre};
}

string personaToString (Persona p){

    return intToString(p.dni)+","+p.nombre;
}

Persona personaFromString(string tokens){
    Persona p;
    p.dni=stringToInt(getTokenAt(tokens,',',0));// destokenizar a
    p.nombre=getTokenAt(tokens,',',1);// tokenizar a
    return p;
}

int cmpDni(Persona p, int dni){
    return p.dni-dni;
}

int cmpPersonaNombre(Persona p1,Persona p2)
{
    return cmpString(p1.nombre,p2.nombre);
}

int cmpPersonaDNI(Persona p1,Persona p2)
{
    return p1.dni-p2.dni;
}

void mostrarColeccion(Coll<Persona> collPersonas){
    int n = collSize<Persona>(collPersonas);
    for (int i = 0; i < n; i++)
    {
        Persona personita = collGetAt<Persona>(collPersonas,i,personaFromString);
        cout<<"Elemento "<<i<<":  "<<"["<<personaToString(personita)<<"]"<<endl;
    }
}


int main()
{   
    Coll<Persona> collPersonas =coll<Persona>();
    collAdd<Persona>(collPersonas,persona(4,"Kaka"),personaToString);
    collAdd<Persona>(collPersonas,persona(12,"Javier"),personaToString);
    collAdd<Persona>(collPersonas,persona(15,"Maria"),personaToString);
    collAdd<Persona>(collPersonas,persona(60,"Paul"),personaToString);
    collAdd<Persona>(collPersonas,persona(75,"Beto"),personaToString);
    collAdd<Persona>(collPersonas,persona(1,"Soza"),personaToString);
    collAdd<Persona>(collPersonas,persona(90,"Ñol"),personaToString);
    collAdd<Persona>(collPersonas,persona(34,"Benzeman"),personaToString);
    collAdd<Persona>(collPersonas,persona(67,"Carlos"),personaToString);
    collAdd<Persona>(collPersonas,persona(22,"Raul"),personaToString);
    collAdd<Persona>(collPersonas,persona(91,"Yoel"),personaToString);
    collAdd<Persona>(collPersonas,persona(23,"Gabriel"),personaToString);
    collAdd<Persona>(collPersonas,persona(67,"Belen"),personaToString);
    collAdd<Persona>(collPersonas,persona(86,"Ben"),personaToString);
    collAdd<Persona>(collPersonas,persona(35,"Pedro"),personaToString);

    // cout<<"***********Eliminando Personas**********"<<endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     collRemoveAt<Persona>(collPersonas,i*2);
    // }
    
    // cout<<"ordenamos por nombre alfabeticamente"<<endl;
    // // ordenamos por nombre alfabeticamente
    // collSort<Persona>(collPersonas,cmpPersonaNombre,personaFromString,personaToString);

    // mostrarColeccion(collPersonas);

    // // ordenamos por DNI ascendente
    // collSort<Persona>(collPersonas,cmpPersonaDNI,personaFromString,personaToString);
    // // iteramos y mostramos
    // cout<<"***********************************************************************"<<endl;
    // cout<<"ordenamos por DNI ascendente"<<endl;
    // mostrarColeccion(collPersonas);

    // // primera posibilidad para iterar una coleccion
    // collReset<Persona>(collPersonas);
    // while (collHasNext<Persona>(collPersonas))
    // {
    //     Persona p = collNext<Persona>(collPersonas,personaFromString);
    //     cout<<personaToString(p)<<endl;
    // }
    
    collReset<Persona>(collPersonas);
    bool endOfColl;

    Persona p = collNext<Persona>(collPersonas,endOfColl,personaFromString);
    while (!endOfColl)
    {
        cout<<personaToString(p)<<endl;
        p = collNext<Persona>(collPersonas,endOfColl,personaFromString);
    }
    

    return 0;
}
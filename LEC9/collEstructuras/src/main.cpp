#include <iostream>
// #include "../include/funciones/strings.hpp"
#include "../include/tads/Coll.hpp"
using namespace std;


int main()
{   
    Coll<Persona> collPersona = coll<Persona>();
    
    Persona p ={102,"JAVIER"};

    collAdd<Persona>(collPersona,p,personaToString);
    collAdd<Persona>(collPersona,persona(100,"Felipe"),personaToString);
    p ={101,"CALEZI"};
    collAdd<Persona>(collPersona,p,personaToString);

    for (int i = 0; i < collSize<Persona>(collPersona); i++)
    {
        Persona p = collGetAt<Persona>(collPersona,i,personaFromString);
        cout<<personaToString(p)<<endl;
    }
    

    return 0;
}

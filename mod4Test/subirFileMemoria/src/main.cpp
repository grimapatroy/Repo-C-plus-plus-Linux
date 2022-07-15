#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;






int main()
{   

    Coll<Ciudad> collCiudades = subirCiudades();

    int codCiudad = 3;
    bool encontrado ;
    Ciudad ciudad = buscarCiudad(collCiudades,codCiudad,encontrado);

    if (encontrado)
    {
        cout<<"La ciudad Buscada es: "<<ciudadToDebug(ciudad)<<endl;
    }
    

    return 0;
}

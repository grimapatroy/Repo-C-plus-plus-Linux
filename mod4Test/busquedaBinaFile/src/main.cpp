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

    FILE* f = fopen("CIUDADES.dat","r+b");
    // id de la ciudad que vamos a buscar
    int id = 9;
    bool encontrado;
    Ciudad c = buscarCiudad(f,id,encontrado);
    if (encontrado)
    {
        cout<<"La ciudad Buscada: "<<ciudadToDebug(c)<<endl;
    }
    fclose(f);


    return 0;
}

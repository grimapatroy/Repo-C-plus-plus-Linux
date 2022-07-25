#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// Se pide emitir un listado detallando,
// para cada estudiante, cuál fue su calificación promedio

// CALIFICACIONES                     
//                                |             
// struct Calificacion            |     
// {                              |        
// int idAsig;                    |     
// int idEst;                     |     
// int calif;                     |     
// };                              




int main()
{   
    // inicialzo una coleccion de cont y acum
    Coll<Estad> collEstad = coll<Estad>();

    FILE* f = fopen("CALIFICACIONES_v05.dat","r+b");

    Calificacion regCalificacion = read<Calificacion>(f);

    while (!feof(f))
    {
        // buscamos (y eventualmente agregamos) en la coleccion
        int pos = buscarElemento(collEstad,regCalificacion.idEst);

            // procesar los datos
                Estad elem = collGetAt<Estad>(collEstad,pos,estadFromString);
                elem.cont++;
                elem.acum+=regCalificacion.calif;

                // actualizamos datos
                collSetAt<Estad>(collEstad,elem,pos,estadToString);

        // leo el siguiente registro
        regCalificacion = read<Calificacion>(f);
    }
    

    mostrarResultados(collEstad);


    fclose(f);


    return 0;
}

#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// Se dispone del archivo CALIFICACIONES.dat, cuyos registros no respetan ningún
// orden en particular. Se pide informar: para cada asignatura, la calificación promedio
// obtenida por los estudiantes.

int main()
{

    FILE* f = fopen("CALIFICACIONES_v03.dat", "r+b");
    
    // inicializo la coleccion de objetos de acumuladores y contadores de idAsig
    Coll<Estad> collEstad = coll<Estad>();

    // leo el primer registro
    Calificacion registro = read<Calificacion>(f);

    // iteramos el archivo
    while (!feof(f))
    {
        // buscamos (y eventualmete agregamos) en la coleccion
        int pos = descubrirElemento(collEstad,registro.idAsig);

        // procesamos el elemento  lo obtenemos de la coleccion
        Estad elem = collGetAt<Estad>(collEstad,pos,estadFromString);
        elem.cont++;
        elem.acum +=registro.calif;
        // incorporamos el elemento modificado en la coleccion
        collSetAt<Estad>(collEstad,elem,pos,estadToDebug);

    // lee el siguiente registro
        registro = read<Calificacion>(f);
    }
    // resultados
    mostrarResultados(collEstad);


    fclose(f);

    return 0;
}







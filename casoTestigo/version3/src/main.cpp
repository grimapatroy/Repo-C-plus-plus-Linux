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
    
    // coleccion de contadores y acumuladores
    Coll<Estad> collEstad = coll<Estad>();
    // leemos el primer registro del archivo
    Calificacion reg = read<Calificacion>(f);
    while( !feof(f) )
    {
    // buscamos (y eventualmente agragamos) en la coll
    int pos = descubrirElemento(collEstad,reg.idAsig);
    // procesamos
    Estad elm = collGetAt<Estad>(collEstad,pos,estadFromString);
    elm.cont++;
    elm.acum += reg.calif;
    collSetAt<Estad>(collEstad,elm,pos,estadToString);
    // leemos el siguiente registro
    reg = read<Calificacion>(f);
    }
    // resultados
    mostrarResultados(collEstad);


    fclose(f);

    return 0;
}







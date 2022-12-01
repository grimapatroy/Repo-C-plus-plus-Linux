#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

using namespace std;

// 1. Se pide generar el archivo PADRONFIX.dat, con la misma estructura
// que PADRON, asignando nuevos idEst a aquellos estudiantes cuyo iden-
// tificador está duplicado. El nuevo archivo debe estar ordenado por idEst.
// 2. ¿Cómo cambiarían la estructura de datos, estrategia y algoritmo, si el lista-
// do del punto anterior debiera estar ordenado por idEscuela+idEst?



int main()
{
    FILE* archPadron = fopen("PADRON_v15.dat","r+b");

    Coll<Idx> collIdx = coll<Idx>();

    Padron  regPadron = read<Padron>(archPadron);
    while (!feof(archPadron))
    {
        // / buscamos por idEst y (si corresponde) agregamos
        int posElment = descubrirOAgregar(regPadron.idEst,regPadron.idEscuela,collIdx);
        Idx p = collGetAt<Idx>(collIdx,posElment,idxFromString);

        // agregar la poscion del registro a la coll
        int posRegistro = filePos<Padron>(archPadron)-1;
        collAdd<int>(p.collPos,posRegistro,intToString);
        //reemplazar el elemento en la posicion X en la coleccion o actualziarlo
        collSetAt<Idx>(collIdx,p,posElment,idxToString);
    }
    
    // ordeamos y genermos el archivo
    generarArchivo(collIdx,archPadron);


    fclose(archPadron);

    return 0;
}


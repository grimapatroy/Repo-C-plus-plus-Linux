#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

using namespace std;



// el archivo Padron.dat esta desordenado 
// 1. Un listado de todos los estudiantes empadronados correctamente (sin
// error), ordenado por idEst.
// 2. Para aquellos estudiantes con idEst duplicado, emitir el siguiente listado,
// ordenado por idEst, y con el siguiente formato:
// Id. Estudiante: 999
// Nombre         DNI  Telefono        Direccion
// XXXXXXXXXXXX 99999 99999999999 XXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXX 99999 99999999999 XXXXXXXXXXXXXXXXXXX
//     :           :       :           :
// Id. Estudiante: 999
// Nombre DNI Telefono Direccion
// :       :        :       :
// -----------------------------------------------------------
// struct Idx
// {
// int idEst; // clave de busqueda
// Coll<int> collPos; // posiciones con este idEst
// }


int main()
{

    FILE* archPradron = fopen("PADRON_v14.dat","r+b");

    // creo la coleccion e inicializo
    Coll<Idx> collIdx =  coll<Idx>();


    // empiezo a recorrer el archivo registro por registro
    Padron p = read<Padron>(archPradron);
    while (!feof(archPradron))
    {
        // busco el registro por id y sino lo agrego
        int pos = descubirEnIdx(p.idEst,collIdx);
        
        // obtengo el elemento
        Idx elemIdx = collGetAt<Idx>(collIdx,pos,idxFromString);

        // obtenemos la poscion del archivo
        int posArch = filePos<Padron>(archPradron)-1;
        // agregamos la posicion del archivo
        collAdd<int>(elemIdx.collPos,posArch,intToString);

        // actualizamos el elemento a la coleccion
        collSetAt<Idx>(collIdx,elemIdx,pos,idxToString);

        p = read<Padron>(archPradron);
    }

    // ordeno la coleccion de indices
    collSort<Idx>(collIdx,cmpIdEst,idxFromString,idxToString);
    
    // muestro las listas
    mostrarLista1(collIdx,archPradron);
    mostrarLista2(collIdx,archPradron);


    fclose(archPradron);
    return 0;
}


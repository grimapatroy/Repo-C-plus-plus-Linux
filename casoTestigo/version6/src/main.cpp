#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// PUNTO1: Por cada asignatura, mostrar la calificación promedio anterior, y la nueva cali-
// ficación promedio que surge de procesar las calificaciones.

// Asignatura      Promedio anterior Promedio actual
// Arte            7.88                    6.25
// Geografía       6.09                    6,57
// Historia        8.23                    7.34
// Matemáticas     7.34                    5.48
// :                   :                       :

// PUNTO2: Actualizar el archivo de asignaturas con los nuevos promedios



int main()
{   
    Coll<RAsignatura> collRAsigs = subirAsignaturas();

    FILE* f = fopen("CALIFICACIONES_v06.dat","r+b");

    Calificacion elemCalif = read<Calificacion>(f);

    while (!feof(f))
    {
        int pos = collFind<RAsignatura,int>(collRAsigs,elemCalif.idAsig,cmpRAsigId,rAsignaturaFromString);

        RAsignatura elemRAsig = collGetAt<RAsignatura>(collRAsigs,pos,rAsignaturaFromString);

        elemRAsig.estad.cont++;
        elemRAsig.estad.acum+=elemCalif.calif;

        collSetAt<RAsignatura>(collRAsigs,elemRAsig,pos,rAsignaturaToString);

        elemCalif = read<Calificacion>(f);
    }
    
    mostrarResultados(collRAsigs);

    actualizar(collRAsigs);

    fclose(f);

    return 0;
}

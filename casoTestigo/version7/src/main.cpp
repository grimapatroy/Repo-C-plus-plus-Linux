#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// Se pide mostrar un listado indicando, por cada asignatura, 
// el maestro a cargo, y la lista de estudiantes cuya calificación 
// es inferior a 4 (cuatro).

// Asignatura   Maestro         Estudiantes aplazados
// Arte         Juan            2, 6, 9, 10, 15
// Geografía    Pedro           1, 2, 8, 14
// Historia     Juan            3, 5, 6, 10, 17, 23
// Matemáticas  Marta           2, 4, 5, 14, 15, 16, 19, 21, 23
// : :               :                       :



int main()
{   
    Coll<RAsignatura> collRAsignaturas = subirAsignaturas();
    
    FILE* f = fopen("CALIFICACIONES_v07.dat","r+b");

    Calificacion elemCalif = read<Calificacion>(f);
    
    while (!feof(f))
    {
        procesarCalificacion(elemCalif,collRAsignaturas);
        
        elemCalif = read<Calificacion>(f);
    }
    
    mostarResultados(collRAsignaturas);

    fclose(f);


    return 0;
}


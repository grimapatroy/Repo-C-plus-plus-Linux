#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// Se dispone del archivo CALIFICACIONES.dat, cuya estructura recordamos a continuación, ordenado por idAsig.
// Se pide informar, por cada asignatura, la lista de
// estudiantes aprobados (calif>=4), ordenada decrecientemente por calificación.

int main()
{

    FILE *f = fopen("CALIFICACIONES_v02.dat", "r+b");

    // leemos el primer registro del archivo
    Calificacion resgistro = read<Calificacion>(f);

    // hasta que no llege al final del archivo
    while (!feof(f))
    {
        // SECCON DE INICIALIZACION
        Coll<Calificacion> buff = coll<Calificacion>();
        // guardamos el registro anterior
        int idAsigAnt = resgistro.idAsig;
        while (!feof(f) && idAsigAnt == resgistro.idAsig)
        {
            // SECCION DE PROCESAMIENTO
            if (resgistro.calif >= 4)
            {
                collAdd<Calificacion>(buff,resgistro,calificacionToString);
            }
            resgistro = read<Calificacion>(f);
        }
        // RESULTADOS
        mostrarEstudiantesAprobados(idAsigAnt,buff);
    }


    fclose(f);

    return 0;
}

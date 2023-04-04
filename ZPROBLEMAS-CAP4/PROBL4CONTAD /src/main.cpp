#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/negocio/Cursos.hpp"
#include "../include/tads/negocio/AlumnosRechazados.hpp"
#include "../include/tads/negocio/Reasignaciones.hpp"
#include "../include/tads/negocio/Revisicones.hpp"
#include "../include/tads/negocio/Inscripciones.hpp"
#include "../include/funciones/fmain.hpp"


using namespace std;

// Inscripción en la facultad (4 y 5)



int main()
{
    FILE* fArchivoIns = fopen("INSCRIPCIONES.dat","r+b");

    Inscripcion  regInsc = inscripcionLeer(fArchivoIns);
    Cursos cCurso = cursosSubirConsultas();
    AlumnosRechazados alumRecha = alumnosRechazadosCreate();
    Reasignaciones cReasig = reasignacionesCreate(); 
    Reviciones cRevision = revicionesCreate();

    while (!feof(fArchivoIns))
    {
        procesarInscripcionesYCursosRechazados(cCurso,regInsc,alumRecha);
        regInsc = inscripcionLeer(fArchivoIns);
    }
    procesarReasignaciones(cReasig,alumRecha,cCurso);
    // procesarReviciones(cReasig,alumRecha,cCurso,cRevision);
    // reasignacionesWrite(cReasig);
    // revisionesWrite(cRevision);

    fclose(fArchivoIns);

    return 0;
}


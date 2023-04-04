#ifndef _FMAIN
#define _FMAIN
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../tads/negocio/AlumnosRechazados.hpp"
#include "../tads/negocio/Cursos.hpp"
#include "../tads/negocio/Reasignaciones.hpp"
#include "../tads/negocio/Revisicones.hpp"
#include "../tads/negocio/Inscripciones.hpp"


void procesarInscripcionesYCursosRechazados(Cursos& cCurso,Inscripcion& regInsc,AlumnosRechazados& alumRecha){
    Curso cur = cursosActualizarCapacidad(cCurso.c,regInsc.idCur);
    if (!isCursosCapacidad(cur))
    {
        alumnosRechazadosActualizar(alumRecha,cur.materia,regInsc.idAlu);
    }
}

void  procesarReasignaciones(Reasignaciones& cReasig,AlumnosRechazados alumRecha,    Cursos cCurso){
    for (int posAlum = 0; posAlum <alumnosRechazadosSize(alumRecha.c); posAlum++)
    {
        AlumnoRechasoInsc alumnitoX =  AlumnoRechasoInscObtener(alumRecha.c,posAlum);
        bool libre ;
        Curso cursito = cursosBucarCapacidadLibre(cCurso.c,libre);
        while (!libre)
        {
            reasignacionBuscarYOAgregar(cReasig.c,cursito.idCur,alumnitoX.idAlumno);
            Curso cursito = cursosBucarCapacidadLibre(cCurso.c,libre);
        }
    }
}






#endif
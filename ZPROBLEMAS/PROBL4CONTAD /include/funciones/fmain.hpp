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


void procesarInscripcionesYCursosRechazados(Cursos& cCurso,Inscripcion regInsc,AlumnosRechazados& alumRecha){
    
    int pos = cursosBuscar(cCurso.c,regInsc.idCur);
    // Curso cur = collGetAt<Curso>(cCurso.c,pos,)
    Curso cur = cursosObtener(cCurso.c,pos);
    cursosActualizarInscripcionesCapacidad(cur,regInsc);
    if (isCursosCapacidad(cur))
    {
        alumnosRechazadosActualizar(alumRecha,cur,regInsc.idAlu);
    }
    
}

#endif
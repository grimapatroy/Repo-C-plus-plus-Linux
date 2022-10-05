#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

// CONTANTES
// #define ERR_ESTINEXIST 1; //error tipo1
// #define ERR_ESCUELADIF 2;//error tipo2
// #define ERR_FECHAANT 3;//error tipo3

using namespace std;




// Este archivo se encuentra ordenado por idEst y el archivo de consultas PADRON es muy graden paratenerlo en memoria
// Se pide generar el archivo INCONSISTENCIAS.dat con aquellas inscripcio-
// nes que resultan ser inconsistentes. Detallando el tipo de problema (1, 2 o 3), el
// nombre del estudiante involucrado, y el identificador de la escuela (idEscuela).
// Tipos de problema:
// 1. El estudiantes no figuran en el padrón (tipo de problema: 1).
// 2. El estudiante figura matriculado en una escuela diferente a la que se inscribió
// (tipo de problema: 2).
// 3. La fecha de inscripción es anterior a la de matriculación (tipo de problema 3).



int main()
{   
    FILE* archPadron = fopen("PADRON_v11.dat","r+b");
    FILE* archInsc= fopen("INSCRIPCIONES_v11.dat","r+b");
    FILE* archOut= fopen("INCONSISTENCIAS.dat","w+b");

    Inscripcion regInscrip = read<Inscripcion>(archInsc);
    while (!feof(archInsc))
    {
        // iniciamos , buscamos el registro
        bool enc;
        Padron regPadron = buscarPadron(archPadron,regInscrip.idEst,enc);

        // procesamos el registro
        procesarIncripcion(regPadron,enc,archOut,regInscrip);

        // leemos el siguiente registro
        regInscrip = read<Inscripcion>(archInsc);
    }
    

    fclose(archPadron);
    fclose(archInsc);
    fclose(archOut);
    return 0;
}


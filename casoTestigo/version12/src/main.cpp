#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

using namespace std;






int main()
{   

    FILE* archInscrip = fopen("INSCRIPCIONES_v12.dat","r+b");
    FILE* archPadron = fopen("PADRON_v12.dat","r+b");
    FILE* archOut = fopen("INCONSISTENCIA.dat","w+b");

    // creamos la coleccion  para indexar
    Coll<int> idx = idxCrear(archPadron);

    // leemos el primer registro
    Inscripcion regINscrip = read<Inscripcion>(archInscrip);

    while (!feof(archInscrip))
    {
        bool enc;
        
        // buscamos el padron , y asignamos true o false a enc si encuentra
        Padron regPradon = buscarEstudiante(archPadron,regINscrip.idEst,enc,idx);

        // procesamos el registro
        procesarIncripcion(regPradon,enc,archOut,regINscrip);

        // leemos el sgt registro
        regINscrip = read<Inscripcion>(archInscrip);

    }
    
    // cerramos los archivos
    fclose(archInscrip);
    fclose(archPadron);
    fclose(archOut);
    
    return 0;
}


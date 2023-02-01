#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

using namespace std;

// Torneo de fútbol (4 y 5)


int main()
{
    FILE* archivoResul = fopen("RESULTADOS.dat","r+b");
    Resultado r = resultadoLeer(archivoResul);

    Equipos eqs = equiposCreate();
    Estadios estads = estadiosCreate();


    while (!feof(archivoResul))
    {
        if (r.codRes<0)
        {
                // gano equ1
            equiposGanador(r.idEq1,eqs);
            estadiosJugados(estads,r);
        }
        else
        {
            if (r.codRes>0)
            {
                // gano eq2
                equiposGanador(r.idEq2,eqs);
                estadiosJugados(estads,r);
            }
            else
            {
                // empate
                equiposEmpate(r.idEq1,r.idEq2,eqs);
                estadiosEmpate(r,estads);
                // estadiosJugados(eqs);
            }
        }
        // falta descubrir los estadios donde se jugo 
        r = resultadoLeer(archivoResul);
    }

    equiposMostrarPoscisiones(eqs);
    estadiosImprimir(estads);    
    // equiposArchivoNuevosPuntos(eqs);    

    fclose(archivoResul);

    return 0;
}


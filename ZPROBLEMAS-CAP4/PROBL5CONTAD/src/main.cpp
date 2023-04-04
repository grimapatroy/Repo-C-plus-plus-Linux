#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/Coll.hpp"
#include "../include/funciones/fmain.hpp"
#include "../include/tads/negocio/Resultado.hpp"


using namespace std;

// Streaming de música (4 y 5)

int main()
{
    FILE* fReproducion = fopen("REPRODUCCIONES.dat","r+b");
    FILE* fAlbum = fopen("ALBUNES.dat","r+b");
    Reproduccion r = reproduccionLeer(fReproducion);
    Resultados cresults = resultadosCreate();
    Coll<int> conteo = conteoInit();

    while (reproduccionSiguiente(fReproducion))
    {    
        int albumAnterior = r.idAlbum;
        Album alb =  albumBuscar(r.idAlbum,fAlbum);
        while (reproduccionSiguiente(fReproducion) && albumAnterior == r.idAlbum)
        {
            calcularYValidarDuracion(r.minutos,conteo,alb.duracion);
            r = reproduccionLeer(fReproducion);
        }
        resultadosProcesar(r,alb,cresults,conteo);
    }
    // ResultadosImprimir(cresults);

    fclose(fReproducion);
    fclose(fAlbum);

    return 0;
}


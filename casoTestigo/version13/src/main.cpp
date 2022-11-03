#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

using namespace std;



// el archivo Padron.dat esta desordenado , aprte nos piden mostrar un listado por mostrando sus datos por codigo postal

// solucion: aplicamos indexacion indirecta , luego ordenamos la coleccion y aplicamos corte de control por codigo

int main()
{
    FILE* archPadron = fopen("PADRON_v13.dat","r+b");

    // creamos la coleccion Indixes ordenada
    Coll<Idx> collIdx = crearIndexacion(archPadron);

    // obtengo el primer elemento y empiezo a iterar hasta que no llege al final(enc);
    bool enc ;
    Idx i = collNext<Idx>(collIdx,enc,idxFromString);

    while (!enc)
    {
        // mostramos el codigo postal
        cout<<"CODIGO POSTAL: "<<i.codigoPostal;

        // aplicamos corte de control
            // variable de control
            int codigoPostalAnt = i.codigoPostal;
            while (!enc && codigoPostalAnt ==i.codigoPostal)
            {
                // leo el registro en la posicion pos
                Padron p = leerPadron(archPadron,i.pos);

                // muestro los datos de registro
                cout<<padronToDebug(p)<<endl;

                // leo el siguiente elemento de la coleccion indexada
                i = collNext<Idx>(collIdx,enc,idxFromString);
            }
    }
    fclose(archPadron);

    return 0;
}


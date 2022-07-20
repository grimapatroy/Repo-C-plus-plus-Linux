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

    FILE* f = fopen("ABONADOS.dat","r+b");
    Coll<AbonadoIdx> collIdx = indexarAbonados(f);

    // ordeno la coleccion de menor a mayor ascendente
    collSort<AbonadoIdx>(collIdx,cmpAbonadoId,abonadoIdxFromString,abonadoIdxToString);

    collReset<AbonadoIdx>(collIdx);
    while (collHasNext<AbonadoIdx>(collIdx))
    {
        AbonadoIdx idx = collNext<AbonadoIdx>(collIdx,abonadoIdxFromString);

        // me voy al archivo a obtener cada elemneto para mostralo
            // muevo el indicador de posicion del archivo, donde esta la pos de su idx
            seek<Abonado>(f,idx.pos);
            Abonado a = read<Abonado>(f);
            cout<< abonadoToDebug(a)<<endl;
    }
    
    fclose(f);

    return 0;
}

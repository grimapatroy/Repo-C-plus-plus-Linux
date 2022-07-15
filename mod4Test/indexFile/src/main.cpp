#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// ----funciones para el testToll---
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
// #include "../funciones/files.hpp"

using namespace std;






int main()
{   

    FILE* f = fopen("ABONADOS.dat","r+b");
    Coll<AbonadoIdx> collIdx = indexarAbonados(f);
    int id = 7;
    bool  encontrado;
    
    Abonado a = buscarAbonado(collIdx,f,id,encontrado);

    if (encontrado)
    {
        cout<<"EL ABONADO BUSCADO ES: "<<abonadoToDebug(a)<<endl;
    }
    

    
    fclose(f);


    return 0;
}

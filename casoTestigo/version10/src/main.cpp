#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;


// Podrían existir asignaturas que sólo se dictaron en 2019, otras que comen-
// zaron a dictarse en 2020, y otras que se dictaron ambos años.
// Se pide:
    // 1. Para las asignaturas que sólo se dictaron en 2019, indicar cuál fue la
    // mejor, y cuál la peor calificación promedio lograda por una comisión.

    // 2. Para las asignaturas que sólo se dictaron durante 2020, indicar la
    // calificación promedio general (promedio de los promedios de las comisiones).
    
    // 3. Para las asignaturas que se dictaron ambos años, un listado indicando la ca-
    // lificación promedio 2020, y en qué proporción aumentó o disminuyó este va-
    // lor respecto a 2019.


int main()
{   
    
    Coll<Lst1> collLista2019 = coll<Lst1>();
    Coll<Lst2> collLista2020 = coll<Lst2>();
    Coll<LstA> collListaAmbas = coll<LstA>();

    FILE* arch19 = fopen("RENDI19_v10.dat","r+b");
    FILE* arch20 = fopen("RENDI20_v10.dat","r+b");


    Rendi regRend19 = read<Rendi>(arch19);
    Rendi regRend20 = read<Rendi>(arch20);

// aplicamos apareo de archivos
        while (!feof(arch19) && !feof(arch20))
        {
            if (regRend19.idAsig<regRend20.idAsig)
            {
                procesar1(regRend19,arch19,collLista2019);
            }
            else
            {
                if (regRend19.idAsig>regRend20.idAsig)
                {
                    procesar2(regRend20,arch20,collLista2020);
                }
                else
                {
                    procesar3(regRend19,regRend20,arch19,arch20,collListaAmbas);
                }
            }
            regRend19 = read<Rendi>(arch19);
            regRend20 = read<Rendi>(arch20);
        }
    
        while (!feof(arch19))
        {
            procesar1(regRend19,arch19,collLista2019);
        }
        
        while (!feof(arch20))
        {
            procesar2(regRend20,arch20,collLista2020);
        }
        // aqui acaba el corte de control
    
    //mostramos resltados
        mostrarResultados(collLista2019);
        mostrarResultados(collLista2020);
        mostrarResultados(collListaAmbas);


    fclose(arch19);
    fclose(arch20);

    return 0;
}


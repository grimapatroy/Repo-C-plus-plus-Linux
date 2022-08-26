#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;


// Se dispone de los archivo ASIGNATURAS19.dat y ASIGNATURAS20.dat, ambos
// con el mismo formato de registro, describiendo respectivamente las asignaturas y sus
// calificaciones promedio durante los años 2019 y 2020. Los dos archivos se encuen-
// tran ordenados por idAsig.
// struct Asignatura{ 
//     int idAsig;
//     char nomAsig[30];
//     char maestroACargo[50];
//     double califProm; }

// Se pide : asdemas todos deben estar ordenados alfabeticamente por nomAsig
    // 1. Un listado de las asignaturas que sólo se dictaron en 2019.
    // 2. Un listado de las asignaturas que comenzaron a dictarse en 2020.
    // 3. Un listado de las asignaturas que se dictaron durante ambos años, pero estuvieron a cargo de diferentes maestros.


int main()
{   
    Coll<Asignatura> collAsig19 = coll<Asignatura>();
    Coll<Asignatura> collAsig20 = coll<Asignatura>();
    Coll<Asignatura> coll19Y20 = coll<Asignatura>();

    FILE* archivo2019 = fopen("ASIGNATURAS19_v09.dat","r+b");
    FILE* archivo2020 = fopen("ASIGNATURAS20_v09.dat","r+b");

    Asignatura elemAsig2019 = read<Asignatura>(archivo2019);
    Asignatura elemAsig2020 = read<Asignatura>(archivo2020);

    while (!feof(archivo2019)  && !feof(archivo2020))
    {
        if (elemAsig2019.idAsig<elemAsig2020.idAsig)
        {
            collAdd<Asignatura>(collAsig19,elemAsig2019,asignaturaToString);
            elemAsig2019 = read<Asignatura>(archivo2019);
        }
        else
        {
            if (elemAsig2019.idAsig>elemAsig2020.idAsig)
            {
                collAdd<Asignatura>(collAsig20,elemAsig2020,asignaturaToString);
                elemAsig2020 = read<Asignatura>(archivo2020);
            }
            else
            {
                procesarPunto3(elemAsig2019 ,elemAsig2020,coll19Y20);
                elemAsig2019 = read<Asignatura>(archivo2019);
                elemAsig2020 = read<Asignatura>(archivo2020);
            }
        }
    }
    
        
    while (!feof(archivo2019))
    {
        collAdd<Asignatura>(collAsig19,elemAsig2019,asignaturaToString);
        read<Asignatura>(archivo2019);
    }
    
    while (!feof(archivo2020))
    {
        collAdd<Asignatura>(collAsig20,elemAsig2020,asignaturaToString);
        read<Asignatura>(archivo2020);
    }

    mostrarResultados("Solo en el 2019 ",collAsig19);
    mostrarResultados("Comenzo en el 2020 ",collAsig20);
    mostrarResultados("Ambos, diferentes maestros",coll19Y20);


    fclose(archivo2019);
    fclose(archivo2020);

    return 0;
}


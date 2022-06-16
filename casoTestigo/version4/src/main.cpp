#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// Se pide: emitir dos listados, ambos detallando la calificación promedio obtenida por los estudiantes de cada asignatura. 
// El primero debe estar ordenado alfabéticamente por asignatura (nomAsig), tal como se muestra a la izquierda. El segundo
// listado debe estar ordenado decrecientemente según la calificación promedio, tal
// como se ilustra a la derecha.
// Asignatura      Promedio   |    Asignatura    Promedio                                                             
// Arte            7.88       |      Historia      8.23                                  
// Geografía       6.09       |      Arte          7.88                            
// Historia        8.23       |      Matemáticas   7.34                                                               
// Matemáticas     7.34       |      Geografía     6.09                                                                  
//     :              :       |           :            :

// CALIFICACIONES                      ASIGNATUAS
//                                |     struct Asignatura         
// struct Calificacion            |     {
// {                              |     int idAsig;   
// int idAsig;                    |     char nomAsig[30];
// int idEst;                     |     char maestroACargo[50];
// int calif;                     |     };
// };                              

int main()
{
    // subir el archivo de consultas a memoria
    Coll<RAsignatura> collAsig = subirAsignaturas();
    
    FILE* f = fopen("CALIFICACIONES_v04.dat", "r+b");

    // leo el primer registro del archivo
    Calificacion registro = read<Calificacion>(f);

    while (!feof(f))
    {
        // buscamos la asignatura en la coleccion
        int pos = collFind<RAsignatura,int>(collAsig,registro.idAsig,cmpRAsigId,rAsignaturaFromString);
        // obtenemos el elemento encontrado atraves de pos
        RAsignatura elm =  collGetAt<RAsignatura>(collAsig,pos,rAsignaturaFromString);

        // PROCESAMOS
        elm.estad.cont++;
        elm.estad.acum+=registro.calif;

        // actualizamos los cambis en la coleccion
        collSetAt<RAsignatura>(collAsig,elm,pos,rAsignaturaToDebug);

        // leemos el siguiente registro
        registro = read<Calificacion>(f);
    }
    // mostramos el listado numero1(ordenado alfabeticamente)
    
    
    // mostramos el listado numero2(ordenado por prom descend)


    fclose(f);

    return 0;
}


















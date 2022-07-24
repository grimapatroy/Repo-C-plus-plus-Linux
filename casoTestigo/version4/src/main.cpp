#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// Se pide: emitir dos listados, ambos detallando la calificación promedio obtenida 
// por los estudiantes de cada asignatura. 
// El primero debe estar ordenado alfabéticamente
// por asignatura (nomAsig),tal como se muestra a la izquierda. 
// El segundo listado debe estar ordenado decrecientemente según 
// la calificación promedio, tal como se ilustra a la derecha.
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
    Coll<RAsignatura> collRAsig = subiraAsignaturas();

    FILE* f = fopen("CALIFICACIONES_v04.dat","r+b");

    Calificacion regCalificacion = read<Calificacion>(f);

    while (!feof(f))
    {
        int pos = collFind<RAsignatura,int>(collRAsig,regCalificacion.idAsig,cmpRAsigId,rAsignaturaFromString);

        RAsignatura rAsignatura = collGetAt<RAsignatura>(collRAsig,pos,rAsignaturaFromString);

        rAsignatura.estad.cont++;
        rAsignatura.estad.acum += regCalificacion.calif;

        collSetAt<RAsignatura>(collRAsig,rAsignatura,pos,rAsignaturaToString);

        regCalificacion = read<Calificacion>(f);

    }
    
    // mostrar listado numero 1
    cout<<"***ordenado alfabéticamente por asignatura (nomAsig)***"<<endl;
    mostarResultados(collRAsig,cmpRAsigAlfabetico);

    // mostrar listado numero 2
    cout<<"***ordenado descendentemente por promedio***"<<endl;
    mostarResultados(collRAsig,cmpRAsigPromedio);

    fclose(f);

    return 0;
}

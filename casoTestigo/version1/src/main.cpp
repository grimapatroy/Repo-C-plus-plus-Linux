#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;


//  Se pide informar: para cada asignatura,
// la calificación promedio obtenida por los estudiantes.

struct Calificacion
{
    int idAsig; //identificador de asignatura
    int idEst; // identificador del estudiante
    int calif; //calificacion obtenida durante el bimestre

};


int main()
{   

    FILE* f = fopen("CALIFICACIONES_v01.dat","r+b");
    Calificacion resgistro = read<Calificacion>(f);
    while (!feof(f))
    {
        int cont = 0;
        int acum = 0;
        int idAsigAnt = resgistro.idAsig; //variable de control para saber que el registro leido corresponde al subconjunto

        while (!feof(f) && idAsigAnt == resgistro.idAsig)
        {
            cont++; 
            acum += resgistro.calif;
            resgistro = read<Calificacion>(f);
        }
        // RESULTADOS
        double promedio = acum/(double)cont;
        cout<<"[ID ASIGNATURA: "<<idAsigAnt<<"\t"<<"\t"<<" "<<"PROMEDIO: "<<promedio<<"]"<<endl;
    }
    
    fclose(f);

    return 0;
}

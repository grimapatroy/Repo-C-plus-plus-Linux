#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/tads/Coll.hpp"
using namespace std;

struct Persona
{
    int dni;
    char nombre[10]; // array de caracteres
    double altura;
};

Persona personaCreate (int dni,string n,double a){

    Persona p;
    p.dni= dni;
    // asigna y convierte el contenido de n a p.nombre
    strcpy(p.nombre,n.c_str());
    p.altura = a;
    return p;
}


string personaToStringCon3Atrib(Persona p){
    string nombre = p.nombre; // laconversion de char[] y string es directa
    return intToString(p.dni)+","+ nombre + ","+ doubleToString(p.altura);
}





int main()
{   
    // Para registros de tipo aracteres y tipos primitivos
            // Para escribir en unarchivo
                // FILE* archi = fopen("archiApiFile.zz","w+b");
                // write<int>(archi,12345);
                // write<int>(archi,12345689);
                // write<int>(archi,98789222);
            // Para leer un archivo
                // FILE* archi=fopen("archiApiFile.zz","r+b");
                // int numerito = read<int>(archi);
                // while (!feof(archi))
                // {
                //     cout<<numerito<<endl;
                //     numerito = read<int>(archi);
                // }
            // Para mover el indicador de posicion
                // FILE* archi=fopen("archiApiFile.zz","r+b");
                // // apunto al tercer registro(comensando desde cero)
                // seek<int>(archi,2);
                // //leeo el registro apuntado 
                // int numerito = read<int>(archi);
                // // muestro el registro
                // cout<<numerito<<endl;
            // Para fileZise
                // FILE* archi=fopen("archiApiFile.zz","r+b");
                // cout<<fileSize<int>(archi)<<endl;
            // Para filePos
                //     FILE* archi=fopen("archiApiFile.zz","r+b");
                // // mostramos el archivo desde el final hasta el inicio
                // for( int i=fileSize<int>(archi)-1; i>=0; i-- )
                // {
                // seek<int>(archi,i);
                // // numero de registro apuntado por el indicador de posicion
                // int pos = filePos<int>(archi);
                // int s = read<int>(archi);
                // cout << "Registro Nro. " << pos << "," << s << endl;
                // }

    // Para registros de tipo persona
        // Para escribir un archivo
                // abro el archivo
            // FILE* archi = fopen("registroPersona.zz","w+b");

            // // Persona p = personaCreate(10,"juan",1.70);
            // Persona p1 = {10,"juan",1.70};
            // write<Persona>(archi,p1);

            // // p = personaCreate(20,"Pablo",1.80);
            // Persona p2 = {20,"Pablo",1.80};
            // write<Persona>(archi,p2);

            // // p = personaCreate(30,"Joseph",1.75);
            // Persona p3 = {30,"Joseph",1.69};
            // write<Persona>(archi,p3);

            // Persona p4 = {40,"Silvestre",1.75};
            // write<Persona>(archi,p4);

            // Persona p5 = {50,"Javivi",1.90};
            // write<Persona>(archi,p5);

        // Para LEER un archivo
            FILE* archi = fopen("registroPersona.zz","r+b");
            Persona p = read<Persona>(archi);
            while (!feof(archi))
            {
                cout<<personaToStringCon3Atrib(p)<<endl;
                p = read<Persona>(archi);
            }
        


    fclose(archi);
    return 0;
}
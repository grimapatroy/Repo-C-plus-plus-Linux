#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
using namespace std;


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
    

    fclose(archi);

    return 0;
}

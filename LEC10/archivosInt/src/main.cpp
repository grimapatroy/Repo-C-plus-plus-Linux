#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
using namespace std;

void fseekInt(FILE* arch, int nro){
    int byteInt = sizeof(int)*nro;
    fseek(arch,byteInt,SEEK_SET);
}

int longitudEnBytes (FILE* f){
    // guardo  indicador de  posicion actual
    int posActual = ftell(f);
    // me muevo al ultimo byte
    fseek(f,0,SEEK_END);
    // guardo indicador en el ultimo byte
    int nroUltimoByte = ftell(f);
    // me muevo a la posicion anterior que guarde
    fseek(f,posActual,SEEK_SET);
    return nroUltimoByte;
}

int longitudEnInts (FILE* f){

    return longitudEnBytes(f)/sizeof(int);
}


int main()
{   
    // ---------------------para escribir un archivo (write)-----------------------
    // // para escribir un archivo (write)
    // FILE* archivix = fopen("enteros.xx","w+b");

    // int numero = 1234;
    // fwrite(&numero,sizeof(int),1,archivix);

    // numero = 8907;
    // fwrite(&numero,sizeof(int),1,archivix);

    // numero = -2345;
    // fwrite(&numero,sizeof(int),1,archivix);

    // // // cierro el archivo
    // fclose(archivix);

// ----------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------
// Leo el archivo que eh generado c.xx
    // abro para lectura
    FILE* archivix=fopen("enteros.xx","r+b");
    int num;
    
            // leo el primer byte
            //     fread(&num,sizeof(int),1,archivix);


            // mientras no llegue el fin
            //     while( !feof(archivix) )
            //     {
            //         // caracterleido
            //         cout << num << endl;
                    
            //         // leo caracter
            //         fread(&num,sizeof(int),1,archivix);
            //     }
            
    // muevo al 4 byte ( se llama acceso directo)
    // fseek(archivix,8,SEEK_SET);

    // leo el 4 byte
    
    // fread(&num,sizeof(int),1,archivix);
    // cout<<int(num)<<endl;

    for (int i = 0; i < 3; i++)
    {
        fseekInt(archivix,i);
        fread(&num,sizeof(int),1,archivix);
        cout<<num<<endl;
    }
    
    // cout<<longitudEnInts(archivix)<<endl;


        // cierro el archivo
    fclose(archivix);
    return 0;
}

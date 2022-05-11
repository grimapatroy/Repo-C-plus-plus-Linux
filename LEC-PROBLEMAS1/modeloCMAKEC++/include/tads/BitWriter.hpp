#ifndef _TDA_BITWRITER
#define _TDA_BITWRITER

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

struct BitWriter
{
    FILE* arch; //archivo orignal 
    int BYTE; //1111 1111
};

int static cont=0;


BitWriter bitWriter(FILE* f){
    BitWriter bw;
    bw.arch = f;
    bw.BYTE = 0;
    return bw;
}

void bitWriterWrite(BitWriter bw,int bit){

           // modifica el marcado de posicion para que grabe desde el final     
        // fseek(bw.arch,1,SEEK_END);

        // grabar el bit que revibo si bien es un1 se supone que solo va  a venir un numero hasta 255
        fwrite(&bit,1,1,bw.arch);// la variabe que voy a grabar(direccion de memoria),cuantos  byte voy a grabar , cuantos bloques voy a grabar,el archivo

        cont++;
}

void bitWriterFlush(BitWriter bw){
    int posActual = ftell(bw.arch);
    if(posActual%8!=0)
    {
        fseek(bw.arch,1,SEEK_END);
        int resto = 8-posActual ;
        for (int i = 1; i < resto; i++)
        {
            int bit=0;
            fwrite(&bit,1,1,bw.arch);
        }
    
    } 
}
// fseek(archivo,pesoEnByte,constante"SEEK_SET,SEEK_END,SEEK-CUR")
// ftell(archivo)
// fwrite(&variable,pesoByte,bloquesByte,archivo)
//  fread(&variable,pesoByte,bloquesByte,archivo)

#endif

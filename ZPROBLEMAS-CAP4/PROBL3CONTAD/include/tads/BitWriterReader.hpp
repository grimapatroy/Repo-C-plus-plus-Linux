#ifndef _TDA_BITWRITER
#define _TDA_BITWRITER

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;
int static cont=0;


struct BitWriter
{
    FILE* arch; //archivo orignal 
    int BYTE; //1111 1111
};

struct BitReader
{
    // char BYTE[8];
    // FILE* arch; //archivo orignal 
    // unsigned char BYTE; //00000000
    FILE* arch; //archivo orignal 
    char unsigned BYTE; //1111 1111

};


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


BitReader bitReader(FILE* f){
    BitReader br;
    // // br.BYTE>>3 = 0;
    // // br.arch = fopen("archivo.dat","w+b") ;
    br.arch = f;
    br.BYTE = 0;
    return br;
}

int bitReaderRead(BitReader br){
    // int a = 0;
    fread(&br.BYTE,1,1,br.arch);
    return br.BYTE;
}




#endif

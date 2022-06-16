#ifndef _TDA_BITREADER
#define _TDA_BITREADER

#include <iostream>
#include <string.h>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

struct BitReader
{
    // char BYTE[8];
    // FILE* arch; //archivo orignal 
    // unsigned char BYTE; //00000000
    FILE* arch; //archivo orignal 
    char unsigned BYTE; //1111 1111

};

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

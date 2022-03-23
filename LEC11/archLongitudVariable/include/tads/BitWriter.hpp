#ifndef _TDA_BITWRITER
#define _TDA_BITWRITER

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

struct BitWriter
{
    // char bits[8];
    // char bit2;
    // char bit3;
    // char bit4;
    // char bit5;
    // char bit6;
    // char bit7;
    // char bit8;
    // int bit1;
    // int bit2;
    // int bit3;
    // int bit4;
    // int bit5;
    // int bit6;
    // int bit7;
    // int bit8;
    char bits;
};



BitWriter bitWriter(FILE* f){
    BitWriter byte = {255};
    fwrite(&byte,sizeof(BitWriter),1,f);
    // fseek(f,0,SEEK_END);
    return  byte;
}

void bitWriterWrite(BitWriter bw,int bit){
    // bw.bits[7]= bit;
    bw.bits>>7;

    // fwrite(&bw.bits,sizeof(BitWriter),1,);

}

#endif

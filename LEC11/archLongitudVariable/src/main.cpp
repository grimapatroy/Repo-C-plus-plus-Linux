#include <string.h>
#include <stdio.h>
#include "../include/funciones/strings.hpp"
#include "../include/funciones/tokens.hpp"
#include "../include/funciones/files.hpp"
#include "../include/tads/BitReader.hpp"
#include "../include/tads/BitWriter.hpp"
using namespace std;

typedef unsigned char uchar;
typedef unsigned short ushort;


struct  Fecha
{
    uchar dia;
    uchar mes;
    uchar anio;    
};



unsigned short permutarShort (unsigned short x){
    unsigned short parateUnBit = x>>8;
    unsigned short parteDosBit = x<<8;
    return parateUnBit|parteDosBit;
}

// unsigned short permutarShortMask (unsigned short x){
    
//     unsigned short mask1 = 65280;    //lo puedes representar en octal,hexa,decimal 11111111 00000000
//     unsigned short mask2 = 255;     // 00000000 11111111
//     unsigned short var = x; // x = 11101001100100
//     return mask1+mask2;
// }

// int readByte(FILE* f){
//     unsigned char bit; //lo utilizo como buffer
//     fread(&bit,1,1,f);
//     return bit;
// }

// int readInteger (FILE* f){
//     unsigned short bit; //lo utilizo como buffer
//     fread(&bit,2,1,f);
//     return permutarShort(bit);
// }



int readByte(FILE* f){
    return read<uchar>(f);
}

int readInteger (FILE* f){
    return permutarShort(read<ushort>(f));
}

string readString(FILE* f){
    string cadena="";
    // leo elprimer byte que es la longitud de la cadena
    int LongByte = readByte(f);
    if (LongByte>=0 and LongByte<255)
    {
        for (int i = LongByte ; 0<=i and i<255 and !feof(f); i--)
        {
            // leo un byte
            uchar byte = readByte(f);
            cadena += charToString(byte);
        }
    }
    else
    {
        // leo dos byte
        int LongByte = readInteger(f);
        for (int i = LongByte; i>=0 and !feof(f); i--)
        {
            // leo un byte
            uchar byte = readByte(f);
            cadena += charToString(byte);
        }
    }
    return cadena;
}

int readDate(FILE* f){

    return 1;
}

int main()
{   
    FILE* f = fopen("DEMO.dat","r+b");

    // int bit = readByte(f);
    // cout<<bit<<endl;

    // bit = readByte(f);
    // cout<<bit<<endl;

    // bit = readByte(f);
    // cout<<bit<<endl;

    cout<<"----[CONTENIDO DEL ARCHIVO]--------------------"<<endl;
    int i = readInteger(f);
    cout<<"Nro. de serie: "<<i<<endl;

    string ruta = readString(f);
    cout<<"Full filename: "<<ruta<<endl;
    fclose(f);
    
    
    cout<<"----[FIN CONTENIDO DEL ARCHIVO]-----------------"<<endl;
    return 0;
}

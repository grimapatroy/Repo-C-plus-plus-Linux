#include <string.h>
#include <stdio.h>
#include <filesystem>
#include <unistd.h>
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
    ushort dia;
    ushort mes;
    ushort anio;    
};

string fechaToString1 (Fecha f){
    
    return  intToString(f.anio)+"/"+intToString(f.mes)+"/"+intToString(f.dia);
}

// ---------------------------------------------------------------------------------------------
struct RegType
{
    ushort codigo;
    string descripcion;
};

// ---------------------------------------------------------------------------------------------

struct RegData
{
    ushort cantCampos;
    ushort bitPerdido; 
    ushort codigo;
    string campo;
};

// ---------------------------------------------------------------------------------------------
// ----------Funciones para leer-----------------------------------------------------------------------------------

unsigned short permutarShort (unsigned short x){
    unsigned short parateUnBit = x>>8;
    unsigned short parteDosBit = x<<8;
    return parateUnBit|parteDosBit;
}

int readByte(FILE* f){
    int x = ftell(f);
    return read<uchar>(f);
}

int readInteger (FILE* f){
    return permutarShort(read<ushort>(f));
}

string readString(FILE* f){
    string cadena="";
    // leo elprimer byte que es la longitud de la cadena
    int LongByte = readByte(f);
    if (LongByte>0 and LongByte<255)
    {
        for (int i = LongByte ; 0<i ; i--)
        {
            // leo un byte
            uchar byte = readByte(f);
            int p = ftell(f);
            cadena += charToString(byte);
        }
    }
    else
    {
        // leo dos byte
        int LongByte = readInteger(f);
        for (int i = LongByte; i>0 ; i--)
        {
            // leo un byte
            uchar byte = readByte(f);
            cadena += charToString(byte);
        }
    }
    return cadena;
}

Fecha readDate(FILE* f){
    Fecha fechita;
    // ago untratamientos de bits para decodificar el anio , mes y dia
        // tecnica mascara de bit
            // leo los dosbyte
            ushort date = readInteger(f);
            // convierto en unos solo la porcion de bits que quiero averiguar y lo represento en un sistema numerico(hexa)
            ushort maskDia = 0x1F ; //   0000000000011111 
            ushort maskMes = 0x1E0; //   0000000111100000
            ushort maskAnio = 0xFE00 ;// 1111111000000000

            // operacion logica and entre date y mask
            ushort resultDia = date&maskDia;
            ushort resultMes = date&maskMes;
            ushort resultAnio = date&maskAnio;

            // descodifico
            fechita.dia = resultDia;
            fechita.mes = resultMes>>5;
            ushort auxAnio = resultAnio>>9;
            fechita.anio = auxAnio>=100?1999-auxAnio+100:2000+auxAnio;

    // devuelvo un struc fecha
    return fechita;
}

RegType ReadRegType(FILE* f){
    RegType t;
    t.codigo = readByte(f);
    t.descripcion = readString(f);
    return t;
}

RegData ReadRegData (FILE* f){
    RegData rd;



    rd.codigo = readByte(f);
    rd.campo = readString(f);
    return rd;
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// -------------------------------ESCRIBIR ARCHIVOS---------------------------------------------


struct String
{
    uchar longPeque;
    ushort longGrande;
    string cadena;
};

String stringIniciar(){
    String st;

    return st;
}
// --------------------------Funciones para escribir-----------------------------------------------------------------

string getDirectory()
{
    char abs_path[1024];
    int cnt = readlink("/proc/self/exe", abs_path, 1024);// Obtener la ruta absoluta del programa ejecutable
    if(cnt < 0|| cnt >= 1024)
    {
        return NULL;
    }
    // El último '/' va seguido del nombre del programa ejecutable, elimine devel / lib / m100 / exe y solo conserve la primera parte de la ruta
    for(int i = cnt; i >= 0; --i)
    {
        if(abs_path[i]=='/')
        {
            abs_path[i + 1]='\0';
            break;
        }
    }
    string path(abs_path);
    return path;
}



void writeByte(FILE* f, uchar bit){
    write<ushort>(f,bit);
}

void writeInteger(FILE* f, ushort bit){
    write<ushort>(f,bit);
}


























int main()
{   
    // for (int z = 1; z < argc; z++)
    // {
    //     // string s = argv[z];


    //         FILE* f = fopen("DEMO.dat","r+b");
                FILE* f = fopen("AGENDA.dat","w+b");
                ushort nSerie;
                String arcivo;
                cout<<"Ingrese el numero de serie: ";
                cin>>nSerie;
                writeInteger(f,nSerie);
                
                string ruta = getDirectory()+"AGENDA.dat";
                int cantCaracter = length(ruta);
                if (cantCaracter>255)
                {
                    // dos dos byte y graba caracteres
                    ushort longByte = cantCaracter;

                }
                else
                {
                    // grabo un byte y graba caracteres
                    uchar longByte = cantCaracter;
                }
                


                fclose(f);


    //         // int bit = readByte(f);
    //         // cout<<bit<<endl;
    //         // bit = readByte(f);
    //         // cout<<bit<<endl;
    //         // bit = readByte(f);
    //         // cout<<bit<<endl;

    //         cout<<"----[CONTENIDO DEL ARCHIVO]--------------------"<<endl;
    //         int i = readInteger(f);
    //         cout<<"Nro. de serie: "<<i<<endl;

    //         string ruta = readString(f);
    //         cout<<"Full filename: "<<ruta<<endl;


    //         Fecha fech = readDate(f);
    //         cout<<"Fecha de ultimo acceso: "<<fechaToString1(fech)<<endl;
    //         int u = readInteger(f);
    //         cout<<"Cantidad de campos configurados: "<<u<<endl;

    //         for (int j = 0; j < u; j++)
    //         {
    //             int bitPerdido = readByte(f);
    //             RegType r = ReadRegType(f);
    //             cout<<"Campo [codigo: "<<r.codigo<<"]"<<", descripcion : "<<r.descripcion<<endl;    
    //         }
    //         u = readInteger(f);
    //         cout<<"Cantidad de Registros (contactos): "<<u<<endl;
    //         cout<<"--------------------------------------------"<<endl;
    //         // leo todos los registros
    //         for (int k = 0; k < u; k++)
    //         {
    //             int bitPerdida = readByte(f);
    //             RegData rd = ReadRegData(f);
    //                 switch (rd.codigo)
    //                 {
    //                 case 1:
    //                     cout<<"Nombre: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 case 2:
    //                     cout<<"Telefono: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 case 3:
    //                     cout<<"Direccion: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 case 4:
    //                     cout<<"Email: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 }
    //             for (int p = 0; p < rd.cantCampos-1; p++)
    //             {
    //                 // leo el siguiente bytePerdido , byteCodigo e stringCampo
    //                 rd.bitPerdido=readByte(f);
    //                 rd.codigo = readByte(f);
    //                 rd.campo = readString(f);
    //                 switch (rd.codigo)
    //                 {
    //                 case 1:
    //                     cout<<"Nombre: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 case 2:
    //                     cout<<"Telefono: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 case 3:
    //                     cout<<"Direccion: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 case 4:
    //                     cout<<"Email: ";
    //                     cout<<rd.campo<<endl;
    //                     break;
    //                 }
    //             }
    //         cout<<"--------------------------------------------"<<endl;
    //         }
    //         fclose(f);
    //         cout<<"----[FIN CONTENIDO DEL ARCHIVO]-----------------"<<endl;


    // }
    



    return 0;
}

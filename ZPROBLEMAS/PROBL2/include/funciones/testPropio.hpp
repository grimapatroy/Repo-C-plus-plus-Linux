#ifndef _FUNCIONES_TADS_
#define _FUNCIONES_TADS_


#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include "../tads/Coll.hpp"
#include "../include/funciones/files.hpp"
// ----------------------------------------------------------------
// ----------------------------------------------------------------
struct Persona
{
    int dni;
    string nombre;
};
// ------##########FUNCIONES DEL TAD Struct PERSONA##################-------------------------

Persona persona(int a ,string n){
    return {a,n};
}
// ---------------------------------------------------------
string personaToString(Persona p){
    // devuelve addToken
    return intToString(p.dni) + "," + p.nombre;
}

Persona personaFromString(string a){
    Persona p;
    p.dni=stringToInt(getTokenAt(a,',',0));// destokenizar a
    p.nombre=getTokenAt(a,',',1);// tokenizar a
    return p;
}
// ------################################################-------------------------
// ------##########FUNCIONES DEL TAD String##################-------------------------
// ----------------------------------------------------------------
string stringFromString(string cadena){
return cadena;
}



// ----------------------------------------------------------------
// -------------funciones de comparacion--------------------------------------------

int cmpPersonaNombre(Persona p1,Persona p2)
{
    return cmpString(p1.nombre,p2.nombre);
}

int cmpPersonaDNI(Persona p1,Persona p2)
{
    return p1.dni-p2.dni;
}

int cmpPersonasNomAsc(Persona p1,Persona p2)
{
    int i = p2.nombre<p1.nombre?-1:p2.nombre>p1.nombre?1:0;
    // int i =p1.nombre>p2.nombre?-1:p1.nombre<p2.nombre?1:0;
    // int i =p1.nombre<p2.nombre?1:p1.nombre<p2.nombre?-1:0;
    return i;
}

int cmpPersonasNomDesc(Persona p1,Persona p2)
{
    int i= p1.nombre<p2.nombre?-1:p1.nombre>p2.nombre?1:0;
    return i;
}

int cmpPersonasDNI(Persona p1,Persona p2)
{
return p1.dni-p2.dni;
}


// ----------------------------------------------------------------
// ascendente
int cmpInt (int a,int b){
    return b-a;
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------

// ------------------------funciones para coleccion de colecciones de tipo T----------------------------------
// TtoString

string collIntToString(Coll<int> x){
string r="";
collReset<int>(x);
while (collHasNext<int>(x))
{
    int i = collNext<int>(x,stringToInt);
    addToken(r,',',intToString(i));
}
return r;
}

// tFromString
Coll<int>  collIntFromString(string s){
Coll<int> x = coll<int>(',');  
for (int i = 0; i < tokenCount(s,','); i++)
{
    int token = stringToInt(getTokenAt(s,',',i));
    collAdd<int>(x,token,intToString);
}

return x;
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------


// Colecciones de estructuras que tienen colecciones
struct Conjunto
{
    string nombre;
    Coll<int>c;
};

// ----------------------------------------------------------------
// Funciones de Colecciones de estructuras que tienen colecciones


string conjuntoToString(Conjunto cjt){

string token=cjt.nombre+"#";
// collReset<int>(cjt.c);
// while (collHasNext<int>(cjt.c))
// {
// }
int size = collSize<int>(cjt.c);
for (int i = 0; i < size; i++)
{
    int subTokenInt = collGetAt<int>(cjt.c,i,stringToInt);
    token += intToString(subTokenInt)+(i<size-1?",":"");
}
return token;
}

Conjunto conjuntoFromString(string token){
Conjunto c;

c.nombre = getTokenAt(token,'#',0);

c.c = coll<int>(',');
string x = getTokenAt(token,'#',1);
for (int i = 0; i < tokenCount(x,','); i++)
{
    int subTokenInt = stringToInt(getTokenAt(x,',',i));
    collAdd<int>(c.c,subTokenInt,intToString);
}
return c;
}

void mostrarColeccion(Coll<Persona> c) 
{ 
collReset<Persona>(c); 
while( collHasNext<Persona>(c))
{
    Persona p = collNext<Persona>(c,personaFromString);
    cout<<personaToString(p)<<endl;
}
} 

// -----------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------TAD  de struct que encapsulan otras variables nativas ysin byte de signo alveces----------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------------------------

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

RegType regType (ushort cod, string desp){
    // RegType rt;
    // rt.codigo = cod;
    // rt.descripcion = desp;
    return{cod,desp};
    // return rt;
}

// ---------------------------------------------------------------------------------------------
struct RegRegistro
{
    ushort codigo;
    string campo;
};

struct RegData
{
    ushort cantCampos;
    ushort bitPerdido; 
    ushort codigo;
    string campo;
};

struct RegData2
{
    ushort cantCampos;
    // ushort bitPerdido; 
    Coll<RegRegistro>  registro;
};



// RegData regData(){
//     RegData reg;

//     return reg;
// }

RegRegistro regRegistroFromString (string token ){
    RegRegistro rg;
    int pos = indexOf(token,'-');
    rg.codigo = stringToInt(getTokenAt(token,'-',0));
    rg.campo = substring(token,pos+1,length(token));
    return rg;
}

string regRegistroToString (RegRegistro rg)
{
    return intToString(rg.codigo)+"-"+rg.campo;
}

string regData2ToString (RegData2 rd2){
    string s = intToString(rd2.cantCampos)+"#";
    // rd2.registro = coll<RegRegistro>(',');
    int zise = collSize<RegRegistro>(rd2.registro);
    for (int i = 0; i <zise; i++)
    {
        RegRegistro rr=collGetAt<RegRegistro>(rd2.registro,i,regRegistroFromString);
        s+=intToString(rr.codigo)+"-"+rr.campo+(i<zise-1?",":"");
    }

    return s;
}

RegData2 regData2FromString (string token){
    RegData2 rd2;
    rd2.cantCampos = stringToInt(getTokenAt(token,'#',0));
    rd2.registro = coll<RegRegistro>(',');
    int pos = indexOf(token,'#');
    string registros = substring(token,pos+1);
    for (int i = 0; i < tokenCount(registros,','); i++)
    {
        RegRegistro rg;
        string tokenRegistro= getTokenAt(registros,',',i);
        int x = indexOf(token,'-');
        rg.codigo = stringToInt(getTokenAt(token,'-',0));
        rg.campo = substring(token,x+1);
        // agrego elemnetos a la coleccion
        collAdd<RegRegistro>(rd2.registro,rg,regRegistroToString);
    }
    return rd2;
}

// ---------------------------------------------------------------------------------------------
// ----------Funciones para leer-----------------------------------------------------------------------------------

unsigned short permutarShort (unsigned short x){
    ushort parateUnBit = x>>8;
    ushort parteDosBit = x<<8;
    ushort resul = parateUnBit|parteDosBit;
    return resul;
}

int readByte(FILE* f){
    int x = ftell(f);
    return read<uchar>(f);
}

int readInteger (FILE* f){
    return permutarShort(read<ushort>(f));
}

int readInteger2 (FILE* f){
    return read<ushort>(f);
}

string readString2(FILE* f){
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

// string readString(FILE* f){
//     string cadena="";
//     // leo elprimer byte que es la longitud de la cadena
//     int LongByte = readByte(f);
//     if (LongByte>0 and LongByte<255)
//     {
//         for (int i = LongByte ; 0<i ; i--)
//         {
//             // leo un byte
//             uchar byte = readByte(f);
//             int p = ftell(f);
//             cadena += charToString(byte);
//         }
//     }
//     else
//     {
//         // leo dos byte
//         int LongByte = readInteger(f);
//         for (int i = LongByte; i>0 ; i--)
//         {
//             // leo un byte
//             uchar byte = readByte(f);
//             cadena += charToString(byte);
//         }
//     }
//     return cadena;
// }

// Fecha readDate(FILE* f){
//     Fecha fechita;
//     // ago untratamientos de bits para decodificar el anio , mes y dia
//         // tecnica mascara de bit
//             // leo los dosbyte
//             ushort date = readInteger(f);
//             // convierto en unos solo la porcion de bits que quiero averiguar y lo represento en un sistema numerico(hexa)
//             ushort maskDia = 0x1F ; //   0000000000011111 
//             ushort maskMes = 0x1E0; //   0000000111100000
//             ushort maskAnio = 0xFE00 ;// 1111111000000000
//             // operacion logica and entre date y mask
//             ushort resultDia = date&maskDia;
//             ushort resultMes = date&maskMes;
//             ushort resultAnio = date&maskAnio;
//             // descodifico
//             fechita.dia = resultDia;
//             fechita.mes = resultMes>>5;
//             ushort auxAnio = resultAnio>>9;
//             fechita.anio = auxAnio>=100?1999-auxAnio+100:2000+auxAnio;
//     // devuelvo un struc fecha
//     return fechita;
// }

Fecha readDate2(FILE* f){
    Fecha fechita;
    // ago untratamientos de bits para decodificar el anio , mes y dia
        // tecnica mascara de bit
            // leo los dosbyte
            ushort date = readInteger2(f);
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

// RegType ReadRegType(FILE* f){
//     RegType t;
//     t.codigo = readByte(f);
//     t.descripcion = readString2(f);
//     return t;
// }

RegType ReadRegType2(FILE* f){
    RegType t;
    t.codigo = readByte(f);
    // int bitPe = readByte(f);
    t.descripcion = readString2(f);
    return t;
}

// RegData ReadRegData (FILE* f){
//     RegData rd;
//     rd.codigo = readByte(f);
//     rd.campo = readString(f);
//     return rd;
// }

string  regDataToString (RegData rd){

    return "";
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

// String stringIniciar(){
//     String st;
//     return st;
// }

// --------------------------Funciones para escribir-----------------------------------------------------------------

string getDirectory()
{
    char abs_path[1024];
    // int cnt = readlink("/proc/self/exe", abs_path, 1024);// Obtener la ruta absoluta del programa ejecutable
    // if(cnt < 0|| cnt >= 1024)
    // {
    //     return NULL;
    // }
    // // El último '/' va seguido del nombre del programa ejecutable, elimine devel / lib / m100 / exe y solo conserve la primera parte de la ruta
    // for(int i = cnt; i >= 0; --i)
    // {
    //     if(abs_path[i]=='/')
    //     {
    //         abs_path[i + 1]='\0';
    //         break;
    //     }
    // }
    string path(abs_path);
    return path;
}



void writeByte(FILE* f, uchar bit){
    write<uchar>(f,bit);
}

void writeInteger(FILE* f, ushort bit){
    write<ushort>(f,bit);
}


void writeStringGrabar(FILE* f,string ruta ){
    
    for (int i = 0; i < length(ruta); i++)
    {
        write<uchar>(f,ruta[i]);
    }
    
}


void writeString(FILE* f,string cadena){
    int cantCaracter = length(cadena);
                if (cantCaracter>255)
                {
                    // dos dos byte y graba caracteres
                    ushort longByte = cantCaracter;
                    writeInteger(f,longByte);
                    writeStringGrabar(f,cadena);
                }
                else
                {
                    // grabo un byte y graba caracteres
                    uchar longByte = cantCaracter;
                    writeByte(f,longByte);
                    writeStringGrabar(f,cadena);
                }
}


// 2022/3/12
void writeFecha(FILE* f, Fecha fech){
    ushort fechita = 0;
    fechita = fechita|fech.dia;//0000000 0000 01100 
    ushort maskMes=fech.mes<<5;//0000000 0011 00000
    fechita = fechita|maskMes;// 0000000 0011 01100 

    ushort a;
    if (fech.anio>2000)
    {
        a=fech.anio-2000;
    }
    else
    {
        a=1999-fech.anio+100;
    }
    // 000000000 0010110
    ushort maskAnio=a<<9;//     0010110 0000 00000
    fechita=fechita|maskAnio;// 0000000 0011 01100 
    writeInteger(f,fechita);
}


void writeRegType(FILE* f, RegType rt){
    writeByte(f,rt.codigo);
    //  grabar el string
    writeString(f,rt.descripcion);
}

#endif
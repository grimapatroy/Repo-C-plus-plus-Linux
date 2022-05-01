#include <string.h>
#include <stdio.h>
#include <filesystem>
#include <unistd.h>
#include "../include/funciones/strings.hpp"
#include "../include/tads/Coll.hpp"
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

string regRegistroToString (RegRegistro rg)
{
    return intToString(rg.codigo)+","+rg.campo;
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

























int main()
{   
    // for (int z = 1; z < argc; z++)
    // {
    //     // string s = argv[z];


    //         FILE* f = fopen("DEMO.dat","r+b");
                FILE* f = fopen("AGENDA.dat","w+b");
                uchar bitPerdido = 0;
                int contPersonas=0;
                int campos = 0;
                // ingresar numero de serie y grabar
                ushort nSerie;
                cout<<"Ingrese el numero de serie: ";
                cin>>nSerie;
                writeInteger(f,nSerie);
                // // obtener ruta y grabar
                string ruta = getDirectory()+"AGENDA.dat";
                writeString(f,ruta);
                
                
                // // ingresar fecha y grabar
                Fecha fechita;
                cout<<"Ingrese Año: ";
                cin>>fechita.anio;
                cout<<"Ingrese Mes: ";
                cin>>fechita.mes;
                cout<<"Ingrese Dia: ";
                cin>>fechita.dia;
                writeFecha(f,fechita);
                // // Cantidad de campos configurados =4
                writeInteger(f,4);


                //grabo cada campo con su codigo y descripion
                // writeByte(f,bitPerdido);
                RegType rt;
                rt = regType(1,"Nombre");
                writeRegType(f,rt);
                rt=regType(2,"Telefono");
                writeRegType(f,rt);
                rt=regType(3,"Direccion");
                writeRegType(f,rt);
                rt=regType(4,"EMail");
                writeRegType(f,rt);

                // // descripcion de campos configurados  RegData2
                // Ingresar Registros y grabar
                    int opt=1;
                    int optCampos=1;
                    // writeByte(f,bitPerdido);
                    // RegData2 regd;
                    // creo una coleccion COLL TAD de ------------------regData(persona) 
                    Coll<RegData2> collectionRegData = coll<RegData2>();
                    // inicializo la colleccion de RegRegistros
                    RegData2 regd1= {0,coll<RegRegistro>(',')};
                    
                    ushort auxCodigito;
                    string auxCampito;

                    while (opt)
                    {
                        while (optCampos and campos<=4)
                        {
                            cout<<"Ingrese Codigo [1:Nombre][2:Telefono][4:Direccion][4:EMail]:";
                            cin>>auxCodigito;
                            switch (auxCodigito)
                                {
                                case 1:
                                    // cin>>regd.codigo;
                                    cout<<"INGRESE SU Nombre: ";
                                    cin>>auxCampito;
                                    break;
                                case 2:
                                    // cin>>regd.codigo;
                                    cout<<"INGRESE SU Telefono: ";
                                    cin>>auxCampito;
                                    break;
                                case 3:
                                    // cin>>regd.codigo;
                                    cout<<"INGRESE SU Direccion: ";
                                    cin>>auxCampito;
                                    break;
                                case 4:
                                    // cin>>regd.codigo;
                                    cout<<"INGRESE SU Email: ";
                                    cin>>auxCampito;
                                    break;
                                }
                                // validar para que no se repita campos
                            campos++;
                            RegRegistro rg ={auxCodigito,auxCampito};
                            // tokenizar y guardar cod , campo ( coll registro)
                            collAdd<RegRegistro>(regd1.registro,rg,regRegistroToString);
                            
                            // 1, descripsion,2,descripsion... 
                            cout<<"DESEA SEGUIR INGRESANDO CAMPOS? [1=SI][0=NO]: ";
                            cin>>optCampos;
                        }
                        // tengo que asignarle cantCampos(campos) , al objeto +id,clave
                        regd1.cantCampos=campos;
                        //agregar objetos a la coleccion     
                        collAdd<RegData2>(collectionRegData,regd1,regData2ToString);
                        contPersonas++;
                        cout<<"DESEA SEGUIR REGISTRANDO PERSONAS [1=SI][0=NO]: ";
                        cin>>opt;
                    }
                    int unicaVez=0;

                    // Recorrer y grabo la cantidad de registros de personas y uno por uno los datos de l  objetos de la coleccion los empiezo a sacar y grabar
                    for (int i = 0; i < collSize<RegData2>(collectionRegData); i++)
                    {
                        // objeto RegData
                        RegData2 regD = collGetAt<RegData2>(collectionRegData,i,regData2FromString);
                        if (unicaVez>=0 and unicaVez<1)
                        {
                            unicaVez++;
                            // grabo la cantidad de registros
                            writeByte(f,contPersonas);
                        }
                        // Grabamos la estructura regData
                            // grabamos el cantCampos completados
                            writeByte(f,regD.cantCampos);
                                    // recorro la collecion de RegRegistros 
                                for (int j = 0; j < collSize<RegRegistro>(regD.registro); j++)
                                {
                                    RegRegistro regRegis = collGetAt<RegRegistro>(regD.registro,j,regRegistroFromString);
                                    // grabo codigo y registro
                                    writeByte(f,regRegis.codigo);
                                    writeString(f,regRegis.campo);
                                }
                                
                    }
                    

// -----------------------------------------------------------------------------------

                seek<int>(f,0);
                // fseek(f,0,SEEK_SET);

                // probando el codigo leyendo 
                cout<<"----[CONTENIDO DEL ARCHIVO]--------------------"<<endl;
                int i = readInteger2(f);
                cout<<"Nro. de serie: "<<i<<endl;

                string rutita= readString2(f);
                cout<<"Full filename: "<<rutita<<endl;
                // i = readInteger(f);
                // cout<<i;

                Fecha fech = readDate2(f);
                cout<<"Fecha de ultimo acceso: "<<fechaToString1(fech)<<endl;
                int u = readInteger2(f);
                cout<<"Cantidad de campos configurados: "<<u<<endl;


                // // int bitPe = readByte(f);
                for (int j = 0; j < u; j++)
                {
                    RegType r = ReadRegType2(f);
                    cout<<"Campo [codigo: "<<r.codigo<<"]"<<", [descripcion : "<<r.descripcion<<"]"<<endl;    
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

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
#include "../include/tads/fReadWrite.hpp"
#include "../include/tads/BitWriter.hpp"
using namespace std;


typedef unsigned char uchar;
typedef unsigned short ushort;



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
                // ushort nSerie;
                // cout<<"Ingrese el numero de serie: ";
                // cin>>nSerie;
                // writeInteger(f,nSerie);
                // // // obtener ruta y grabar
                // string ruta = getDirectory()+"AGENDA.dat";
                // writeString(f,ruta);
                
                
                // // // ingresar fecha y grabar
                // Fecha fechita;
                // cout<<"Ingrese Año: ";
                // cin>>fechita.anio;
                // cout<<"Ingrese Mes: ";
                // cin>>fechita.mes;
                // cout<<"Ingrese Dia: ";
                // cin>>fechita.dia;
                // writeFecha(f,fechita);
                // // // Cantidad de campos configurados =4
                // writeInteger(f,4);


                // //grabo cada campo con su codigo y descripion
                // // writeByte(f,bitPerdido);
                // RegType rt;
                // rt = regType(1,"Nombre");
                // writeRegType(f,rt);
                // rt=regType(2,"Telefono");
                // writeRegType(f,rt);
                // rt=regType(3,"Direccion");
                // writeRegType(f,rt);
                // rt=regType(4,"EMail");
                // writeRegType(f,rt);

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
                        //agregar objetos a la coleccion  tokenizada   
                        collAdd<RegData2>(collectionRegData,regd1,regData2ToString);
                        contPersonas++;
                        cout<<"DESEA SEGUIR REGISTRANDO PERSONAS [1=SI][0=NO]: ";
                        cin>>opt;
                        if (opt)
                        {
                            campos=0;
                            optCampos=1;
                            regd1= {0,coll<RegRegistro>(',')};
                        }
                        
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

                // seek<int>(f,0);

                // // probando el codigo leyendo 
                // cout<<"----[CONTENIDO DEL ARCHIVO]--------------------"<<endl;
                // int i = readInteger2(f);
                // cout<<"Nro. de serie: "<<i<<endl;

                // string rutita= readString2(f);
                // cout<<"Full filename: "<<rutita<<endl;
                // // i = readInteger(f);
                // // cout<<i;

                // Fecha fech = readDate2(f);
                // cout<<"Fecha de ultimo acceso: "<<fechaToString1(fech)<<endl;
                // int u = readInteger2(f);
                // cout<<"Cantidad de campos configurados: "<<u<<endl;


                // // // int bitPe = readByte(f);
                // for (int j = 0; j < u; j++)
                // {
                //     RegType r = ReadRegType2(f);
                //     cout<<"Campo [codigo: "<<r.codigo<<"]"<<", [descripcion : "<<r.descripcion<<"]"<<endl;    
                // }

                
                fclose(f);


    //         // int bit = readByte(f);
    //         // cout<<bit<<endl;
    //         // bit = readByte(f);
    //         // cout<<bit<<endl;
    //         // bit = readByte(f);
    //         // cout<<bit<<endl;
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

#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include "../tads/Coll.hpp"
#include "../funciones/files.hpp"
#define ERR_ESTINEXIST 1; //error tipo1
#define ERR_ESCUELADIF 2;//error tipo2
#define ERR_FECHAANT 3;//error tipo3


using namespace std;

// string asignaturaToString(Asignatura x){
// 	string sNomAsig=x.nomAsig;
// 	string sMaestroACargo=x.maestroACargo;
// 	return intToString(x.idAsig)+','+ sNomAsig +','+ sMaestroACargo + ',' + doubleToString(x.califProm);
// }

// Asignatura asignaturaFromString(string s)
// {
// 	Asignatura x;
// 	x.idAsig = stringToInt(getTokenAt(s, ',', 0));
// 	string sNomAsig = getTokenAt(s, ',', 1);
// 	strcpy(x.nomAsig,sNomAsig.c_str());
// 	string t2= getTokenAt(s, ',', 2);
// 	strcpy(x.maestroACargo,t2.c_str());
// 	x.califProm = stringToDouble(getTokenAt(s, ',', 3));
// 	// x.idAsig = stringToInt(getTokenAt(s, ',', 2));
// 	return x;
// }

struct Padron
{
    int idEst;
    int dni;
    char nombre[20];
    char telefono[20];
    char direccion[20];
    int codigoPostal;
    int fechaNacimiento;
    int idEscuela;
    int fechaMatriculacion;
    int idSeguroSocial;
};

struct Idx
{
    int idEst;
    Coll<int> collPos;
};

string padronToString(Padron x)
{
    char sep = 1;
    string sIdEst=to_string(x.idEst);
    string sDni=to_string(x.dni);
    string sNombre=x.nombre;
    string sTelefono=x.telefono;
    string sDireccion=x.direccion;
    string sCodigoPostal=to_string(x.codigoPostal);
    string sFechaNacimiento=to_string(x.fechaNacimiento);
    string sIdEscuela=to_string(x.idEscuela);
    string sFechaMatriculacion=to_string(x.fechaMatriculacion);
    string sIdSeguroSocial=to_string(x.idSeguroSocial);
    return sIdEst+sep+sDni+sep+sNombre+sep+sTelefono+sep+sDireccion+sep+sCodigoPostal+sep+sFechaNacimiento+sep+sIdEscuela+sep+sFechaMatriculacion+sep+sIdSeguroSocial;
}

Padron padronFromString(string s)
{
    char sep = 1;
    Padron x;
    string t0 = getTokenAt(s,sep,0);
    x.idEst=stoi(t0);
    string t1 = getTokenAt(s,sep,1);
    x.dni=stoi(t1);
    string t2 = getTokenAt(s,sep,2);
    strcpy(x.nombre,t2.c_str());
    string t3 = getTokenAt(s,sep,3);
    strcpy(x.telefono,t3.c_str());
    string t4 = getTokenAt(s,sep,4);
    strcpy(x.direccion,t4.c_str());
    string t5 = getTokenAt(s,sep,5);
    x.codigoPostal=stoi(t5);
    string t6 = getTokenAt(s,sep,6);
    x.fechaNacimiento=stoi(t6);
    string t7 = getTokenAt(s,sep,7);
    x.idEscuela=stoi(t7);
    string t8 = getTokenAt(s,sep,8);
    x.fechaMatriculacion=stoi(t8);
    string t9 = getTokenAt(s,sep,9);
    x.idSeguroSocial=stoi(t9);
    return x;
}

string padronToDebug(Padron x)
{
    stringstream sout;
    sout<< "[";
    sout << x.idEst;
    sout << ",";
    sout << x.dni;
    sout << ",";
    sout << x.nombre;
    sout << ",";
    sout << x.telefono;
    sout << ",";
    sout << x.direccion;
    sout << ",";
    sout << x.codigoPostal;
    sout << ",";
    sout << x.fechaNacimiento;
    sout << ",";
    sout << x.idEscuela;
    sout << ",";
    sout << x.fechaMatriculacion;
    sout << ",";
    sout << x.idSeguroSocial;
    sout<< "]";
    return sout.str();
}

string padronToDebug(string mssg,Padron x)
{
    stringstream sout;
    sout<< mssg<<":[";
    sout << x.idEst;
    sout << ",";
    sout << x.dni;
    sout << ",";
    sout << x.nombre;
    sout << ",";
    sout << x.telefono;
    sout << ",";
    sout << x.direccion;
    sout << ",";
    sout << x.codigoPostal;
    sout << ",";
    sout << x.fechaNacimiento;
    sout << ",";
    sout << x.idEscuela;
    sout << ",";
    sout << x.fechaMatriculacion;
    sout << ",";
    sout << x.idSeguroSocial;
    sout<< "]";
    return sout.str();
}

Padron padron(int idEst,int dni,string nombre,string telefono,string direccion,int codigoPostal,int fechaNacimiento,int idEscuela,int fechaMatriculacion,int idSeguroSocial)
{
    Padron a;
    a.idEst = idEst;
    a.dni = dni;
    strcpy(a.nombre,nombre.c_str());
    strcpy(a.telefono,telefono.c_str());
    strcpy(a.direccion,direccion.c_str());
    a.codigoPostal = codigoPostal;
    a.fechaNacimiento = fechaNacimiento;
    a.idEscuela = idEscuela;
    a.fechaMatriculacion = fechaMatriculacion;
    a.idSeguroSocial = idSeguroSocial;
    return a;
}

bool padronEquals(Padron a,Padron b)
{
    if(a.idEst!=b.idEst) return false;
    if(a.dni!=b.dni) return false;
    if(a.codigoPostal!=b.codigoPostal) return false;
    if(a.fechaNacimiento!=b.fechaNacimiento) return false;
    if(a.idEscuela!=b.idEscuela) return false;
    if(a.fechaMatriculacion!=b.fechaMatriculacion) return false;
    if(a.idSeguroSocial!=b.idSeguroSocial) return false;
    return true;
}

string idxToString(Idx x)
{
    // char sep = 2;
    string sIdEst=to_string(x.idEst);
    string sCollPos=collToString<int>(x.collPos);
    return sIdEst+"*"+sCollPos;
}

Idx idxFromString(string s)
{
    // char sep = 2;
    Idx x;
    string t0 = getTokenAt(s,'*',0);
    x.idEst=stoi(t0);
    string t1 = getTokenAt(s,'*',1);
    x.collPos=collFromString<int>(t1);
    return x;
}
// Idx idxFromString(string s)
// {
//     char sep = 2;
//     Idx x;
//     string t0 = getTokenAt(s,sep,0);
//     x.idEst=stoi(t0);
//     string t1 = getTokenAt(s,sep,1);
//     x.collPos=collFromString<int>(t1);
//     return x;
// }




string idxToDebug(Idx x)
{
    stringstream sout;
    sout<< "[";
    sout << x.idEst;
    sout << ",";
    collReset<int>(x.collPos);
    int n=collSize<int>(x.collPos);
    sout << "{";
    for(int i=0; i<n; i++)
    {
        int q = collGetAt<int>(x.collPos,i,stringToInt);
        sout << intToString(q) << ((i<n-1)?",":"");
    }
    sout << "}";
    sout<< "]";
    return sout.str();
}

string idxToDebug(string mssg,Idx x)
{
    stringstream sout;
    sout<< mssg<<":[";
    sout << x.idEst;
    sout << ",";
    collReset<int>(x.collPos);
    int n=collSize<int>(x.collPos);
    sout << "{";
    for(int i=0; i<n; i++)
    {
        int q = collGetAt<int>(x.collPos,i,stringToInt);
        sout << intToString(q) << ((i<n-1)?",":"");
    }
    sout << "}";
    sout<< "]";
    return sout.str();
}

Idx idx(int idEst,Coll<int> collPos)
{
    Idx a;
    a.idEst = idEst;
    a.collPos = collPos;
    return a;
}

bool idxEquals(Idx a,Idx b)
{
    if(a.idEst!=b.idEst) return false;
    if(collToString<int>(a.collPos)!=collToString<int>(b.collPos)) return false;
    return true;
}

int cmpIdEst(Idx a ,Idx b){
    return a.idEst-b.idEst;
}


int cmpIdxIdEst(Idx i , int id){
    return i.idEst-id;
}   


int descubirEnIdx(int idEst,Coll<Idx> collIdx){
    int pos = collFind<Idx,int>(collIdx,idEst,cmpIdxIdEst,idxFromString);
    if (pos<0)
    {   
        Idx elemIdx = idx(idEst,coll<int>(','));
        pos = collAdd<Idx>(collIdx,elemIdx,idxToString);
    }
    return pos;
}

void mostrarLista1(Coll<Idx> collIdx,FILE* archPradron){
    
    collReset<Idx>(collIdx);
    bool enc;
    cout<<"\t"<<"ID ESTUDIANTE"<<"\t"<<"NOMBRE"<<"\t"<<"TELEFONO"<<"\t"<<"\t"<<""<<endl;
    while (!enc)
    {
        Idx idx = collNext<Idx>(collIdx,enc,idxFromString);
        if (collSize<int>(idx.collPos)<=1)
        {
            int posArch = collGetAt<int>(idx.collPos,0,stringToInt);
            
            seek<Padron>(archPradron,posArch);
            Padron p = read<Padron>(archPradron);
            // cout<<p.idEst<<"\t"<<p.nombre<<"\t"<<p.telefono<<endl;
            cout<<padronToString(p)<<endl;
        }
    }
}


void mostrarLista2(Coll<Idx> collIdx,FILE* archPradron){
    
    collReset<Idx>(collIdx);
    while (collHasNext<Idx>(collIdx))
    {
        Idx idx = collNext<Idx>(collIdx,idxFromString);
        if (collSize<int>(idx.collPos)>1)
        {
            cout<<"ID ESTUDIANTE: "<<idx.idEst<<endl;
            // cout<<"\t"<<"NOMBRE"<<"\t"<<"DNI"<<"\t"<<"TELEFONO"<<"\t"<<"DIRECCION""\t"<<"\t"<<""<<endl;
            collReset<int>(idx.collPos);
            bool enc;
            while (!enc)
            {
                int posArch = collNext<int>(idx.collPos,enc,stringToInt);
                seek<int>(archPradron,posArch);
                Padron p = read<Padron>(archPradron);
                cout<<padronToString(p)<<endl;
                // cout<<"\t"<<p.nombre<<"\t"<<p.dni<<"\t"<<p.telefono<<"\t"<<p.direccion<<"\t"<<endl;
            }
        }
    }
}

#endif
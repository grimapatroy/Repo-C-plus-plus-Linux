#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include "../tads/Coll.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct Abonado
{
	int idAbo;
	char nombre[50];
	char direccion[200];
	int fechaAlta;
};

struct AbonadoIdx
{
	int idAbo;
	int pos;
};

string abonadoToString(Abonado x)
{
	char sep = 1;
	string sIdAbo=to_string(x.idAbo);
	string sNombre=x.nombre;
	string sDireccion=x.direccion;
	string sFechaAlta=to_string(x.fechaAlta);
	return sIdAbo+sep+sNombre+sep+sDireccion+sep+sFechaAlta;
}

Abonado abonadoFromString(string s)
{
	char sep = 1;
	Abonado x;
	string t0 = getTokenAt(s,sep,0);
	x.idAbo=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.direccion,t2.c_str());
	string t3 = getTokenAt(s,sep,3);
	x.fechaAlta=stoi(t3);
	return x;
}

string abonadoToDebug(Abonado x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAbo;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.fechaAlta;
	sout<< "]";
	return sout.str();
}

string abonadoToDebug(string mssg,Abonado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAbo;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.fechaAlta;
	sout<< "]";
	return sout.str();
}

Abonado abonado(int idAbo,string nombre,string direccion,int fechaAlta)
{
	Abonado a;
	a.idAbo = idAbo;
	strcpy(a.nombre,nombre.c_str());
	strcpy(a.direccion,direccion.c_str());
	a.fechaAlta = fechaAlta;
	return a;
}

bool abonadoEquals(Abonado a,Abonado b)
{
	if(a.idAbo!=b.idAbo) return false;
	if(a.fechaAlta!=b.fechaAlta) return false;
	return true;
}

string abonadoIdxToString(AbonadoIdx x)
{
	char sep = 2;
	string sIdAbo=to_string(x.idAbo);
	string sPos=to_string(x.pos);
	return sIdAbo+sep+sPos;
}

AbonadoIdx abonadoIdxFromString(string s)
{
	char sep = 2;
	AbonadoIdx x;
	string t0 = getTokenAt(s,sep,0);
	x.idAbo=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.pos=stoi(t1);
	return x;
}

string abonadoIdxToDebug(AbonadoIdx x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAbo;
	sout << ",";
	sout << x.pos;
	sout<< "]";
	return sout.str();
}

string abonadoIdxToDebug(string mssg,AbonadoIdx x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAbo;
	sout << ",";
	sout << x.pos;
	sout<< "]";
	return sout.str();
}

AbonadoIdx abonadoIdx(int idAbo,int pos)
{
	AbonadoIdx a;
	a.idAbo = idAbo;
	a.pos = pos;
	return a;
}

bool abonadoIdxEquals(AbonadoIdx a,AbonadoIdx b)
{
	if(a.idAbo!=b.idAbo) return false;
	if(a.pos!=b.pos) return false;
	return true;
}

Coll<AbonadoIdx> indexarAbonados (FILE* f){
	
	Coll<AbonadoIdx> collIdx = coll<AbonadoIdx>();
	Abonado a = read<Abonado>(f);
	AbonadoIdx idx = abonadoIdx(a.idAbo,filePos<Abonado>(f)-1);

	while (!feof(f))
	{
		collAdd<AbonadoIdx>(collIdx,idx,abonadoIdxToString);
		a = read<Abonado>(f);
		idx = abonadoIdx(a.idAbo,filePos<Abonado>(f)-1);
	}
	return collIdx;
}

// int cmpAbonadoIdxId(AbonadoIdx idx,int id){
// 	return idx.idAbo-id;
// }

// Abonado buscarAbonado(Coll<AbonadoIdx> collIdx,FILE* f,int id,bool& encontrado){
// 	int posIdx = collFind<AbonadoIdx,int>(collIdx,id,cmpAbonadoIdxId,abonadoIdxFromString);
// 	Abonado a;
// 	// AbonadoIdx idx = collFind<>();
// 	if (posIdx>=0)
// 	{
// 		encontrado = true;
// 		AbonadoIdx idx = collGetAt<AbonadoIdx>(collIdx,posIdx,abonadoIdxFromString);
// 		seek<Abonado>(f,idx.pos);
// 		a = read<Abonado>(f);
// 	}
// 	return a;
// }

int cmpAbonadoId(AbonadoIdx a, AbonadoIdx b){
	return b.idAbo-a.idAbo;	
}






#endif
#ifndef _INSCRIPCIONES
#define _INSCRIPCIONES
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../funciones/strings.hpp"
#include "../../funciones/tokens.hpp"
#include "../../funciones/files.hpp"
#include "../../tads/Coll.hpp"


using namespace std;

struct Inscripcion
{
	int idAlu;
	int idCur;
	int fecha;
};

string inscripcionToString(Inscripcion x)
{
	char sep = 1;
	string sIdAlu=to_string(x.idAlu);
	string sIdCur=to_string(x.idCur);
	string sFecha=to_string(x.fecha);
	return sIdAlu+sep+sIdCur+sep+sFecha;
}

Inscripcion inscripcionFromString(string s)
{
	char sep = 1;
	Inscripcion x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCur=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	return x;
}

string inscripcionToDebug(Inscripcion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCur;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

string inscripcionToDebug(string mssg,Inscripcion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCur;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

Inscripcion inscripcion(int idAlu,int idCur,int fecha)
{
	Inscripcion a;
	a.idAlu = idAlu;
	a.idCur = idCur;
	a.fecha = fecha;
	return a;
}

bool inscripcionEquals(Inscripcion a,Inscripcion b)
{
	if(a.idAlu!=b.idAlu) return false;
	if(a.idCur!=b.idCur) return false;
	if(a.fecha!=b.fecha) return false;
	return true;
}
// -------------------------------------------------------------
Inscripcion inscripcionLeer(FILE* f){
	Inscripcion r = read<Inscripcion>(f);
	return r ;
}

// bool isInscripcion(FILE* arcInsc){
// 	return !feof(arcInsc)?true:false;
// }



#endif
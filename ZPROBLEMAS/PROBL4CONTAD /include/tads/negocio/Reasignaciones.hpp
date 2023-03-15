#ifndef _REACIGNACIONES
#define _REACIGNACIONES
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

struct Reasignacion
{
int idAlu;
int idCurReasig;
};

struct Reasignaciones
{
Coll <Reasignacion> c;
};



string reasignacionToString(Reasignacion x)
{
	char sep = 3;
	string sIdAlu=to_string(x.idAlu);
	string sIdCurReasig=to_string(x.idCurReasig);
	return sIdAlu+sep+sIdCurReasig;
}

Reasignacion reasignacionFromString(string s)
{
	char sep = 3;
	Reasignacion x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCurReasig=stoi(t1);
	return x;
}

string reasignacionToDebug(Reasignacion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCurReasig;
	sout<< "]";
	return sout.str();
}

string reasignacionToDebug(string mssg,Reasignacion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCurReasig;
	sout<< "]";
	return sout.str();
}

Reasignacion reasignacion(int idAlu,int idCurReasig)
{
	Reasignacion a;
	a.idAlu = idAlu;
	a.idCurReasig = idCurReasig;
	return a;
}

bool reasignacionEquals(Reasignacion a,Reasignacion b)
{
	if(a.idAlu!=b.idAlu) return false;
	if(a.idCurReasig!=b.idCurReasig) return false;
	return true;
}


string reasignacionesToString(Reasignaciones x)
{
	char sep = 7;
	string sC=collToString<Reasignacion>(x.c);
	return sC;
}

Reasignaciones reasignacionesFromString(string s)
{
	char sep = 7;
	Reasignaciones x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<Reasignacion>(t0);
	return x;
}

string reasignacionesToDebug(Reasignaciones x)
{
	stringstream sout;
	sout<< "[";
	collReset<Reasignacion>(x.c);
	int n=collSize<Reasignacion>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Reasignacion q = collGetAt<Reasignacion>(x.c,i,reasignacionFromString);
		sout << reasignacionToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string reasignacionesToDebug(string mssg,Reasignaciones x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<Reasignacion>(x.c);
	int n=collSize<Reasignacion>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Reasignacion q = collGetAt<Reasignacion>(x.c,i,reasignacionFromString);
		sout << reasignacionToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Reasignaciones reasignaciones(Coll <Reasignacion> c)
{
	Reasignaciones a;
	a.c = c;
	return a;
}

bool reasignacionesEquals(Reasignaciones a,Reasignaciones b)
{
	if(collToString<Reasignacion>(a.c)!=collToString<Reasignacion>(b.c)) return false;
	return true;
}
// ------------------------------------------------------------------------------------
Reasignaciones reasignacionesCreate(){
	Reasignacion r = reasignacion(0,0);
	Reasignaciones cReag = reasignaciones(coll<Reasignacion>());
	collAdd<Reasignacion>(cReag.c,r,reasignacionToString);
	return cReag;
}

int reasignacionAgregar(Coll<Reasignacion>&c,Reasignacion reag){
	return collAdd<Reasignacion>(c,reag,reasignacionToString);
}

int cmpReasignacionIdAlum(Reasignacion r, int id){
	return r.idAlu-id;
}


void reasignacionBuscarYOAgregar(Coll<Reasignacion>& c,int idAlumno ,int idCurso){
	int pos = collFind<Reasignacion,int>(c,idAlumno,cmpReasignacionIdAlum,reasignacionFromString);
	if (pos<0)
	{	
		Reasignacion reag = reasignacion(idAlumno,idCurso);
		pos = reasignacionAgregar(c,reag);
	}
}




// Reasignacion reasignacionObtener(Coll<Reasignacion>c,int i){
// 	return collGetAt<Reasignacion>(c,i,reasignacionFromString);
// }
// int cmpReasigIdAlum(Reasignacion r, int a){
// 	return r.idAlu - a;
// }
// int reasignacionBuscar(Coll<Reasignacion> c, int id){
// 	return collFind<Reasignacion,int>(c,id,cmpReasigIdAlum,reasignacionFromString);
// }
// void reasignacionActualizar(AlumnoRechasoInsc alum,Curso curs,Coll<Reasignacion>& c){
// 		int pos = reasignacionBuscar(c,alum.idAlumno);
// 		if (pos<0)
// 		{
// 			Reasignacion re = reasignacion(alum.idAlumno,curs.idCur);
// 			collAdd<Reasignacion>(c,re,reasignacionToString);
// 		}
// }
// void reasignacionGrabar(FILE* arReasig,Reasignacion reasig){
// 	write<Reasignacion>(arReasig,reasig);
// }
// void reasignacionesWrite(Reasignaciones& cReasig,AlumnosRechazados& alumRecha, Cursos& cCurso){
// 	FILE* arReasig = fopen("REASIGNACIONES.dat","w+b");
// 	for (int i = 0; i < collSize<AlumnoRechasoInsc>(alumRecha.c); i++)
// 	{
// 		AlumnoRechasoInsc alum = alumnosRechazadosObtener(alumRecha.c,i);
// 		Curso curs = cursoBuscarCapacidadLibreYActualizar(cCurso);//tengo que actualizar la cap del curso reasignado
// 		reasignacionActualizar(alum,curs,cReasig.c);
// 	}
// 	for (int i = 0; i < collSize<Reasignacion>(cReasig.c); i++)
// 	{
// 		Reasignacion reasig = reasignacionObtener(cReasig.c,i);
// 		reasignacionGrabar(arReasig,reasig);
// 	}
// 	fclose(arReasig);
// }



#endif
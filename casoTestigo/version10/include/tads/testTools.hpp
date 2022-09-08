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


struct Asignatura
{
	int idAsig;
	char nomAsig[30];
	char maestroACargo[50];
	double califProm;
};

struct Calificacion
{
	int idAsig;
	int idEst;
	int calif;
};

struct RMaestro
{
	string maestro;
	Coll<int> collEst;
};
// --------------------------------------------------
// string asignaturaToString(Asignatura x)
// {
// 	char sep = 1;
// 	string sIdAsig=to_string(x.idAsig);
// 	string sNomAsig=x.nomAsig;
// 	string sMaestroACargo=x.maestroACargo;
// 	string sCalifProm=to_string(x.califProm);
// 	return sIdAsig+sep+sNomAsig+sep+sMaestroACargo+sep+sCalifProm;
// }

string asignaturaToString(Asignatura x){
	string sNomAsig=x.nomAsig;
	string sMaestroACargo=x.maestroACargo;
	return intToString(x.idAsig)+','+ sNomAsig +','+ sMaestroACargo + ',' + doubleToString(x.califProm);
}


Asignatura asignaturaFromString(string s)
{
	Asignatura x;
	x.idAsig = stringToInt(getTokenAt(s, ',', 0));
	string sNomAsig = getTokenAt(s, ',', 1);
	strcpy(x.nomAsig,sNomAsig.c_str());
	string t2= getTokenAt(s, ',', 2);
	strcpy(x.maestroACargo,t2.c_str());
	x.califProm = stringToDouble(getTokenAt(s, ',', 3));
	// x.idAsig = stringToInt(getTokenAt(s, ',', 2));
	return x;
}


// Asignatura asignaturaFromString(string s)
// {
// 	char sep = 1;
// 	Asignatura x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.idAsig=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	strcpy(x.nomAsig,t1.c_str());
// 	string t2 = getTokenAt(s,sep,2);
// 	strcpy(x.maestroACargo,t2.c_str());
// 	string t3 = getTokenAt(s,sep,3);
// 	x.califProm=stod(t3);
// 	return x;
// }

string asignaturaToDebug(Asignatura x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.nomAsig;
	sout << ",";
	sout << x.maestroACargo;
	sout << ",";
	sout << x.califProm;
	sout<< "]";
	return sout.str();
}

Asignatura asignatura(int idAsig,string nomAsig,string maestroACargo,double califProm)
{
	Asignatura a;
	a.idAsig = idAsig;
	strcpy(a.nomAsig,nomAsig.c_str());
	strcpy(a.maestroACargo,maestroACargo.c_str());
	a.califProm = califProm;
	return a;
}

bool asignaturaEquals(Asignatura a,Asignatura b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.califProm!=b.califProm) return false;
	return true;
}

// --------------------------------------------------

// --------------------------------------------------
string calificacionToString(Calificacion x){
	return intToString(x.idAsig)+','+ intToString(x.idEst)+','+intToString(x.calif);
}


Calificacion calificacionFromString(string s)
{
	Calificacion x;
	x.idAsig = stringToInt(getTokenAt(s, ',', 0));
	x.idEst = stringToInt(getTokenAt(s, ',', 1));
	x.idAsig = stringToInt(getTokenAt(s, ',', 2));
	return x;
}

// Calificacion calificacionFromString(string s)
// {
// 	char sep = 2;
// 	Calificacion x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.idAsig=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.idEst=stoi(t1);
// 	string t2 = getTokenAt(s,sep,2);
// 	x.calif=stoi(t2);
// 	return x;
// }

string calificacionToDebug(Calificacion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.idEst;
	sout << ",";
	sout << x.calif;
	sout<< "]";
	return sout.str();
}

Calificacion calificacion(int idAsig,int idEst,int calif)
{
	Calificacion a;
	a.idAsig = idAsig;
	a.idEst = idEst;
	a.calif = calif;
	return a;
}

bool calificacionEquals(Calificacion a,Calificacion b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.idEst!=b.idEst) return false;
	if(a.calif!=b.calif) return false;
	return true;
}


// --------------------------------------------------

// string rAsignaturaToString(RAsignatura x)
// {
// 	char sep = 3;
// 	string sAsig=asignaturaToString(x.asig);
// 	string sCollEst=collToString<int>(x.collEst);
// 	return sAsig+sep+sCollEst;
// }

string rMaestroToString(RMaestro x)
{
	// char sep = 3;
	// string sAsig=asignaturaToString(x.asig);
	string sCollEst=collToString<int>(x.collEst);
	return x.maestro+"*"+sCollEst;
}


// RAsignatura rAsignaturaFromString(string s)
// {
// 	char sep = 3;
// 	RAsignatura x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.asig=asignaturaFromString(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.collEst=collFromString<int>(t1);
// 	return x;
// }

RMaestro rMaestroFromString(string s)
{
	// char sep = 3;
	RMaestro x;
	// string t0 = getTokenAt(s,'*',0);
	// x.asig=asignaturaFromString(t0);
	x.maestro =  getTokenAt(s,'*',0);
	string t1 = getTokenAt(s,'*',1);
	x.collEst=collFromString<int>(t1);
	return x;
}

string rMaestroToDebug(RMaestro x)
{
	stringstream sout;
	sout<< "[";
	sout << x.maestro;
	sout << ",";
	collReset<int>(x.collEst);
	int n=collSize<int>(x.collEst);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		int q = collGetAt<int>(x.collEst,i,stringToInt);
		sout << intToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

RMaestro rMaestro(string maestro,Coll<int> collEst)
{
	RMaestro a;
	a.maestro = maestro;
	a.collEst = collEst;
	return a;
}

bool rMaestroEquals(RMaestro a,RMaestro b)
{
	if(a.maestro!=b.maestro) return false;
	if(collToString<int>(a.collEst)!=collToString<int>(b.collEst)) return false;
	return true;
}

int cmpAsignatura (Asignatura x , Asignatura y){
	string m1 = x.maestroACargo;
	string m2 = y.maestroACargo;
	return m1<m2?-1:m1>m2?1:0;
}

void procesarPunto3(Asignatura elemAsig2019 ,Asignatura elemAsig2020,Coll<Asignatura>& coll19Y20){
	
	string nomes2019 = elemAsig2019.maestroACargo;
	string nomes2020 = elemAsig2020.maestroACargo;

	if (nomes2019!=nomes2020)
	{
		collAdd<Asignatura>(coll19Y20,elemAsig2019,asignaturaToString);
	}
}

void mostrarResultados(string s,Coll<Asignatura> collAsig){

	// Asignatura elemAsig = ;
	collSort<Asignatura>(collAsig,cmpAsignatura,asignaturaFromString,asignaturaToString);

	collReset<Asignatura>(collAsig);
	
	cout<<s<<endl;
	while (collHasNext<Asignatura>(collAsig))
	{
		Asignatura elemAsig = collNext<Asignatura>(collAsig,asignaturaFromString);
		cout<<asignaturaToString(elemAsig)<<endl;
	}
	
}

#endif
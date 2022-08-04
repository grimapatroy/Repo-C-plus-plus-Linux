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

struct Estad
{
	int id;
	int cont;
	int acum;
};

struct RAsignatura
{
	Asignatura asig;
	Estad estad;
};

string asignaturaToString(Asignatura x)
{
	char sep = 1;
	string sIdAsig=to_string(x.idAsig);
	string sNomAsig=x.nomAsig;
	string sMaestroACargo=x.maestroACargo;
	string sCalifProm=to_string(x.califProm);
	return sIdAsig+sep+sNomAsig+sep+sMaestroACargo+sep+sCalifProm;
}

Asignatura asignaturaFromString(string s)
{
	char sep = 1;
	Asignatura x;
	string t0 = getTokenAt(s,sep,0);
	x.idAsig=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nomAsig,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.maestroACargo,t2.c_str());
	string t3 = getTokenAt(s,sep,3);
	x.califProm=stod(t3);
	return x;
}

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

// string calificacionToString(Calificacion x)
// {
// 	char sep = 2;
// 	string sIdAsig=to_string(x.idAsig);
// 	string sIdEst=to_string(x.idEst);
// 	string sCalif=to_string(x.calif);
// 	return sIdAsig+sep+sIdEst+sep+sCalif;
// }

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

// string estadToString(Estad x)
// {
// 	char sep = 3;
// 	string sId=to_string(x.id);
// 	string sCont=to_string(x.cont);
// 	string sAcum=to_string(x.acum);
// 	return sId+sep+sCont+sep+sAcum;
// }

string estadToString(Estad x)
{
	return intToString(x.id) + "," + intToString(x.cont) + "," + intToString(x.acum);
}

// Estad estadFromString(string s)
// {
// 	char sep = 3;
// 	Estad x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.id=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.cont=stoi(t1);
// 	string t2 = getTokenAt(s,sep,2);
// 	x.acum=stoi(t2);
// 	return x;
// }
Estad estadFromString(string s)
{
	Estad c;
	c.id = stringToInt(getTokenAt(s, ',', 0));
	c.cont = stringToInt(getTokenAt(s, ',', 1));
	c.acum = stringToInt(getTokenAt(s, ',', 2));
	return c;
}


string estadToDebug(Estad x)
{
	stringstream sout;
	sout<< "[";
	sout << x.id;
	sout << ",";
	sout << x.cont;
	sout << ",";
	sout << x.acum;
	sout<< "]";
	return sout.str();
}

Estad estad(int id,int cont,int acum)
{
	Estad b;
	b.id = id;
	b.cont = cont;
	b.acum = acum;
	return b;
}

bool estadEquals(Estad a,Estad b)
{
	if(a.id!=b.id) return false;
	if(a.cont!=b.cont) return false;
	if(a.acum!=b.acum) return false;
	return true;
}

// string rAsignaturaToString(RAsignatura x)
// {
// 	char sep = 4;
// 	string sAsig=asignaturaToString(x.asig);
// 	string sEstad=estadToString(x.estad);
// 	return sAsig+sep+sEstad;
// }
string rAsignaturaToString(RAsignatura x)
{
	return asignaturaToString(x.asig)+"*"+ estadToString(x.estad);
}


// RAsignatura rAsignaturaFromString(string s)
// {
// 	char sep = 4;
// 	RAsignatura x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.asig=asignaturaFromString(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.estad=estadFromString(t1);
// 	return x;
// }

RAsignatura rAsignaturaFromString(string s)
{
	RAsignatura x;
	x.asig = asignaturaFromString(getTokenAt(s,'*',0));
	x.estad = estadFromString(getTokenAt(s,'*',1));
	return x;
}


string rAsignaturaToDebug(RAsignatura x)
{
	stringstream sout;
	sout<< "[";
	sout << asignaturaToDebug(x.asig);
	sout << ",";
	sout << estadToDebug(x.estad);
	sout<< "]";
	return sout.str();
}

RAsignatura rAsignatura(Asignatura asig,Estad estad)
{
	RAsignatura b;
	b.asig = asig;
	b.estad = estad;
	return b;
}

bool rAsignaturaEquals(RAsignatura a,RAsignatura b)
{
	if(!asignaturaEquals(a.asig,b.asig)) return false;
	if(!estadEquals(a.estad,b.estad)) return false;
	return true;
}


int cmpRAsigId(RAsignatura a , int b){
	return a.asig.idAsig - b;
}


Coll<RAsignatura> subirAsignaturas(){
	Coll<RAsignatura> collRAsigs =coll<RAsignatura>();
	
	FILE* f = fopen("ASIGNATURAS_v06.dat","r+b");
	
	Asignatura elemAsig = read<Asignatura>(f);
	while (!feof(f))
	{
		Estad elemEstd = estad(-1,0,0);
		RAsignatura elemRA = rAsignatura(elemAsig,elemEstd);
		collAdd<RAsignatura>(collRAsigs,elemRA,rAsignaturaToString);

		elemAsig = read<Asignatura>(f);
	}

	fclose(f);
	return collRAsigs;
}


void mostrarResultados(Coll<RAsignatura> collRAsigs){

	collReset<RAsignatura>(collRAsigs);
	// collHasNext<RAsignatura>(collRAsigs);
	while (collHasNext<RAsignatura>(collRAsigs))
	{
		RAsignatura	elemRAsig = collNext<RAsignatura>(collRAsigs,rAsignaturaFromString);

		double promedioAnter = elemRAsig.asig.califProm;
		double promedioActual = elemRAsig.estad.acum/(double)elemRAsig.estad.cont;
		string nombreAsig = elemRAsig.asig.nomAsig;

		cout<<"ASIGNATURA: "<<elemRAsig.asig.idAsig<<"\t"<<"PROMEDIO ANTERIOR: "<<promedioAnter<<"\t"<<"PROMEDIO ACTUAL: "<<promedioActual<<endl;
	}
}


void actualizar(Coll<RAsignatura> collRAsigs){
	FILE* f = fopen("ASIGNATURAS_v06.dat","r+b");

	Asignatura elemAsig = read<Asignatura>(f);


	while (!feof(f))
	{
		int pos = collFind<RAsignatura,int>(collRAsigs,elemAsig.idAsig,cmpRAsigId,rAsignaturaFromString);

		RAsignatura elemRAsigs = collGetAt<RAsignatura>(collRAsigs,pos,rAsignaturaFromString);

		double promAnterior= elemRAsigs.asig.califProm;
		double promActual = elemRAsigs.estad.acum/(double)elemRAsigs.estad.cont;

		double promNuevo = (promActual + promAnterior)/2;

		elemRAsigs.asig.califProm = promNuevo;

		seek<Asignatura>(f,filePos<Asignatura>(f)-1);
		write<Asignatura>(f,elemRAsigs.asig);

		elemAsig = read<Asignatura>(f);
	}

	fclose(f);

}


// void actualizar(Coll<RAsignatura> collRAsigs){
	
// 	FILE* f = fopen("ASIGNATURAS_v06.dat","w+b"); 

// 	collReset<RAsignatura>(collRAsigs);
// 	while (collHasNext<RAsignatura>(collRAsigs))
// 	{
// 		RAsignatura elemRAsi = collNext<RAsignatura>(collRAsigs,rAsignaturaFromString);

// 		double promAnter = elemRAsi.asig.califProm;
// 		double promActual = elemRAsi.estad.acum/(double)elemRAsi.estad.cont;
// 		double promNuevo = promActual + promAnter /2;

// 		elemRAsi.asig.califProm = promNuevo;
// 		write<Asignatura>(f,elemRAsi.asig);
// 	}
// 	fclose(f);
// }




#endif
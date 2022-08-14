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

string asignaturaToString(Asignatura x)
{
	char sep = 1;
	string sIdAsig=to_string(x.idAsig);
	string sNomAsig=x.nomAsig;
	string sMaestroACargo=x.maestroACargo;
	// string sCalifProm=to_string(x.califProm);
	return sIdAsig+sep+sNomAsig+sep+sMaestroACargo;
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
	// x.califProm=stod(t3);
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
	// sout << ",";
	// sout << x.califProm;
	sout<< "]";
	return sout.str();
}

Asignatura asignatura(int idAsig,string nomAsig,string maestroACargo,double califProm)
{
	Asignatura a;
	a.idAsig = idAsig;
	strcpy(a.nomAsig,nomAsig.c_str());
	strcpy(a.maestroACargo,maestroACargo.c_str());
	// a.califProm = califProm;
	return a;
}

bool asignaturaEquals(Asignatura a,Asignatura b)
{
	if(a.idAsig!=b.idAsig) return false;
	// if(a.califProm!=b.califProm) return false;
	return true;
}

// string asignaturaToString(Asignatura x)
// {
// 	// char sep = 2;
// 	string sIdAsig=intToString(x.idAsig);
// 	string sNomAsig=x.nomAsig;
// 	string sMaestroACargo=x.maestroACargo;
// 	return sIdAsig+","+sNomAsig+","+sMaestroACargo;
// }
// Asignatura asignaturaFromString(string s)
// {
// 	// char sep = 2;
// 	Asignatura x;
// 	string t0 = getTokenAt(s,'|',0);
// 	x.idAsig=stoi(t0);
// 	string t1 = getTokenAt(s,'|',1);
// 	strcpy(x.nomAsig,t1.c_str());
// 	string t2 = getTokenAt(s,'|',2);
// 	strcpy(x.maestroACargo,t2.c_str());
// 	return x;
// }

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


// Coll<RAsignatura> subirAsignaturas (){
// 	FILE* f =fopen("ASIGNATURAS_v07.dat","r+b");
// 	Asignatura elemAsig = read<Asignatura>(f);
// 	Coll<RAsignatura> collRAsig = coll<RAsignatura>();
// 	while (!feof(f))
// 	{
// 		RAsignatura elemRAsig = rAsignatura(elemAsig,coll<int>(','));
// 		collAdd<RAsignatura>(collRAsig,elemRAsig,rAsignaturaToString);
// 		elemAsig = read<Asignatura>(f);
// 	}
// 	fclose(f);
// 	return collRAsig;
// }

// int cmpRAsignaturaId(RAsignatura a ,int b){
// 	return a.asig.idAsig-b;
// }

// void procesarCalificacion(Calificacion elemCalif,Coll<RAsignatura>& collRAsignaturas){
// 	if (elemCalif.calif<4)
// 	{
// 		int pos = collFind<RAsignatura,int>(collRAsignaturas,elemCalif.idAsig,cmpRAsignaturaId,rAsignaturaFromString);
// 		RAsignatura elemRAsig = collGetAt<RAsignatura>(collRAsignaturas,pos,rAsignaturaFromString);
// 		collAdd<int>(elemRAsig.collEst,elemCalif.idEst,intToString);
// 		collSetAt<RAsignatura>(collRAsignaturas,elemRAsig,pos,rAsignaturaToString);
// 	}
// }

// void mostarResultados(Coll<RAsignatura> collRAsignaturas){
// 	cout<<"Asignaruta"<<"\t"<<"\t"<<"\t"<<"Maestro"<<"\t"<<"\t"<<"\t"<<"Estudiantes Aplazados"<<endl;
// 	collReset<RAsignatura>(collRAsignaturas);
// 	while(collHasNext<RAsignatura>(collRAsignaturas)){
// 		RAsignatura elemRAsig = collNext<RAsignatura>(collRAsignaturas,rAsignaturaFromString);
// 		string sNombreAsig = elemRAsig.asig.nomAsig;
// 		string sMaestroACargo = elemRAsig.asig.maestroACargo;
// 		cout<<sNombreAsig<<"\t"<<sMaestroACargo<<"\t";
// 		int i=0;
// 		for ( i = 0; i < collSize<int>(elemRAsig.collEst); i++)
// 		{
// 			int elemIdEst = collGetAt<int>(elemRAsig.collEst,i,stringToInt);
// 			cout<<elemIdEst<<",";
// 		}
// 		cout<<endl;
// 	}
// }

int cmpAsignaturaId(Asignatura a, int id){
	return a.idAsig-id;
}


Asignatura buscarAsignatura( int idAsig, Coll<Asignatura> collAsig){

	int pos = collFind<Asignatura,int>(collAsig,idAsig,cmpAsignaturaId,asignaturaFromString);
	Asignatura elemAsig = collGetAt<Asignatura>(collAsig,pos,asignaturaFromString);
	return elemAsig;
}


int cmpMaestroNombre(RMaestro a, string nombre){
	return cmpString(a.maestro,nombre);
}


Coll<Asignatura>  subirAsignatura(){
	FILE* f = fopen("ASIGNATURAS_v08.dat","r+b");
	Coll<Asignatura> collAsig = coll<Asignatura>();
	Asignatura regAsig = read<Asignatura>(f);
	while (!feof(f))
	{
		collAdd<Asignatura>(collAsig,regAsig,asignaturaToString);
		regAsig = read<Asignatura>(f);
	}
	fclose(f);
	return collAsig;
}

int buscarYDescubrirMaestro(Coll<RMaestro>& collRMaestros,string maestro){
	int pos = collFind<RMaestro,string>(collRMaestros,maestro,cmpMaestroNombre,rMaestroFromString);
	if (pos<0)
	{
		RMaestro elemRMaestro = rMaestro(maestro,coll<int>(','));
		pos = collAdd<RMaestro>(collRMaestros,elemRMaestro,rMaestroToString);
	}
	return pos;	
}



void procesarCalificacion(Calificacion regCalf,Coll<Asignatura> collAsig,Coll<RMaestro>& collRMaestros){
	if (regCalf.calif<4)
	{
			Asignatura elemAsig = buscarAsignatura(regCalf.idAsig,collAsig);
			string maestro = elemAsig.maestroACargo;
			int pos = buscarYDescubrirMaestro(collRMaestros,maestro);
			RMaestro  elemRMaestro =  collGetAt<RMaestro>(collRMaestros,pos,rMaestroFromString);
			collAdd<int>(elemRMaestro.collEst,regCalf.idEst,intToString);
			collSetAt<RMaestro>(collRMaestros,elemRMaestro,pos,rMaestroToString);
	}
}



void  mostrarResultados(Coll<RMaestro> collRMaestros){
	// bool enc;
	// RMaestro elemRMaestro = collNext<RMaestro>(collRMaestros,enc,rMaestroFromString);
	cout<<"MAESTRO"<<"\t"<<"\t"<<"\t"<<"Estudiantes Aplazados"<<endl;
	// while (!enc)
	for (int i = 0; i < collSize<RMaestro>(collRMaestros); i++)
	{
		RMaestro elemRMaestro = collGetAt<RMaestro>(collRMaestros,i,rMaestroFromString);
		string maestro = elemRMaestro.maestro;
		cout<<maestro<<"\t"<<"\t"<<"\t";

			Coll<int> collEst = elemRMaestro.collEst;
			collReset<int>(collEst);
			while (collHasNext<int>(collEst))
			{
				int elemIdEst  = collNext<int>(collEst,stringToInt);
				cout<<elemIdEst<<",";
			}
		cout<<endl;
	}
	// elemRMaestro = collNext<RMaestro>(collRMaestros,enc,rMaestroFromString);
}





#endif
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

struct Resultado
{
	int idEq1;
	int idEq2;
	int codRes;
	char estadio[20];
};

struct Equipo
{
	int idEq;
	char nombre[20];
	int puntos;
};

struct REstadio
{
	string estadio[20];
	int contPartido;
	int contEmpate;
};

struct REquipo
{
	Equipo e;
	int puntosActual;
};

struct Equipos
{
	Coll <REquipo> c;
};

struct Estadios
{
	Coll <REstadio> c;
};

string resultadoToString(Resultado x)
{
	char sep = 1;
	string sIdEq1=to_string(x.idEq1);
	string sIdEq2=to_string(x.idEq2);
	string sCodRes=to_string(x.codRes);
	string sEstadio=x.estadio;
	return sIdEq1+sep+sIdEq2+sep+sCodRes+sep+sEstadio;
}

Resultado resultadoFromString(string s)
{
	char sep = 1;
	Resultado x;
	string t0 = getTokenAt(s,sep,0);
	x.idEq1=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idEq2=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.codRes=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.estadio,t3.c_str());
	return x;
}

string resultadoToDebug(Resultado x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEq1;
	sout << ",";
	sout << x.idEq2;
	sout << ",";
	sout << x.codRes;
	sout << ",";
	sout << x.estadio;
	sout<< "]";
	return sout.str();
}

string resultadoToDebug(string mssg,Resultado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEq1;
	sout << ",";
	sout << x.idEq2;
	sout << ",";
	sout << x.codRes;
	sout << ",";
	sout << x.estadio;
	sout<< "]";
	return sout.str();
}

Resultado resultado(int idEq1,int idEq2,int codRes,string estadio)
{
	Resultado a;
	a.idEq1 = idEq1;
	a.idEq2 = idEq2;
	a.codRes = codRes;
	strcpy(a.estadio,estadio.c_str());
	return a;
}

bool resultadoEquals(Resultado a,Resultado b)
{
	if(a.idEq1!=b.idEq1) return false;
	if(a.idEq2!=b.idEq2) return false;
	if(a.codRes!=b.codRes) return false;
	return true;
}

string equipoToString(Equipo x)
{
	char sep = 2;
	string sIdEq=to_string(x.idEq);
	string sNombre=x.nombre;
	string sPuntos=to_string(x.puntos);
	return sIdEq+sep+sNombre+sep+sPuntos;
}

Equipo equipoFromString(string s)
{
	char sep = 2;
	Equipo x;
	string t0 = getTokenAt(s,sep,0);
	x.idEq=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.puntos=stoi(t2);
	return x;
}

string equipoToDebug(Equipo x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEq;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.puntos;
	sout<< "]";
	return sout.str();
}

string equipoToDebug(string mssg,Equipo x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEq;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.puntos;
	sout<< "]";
	return sout.str();
}

Equipo equipo(int idEq,string nombre,int puntos)
{
	Equipo a;
	a.idEq = idEq;
	strcpy(a.nombre,nombre.c_str());
	a.puntos = puntos;
	return a;
}

bool equipoEquals(Equipo a,Equipo b)
{
	if(a.idEq!=b.idEq) return false;
	if(a.puntos!=b.puntos) return false;
	return true;
}

string rEstadioToString(REstadio x)
{
	char sep = 3;
	string sEstadio=x.estadio;
	string sContPartido=to_string(x.contPartido);
	string sContEmpate=to_string(x.contEmpate);
	return sEstadio+sep+sContPartido+sep+sContEmpate;
}

REstadio rEstadioFromString(string s)
{
	char sep = 3;
	REstadio x;
	string t0 = getTokenAt(s,sep,0);
	strcpy(x.estadio,t0.c_str());
	string t1 = getTokenAt(s,sep,1);
	x.contPartido=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.contEmpate=stoi(t2);
	return x;
}

string rEstadioToDebug(REstadio x)
{
	stringstream sout;
	sout<< "[";
	sout << x.estadio;
	sout << ",";
	sout << x.contPartido;
	sout << ",";
	sout << x.contEmpate;
	sout<< "]";
	return sout.str();
}

string rEstadioToDebug(string mssg,REstadio x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.estadio;
	sout << ",";
	sout << x.contPartido;
	sout << ",";
	sout << x.contEmpate;
	sout<< "]";
	return sout.str();
}

REstadio rEstadio(string estadio,int contPartido,int contEmpate)
{
	REstadio a;
	strcpy(a.estadio,estadio.c_str());
	a.contPartido = contPartido;
	a.contEmpate = contEmpate;
	return a;
}

bool rEstadioEquals(REstadio a,REstadio b)
{
	if(a.contPartido!=b.contPartido) return false;
	if(a.contEmpate!=b.contEmpate) return false;
	return true;
}

string rEquipoToString(REquipo x)
{
	char sep = 4;
	string sE=equipoToString(x.e);
	string sPuntosActual=to_string(x.puntosActual);
	return sE+sep+sPuntosActual;
}

REquipo rEquipoFromString(string s)
{
	char sep = 4;
	REquipo x;
	string t0 = getTokenAt(s,sep,0);
	x.e=equipoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.puntosActual=stoi(t1);
	return x;
}

string rEquipoToDebug(REquipo x)
{
	stringstream sout;
	sout<< "[";
	sout << equipoToDebug(x.e);
	sout << ",";
	sout << x.puntosActual;
	sout<< "]";
	return sout.str();
}

string rEquipoToDebug(string mssg,REquipo x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << equipoToDebug(x.e);
	sout << ",";
	sout << x.puntosActual;
	sout<< "]";
	return sout.str();
}

REquipo rEquipo(Equipo e,int puntosActual)
{
	REquipo a;
	a.e = e;
	a.puntosActual = puntosActual;
	return a;
}

bool rEquipoEquals(REquipo a,REquipo b)
{
	if(!equipoEquals(a.e,b.e)) return false;
	if(a.puntosActual!=b.puntosActual) return false;
	return true;
}

string equiposToString(Equipos x)
{
	char sep = 5;
	string sC=collToString<REquipo>(x.c);
	return sC;
}

Equipos equiposFromString(string s)
{
	char sep = 5;
	Equipos x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<REquipo>(t0);
	return x;
}

string equiposToDebug(Equipos x)
{
	stringstream sout;
	sout<< "[";
	collReset<REquipo>(x.c);
	int n=collSize<REquipo>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		REquipo q = collGetAt<REquipo>(x.c,i,rEquipoFromString);
		sout << rEquipoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string equiposToDebug(string mssg,Equipos x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<REquipo>(x.c);
	int n=collSize<REquipo>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		REquipo q = collGetAt<REquipo>(x.c,i,rEquipoFromString);
		sout << rEquipoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Equipos equipos(Coll <REquipo> c)
{
	Equipos a;
	a.c = c;
	return a;
}

bool equiposEquals(Equipos a,Equipos b)
{
	if(collToString<REquipo>(a.c)!=collToString<REquipo>(b.c)) return false;
	return true;
}

string estadiosToString(Estadios x)
{
	char sep = 6;
	string sC=collToString<REstadio>(x.c);
	return sC;
}

Estadios estadiosFromString(string s)
{
	char sep = 6;
	Estadios x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<REstadio>(t0);
	return x;
}

string estadiosToDebug(Estadios x)
{
	stringstream sout;
	sout<< "[";
	collReset<REstadio>(x.c);
	int n=collSize<REstadio>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		REstadio q = collGetAt<REstadio>(x.c,i,rEstadioFromString);
		sout << rEstadioToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string estadiosToDebug(string mssg,Estadios x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<REstadio>(x.c);
	int n=collSize<REstadio>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		REstadio q = collGetAt<REstadio>(x.c,i,rEstadioFromString);
		sout << rEstadioToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Estadios estadios(Coll <REstadio> c)
{
	Estadios a;
	a.c = c;
	return a;
}

bool estadiosEquals(Estadios a,Estadios b)
{
	if(collToString<REstadio>(a.c)!=collToString<REstadio>(b.c)) return false;
	return true;
}


Resultado resultadoLeer(FILE* archivoResul){
	Resultado r = read<Resultado>(archivoResul);
	return	r;
}

Equipos  equiposCreate(){
	FILE* archEqp = fopen("EQUIPOS.dat","r+b");
	Equipo e = read<Equipo>(archEqp);
	Equipos eqs = equipos(coll<REquipo>());
	
	while (!feof(archEqp))
	{
		// REquipo re = rEquipo(e,0);
		// collAdd<REquipo>(eqs.c,re,rEquipoToString);
		int pos = equiposBuscar(e,eqs.c);
		if (pos<0)
		{
			equiposAgregar(e,eqs.c);
		}
		e = read<Equipo>(archEqp);
	}
	fclose(archEqp);
	return eqs;
}

int cmpREquipoId(REquipo e, int id){
	return e.e.idEq-id;
}

Estadios  estadiosCreate(){
	Estadios est = estadios(coll<REstadio>());
	return est;
}

int equiposObtenerPos(int idEq1,Equipos& eqs){
	int pos = collFind<REquipo,int>(eqs.c,idEq1,cmpREquipoId,rEquipoFromString);
	return pos;
}

REquipo equiposObtenerREquipo(int pos, Equipos& eqs){
	REquipo re = collGetAt<REquipo>(eqs.c,pos,rEquipoFromString);
	return	re;
}

void equiposActualizar(Equipos& eqs, REquipo& re , int pos){
	collSetAt<REquipo>(eqs.c,re,pos,rEquipoToString);
}

void equiposGanador (int idEq1,Equipos& eqs){
	int pos = equiposObtenerPos(idEq1,eqs);
	REquipo re =equiposObtenerREquipo(pos,eqs);
	re.puntosActual+=3;
	equiposActualizar(eqs,re,pos);
}


void equiposEmpate( int idEq1,int idEq2,Equipos& eqs){
	int pos1 =equiposObtenerPos(idEq1,eqs);
	REquipo re = equiposObtenerREquipo(pos1,eqs);
	re.puntosActual+=1;
	equiposActualizar(eqs,re,pos1);
	int pos2 = equiposObtenerPos(idEq2,eqs);
	REquipo re = equiposObtenerREquipo(pos2,eqs);
	re.puntosActual+=1;
	equiposActualizar(eqs,re,pos2);
}

void estadiosJugados(Estadios& estads,Resultado r ){
	int pos = estadiosBuscar(estads,r.estadio);
	if (pos<0)
	{
		// REstadio res = 
		estadiosAgregarYContarParti(estads,r.estadio);
	}else{
		estadiosActualizarContParti(pos,estads);
	}
}



void estadiosEmpate(Resultado r,Estadios& estads){
	int pos = estadiosBuscar(estads,r.estadio);
	if (pos<0)
	{
		// REstadio res = 
		estadiosAgregarYContarParti(estads,r.estadio);
	}else{
		estadiosActualizarContParti(pos,estads);
	}
}

int cmpREPuntos (REquipo e1, REquipo e2){
	return e1.e.puntos-e2.e.puntos;
}

void equiposMostrarPoscisiones(Equipos& eqs){
	
	collReset<REquipo>(eqs.c);
	for (int i = 0; i < collSize<REquipo>(eqs.c); i++)
	{
		REquipo re = equiposObtenerREquipo(i,eqs);
		re.e.puntos+=re.puntosActual;
		equiposActualizar(eqs,re,i);
	}
	collSort<REquipo>(eqs.c,cmpREPuntos,rEquipoFromString,rEquipoToString);
	collReset<REquipo>(eqs.c);
	for (int i = 0; i < collSize<REquipo>(eqs.c); i++)
	{
		REquipo re = equiposObtenerREquipo(i,eqs);
		cout<<"TABLA ACTUALIZADA DE PUNTUACION "<<endl;
		cout<<"EQUIPO"<<"\t"<<"\t"<<"\t"<<"PUNTOS"<<"\t"<<"\t"<<endl;
		cout<<re.e.nombre<<"\t"<<"\t"<<"\t"<<re.e.puntos<<"\t"<<"\t"<<endl;
	}	
}

void estadiosImprimir(Estadios estads){
	cout<<"PARTIDOS JUGADOS"<<endl;

	cout<<"PARTIDOS EMPATADOS"<<endl;
}


#endif
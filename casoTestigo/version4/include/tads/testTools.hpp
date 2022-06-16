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

struct Estad
{
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
sout<< "]";
return sout.str();
}

Asignatura asignatura(int idAsig,string nomAsig,string maestroACargo)
{
Asignatura a;
a.idAsig = idAsig;
strcpy(a.nomAsig,nomAsig.c_str());
strcpy(a.maestroACargo,maestroACargo.c_str());
return a;
}

bool asignaturaEquals(Asignatura a,Asignatura b)
{
if(a.idAsig!=b.idAsig) return false;
return true;
}

// string calificacionToString(Calificacion x)
// {
// char sep = 2;
// string sIdAsig=to_string(x.idAsig);
// string sIdEst=to_string(x.idEst);
// string sCalif=to_string(x.calif);
// return sIdAsig+sep+sIdEst+sep+sCalif;
// }

// Calificacion calificacionFromString(string s)
// {
// char sep = 2;
// Calificacion x;
// string t0 = getTokenAt(s,sep,0);
// x.idAsig=stoi(t0);
// string t1 = getTokenAt(s,sep,1);
// x.idEst=stoi(t1);
// string t2 = getTokenAt(s,sep,2);
// x.calif=stoi(t2);
// return x;
// }

string calificacionToString(Calificacion x)
{
	return intToString(x.idAsig)+","+intToString(x.idEst)+","+intToString(x.calif);
}

Calificacion calificacionFromString(string s)
{
	Calificacion c ;
	c.idAsig = stringToInt(getTokenAt(s,',',0));
	c.idEst = stringToInt(getTokenAt(s,',',1));
	c.calif = stringToInt(getTokenAt(s,',',2));
	// c.perdido = stringToInt(getTokenAt(s,',',3));
	return c;
}




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
// char sep = 3;
// string sCont=to_string(x.cont);
// string sAcum=to_string(x.acum);
// return sCont+sep+sAcum;
// }

// Estad estadFromString(string s)
// {
// char sep = 3;
// Estad x;
// string t0 = getTokenAt(s,sep,0);
// x.cont=stoi(t0);
// string t1 = getTokenAt(s,sep,1);
// x.acum=stoi(t1);
// return x;
// }

string estadToString(Estad x){
	return intToString(x.cont)+","+intToString(x.acum);
}

Estad estadFromString(string s){
	Estad x;
	x.cont = stringToInt(getTokenAt(s,',',0));
	x.acum = stringToInt(getTokenAt(s,',',1));
	return x;
}




string estadToDebug(Estad x)
{
stringstream sout;
sout<< "[";
sout << x.cont;
sout << ",";
sout << x.acum;
sout<< "]";
return sout.str();
}

Estad estad(int cont,int acum)
{
Estad b;
b.cont = cont;
b.acum = acum;
return b;
}

bool estadEquals(Estad a,Estad b)
{
if(a.cont!=b.cont) return false;
if(a.acum!=b.acum) return false;
return true;
}

string rAsignaturaToString(RAsignatura x)
{
char sep = 4;
string sAsig=asignaturaToString(x.asig);
string sEstad=estadToString(x.estad);
return sAsig+sep+sEstad;
}

RAsignatura rAsignaturaFromString(string s)
{
char sep = 4;
RAsignatura x;
string t0 = getTokenAt(s,sep,0);
x.asig=asignaturaFromString(t0);
string t1 = getTokenAt(s,sep,1);
x.estad=estadFromString(t1);
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

// int cmpCalificacion (Calificacion a , Calificacion b)
// {
// 	return a.calif-b.calif;
// }

// int cmpEstadId(Estad a , int d){
// 	return a.id-d;
// }


// void mostrarEstudiantesAprobados(int idAsig, Coll<Calificacion> buff)
// {
// 	// muestro la IdAsignatura
// 	cout<<"Asignatura: " <<idAsig<<endl;
// 	// ordeno la coleccion
// 	collSort<Calificacion>(buff,cmpCalificacion,calificacionFromString,calificacionToString);
// 	// lo iteramos
// 	collReset<Calificacion>(buff);
// 	while (collHasNext<Calificacion>(buff))
// 	{
// 		Calificacion elemento = collNext<Calificacion>(buff,calificacionFromString);
// 		// mostramos los estudiantes aprobados
// 		cout<<elemento.idEst<<" , "<<elemento.calif<<endl;
// 	}
// }



// int descubrirElemento(Coll<Estad>& collEstad, int id){
// 	int pos = collFind<Estad,int>(collEstad,id,cmpEstadId,estadFromString);
// 	if (pos<0)
// 	{
// 		Estad x = estad(id,0,0);
// 		pos = collAdd<Estad>(collEstad,x,estadToDebug);
// 	}
	
// 	return pos;
// }

// void  mostrarResultados(Coll<Estad> collEstad){
// 	collReset<Estad>(collEstad);
// 	while (collHasNext<Estad>(collEstad))
// 	{
// 		Estad elem = collNext<Estad>(collEstad,estadFromString);
// 		double promedio =elem.acum/(double)elem.cont;
// 		cout<<"La asignatura es :"<<elem.id<<" calificacion Promedio :"<<promedio<<endl;
// 	}
	
// }






#endif
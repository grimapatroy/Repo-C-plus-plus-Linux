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

string calificacionToString(Calificacion x)
{
	char sep = 1;
	string sIdAsig = to_string(x.idAsig);
	string sIdEst = to_string(x.idEst);
	string sCalif = to_string(x.calif);
	return sIdAsig + sep + sIdEst + sep + sCalif;
}

Calificacion calificacionFromString(string s)
{
	char sep = 1;
	Calificacion x;
	string t0 = getTokenAt(s, sep, 0);
	x.idAsig = stoi(t0);
	string t1 = getTokenAt(s, sep, 1);
	x.idEst = stoi(t1);
	string t2 = getTokenAt(s, sep, 2);
	x.calif = stoi(t2);
	return x;
}

string calificacionToDebug(Calificacion x)
{
	stringstream sout;
	sout << "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.idEst;
	sout << ",";
	sout << x.calif;
	sout << "]";
	return sout.str();
}

Calificacion calificacion(int idAsig, int idEst, int calif)
{
	Calificacion a;
	a.idAsig = idAsig;
	a.idEst = idEst;
	a.calif = calif;
	return a;
}

bool calificacionEquals(Calificacion a, Calificacion b)
{
	if (a.idAsig != b.idAsig)
		return false;
	if (a.idEst != b.idEst)
		return false;
	if (a.calif != b.calif)
		return false;
	return true;
}

// string estadToString(Estad x)
// {
// 	char sep = 2;
// 	string sId=to_string(x.id);
// 	string sCont=to_string(x.cont);
// 	string sAcum=to_string(x.acum);
// 	return sId+sep+sCont+sep+sAcum;
// }

// Estad estadFromString(string s)
// {
// 	char sep = 2;
// 	Estad x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.id=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.cont=stoi(t1);
// 	string t2 = getTokenAt(s,sep,2);
// 	x.acum=stoi(t2);
// 	return x;
// }

string estadToString(Estad x)
{
	return intToString(x.id) + "," + intToString(x.cont) + "," + intToString(x.acum);
}

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
	sout << "[";
	sout << x.id;
	sout << ",";
	sout << x.cont;
	sout << ",";
	sout << x.acum;
	sout << "]";
	return sout.str();
}

Estad estad(int id, int cont, int acum)
{
	Estad b;
	b.id = id;
	b.cont = cont;
	b.acum = acum;
	return b;
}

bool estadEquals(Estad a, Estad b)
{
	if (a.id != b.id)
		return false;
	if (a.cont != b.cont)
		return false;
	if (a.acum != b.acum)
		return false;
	return true;
}

int cmpCalificacion(Calificacion a, Calificacion b)
{
	return a.calif - b.calif;
}

int cmpEstadId(Estad a, int d)
{
	return a.id - d;
}

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

int descubrirElemento(Coll<Estad> &collEstad, int id)
{
	int pos = collFind<Estad, int>(collEstad, id, cmpEstadId, estadFromString);
	if (pos < 0)
	{
		Estad x = estad(id, 0, 0);
		pos = collAdd<Estad>(collEstad, x, estadToString);
	}
	return pos;
}

void mostrarResultados(Coll<Estad> collEstad)
{
	collReset<Estad>(collEstad);
	while (collHasNext<Estad>(collEstad))
	{
		Estad elem = collNext<Estad>(collEstad, estadFromString);
		double promedio = elem.acum / (double)elem.cont;
		cout << "La asignatura es :" << elem.id << " calificacion Promedio :" << promedio << endl;
	}
}

#endif
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
	int perdido;
};

// string calificacionToString(Calificacion x)
// {
// 	char sep = 1;
// 	string sIdAsig=to_string(x.idAsig);
// 	string sIdEst=to_string(x.idEst);
// 	string sCalif=to_string(x.calif);
// 	string sPerdido=to_string(x.perdido);
// 	return sIdAsig+sep+sIdEst+sep+sCalif+sep+sPerdido;
// }

// Calificacion calificacionFromString(string s)
// {
// 	char sep = 1;
// 	Calificacion x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.idAsig=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.idEst=stoi(t1);
// 	string t2 = getTokenAt(s,sep,2);
// 	x.calif=stoi(t2);
// 	string t3 = getTokenAt(s,sep,3);
// 	x.perdido=stoi(t3);
// 	return x;
// }

string calificacionToString(Calificacion x)
{
	return intToString(x.idAsig)+","+intToString(x.idEst)+","+intToString(x.calif)+","+intToString(x.perdido);
}

Calificacion calificacionFromString(string s)
{
	Calificacion c ;
	c.idAsig = stringToInt(getTokenAt(s,',',0));
	c.idEst = stringToInt(getTokenAt(s,',',1));
	c.calif = stringToInt(getTokenAt(s,',',2));
	c.perdido = stringToInt(getTokenAt(s,',',3));
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
	sout << ",";
	sout << x.perdido;
	sout<< "]";
	return sout.str();
}

string calificacionToDebug(string mssg,Calificacion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAsig;
	sout << ",";
	sout << x.idEst;
	sout << ",";
	sout << x.calif;
	sout << ",";
	sout << x.perdido;
	sout<< "]";
	return sout.str();
}

Calificacion calificacion(int idAsig,int idEst,int calif,int perdido)
{
	Calificacion a;
	a.idAsig = idAsig;
	a.idEst = idEst;
	a.calif = calif;
	a.perdido = perdido;
	return a;
}

bool calificacionEquals(Calificacion a,Calificacion b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.idEst!=b.idEst) return false;
	if(a.calif!=b.calif) return false;
	if(a.perdido!=b.perdido) return false;
	return true;
}

int cmpCalificacion (Calificacion a , Calificacion b)
{
	return a.calif-b.calif;
}


void mostrarEstudiantesAprobados(int idAsig, Coll<Calificacion> buff)
{
	// muestro la IdAsignatura
	cout<<"Asignatura: " <<idAsig<<endl;

	// ordeno la coleccion
	collSort<Calificacion>(buff,cmpCalificacion,calificacionFromString,calificacionToString);

	// lo iteramos
	collReset<Calificacion>(buff);
	while (collHasNext<Calificacion>(buff))
	{
		Calificacion elemento = collNext<Calificacion>(buff,calificacionFromString);

		// mostramos los estudiantes aprobados
		cout<<elemento.idEst<<" , "<<elemento.calif<<endl;
	}
}







#endif

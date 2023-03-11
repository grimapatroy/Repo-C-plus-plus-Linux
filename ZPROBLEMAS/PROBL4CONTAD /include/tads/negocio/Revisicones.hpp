#ifndef _REVISIONES
#define _REVISIONES
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

struct Revision
{
int idAlu;
char materia[20];
};

struct Reviciones
{
Coll <Revision> c;
};

string revisionToString(Revision x)
{
	char sep = 4;
	string sIdAlu=to_string(x.idAlu);
	string sMateria=x.materia;
	return sIdAlu+sep+sMateria;
}

Revision revisionFromString(string s)
{
	char sep = 4;
	Revision x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.materia,t1.c_str());
	return x;
}

string revisionToDebug(Revision x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

string revisionToDebug(string mssg,Revision x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

Revision revision(int idAlu,string materia)
{
	Revision a;
	a.idAlu = idAlu;
	strcpy(a.materia,materia.c_str());
	return a;
}

bool revisionEquals(Revision a,Revision b)
{
	if(a.idAlu!=b.idAlu) return false;
	return true;
}


string revicionesToString(Reviciones x)
{
	char sep = 8;
	string sC=collToString<Revision>(x.c);
	return sC;
}

Reviciones revicionesFromString(string s)
{
	char sep = 8;
	Reviciones x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<Revision>(t0);
	return x;
}

string revicionesToDebug(Reviciones x)
{
	stringstream sout;
	sout<< "[";
	collReset<Revision>(x.c);
	int n=collSize<Revision>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Revision q = collGetAt<Revision>(x.c,i,revisionFromString);
		sout << revisionToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string revicionesToDebug(string mssg,Reviciones x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<Revision>(x.c);
	int n=collSize<Revision>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Revision q = collGetAt<Revision>(x.c,i,revisionFromString);
		sout << revisionToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Reviciones reviciones(Coll <Revision> c)
{
	Reviciones a;
	a.c = c;
	return a;
}

bool revicionesEquals(Reviciones a,Reviciones b)
{
	if(collToString<Revision>(a.c)!=collToString<Revision>(b.c)) return false;
	return true;
}
// ------------------------------------------------------------------------------
// Reviciones revicionesCreate(){
// 	Reviciones cRev = reviciones(coll<Revision>());
// 	return cRev;
// }

// void revisionesWrite(Reasignaciones& cReasig,Reviciones& cRevision){
// 	//falta
// }

#endif
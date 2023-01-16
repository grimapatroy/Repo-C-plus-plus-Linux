#ifndef _RUBROS
#define _RUBROS
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../funciones/strings.hpp"
#include "../../funciones/tokens.hpp"
#include "../../tads/Coll.hpp"
#include "../../funciones/files.hpp"
#include "elementos.hpp" // mis structuras base


using namespace std;

struct Rubros
{
	Coll <RRubro> c;
};

string rubrosToString(Rubros x)
{
	char sep = 7;
	string sC=collToString<RRubro>(x.c);
	return sC;
}

Rubros rubrosFromString(string s)
{
	char sep = 7;
	Rubros x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<RRubro>(t0);
	return x;
}

string rubrosToDebug(Rubros x)
{
	stringstream sout;
	sout<< "[";
	collReset<RRubro>(x.c);
	int n=collSize<RRubro>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RRubro q = collGetAt<RRubro>(x.c,i,rRubroFromString);
		sout << rRubroToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string rubrosToDebug(string mssg,Rubros x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<RRubro>(x.c);
	int n=collSize<RRubro>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RRubro q = collGetAt<RRubro>(x.c,i,rRubroFromString);
		sout << rRubroToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Rubros rubros(Coll <RRubro> c)
{
	Rubros a;
	a.c = c;
	return a;
}

bool rubrosEquals(Rubros a,Rubros b)
{
	if(collToString<RRubro>(a.c)!=collToString<RRubro>(b.c)) return false;
	return true;
}

Rubros rubrosCreate(){
	Coll<RRubro>  crrubs = rrubrosCreate();
	Rubros rb = rubros(crrubs);
	return rb;
}

int cmpRubroId (RRubro rr, int idR){
	return rr.r.idRub-idR;
}

Rubro rubrosBuscar(Rubros& crubros,int idrubro){
	int posRubro = collFind<RRubro,int>(crubros.c,idrubro,cmpRubroId,rRubroFromString);
	RRubro rRubro = collGetAt<RRubro>(crubros.c,posRubro,rRubroFromString);
	return	rRubro.r;
}

void rubrosActualizarDtos(Rubros& crubros, int idRub,double descto){
	int posB = collFind<RRubro,int>(crubros.c,idRub,cmpRubroId,rRubroFromString);

	RRubro rrb = collGetAt<RRubro>(crubros.c,posB,rRubroFromString);
	rrb.acumTotalDesc+=descto;
	collSetAt<RRubro>(crubros.c,rrb,posB,rRubroToString);

}

#endif
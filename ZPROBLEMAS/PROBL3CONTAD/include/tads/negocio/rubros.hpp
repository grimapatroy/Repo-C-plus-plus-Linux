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

struct Rubro
{
	int idRub;
	char descr[20];
	double promo;
};
struct RRubro
{
	Rubro r;
	int acumTotalDesc;
};

struct Rubros
{
	Coll <RRubro> c;
};

string rubroToString(Rubro x)
{
	char sep = 2;
	string sIdRub=to_string(x.idRub);
	string sDescr=x.descr;
	string sPromo=to_string(x.promo);
	return sIdRub+sep+sDescr+sep+sPromo;
}

Rubro rubroFromString(string s)
{
	char sep = 2;
	Rubro x;
	string t0 = getTokenAt(s,sep,0);
	x.idRub=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.promo=stod(t2);
	return x;
}

string rubroToDebug(Rubro x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

string rubroToDebug(string mssg,Rubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

Rubro rubro(int idRub,string descr,double promo)
{
	Rubro a;
	a.idRub = idRub;
	strcpy(a.descr,descr.c_str());
	a.promo = promo;
	return a;
}

bool rubroEquals(Rubro a,Rubro b)
{
	if(a.idRub!=b.idRub) return false;
	if(a.promo!=b.promo) return false;
	return true;
}


string rRubroToString(RRubro x)
{
	char sep = 5;
	string sR=rubroToString(x.r);
	string sAcumTotalDesc=to_string(x.acumTotalDesc);
	return sR+sep+sAcumTotalDesc;
}

RRubro rRubroFromString(string s)
{
	char sep = 5;
	RRubro x;
	string t0 = getTokenAt(s,sep,0);
	x.r=rubroFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acumTotalDesc=stoi(t1);
	return x;
}

string rRubroToDebug(RRubro x)
{
	stringstream sout;
	sout<< "[";
	sout << rubroToDebug(x.r);
	sout << ",";
	sout << x.acumTotalDesc;
	sout<< "]";
	return sout.str();
}

string rRubroToDebug(string mssg,RRubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << rubroToDebug(x.r);
	sout << ",";
	sout << x.acumTotalDesc;
	sout<< "]";
	return sout.str();
}

RRubro rRubro(Rubro r,int acumTotalDesc)
{
	RRubro b;
	b.r = r;
	b.acumTotalDesc = acumTotalDesc;
	return b;
}

bool rRubroEquals(RRubro a,RRubro b)
{
	if(!rubroEquals(a.r,b.r)) return false;
	if(a.acumTotalDesc!=b.acumTotalDesc) return false;
	return true;
}

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
// -------------------------------------------------------------------------------------

Coll<RRubro> rrubrosCreate(){
	FILE* archiRubros = fopen("RUBROS.dat","r+b");
	Coll<RRubro> collRRubros = coll<RRubro>();

	Rubro ru = read<Rubro>(archiRubros);
	while (!feof(archiRubros))
	{
		RRubro rrb = rRubro(ru,0);
		collAdd<RRubro>(collRRubros,rrb,rRubroToString);
		// collRRubros = coll<RRubro>();
		ru = read<Rubro>(archiRubros);
	}
	fclose(archiRubros);
	return collRRubros;
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

int cmpRubrosNom(RRubro a,RRubro b){
	string sNom1 = a.r.descr;
	string sNom2 = b.r.descr;
	return cmpString(sNom1,sNom2);
}


void rubroMostarDesct(Rubros crubros){ 
	collSort<RRubro>(crubros.c,cmpRubrosNom,rRubroFromString,rRubroToString);

	collReset<RRubro>(crubros.c);
	bool eoc;
	RRubro rr = collNext<RRubro>(crubros.c,eoc,rRubroFromString);
	int totalDesc {0};
	while (!eoc)
	{
		cout<<"AHORRO POR RUBRO: "<<endl;
		cout<<"Rubro"<<"\t"<<"\t"<<"\t"<<"\t"<<"Total"<<endl;
		cout<<rr.r.descr<<"\t"<<"\t"<<"\t"<<"\t"<<rr.acumTotalDesc<<endl;
		totalDesc += rr.acumTotalDesc;
	}
	cout<<"\t"<<"\t"<<"TOTAL:"<<totalDesc<<endl;
}


#endif
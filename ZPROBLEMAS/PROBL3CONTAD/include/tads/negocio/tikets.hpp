#ifndef TIKETS
#define TIKETS
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

struct Tikets
{
	int nroTk;
	Coll <Item> c;
	double tot;
	double totlDesc;
};

string tiketsToString(Tikets x)
{
	char sep = 8;
	string sNroTk=to_string(x.nroTk);
	string sC=collToString<Item>(x.c);
	string sTot=to_string(x.tot);
	string sTotlDesc=to_string(x.totlDesc);
	return sNroTk+sep+sC+sep+sTot+sep+sTotlDesc;
}

Tikets tiketsFromString(string s)
{
	char sep = 8;
	Tikets x;
	string t0 = getTokenAt(s,sep,0);
	x.nroTk=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.c=collFromString<Item>(t1);
	string t2 = getTokenAt(s,sep,2);
	x.tot=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.totlDesc=stod(t3);
	return x;
}

string tiketsToDebug(Tikets x)
{
	stringstream sout;
	sout<< "[";
	sout << x.nroTk;
	sout << ",";
	collReset<Item>(x.c);
	int n=collSize<Item>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Item q = collGetAt<Item>(x.c,i,itemFromString);
		sout << itemToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout << ",";
	sout << x.tot;
	sout << ",";
	sout << x.totlDesc;
	sout<< "]";
	return sout.str();
}

string tiketsToDebug(string mssg,Tikets x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.nroTk;
	sout << ",";
	collReset<Item>(x.c);
	int n=collSize<Item>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Item q = collGetAt<Item>(x.c,i,itemFromString);
		sout << itemToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout << ",";
	sout << x.tot;
	sout << ",";
	sout << x.totlDesc;
	sout<< "]";
	return sout.str();
}

Tikets tikets(int nroTk,Coll <Item> c,double tot,double totlDesc)
{
	Tikets a;
	a.nroTk = nroTk;
	a.c = c;
	a.tot = tot;
	a.totlDesc = totlDesc;
	return a;
}

bool tiketsEquals(Tikets a,Tikets b)
{
	if(a.nroTk!=b.nroTk) return false;
	if(collToString<Item>(a.c)!=collToString<Item>(b.c)) return false;
	if(a.tot!=b.tot) return false;
	if(a.totlDesc!=b.totlDesc) return false;
	return true;
}

Tikets tiketsCreate(int nroTk){
	// Tikets tk {nroTk,coll<Item>c,}
	// Tikets tk;
	// tk.nroTk = nroTk;
	// tk.c = coll<Item>();
	// tk.tot = 0.0;
	// tk.totlDesc = 0.0;
	// return tk;
	return {nroTk,coll<Item>(),0.0,0.0};
}

void tiketsReset(Tikets& tk) {
	tk.nroTk++;
	tk.c= coll<Item>();
	tk.tot= 0.0;
	tk.totlDesc= 0.0;
}

void tiketsAgregarItems(Tikets& Tk,Item it){
	collAdd<Item>(Tk.c,it,itemToString);
}

int cmpItemProductNombre(Item a , Item b){
	return cmpString(a.producto,b.producto);
}

void tiketsImprimir(Tikets tk){
	cout<<"Nº TIKET: "<<tk.nroTk<<endl;
	
	// ordenamos alfabeticamente
	collSort<Item>(tk.c,cmpItemProductNombre,itemFromString,itemToString);
	cout<<"PRODUCTO" <<"\t"<<"\t"<<"PRECIO"<<"\t"<<"c/Dto"<<"\t"<<"Cant."<<"\t"<<"TOTAL"<<endl;
	
	for (int i = 0; i < collSize<Item>(tk.c)-1; i++)
	{
		Item it = collGetAt<Item>(tk.c,i,itemFromString);
		double tot = it.cantidad*it.precio;
		cout<<it.producto<<"\t"<<it.precio<<"\t"<<it.desc<<"\t"<<it.cantidad<<"\t"<<tot<<endl;
		tk.tot+=tot;
		tk.totlDesc+=it.desc;
	}
	
	cout<<"TOTAL BRUTO: "<<tk.tot<<endl;
	cout<<"DESCUENTO TOTAL: "<<tk.totlDesc<<endl;

}

#endif
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

struct Producto
{
	int idPro;
	char descr[8];
	double precio;
	int idRub;
};

struct Persona
{
	int dni;
	string nombe;
	string direccion;
};

struct RPersona
{
	Persona p;
	int cont;
};

string productoToString(Producto x)
{
	char sep = 1;
	string sIdPro=to_string(x.idPro);
	string sDescr=x.descr;
	string sPrecio=to_string(x.precio);
	string sIdRub=to_string(x.idRub);
	return sIdPro+sep+sDescr+sep+sPrecio+sep+sIdRub;
}

Producto productoFromString(string s)
{
	char sep = 1;
	Producto x;
	string t0 = getTokenAt(s,sep,0);
	x.idPro=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.precio=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.idRub=stoi(t3);
	return x;
}

string productoToDebug(Producto x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idPro;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

string productoToDebug(string mssg,Producto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idPro;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

Producto producto(int idPro,string descr,double precio,int idRub)
{
	Producto a;
	a.idPro = idPro;
	strcpy(a.descr,descr.c_str());
	a.precio = precio;
	a.idRub = idRub;
	return a;
}

bool productoEquals(Producto a,Producto b)
{
	if(a.idPro!=b.idPro) return false;
	if(a.precio!=b.precio) return false;
	if(a.idRub!=b.idRub) return false;
	return true;
}

string personaToString(Persona x)
{
	char sep = 2;
	string sDni=to_string(x.dni);
	string sNombe=x.nombe;
	string sDireccion=x.direccion;
	return sDni+sep+sNombe+sep+sDireccion;
}

Persona personaFromString(string s)
{
	char sep = 2;
	Persona x;
	string t0 = getTokenAt(s,sep,0);
	x.dni=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.nombe=t1;
	string t2 = getTokenAt(s,sep,2);
	x.direccion=t2;
	return x;
}

string personaToDebug(Persona x)
{
	stringstream sout;
	sout<< "[";
	sout << x.dni;
	sout << ",";
	sout << x.nombe;
	sout << ",";
	sout << x.direccion;
	sout<< "]";
	return sout.str();
}

string personaToDebug(string mssg,Persona x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.dni;
	sout << ",";
	sout << x.nombe;
	sout << ",";
	sout << x.direccion;
	sout<< "]";
	return sout.str();
}

Persona persona(int dni,string nombe,string direccion)
{
	Persona a;
	a.dni = dni;
	a.nombe = nombe;
	a.direccion = direccion;
	return a;
}

bool personaEquals(Persona a,Persona b)
{
	if(a.dni!=b.dni) return false;
	if(a.nombe!=b.nombe) return false;
	if(a.direccion!=b.direccion) return false;
	return true;
}

string rPersonaToString(RPersona x)
{
	char sep = 3;
	string sP=personaToString(x.p);
	string sCont=to_string(x.cont);
	return sP+sep+sCont;
}

RPersona rPersonaFromString(string s)
{
	char sep = 3;
	RPersona x;
	string t0 = getTokenAt(s,sep,0);
	x.p=personaFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cont=stoi(t1);
	return x;
}

string rPersonaToDebug(RPersona x)
{
	stringstream sout;
	sout<< "[";
	sout << personaToDebug(x.p);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

string rPersonaToDebug(string mssg,RPersona x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << personaToDebug(x.p);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

RPersona rPersona(Persona p,int cont)
{
	RPersona a;
	a.p = p;
	a.cont = cont;
	return a;
}

bool rPersonaEquals(RPersona a,RPersona b)
{
	if(!personaEquals(a.p,b.p)) return false;
	if(a.cont!=b.cont) return false;
	return true;
}

#endif

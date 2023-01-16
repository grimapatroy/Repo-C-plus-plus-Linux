#ifndef _PRODUCTOS
#define _PRODUCTOS
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

struct Productos
{
	Coll <RProducto> c;
};

string productosToString(Productos x)
{
	char sep = 6;
	string sC=collToString<RProducto>(x.c);
	return sC;
}

Productos productosFromString(string s)
{
	char sep = 6;
	Productos x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<RProducto>(t0);
	return x;
}

string productosToDebug(Productos x)
{
	stringstream sout;
	sout<< "[";
	collReset<RProducto>(x.c);
	int n=collSize<RProducto>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RProducto q = collGetAt<RProducto>(x.c,i,rProductoFromString);
		sout << rProductoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string productosToDebug(string mssg,Productos x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<RProducto>(x.c);
	int n=collSize<RProducto>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RProducto q = collGetAt<RProducto>(x.c,i,rProductoFromString);
		sout << rProductoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Productos productos(Coll <RProducto> c)
{
	Productos a;
	a.c = c;
	return a;
}

bool productosEquals(Productos a,Productos b)
{
	if(collToString<RProducto>(a.c)!=collToString<RProducto>(b.c)) return false;
	return true;
}


Producto productosBuscar(Productos& cproductos, int idProducto){
	
	int posProduct = collFind<RProducto,int>(cproductos.c,idProducto,cmpProductId,rProductoFromString);
	RProducto rproduct = collGetAt<RProducto>(cproductos.c,posProduct,rProductoFromString);
	// Producto p;
	return rproduct.p;
}

Productos productosCreate(){
	
	Coll<RProducto> crpdut =  rproductoCreate();
	Productos prod = productos(crpdut);
	return prod;	
}


void productosActualizarDemanda(Productos& cproductos,int idProducto,int cant){
	int p = collFind<RProducto,int>(cproductos.c,idProducto,cmpProductId,rProductoFromString);
	RProducto prod = collGetAt<RProducto>(cproductos.c,p,rProductoFromString);
	prod.acumCant+=cant;
	collSetAt<RProducto>(cproductos.c,prod,p,rProductoToString);
}

#endif
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

struct Producto
{
	int idProd;
	char descr[20];
	double precio;
	int idRub;
};

struct RProducto
{
	Producto p;
	int acumCant;
};

struct Productos
{
	Coll <RProducto> c;
};

string productoToString(Producto x)
{
	char sep = 1;
	string sIdProd=to_string(x.idProd);
	string sDescr=x.descr;
	string sPrecio=to_string(x.precio);
	string sIdRub=to_string(x.idRub);
	return sIdProd+sep+sDescr+sep+sPrecio+sep+sIdRub;
}

Producto productoFromString(string s)
{
	char sep = 1;
	Producto x;
	string t0 = getTokenAt(s,sep,0);
	x.idProd=stoi(t0);
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
	sout << x.idProd;
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
	sout << x.idProd;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

Producto producto(int idProd,string descr,double precio,int idRub)
{
	Producto a;
	a.idProd = idProd;
	strcpy(a.descr,descr.c_str());
	a.precio = precio;
	a.idRub = idRub;
	return a;
}

bool productoEquals(Producto a,Producto b)
{
	if(a.idProd!=b.idProd) return false;
	if(a.precio!=b.precio) return false;
	if(a.idRub!=b.idRub) return false;
	return true;
}



string rProductoToString(RProducto x)
{
	char sep = 4;
	string sP=productoToString(x.p);
	string sAcumCant=to_string(x.acumCant);
	return sP+sep+sAcumCant;
}

RProducto rProductoFromString(string s)
{
	char sep = 4;
	RProducto x;
	string t0 = getTokenAt(s,sep,0);
	x.p=productoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acumCant=stoi(t1);
	return x;
}

string rProductoToDebug(RProducto x)
{
	stringstream sout;
	sout<< "[";
	sout << productoToDebug(x.p);
	sout << ",";
	sout << x.acumCant;
	sout<< "]";
	return sout.str();
}

string rProductoToDebug(string mssg,RProducto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << productoToDebug(x.p);
	sout << ",";
	sout << x.acumCant;
	sout<< "]";
	return sout.str();
}

RProducto rProducto(Producto p,int acumCant)
{
	RProducto b;
	b.p = p;
	b.acumCant = acumCant;
	return b;
}

bool rProductoEquals(RProducto a,RProducto b)
{
	if(!productoEquals(a.p,b.p)) return false;
	if(a.acumCant!=b.acumCant) return false;
	return true;
}


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
// -----------------------------------------------------------------------


int cmpProductId(RProducto rpro , int id){
	return rpro.p.idProd - id;
}


Producto productosBuscar(Productos& cproductos, int idProducto){
	
	int posProduct = collFind<RProducto,int>(cproductos.c,idProducto,cmpProductId,rProductoFromString);
	RProducto rproduct = collGetAt<RProducto>(cproductos.c,posProduct,rProductoFromString);
	// Producto p;
	return rproduct.p;
}

Coll<RProducto> rproductoCreate(){
	FILE* archiProduct = fopen("PRODUCTOS.dat","r+b");

	Producto pr = read<Producto>(archiProduct);
	Coll<RProducto>  collRProduct = coll<RProducto>();
	// RProducto rp;
	while (!feof(archiProduct))
	{
		RProducto rp = rProducto(pr,0);
		collAdd<RProducto>(collRProduct,rp,rProductoToString);
		pr = read<Producto>(archiProduct);
	}

	fclose(archiProduct);
	return collRProduct;
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

int cmpRProdCantDesc(RProducto a, RProducto b){
	return b.acumCant-a.acumCant;
}


void productoMostrarDemanda(Productos cproductos){
		collSort<RProducto>(cproductos.c,cmpRProdCantDesc,rProductoFromString,rProductoToString);
	int n = collSize<RProducto>(cproductos.c);
	if (n!=10)
	{
		cout<<"SOLO EXISTEN "<<n<<" PRODUCTOS"<<endl;
		cout<<"LISTADOS DE PRODUCTOS MAS VENDIDOS"<<endl;
		cout<<"PRODUCTO"<<"\t"<<"\t"<<"\t"<<"CANTIDAD"<<endl;
		
		collReset<RProducto>(cproductos.c);
		while (collHasNext<RProducto>(cproductos.c))
		{
			RProducto rp = collNext<RProducto>(cproductos.c,rProductoFromString);
			cout<<rp.p.descr<<"\t"<<"\t"<<"\t"<<rp.acumCant<<endl;
		}
	}else{
		cout<<"LISTADOS DE PRODUCTOS MAS VENDIDOS"<<endl;
		cout<<"PRODUCTO"<<"\t"<<"\t"<<"\t"<<"CANTIDAD"<<endl;
		
		collReset<RProducto>(cproductos.c);
		// while (collHasNext<RProducto>(cproductos.c))
		for (int i = 0; i < n ; i++)
		{
			RProducto rp = collGetAt<RProducto>(cproductos.c,i,rProductoFromString);
			cout<<rp.p.descr<<"\t"<<"\t"<<"\t"<<rp.acumCant<<endl;
		}
	}
}

#endif
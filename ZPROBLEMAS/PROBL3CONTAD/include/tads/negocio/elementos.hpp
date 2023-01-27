#ifndef _ELEMENTOS
#define _ELEMENTOS
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


using namespace std;

struct Producto
{
	int idProd;
	char descr[20];
	double precio;
	int idRub;
};

struct Rubro
{
	int idRub;
	char descr[20];
	double promo;
};

struct Item
{
	string producto;
	double precio;
	int cantidad;
	double desc;
	double total;
};

struct RProducto
{
	Producto p;
	int acumCant;
};

struct RRubro
{
	Rubro r;
	int acumTotalDesc;
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

string itemToString(Item x)
{
	char sep = 3;
	string sProducto=x.producto;
	string sPrecio=to_string(x.precio);
	string sCantidad=to_string(x.cantidad);
	string sDesc=to_string(x.desc);
	string sTotal=to_string(x.total);
	return sProducto+sep+sPrecio+sep+sCantidad+sep+sDesc+sep+sTotal;
}

Item itemFromString(string s)
{
	char sep = 3;
	Item x;
	string t0 = getTokenAt(s,sep,0);
	x.producto=t0;
	string t1 = getTokenAt(s,sep,1);
	x.precio=stod(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cantidad=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.desc=stod(t3);
	string t4 = getTokenAt(s,sep,4);
	x.total=stod(t4);
	return x;
}

string itemToDebug(Item x)
{
	stringstream sout;
	sout<< "[";
	sout << x.producto;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.cantidad;
	sout << ",";
	sout << x.desc;
	sout << ",";
	sout << x.total;
	sout<< "]";
	return sout.str();
}

string itemToDebug(string mssg,Item x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.producto;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.cantidad;
	sout << ",";
	sout << x.desc;
	sout << ",";
	sout << x.total;
	sout<< "]";
	return sout.str();
}

Item item(string producto,double precio,int cantidad,double desc,double total)
{
	Item a;
	a.producto = producto;
	a.precio = precio;
	a.cantidad = cantidad;
	a.desc = desc;
	a.total = total;
	return a;
}

bool itemEquals(Item a,Item b)
{
	if(a.producto!=b.producto) return false;
	if(a.precio!=b.precio) return false;
	if(a.cantidad!=b.cantidad) return false;
	if(a.desc!=b.desc) return false;
	if(a.total!=b.total) return false;
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

int cmpProductId(RProducto rpro , int id){
	return rpro.p.idProd - id;
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


#endif
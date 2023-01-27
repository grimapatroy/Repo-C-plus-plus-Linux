#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include "../tads/Coll.hpp"
#include "../funciones/files.hpp"
#define ERR_ESTINEXIST 1; //error tipo1
#define ERR_ESCUELADIF 2;//error tipo2
#define ERR_FECHAANT 3;//error tipo3


using namespace std;

// string asignaturaToString(Asignatura x){
// 	string sNomAsig=x.nomAsig;
// 	string sMaestroACargo=x.maestroACargo;
// 	return intToString(x.idAsig)+','+ sNomAsig +','+ sMaestroACargo + ',' + doubleToString(x.califProm);
// }

// Asignatura asignaturaFromString(string s)
// {
// 	Asignatura x;
// 	x.idAsig = stringToInt(getTokenAt(s, ',', 0));
// 	string sNomAsig = getTokenAt(s, ',', 1);
// 	strcpy(x.nomAsig,sNomAsig.c_str());
// 	string t2= getTokenAt(s, ',', 2);
// 	strcpy(x.maestroACargo,t2.c_str());
// 	x.califProm = stringToDouble(getTokenAt(s, ',', 3));
// 	// x.idAsig = stringToInt(getTokenAt(s, ',', 2));
// 	return x;
// }

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

struct RProducto
{
	Producto p;
	int acumCant;
};

struct RRubro
{
	Rubro r;
	int acumDesc;
};

struct Item
{
	string nomProducto;
	double precio;
	int cant;
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

string rProductoToString(RProducto x)
{
	char sep = 3;
	string sP=productoToString(x.p);
	string sAcumCant=to_string(x.acumCant);
	return sP+sep+sAcumCant;
}

RProducto rProductoFromString(string s)
{
	char sep = 3;
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
	char sep = 4;
	string sR=rubroToString(x.r);
	string sAcumDesc=to_string(x.acumDesc);
	return sR+sep+sAcumDesc;
}

RRubro rRubroFromString(string s)
{
	char sep = 4;
	RRubro x;
	string t0 = getTokenAt(s,sep,0);
	x.r=rubroFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acumDesc=stoi(t1);
	return x;
}

string rRubroToDebug(RRubro x)
{
	stringstream sout;
	sout<< "[";
	sout << rubroToDebug(x.r);
	sout << ",";
	sout << x.acumDesc;
	sout<< "]";
	return sout.str();
}

string rRubroToDebug(string mssg,RRubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << rubroToDebug(x.r);
	sout << ",";
	sout << x.acumDesc;
	sout<< "]";
	return sout.str();
}

RRubro rRubro(Rubro r,int acumDesc)
{
	RRubro b;
	b.r = r;
	b.acumDesc = acumDesc;
	return b;
}

bool rRubroEquals(RRubro a,RRubro b)
{
	if(!rubroEquals(a.r,b.r)) return false;
	if(a.acumDesc!=b.acumDesc) return false;
	return true;
}

string itemToString(Item x)
{
	char sep = 5;
	string sNomProducto=x.nomProducto;
	string sPrecio=to_string(x.precio);
	string sCant=to_string(x.cant);
	return sNomProducto+sep+sPrecio+sep+sCant;
}

Item itemFromString(string s)
{
	char sep = 5;
	Item x;
	string t0 = getTokenAt(s,sep,0);
	x.nomProducto=t0;
	string t1 = getTokenAt(s,sep,1);
	x.precio=stod(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cant=stoi(t2);
	return x;
}

string itemToDebug(Item x)
{
	stringstream sout;
	sout<< "[";
	sout << x.nomProducto;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

string itemToDebug(string mssg,Item x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.nomProducto;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

Item item(string nomProducto,double precio,int cant)
{
	Item a;
	a.nomProducto = nomProducto;
	a.precio = precio;
	a.cant = cant;
	return a;
}

bool itemEquals(Item a,Item b)
{
	if(a.nomProducto!=b.nomProducto) return false;
	if(a.precio!=b.precio) return false;
	if(a.cant!=b.cant) return false;
	return true;
}


Coll<RProducto> subirProductos(){

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

Coll<RRubro> subirRubros(){
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

int cmpProductId(RProducto rp , int id){
	return rp.p.idProd-id;
}

int cmpRubroId (RRubro rr, int idR){
	return rr.r.idRub-idR;
}


void procesarItem(Coll<RProducto>& collProductos,Coll<RRubro>& collRubros,Coll<Item>& collItems,int idProducto,int cant,double& total,double& descTotal){

	int posProduct = collFind<RProducto,int>(collProductos,idProducto,cmpProductId,rProductoFromString);
	// este caso para productos desconocidos esta fuera del contexto
	// if (posProduct<0)
	// {
	// 	Producto p = producto()
	// 	RProducto nuevoRP = rProducto();
	// 	collAdd
	// }
	RProducto rproduct = collGetAt<RProducto>(collProductos,posProduct,rProductoFromString);

	int posRubro = collFind<RRubro,int>(collRubros,rproduct.p.idRub,cmpRubroId,rRubroFromString);
	RRubro rRubro = collGetAt<RRubro>(collRubros,posRubro,rRubroFromString);


	// actualizo el item
	Item ite = item(rproduct.p.descr,rproduct.p.precio,cant);
	// collSetAt<Item>(collItems,);
	collAdd<Item>(collItems,ite,itemToString);

	// actualizo la coleccion para cada uno
	rproduct.acumCant+=cant;
	double descto = rproduct.p.precio*rRubro.r.promo*cant;
	rRubro.acumDesc+=descto;
	
	// Voy actualizando los totales de precios y descuentos
	total = rproduct.p.precio*cant-descto;
	descTotal +=descto;

	// actualizo la coleccion para cada uno
	collSetAt<RProducto>(collProductos,rproduct,posProduct,rProductoToString);
	collSetAt<RRubro>(collRubros,rRubro,posRubro,rRubroToString);
	

}

void mostrarTikets(Coll<Item> collItems){

	collReset<Item>(collItems);
	while (collHasNext<Item>(collItems))
	{
		Item it = collNext<Item>(collItems,itemFromString);
		cout<<it.nomProducto<<"\t"<<it.cant<<"\t"<<it.precio<<endl;
	}
	
}


#endif
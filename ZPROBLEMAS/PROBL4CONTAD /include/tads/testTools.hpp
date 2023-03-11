// #ifndef _MAINHPP
// #define _MAINHPP
// #include <iostream>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
// #include "../funciones/files.hpp"
// #define ERR_ESTINEXIST 1; //error tipo1
// #define ERR_ESCUELADIF 2;//error tipo2
// #define ERR_FECHAANT 3;//error tipo3


// using namespace std;

// // string asignaturaToString(Asignatura x){
// // 	string sNomAsig=x.nomAsig;
// // 	string sMaestroACargo=x.maestroACargo;
// // 	return intToString(x.idAsig)+','+ sNomAsig +','+ sMaestroACargo + ',' + doubleToString(x.califProm);
// // }

// // Asignatura asignaturaFromString(string s)
// // {
// // 	Asignatura x;
// // 	x.idAsig = stringToInt(getTokenAt(s, ',', 0));
// // 	string sNomAsig = getTokenAt(s, ',', 1);
// // 	strcpy(x.nomAsig,sNomAsig.c_str());
// // 	string t2= getTokenAt(s, ',', 2);
// // 	strcpy(x.maestroACargo,t2.c_str());
// // 	x.califProm = stringToDouble(getTokenAt(s, ',', 3));
// // 	// x.idAsig = stringToInt(getTokenAt(s, ',', 2));
// // 	return x;
// // }

// struct Producto
// {
// 	int idProd;
// 	char descr[20];
// 	double precio;
// 	int idRub;
// };

// struct Rubro
// {
// 	int idRub;
// 	char descr[20];
// 	double promo;
// };

// struct Item
// {
// 	string producto;
// 	double precio;
// 	int cantidad;
// 	double desc;
// 	double total;
// };

// struct RProducto
// {
// 	Producto p;
// 	int acumCant;
// };

// struct RRubro
// {
// 	Rubro r;
// 	int acumTotalDesc;
// };



// // -------- TAD's del negocio----------------------------------
// struct Productos
// {
// 	Coll <RProducto> c;
// };

// struct Rubros
// {
// 	Coll <RRubro> c;
// };

// struct Tikets
// {
// 	int nroTk;
// 	Coll <Item> c;
// 	double tot;
// 	double totlDesc;
// };

// string productoToString(Producto x)
// {
// 	char sep = 1;
// 	string sIdProd=to_string(x.idProd);
// 	string sDescr=x.descr;
// 	string sPrecio=to_string(x.precio);
// 	string sIdRub=to_string(x.idRub);
// 	return sIdProd+sep+sDescr+sep+sPrecio+sep+sIdRub;
// }

// Producto productoFromString(string s)
// {
// 	char sep = 1;
// 	Producto x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.idProd=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	strcpy(x.descr,t1.c_str());
// 	string t2 = getTokenAt(s,sep,2);
// 	x.precio=stod(t2);
// 	string t3 = getTokenAt(s,sep,3);
// 	x.idRub=stoi(t3);
// 	return x;
// }

// string productoToDebug(Producto x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	sout << x.idProd;
// 	sout << ",";
// 	sout << x.descr;
// 	sout << ",";
// 	sout << x.precio;
// 	sout << ",";
// 	sout << x.idRub;
// 	sout<< "]";
// 	return sout.str();
// }

// string productoToDebug(string mssg,Producto x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	sout << x.idProd;
// 	sout << ",";
// 	sout << x.descr;
// 	sout << ",";
// 	sout << x.precio;
// 	sout << ",";
// 	sout << x.idRub;
// 	sout<< "]";
// 	return sout.str();
// }

// Producto producto(int idProd,string descr,double precio,int idRub)
// {
// 	Producto a;
// 	a.idProd = idProd;
// 	strcpy(a.descr,descr.c_str());
// 	a.precio = precio;
// 	a.idRub = idRub;
// 	return a;
// }

// bool productoEquals(Producto a,Producto b)
// {
// 	if(a.idProd!=b.idProd) return false;
// 	if(a.precio!=b.precio) return false;
// 	if(a.idRub!=b.idRub) return false;
// 	return true;
// }

// string rubroToString(Rubro x)
// {
// 	char sep = 2;
// 	string sIdRub=to_string(x.idRub);
// 	string sDescr=x.descr;
// 	string sPromo=to_string(x.promo);
// 	return sIdRub+sep+sDescr+sep+sPromo;
// }

// Rubro rubroFromString(string s)
// {
// 	char sep = 2;
// 	Rubro x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.idRub=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	strcpy(x.descr,t1.c_str());
// 	string t2 = getTokenAt(s,sep,2);
// 	x.promo=stod(t2);
// 	return x;
// }

// string rubroToDebug(Rubro x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	sout << x.idRub;
// 	sout << ",";
// 	sout << x.descr;
// 	sout << ",";
// 	sout << x.promo;
// 	sout<< "]";
// 	return sout.str();
// }

// string rubroToDebug(string mssg,Rubro x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	sout << x.idRub;
// 	sout << ",";
// 	sout << x.descr;
// 	sout << ",";
// 	sout << x.promo;
// 	sout<< "]";
// 	return sout.str();
// }

// Rubro rubro(int idRub,string descr,double promo)
// {
// 	Rubro a;
// 	a.idRub = idRub;
// 	strcpy(a.descr,descr.c_str());
// 	a.promo = promo;
// 	return a;
// }

// bool rubroEquals(Rubro a,Rubro b)
// {
// 	if(a.idRub!=b.idRub) return false;
// 	if(a.promo!=b.promo) return false;
// 	return true;
// }

// string itemToString(Item x)
// {
// 	char sep = 3;
// 	string sProducto=x.producto;
// 	string sPrecio=to_string(x.precio);
// 	string sCantidad=to_string(x.cantidad);
// 	string sDesc=to_string(x.desc);
// 	string sTotal=to_string(x.total);
// 	return sProducto+sep+sPrecio+sep+sCantidad+sep+sDesc+sep+sTotal;
// }

// Item itemFromString(string s)
// {
// 	char sep = 3;
// 	Item x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.producto=t0;
// 	string t1 = getTokenAt(s,sep,1);
// 	x.precio=stod(t1);
// 	string t2 = getTokenAt(s,sep,2);
// 	x.cantidad=stoi(t2);
// 	string t3 = getTokenAt(s,sep,3);
// 	x.desc=stod(t3);
// 	string t4 = getTokenAt(s,sep,4);
// 	x.total=stod(t4);
// 	return x;
// }

// string itemToDebug(Item x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	sout << x.producto;
// 	sout << ",";
// 	sout << x.precio;
// 	sout << ",";
// 	sout << x.cantidad;
// 	sout << ",";
// 	sout << x.desc;
// 	sout << ",";
// 	sout << x.total;
// 	sout<< "]";
// 	return sout.str();
// }

// string itemToDebug(string mssg,Item x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	sout << x.producto;
// 	sout << ",";
// 	sout << x.precio;
// 	sout << ",";
// 	sout << x.cantidad;
// 	sout << ",";
// 	sout << x.desc;
// 	sout << ",";
// 	sout << x.total;
// 	sout<< "]";
// 	return sout.str();
// }

// Item item(string producto,double precio,int cantidad,double desc,double total)
// {
// 	Item a;
// 	a.producto = producto;
// 	a.precio = precio;
// 	a.cantidad = cantidad;
// 	a.desc = desc;
// 	a.total = total;
// 	return a;
// }

// bool itemEquals(Item a,Item b)
// {
// 	if(a.producto!=b.producto) return false;
// 	if(a.precio!=b.precio) return false;
// 	if(a.cantidad!=b.cantidad) return false;
// 	if(a.desc!=b.desc) return false;
// 	if(a.total!=b.total) return false;
// 	return true;
// }

// string rProductoToString(RProducto x)
// {
// 	char sep = 4;
// 	string sP=productoToString(x.p);
// 	string sAcumCant=to_string(x.acumCant);
// 	return sP+sep+sAcumCant;
// }

// RProducto rProductoFromString(string s)
// {
// 	char sep = 4;
// 	RProducto x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.p=productoFromString(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.acumCant=stoi(t1);
// 	return x;
// }

// string rProductoToDebug(RProducto x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	sout << productoToDebug(x.p);
// 	sout << ",";
// 	sout << x.acumCant;
// 	sout<< "]";
// 	return sout.str();
// }

// string rProductoToDebug(string mssg,RProducto x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	sout << productoToDebug(x.p);
// 	sout << ",";
// 	sout << x.acumCant;
// 	sout<< "]";
// 	return sout.str();
// }

// RProducto rProducto(Producto p,int acumCant)
// {
// 	RProducto b;
// 	b.p = p;
// 	b.acumCant = acumCant;
// 	return b;
// }

// bool rProductoEquals(RProducto a,RProducto b)
// {
// 	if(!productoEquals(a.p,b.p)) return false;
// 	if(a.acumCant!=b.acumCant) return false;
// 	return true;
// }

// string rRubroToString(RRubro x)
// {
// 	char sep = 5;
// 	string sR=rubroToString(x.r);
// 	string sAcumTotalDesc=to_string(x.acumTotalDesc);
// 	return sR+sep+sAcumTotalDesc;
// }

// RRubro rRubroFromString(string s)
// {
// 	char sep = 5;
// 	RRubro x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.r=rubroFromString(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.acumTotalDesc=stoi(t1);
// 	return x;
// }

// string rRubroToDebug(RRubro x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	sout << rubroToDebug(x.r);
// 	sout << ",";
// 	sout << x.acumTotalDesc;
// 	sout<< "]";
// 	return sout.str();
// }

// string rRubroToDebug(string mssg,RRubro x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	sout << rubroToDebug(x.r);
// 	sout << ",";
// 	sout << x.acumTotalDesc;
// 	sout<< "]";
// 	return sout.str();
// }

// RRubro rRubro(Rubro r,int acumTotalDesc)
// {
// 	RRubro b;
// 	b.r = r;
// 	b.acumTotalDesc = acumTotalDesc;
// 	return b;
// }

// bool rRubroEquals(RRubro a,RRubro b)
// {
// 	if(!rubroEquals(a.r,b.r)) return false;
// 	if(a.acumTotalDesc!=b.acumTotalDesc) return false;
// 	return true;
// }
// // --------------------------------------------------------------------------
// string productosToString(Productos x)
// {
// 	char sep = 6;
// 	string sC=collToString<RProducto>(x.c);
// 	return sC;
// }

// Productos productosFromString(string s)
// {
// 	char sep = 6;
// 	Productos x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.c=collFromString<RProducto>(t0);
// 	return x;
// }

// string productosToDebug(Productos x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	collReset<RProducto>(x.c);
// 	int n=collSize<RProducto>(x.c);
// 	sout << "{";
// 	for(int i=0; i<n; i++)
// 	{
// 		RProducto q = collGetAt<RProducto>(x.c,i,rProductoFromString);
// 		sout << rProductoToDebug(q) << ((i<n-1)?",":"");
// 	}
// 	sout << "}";
// 	sout<< "]";
// 	return sout.str();
// }

// string productosToDebug(string mssg,Productos x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	collReset<RProducto>(x.c);
// 	int n=collSize<RProducto>(x.c);
// 	sout << "{";
// 	for(int i=0; i<n; i++)
// 	{
// 		RProducto q = collGetAt<RProducto>(x.c,i,rProductoFromString);
// 		sout << rProductoToDebug(q) << ((i<n-1)?",":"");
// 	}
// 	sout << "}";
// 	sout<< "]";
// 	return sout.str();
// }

// Productos productos(Coll <RProducto> c)
// {
// 	Productos a;
// 	a.c = c;
// 	return a;
// }

// bool productosEquals(Productos a,Productos b)
// {
// 	if(collToString<RProducto>(a.c)!=collToString<RProducto>(b.c)) return false;
// 	return true;
// }
// // ----------------------------------------------------------
// string rubrosToString(Rubros x)
// {
// 	char sep = 7;
// 	string sC=collToString<RRubro>(x.c);
// 	return sC;
// }

// Rubros rubrosFromString(string s)
// {
// 	char sep = 7;
// 	Rubros x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.c=collFromString<RRubro>(t0);
// 	return x;
// }

// string rubrosToDebug(Rubros x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	collReset<RRubro>(x.c);
// 	int n=collSize<RRubro>(x.c);
// 	sout << "{";
// 	for(int i=0; i<n; i++)
// 	{
// 		RRubro q = collGetAt<RRubro>(x.c,i,rRubroFromString);
// 		sout << rRubroToDebug(q) << ((i<n-1)?",":"");
// 	}
// 	sout << "}";
// 	sout<< "]";
// 	return sout.str();
// }

// string rubrosToDebug(string mssg,Rubros x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	collReset<RRubro>(x.c);
// 	int n=collSize<RRubro>(x.c);
// 	sout << "{";
// 	for(int i=0; i<n; i++)
// 	{
// 		RRubro q = collGetAt<RRubro>(x.c,i,rRubroFromString);
// 		sout << rRubroToDebug(q) << ((i<n-1)?",":"");
// 	}
// 	sout << "}";
// 	sout<< "]";
// 	return sout.str();
// }

// Rubros rubros(Coll <RRubro> c)
// {
// 	Rubros a;
// 	a.c = c;
// 	return a;
// }

// bool rubrosEquals(Rubros a,Rubros b)
// {
// 	if(collToString<RRubro>(a.c)!=collToString<RRubro>(b.c)) return false;
// 	return true;
// }
// // ------------------------------------------------------------------------------
// string tiketsToString(Tikets x)
// {
// 	char sep = 8;
// 	string sNroTk=to_string(x.nroTk);
// 	string sC=collToString<Item>(x.c);
// 	string sTot=to_string(x.tot);
// 	string sTotlDesc=to_string(x.totlDesc);
// 	return sNroTk+sep+sC+sep+sTot+sep+sTotlDesc;
// }

// Tikets tiketsFromString(string s)
// {
// 	char sep = 8;
// 	Tikets x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.nroTk=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.c=collFromString<Item>(t1);
// 	string t2 = getTokenAt(s,sep,2);
// 	x.tot=stod(t2);
// 	string t3 = getTokenAt(s,sep,3);
// 	x.totlDesc=stod(t3);
// 	return x;
// }

// string tiketsToDebug(Tikets x)
// {
// 	stringstream sout;
// 	sout<< "[";
// 	sout << x.nroTk;
// 	sout << ",";
// 	collReset<Item>(x.c);
// 	int n=collSize<Item>(x.c);
// 	sout << "{";
// 	for(int i=0; i<n; i++)
// 	{
// 		Item q = collGetAt<Item>(x.c,i,itemFromString);
// 		sout << itemToDebug(q) << ((i<n-1)?",":"");
// 	}
// 	sout << "}";
// 	sout << ",";
// 	sout << x.tot;
// 	sout << ",";
// 	sout << x.totlDesc;
// 	sout<< "]";
// 	return sout.str();
// }

// string tiketsToDebug(string mssg,Tikets x)
// {
// 	stringstream sout;
// 	sout<< mssg<<":[";
// 	sout << x.nroTk;
// 	sout << ",";
// 	collReset<Item>(x.c);
// 	int n=collSize<Item>(x.c);
// 	sout << "{";
// 	for(int i=0; i<n; i++)
// 	{
// 		Item q = collGetAt<Item>(x.c,i,itemFromString);
// 		sout << itemToDebug(q) << ((i<n-1)?",":"");
// 	}
// 	sout << "}";
// 	sout << ",";
// 	sout << x.tot;
// 	sout << ",";
// 	sout << x.totlDesc;
// 	sout<< "]";
// 	return sout.str();
// }

// Tikets tikets(int nroTk,Coll <Item> c,double tot,double totlDesc)
// {
// 	Tikets a;
// 	a.nroTk = nroTk;
// 	a.c = c;
// 	a.tot = tot;
// 	a.totlDesc = totlDesc;
// 	return a;
// }

// bool tiketsEquals(Tikets a,Tikets b)
// {
// 	if(a.nroTk!=b.nroTk) return false;
// 	if(collToString<Item>(a.c)!=collToString<Item>(b.c)) return false;
// 	if(a.tot!=b.tot) return false;
// 	if(a.totlDesc!=b.totlDesc) return false;
// 	return true;
// }
// // -----------------------------------------------------------------
// Coll<RProducto> rproductoCreate(){
// 	FILE* archiProduct = fopen("PRODUCTOS.dat","r+b");

// 	Producto pr = read<Producto>(archiProduct);
// 	Coll<RProducto>  collRProduct = coll<RProducto>();
// 	// RProducto rp;
// 	while (!feof(archiProduct))
// 	{
// 		RProducto rp = rProducto(pr,0);
// 		collAdd<RProducto>(collRProduct,rp,rProductoToString);
// 		pr = read<Producto>(archiProduct);
// 	}

// 	fclose(archiProduct);
// 	return collRProduct;
// }

// int cmpProductId(RProducto rpro , int id){
// 	return rpro.p.idProd - id;
// }


// Producto productosBuscar(Productos& cproductos, int&idProducto){
	
// 	int posProduct = collFind<RProducto,int>(cproductos.c,idProducto,cmpProductId,rProductoFromString);
// 	RProducto rproduct = collGetAt<RProducto>(cproductos.c,posProduct,rProductoFromString);
// 	// Producto p;
// 	return rproduct.p;
// }

// Productos productosCreate(){
	
// 	Coll<RProducto> crpdut =  rproductoCreate();
// 	Productos prod = productos(crpdut);
// 	return prod;	
// }






















// // ----------------------------Funcionen del main----------------------------------
// void procesar(Productos& cproductos,Rubros& crubros,Tikets Tk, int& idProducto,int& cant){

// 	Producto elemProduct = productosBuscar(cproductos, idProducto);

// 	Rubro elemRubro = rubrosBuscar(crubros, elemProduct.idRub);

// 	productosActualizarDemanda(cproductos,idProducto,cant);

// 	double descto = elemProduct.precio*elemRubro.promo*cant;

// 	rubrosActualizarDtos(crubros,descto);

// 	Item it = {elemProduct.descr,elemProduct.precio,cant,elemRubro.promo,elemProduct.precio*cant};

// 	tiketsAgregarItems(Tk,it);

// }

// #endif
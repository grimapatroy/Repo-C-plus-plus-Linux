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
#include "../funciones/files.hpp"
using namespace std;



struct Ciudad
{
	int idCiu;
	char descr[20];
	int millas;
};

struct Vuelo
{
	int idVue;
	int cap;
	int idOri;
	int idDes;
};

struct Reserva
{
	int idCli;
	int idVue;
	int cant;
};

struct RCiudad
{
	Ciudad ciudad;
	int cont;
};

struct RVuelo
{
	Vuelo vuelo;
	int acumRechazada;
};

struct RCliente
{
	int idCli;
	int acumMillas;
};

struct Ciudades
{
	Coll <RCiudad> c;
};

struct Vuelos
{
	Coll <RVuelo> c;
};

struct Clientes
{
	Coll <RCliente> c;
};

string ciudadToString(Ciudad x)
{
	char sep = 1;
	string sIdCiu=to_string(x.idCiu);
	string sDescr=x.descr;
	string sMillas=to_string(x.millas);
	return sIdCiu+sep+sDescr+sep+sMillas;
}

Ciudad ciudadFromString(string s)
{
	char sep = 1;
	Ciudad x;
	string t0 = getTokenAt(s,sep,0);
	x.idCiu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.millas=stoi(t2);
	return x;
}

string ciudadToDebug(Ciudad x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCiu;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.millas;
	sout<< "]";
	return sout.str();
}

string ciudadToDebug(string mssg,Ciudad x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCiu;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.millas;
	sout<< "]";
	return sout.str();
}

Ciudad ciudad(int idCiu,string descr,int millas)
{
	Ciudad a;
	a.idCiu = idCiu;
	strcpy(a.descr,descr.c_str());
	a.millas = millas;
	return a;
}

bool ciudadEquals(Ciudad a,Ciudad b)
{
	if(a.idCiu!=b.idCiu) return false;
	if(a.millas!=b.millas) return false;
	return true;
}

string vueloToString(Vuelo x)
{
	char sep = 2;
	string sIdVue=to_string(x.idVue);
	string sCap=to_string(x.cap);
	string sIdOri=to_string(x.idOri);
	string sIdDes=to_string(x.idDes);
	return sIdVue+sep+sCap+sep+sIdOri+sep+sIdDes;
}

Vuelo vueloFromString(string s)
{
	char sep = 2;
	Vuelo x;
	string t0 = getTokenAt(s,sep,0);
	x.idVue=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cap=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.idOri=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.idDes=stoi(t3);
	return x;
}

string vueloToDebug(Vuelo x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idVue;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.idOri;
	sout << ",";
	sout << x.idDes;
	sout<< "]";
	return sout.str();
}

string vueloToDebug(string mssg,Vuelo x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idVue;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.idOri;
	sout << ",";
	sout << x.idDes;
	sout<< "]";
	return sout.str();
}

Vuelo vuelo(int idVue,int cap,int idOri,int idDes)
{
	Vuelo a;
	a.idVue = idVue;
	a.cap = cap;
	a.idOri = idOri;
	a.idDes = idDes;
	return a;
}

bool vueloEquals(Vuelo a,Vuelo b)
{
	if(a.idVue!=b.idVue) return false;
	if(a.cap!=b.cap) return false;
	if(a.idOri!=b.idOri) return false;
	if(a.idDes!=b.idDes) return false;
	return true;
}

string reservaToString(Reserva x)
{
	char sep = 3;
	string sIdCli=to_string(x.idCli);
	string sIdVue=to_string(x.idVue);
	string sCant=to_string(x.cant);
	return sIdCli+sep+sIdVue+sep+sCant;
}

Reserva reservaFromString(string s)
{
	char sep = 3;
	Reserva x;
	string t0 = getTokenAt(s,sep,0);
	x.idCli=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idVue=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cant=stoi(t2);
	return x;
}

string reservaToDebug(Reserva x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCli;
	sout << ",";
	sout << x.idVue;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

string reservaToDebug(string mssg,Reserva x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCli;
	sout << ",";
	sout << x.idVue;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

Reserva reserva(int idCli,int idVue,int cant)
{
	Reserva a;
	a.idCli = idCli;
	a.idVue = idVue;
	a.cant = cant;
	return a;
}

bool reservaEquals(Reserva a,Reserva b)
{
	if(a.idCli!=b.idCli) return false;
	if(a.idVue!=b.idVue) return false;
	if(a.cant!=b.cant) return false;
	return true;
}

string rCiudadToString(RCiudad x)
{
	char sep = 4;
	string sCiudad=ciudadToString(x.ciudad);
	string sCont=to_string(x.cont);
	return sCiudad+sep+sCont;
}

RCiudad rCiudadFromString(string s)
{
	char sep = 4;
	RCiudad x;
	string t0 = getTokenAt(s,sep,0);
	x.ciudad=ciudadFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cont=stoi(t1);
	return x;
}

string rCiudadToDebug(RCiudad x)
{
	stringstream sout;
	sout<< "[";
	sout << ciudadToDebug(x.ciudad);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

string rCiudadToDebug(string mssg,RCiudad x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << ciudadToDebug(x.ciudad);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

RCiudad rCiudad(Ciudad ciudad,int cont)
{
	RCiudad a;
	a.ciudad = ciudad;
	a.cont = cont;
	return a;
}

bool rCiudadEquals(RCiudad a,RCiudad b)
{
	if(!ciudadEquals(a.ciudad,b.ciudad)) return false;
	if(a.cont!=b.cont) return false;
	return true;
}

string rVueloToString(RVuelo x)
{
	char sep = 5;
	string sVuelo=vueloToString(x.vuelo);
	string sAcumRechazada=to_string(x.acumRechazada);
	return sVuelo+sep+sAcumRechazada;
}

RVuelo rVueloFromString(string s)
{
	char sep = 5;
	RVuelo x;
	string t0 = getTokenAt(s,sep,0);
	x.vuelo=vueloFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acumRechazada=stoi(t1);
	return x;
}

string rVueloToDebug(RVuelo x)
{
	stringstream sout;
	sout<< "[";
	sout << vueloToDebug(x.vuelo);
	sout << ",";
	sout << x.acumRechazada;
	sout<< "]";
	return sout.str();
}

string rVueloToDebug(string mssg,RVuelo x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << vueloToDebug(x.vuelo);
	sout << ",";
	sout << x.acumRechazada;
	sout<< "]";
	return sout.str();
}

RVuelo rVuelo(Vuelo vuelo,int acumRechazada)
{
	RVuelo b;
	b.vuelo = vuelo;
	b.acumRechazada = acumRechazada;
	return b;
}

bool rVueloEquals(RVuelo a,RVuelo b)
{
	if(!vueloEquals(a.vuelo,b.vuelo)) return false;
	if(a.acumRechazada!=b.acumRechazada) return false;
	return true;
}

string rClienteToString(RCliente x)
{
	char sep = 6;
	string sIdCli=to_string(x.idCli);
	string sAcumMillas=to_string(x.acumMillas);
	return sIdCli+sep+sAcumMillas;
}

RCliente rClienteFromString(string s)
{
	char sep = 6;
	RCliente x;
	string t0 = getTokenAt(s,sep,0);
	x.idCli=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acumMillas=stoi(t1);
	return x;
}

string rClienteToDebug(RCliente x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCli;
	sout << ",";
	sout << x.acumMillas;
	sout<< "]";
	return sout.str();
}

string rClienteToDebug(string mssg,RCliente x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCli;
	sout << ",";
	sout << x.acumMillas;
	sout<< "]";
	return sout.str();
}

RCliente rCliente(int idCli,int acumMillas)
{
	RCliente b;
	b.idCli = idCli;
	b.acumMillas = acumMillas;
	return b;
}

bool rClienteEquals(RCliente a,RCliente b)
{
	if(a.idCli!=b.idCli) return false;
	if(a.acumMillas!=b.acumMillas) return false;
	return true;
}

string ciudadesToString(Ciudades x)
{
	char sep = 7;
	string sC=collToString<RCiudad>(x.c);
	return sC;
}

Ciudades ciudadesFromString(string s)
{
	char sep = 7;
	Ciudades x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<RCiudad>(t0);
	return x;
}

string ciudadesToDebug(Ciudades x)
{
	stringstream sout;
	sout<< "[";
	collReset<RCiudad>(x.c);
	int n=collSize<RCiudad>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RCiudad q = collGetAt<RCiudad>(x.c,i,rCiudadFromString);
		sout << rCiudadToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string ciudadesToDebug(string mssg,Ciudades x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<RCiudad>(x.c);
	int n=collSize<RCiudad>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RCiudad q = collGetAt<RCiudad>(x.c,i,rCiudadFromString);
		sout << rCiudadToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Ciudades ciudades(Coll <RCiudad> c)
{
	Ciudades a;
	a.c = c;
	return a;
}

bool ciudadesEquals(Ciudades a,Ciudades b)
{
	if(collToString<RCiudad>(a.c)!=collToString<RCiudad>(b.c)) return false;
	return true;
}

string vuelosToString(Vuelos x)
{
	char sep = 8;
	string sC=collToString<RVuelo>(x.c);
	return sC;
}

Vuelos vuelosFromString(string s)
{
	char sep = 8;
	Vuelos x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<RVuelo>(t0);
	return x;
}

string vuelosToDebug(Vuelos x)
{
	stringstream sout;
	sout<< "[";
	collReset<RVuelo>(x.c);
	int n=collSize<RVuelo>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RVuelo q = collGetAt<RVuelo>(x.c,i,rVueloFromString);
		sout << rVueloToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string vuelosToDebug(string mssg,Vuelos x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<RVuelo>(x.c);
	int n=collSize<RVuelo>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RVuelo q = collGetAt<RVuelo>(x.c,i,rVueloFromString);
		sout << rVueloToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Vuelos vuelos(Coll <RVuelo> c)
{
	Vuelos a;
	a.c = c;
	return a;
}

bool vuelosEquals(Vuelos a,Vuelos b)
{
	if(collToString<RVuelo>(a.c)!=collToString<RVuelo>(b.c)) return false;
	return true;
}

string clientesToString(Clientes x)
{
	char sep = 9;
	string sC=collToString<RCliente>(x.c);
	return sC;
}

Clientes clientesFromString(string s)
{
	char sep = 9;
	Clientes x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<RCliente>(t0);
	return x;
}

string clientesToDebug(Clientes x)
{
	stringstream sout;
	sout<< "[";
	collReset<RCliente>(x.c);
	int n=collSize<RCliente>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RCliente q = collGetAt<RCliente>(x.c,i,rClienteFromString);
		sout << rClienteToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string clientesToDebug(string mssg,Clientes x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<RCliente>(x.c);
	int n=collSize<RCliente>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RCliente q = collGetAt<RCliente>(x.c,i,rClienteFromString);
		sout << rClienteToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Clientes clientes(Coll <RCliente> c)
{
	Clientes a;
	a.c = c;
	return a;
}

bool clientesEquals(Clientes a,Clientes b)
{
	if(collToString<RCliente>(a.c)!=collToString<RCliente>(b.c)) return false;
	return true;
}
// ------------------------------------------------------------------------------------
int cmpVueloId(RVuelo r1 , RVuelo r2){
	return r1.vuelo.idVue-r1.vuelo.idVue;
}

int cmpCiudadId(RCiudad c1 , RCiudad c2){
	return c1.ciudad.idCiu-c2.ciudad.idCiu;
}

int cmpRVueloId(RVuelo vue, int id){
	return vue.vuelo.idVue-id;
}

int cmpRCiudadId(RCiudad ciu , int id){
	return ciu.ciudad.idCiu-id;
}

int cmpRClienteId(RCliente r1, int idCli){
	return r1.idCli-idCli;
}


// Coll<RVuelo> subirVuelos(){
// 	FILE* archVuelo = fopen("VUELOS.dat","r+b");
// 	Vuelo v = read<Vuelo>(archVuelo);
// 	Coll<RVuelo> collVuelos = coll<RVuelo>();	
// 	while (!feof(archVuelo))
// 	{	
// 		RVuelo elemRVuelo = rVuelo(v,0);
// 		collAdd<RVuelo>(collVuelos,elemRVuelo,rVueloToString);
// 		v = read<Vuelo>(archVuelo);
// 	}
// 	collSort<RVuelo>(collVuelos,cmpVueloId,rVueloFromString,rVueloToString);
// 	fclose(archVuelo);
// 	return collVuelos;
// }


// Coll<RCiudad> subirCiduades(){
//     FILE* archCiudad = fopen("CIUDAD.dat","r+b");
// 	Ciudad c = read<Ciudad>(archCiudad);
// 	Coll<RCiudad> collCiudades = coll<RCiudad>();
// 	while (!feof(archCiudad))
// 	{
// 		RCiudad elemRCiudad = rCiudad(c,0);
// 		collAdd<RCiudad>(collCiudades,elemRCiudad,rCiudadToString);
// 		c = read<Ciudad>(archCiudad);
// 	}
// 	collSort<RCiudad>(collCiudades,cmpCiudadId,rCiudadFromString,rCiudadToString);
// 	fclose(archCiudad);
// 	return collCiudades;
// }



// void procesarClientes(Coll<RCliente>& collClientes,int millas,Reserva regReserva){
// 	RCliente rc;
// 	int posId = collFind<RCliente,int>(collClientes,regReserva.idCli,cmpRClienteId,rClienteFromString);
// 	if (posId<0)
// 	{
// 		// rc = rCliente(regReserva.idCli,)
// 		rc.idCli = regReserva.idCli;
// 		rc.acumMillas+=millas;
// 		collAdd<RCliente>(collClientes,rc,rClienteToString);
// 	}else{
// 		rc.acumMillas+=millas;
// 		collSetAt<RCliente>(collClientes,rc,posId,rClienteToString);
// 	}
// }

// void mostrarResultados(Coll<RCiudad> collCiudades){
// 	cout<<"******************REPORTES CIUDADES DESTINO***********************"<<endl;
// 	collReset<RCiudad>(collCiudades);
// 	while (collHasNext<RCiudad>(collCiudades))
// 	{
// 		RCiudad rc=collNext<RCiudad>(collCiudades,rCiudadFromString);
// 		cout<<"CIUDAD DESTINO: "<<rc.ciudad.descr<<endl;
// 		cout<<"CANTIDAD DE VECES: "<<rc.cont<<endl;
// 		cout<<"------------------------------"<<endl;
// 	}
// }


// void mostrarResultados(Coll<RVuelo> collVuelos){
// 	cout<<"******************REPORTES VUELOS***********************"<<endl;
// 	RVuelo rv;
// 	string sCap = "";
// 	string sDes = "";
// 	for (int i = 0; i < collSize<RVuelo>(collVuelos); i++)
// 	{
// 		rv = collGetAt<RVuelo>(collVuelos,i,rVueloFromString);
// 		sCap= rv.vuelo.cap==0?"COMPLETO":"INCOMPLETO";
// 		sDes =rv.vuelo.idDes;
// 		cout<<"VUELO: "<<sDes<<" PLAZAS RECHAZADAS: "<<rv.acumRechazada<<" "<<"CAPACIDAD DEL VUELO: "<<sCap<<endl;
// 		cout<<"------------------------------"<<endl;
// 	}
// }


// void mostrarResultados(Coll<RCliente> collClientes){
// 	cout<<"******************REPORTES CLIENTES**********************"<<endl;
// 	bool enc;
// 	collReset<RCliente>(collClientes);
// 	RCliente rc= collNext<RCliente>(collClientes,enc,rClienteFromString);
// 	while (!enc)
// 	{
// 		cout<<"CLIENTE: "<<rc.idCli<endl;
// 		cout<<"TOTAL DE MILLAS ACUMULADAS: "<<rc.acumMillas<<endl;
// 		rc = collNext<RCliente>(collClientes,enc,rClienteFromString);
// 		cout<<"------------------------------"<<endl;
// 	}
// }


Clientes clientesCreate(){
    Coll<RCliente> collClientes = coll<RCliente>();
	Clientes cc = clientes(collClientes);
	return cc;
}

Vuelos  vuelosCreate(){
	FILE* archVuelo = fopen("VUELOS.dat","r+b");
	Vuelo v = read<Vuelo>(archVuelo);
	Vuelos cVuelos = vuelos(coll<RVuelo>());	
	while (!feof(archVuelo))
	{	
		RVuelo elemRVuelo = rVuelo(v,0);
		collAdd<RVuelo>(cVuelos.c,elemRVuelo,rVueloToString);
		v = read<Vuelo>(archVuelo);
	}
	// collSort<RVuelo>(cVuelos,cmpVueloId,rVueloFromString,rVueloToString);
	fclose(archVuelo);
	return cVuelos;
}

Ciudades ciudadesCreate(){
	FILE* archCiudad = fopen("CIUDAD.dat","r+b");
	Ciudad c = read<Ciudad>(archCiudad);
	Ciudades cCidades = ciudades(coll<RCiudad>());
	while (!feof(archCiudad))
	{
		RCiudad elemRCiudad = rCiudad(c,0);
		collAdd<RCiudad>(cCidades.c,elemRCiudad,rCiudadToString);
		c = read<Ciudad>(archCiudad);
	}
	collSort<RCiudad>(cCidades.c,cmpCiudadId,rCiudadFromString,rCiudadToString);
	fclose(archCiudad);
	return cCidades;
}

// ------------------------------------------------------------------------
int rCiudadIdObtener(Ciudades& cc ,  int id){
	int pos = collFind<RCiudad,int>(cc.c,id,cmpRCiudadId,rCiudadFromString);
	return pos;
}

RCiudad rCiudadObtener(Ciudades& cc, int pos){
	RCiudad rc = collGetAt<RCiudad>(cc.c,pos,rCiudadFromString);
	return rc;
}

int rVueloIdObtener(Vuelos& cc, int id){
	int pos =  collFind<RVuelo,int>(cc.c,id,cmpRVueloId,rVueloFromString);
	return pos;
}

RVuelo rVueloObtener(Vuelos& cc, int pos){
	RVuelo rv = collGetAt<RVuelo>(cc.c,pos,rVueloFromString);
	return rv;
}

// ----------------------------------------------------------
Reserva  reservaLeer(FILE* archReserva){
    Reserva regReserva = read<Reserva>(archReserva);
	return regReserva;
}

Vuelo vuelvosProcesar(int id,Vuelos cVuelos){
	// procesamos el vuelo para obtener ciudad de origen y destino
	int posVuelo = rVueloIdObtener(cVuelos,id);
	RVuelo rVuelo = rVueloObtener(cVuelos,posVuelo);
	return rVuelo.vuelo;
}

Ciudad  ciudadesProcesarOrigen(Vuelo v, Ciudades& cCiu){
		// obtener ciudad origen
	int posCiuOri = rCiudadIdObtener(cCiu,v.idOri);
	RCiudad rCiuOrigen = rCiudadObtener(cCiu, posCiuOri);
	return rCiuOrigen.ciudad;
}

Ciudad ciudadesProcesarDestino(Ciudades& cCiudades,Vuelo v){
	int posCiuDes = rCiudadIdObtener(cCiudades,v.idDes);
    RCiudad rCiuDes = rCiudadObtener(cCiudades,posCiuDes);
	return rCiuDes.ciudad;
}

bool isVueloAceptado(Vuelo v,int cant){
	return	v.cap >=cant?true:false;
}

void  vuelosActulizarCap(Vuelo v,int cant, Vuelos& cVuelo){
	// v.cap-=cant;
	int posVuelo = rVueloIdObtener(cVuelo,v.idVue);
	RVuelo rVuelo = rVueloObtener(cVuelo,posVuelo);
	rVuelo.vuelo.cap-=cant;
	collSetAt<RVuelo>(cVuelo.c,rVuelo,posVuelo,rVueloToString);
}

void clientesProcesar(Clientes& cClientes,int millas,int idCli){
	RCliente rc =rCliente(0,0);
	int posId = collFind<RCliente,int>(cClientes.c,idCli,cmpRClienteId,rClienteFromString);
	if (posId<0)
	{
		// rc = rCliente(idCli,)
		rc.idCli = idCli;
		rc.acumMillas+=millas;
		collAdd<RCliente>(cClientes.c,rc,rClienteToString);
	}else{
		rc.acumMillas+=millas;
		collSetAt<RCliente>(cClientes.c,rc,posId,rClienteToString);
	}
}

void  vuelosActulizarRecha(Vuelo v,Reserva regReserva, Vuelos& cVue){
	// Actualizo capacidad del vuelo rechazadas
	int posVuelo = rVueloIdObtener(cVue,v.idVue);
	RVuelo rVuelo = rVueloObtener(cVue,posVuelo);
	rVuelo.acumRechazada+=regReserva.cant;
	collSetAt<RVuelo>(cVue.c,rVuelo,posVuelo,rVueloToString);
}

void ciudadesActulizarDestino(Vuelo v, Ciudades cCiu){
	//actualizo ciudad de destino por cada registo de reserva leido
	int pos = rCiudadIdObtener(cCiu,v.idDes);
	RCiudad rc = rCiudadObtener(cCiu,pos);
	rc.cont++;
	collSetAt<RCiudad>(cCiu.c,rc,pos,rCiudadToString);
}

void ciudadesImprimir(Ciudades cCiudades){
	cout<<"******************REPORTES CIUDADES DESTINO***********************"<<endl;
	collReset<RCiudad>(cCiudades.c);
	while (collHasNext<RCiudad>(cCiudades.c))
	{
		RCiudad rc=collNext<RCiudad>(cCiudades.c,rCiudadFromString);
		cout<<"CIUDAD DESTINO: "<<rc.ciudad.descr<<endl;
		cout<<"CANTIDAD DE VECES: "<<rc.cont<<endl;
		cout<<"------------------------------"<<endl;
	}
}

void vuelosImprimir(Vuelos cVuelos){
	cout<<"******************REPORTES VUELOS***********************"<<endl;
	RVuelo rv;
	string sCap = "";
	string sDes = "";
	for (int i = 0; i < collSize<RVuelo>(cVuelos.c); i++)
	{
		rv = collGetAt<RVuelo>(cVuelos.c,i,rVueloFromString);
		sCap= rv.vuelo.cap==0?"COMPLETO":"INCOMPLETO";
		sDes =rv.vuelo.idDes;
		cout<<"VUELO: "<<sDes<<" PLAZAS RECHAZADAS: "<<rv.acumRechazada<<" "<<"CAPACIDAD DEL VUELO: "<<sCap<<endl;
		cout<<"------------------------------"<<endl;
	}
}

void clientesImprimir(Clientes cClientes){
	cout<<"******************REPORTES CLIENTES**********************"<<endl;
	bool enc;
	collReset<RCliente>(cClientes.c);
	RCliente rc= collNext<RCliente>(cClientes.c,enc,rClienteFromString);
	while (!enc)
	{
		cout<<"CLIENTE: "<<rc.idCli<<endl;
		cout<<"TOTAL DE MILLAS ACUMULADAS: "<<rc.acumMillas<<endl;
		rc = collNext<RCliente>(cClientes.c,enc,rClienteFromString);
		cout<<"------------------------------"<<endl;
	}
}


#endif

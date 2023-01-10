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
struct  RCliente
{
	int idCliente;
	int acuMillas;
};
struct RCiudad
{
	Ciudad ciudad;
	int cont;
};
struct RVuelos
{
	Vuelo vuelo;
	int acumRechazada;
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


string rClienteToString(RCliente x)
{
	char sep = 1;
	string sIdCliente=to_string(x.idCliente);
	string sAcuMillas=to_string(x.acuMillas);
	return sIdCliente+sep+sAcuMillas;
}

RCliente rClienteFromString(string s)
{
	char sep = 1;
	RCliente x;
	string t0 = getTokenAt(s,sep,0);
	x.idCliente=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acuMillas=stoi(t1);
	return x;
}

string rClienteToDebug(RCliente x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCliente;
	sout << ",";
	sout << x.acuMillas;
	sout<< "]";
	return sout.str();
}

string rClienteToDebug(string mssg,RCliente x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCliente;
	sout << ",";
	sout << x.acuMillas;
	sout<< "]";
	return sout.str();
}

RCliente rCliente(int idCliente,int acuMillas)
{
	RCliente b;
	b.idCliente = idCliente;
	b.acuMillas = acuMillas;
	return b;
}

bool rClienteEquals(RCliente a,RCliente b)
{
	if(a.idCliente!=b.idCliente) return false;
	if(a.acuMillas!=b.acuMillas) return false;
	return true;
}

string rCiudadToString(RCiudad x)
{
	char sep = 2;
	string sCiudad=ciudadToString(x.ciudad);
	string sCont=to_string(x.cont);
	return sCiudad+sep+sCont;
}

RCiudad rCiudadFromString(string s)
{
	char sep = 2;
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

string rVuelosToString(RVuelos x)
{
	char sep = 3;
	string sVuelo=vueloToString(x.vuelo);
	string sAcumRechazada=to_string(x.acumRechazada);
	return sVuelo+sep+sAcumRechazada;
}

RVuelos rVuelosFromString(string s)
{
	char sep = 3;
	RVuelos x;
	string t0 = getTokenAt(s,sep,0);
	x.vuelo=vueloFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acumRechazada=stoi(t1);
	return x;
}

string rVuelosToDebug(RVuelos x)
{
	stringstream sout;
	sout<< "[";
	sout << vueloToDebug(x.vuelo);
	sout << ",";
	sout << x.acumRechazada;
	sout<< "]";
	return sout.str();
}

string rVuelosToDebug(string mssg,RVuelos x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << vueloToDebug(x.vuelo);
	sout << ",";
	sout << x.acumRechazada;
	sout<< "]";
	return sout.str();
}

RVuelos rVuelos(Vuelo vuelo,int acumRechazada)
{
	RVuelos b;
	b.vuelo = vuelo;
	b.acumRechazada = acumRechazada;
	return b;
}

bool rVuelosEquals(RVuelos a,RVuelos b)
{
	if(!vueloEquals(a.vuelo,b.vuelo)) return false;
	if(a.acumRechazada!=b.acumRechazada) return false;
	return true;
}


// ----------------------------------------
int cmpVueloId(RVuelos r1 , RVuelos r2){
	return r1.vuelo.idVue-r1.vuelo.idVue;
}

int cmpCiudadId(RCiudad c1 , RCiudad c2){
	return c1.ciudad.idCiu-c2.ciudad.idCiu;
}

int cmpRVueloId(RVuelos vue, int id){
	return vue.vuelo.idVue-id;
}

int cmpRCiudadId(RCiudad ciu , int id){
	return ciu.ciudad.idCiu-id;
}

int cmpRClienteId(RCliente r1, int idCli){
	return r1.idCliente-idCli;
}


Coll<RVuelos> subirVuelos(){
	FILE* archVuelo = fopen("VUELOS.dat","r+b");

	Vuelo v = read<Vuelo>(archVuelo);
	Coll<RVuelos> collVuelos = coll<RVuelos>();	

	while (!feof(archVuelo))
	{	
		RVuelos elemRVuelo = rVuelos(v,0);
		collAdd<RVuelos>(collVuelos,elemRVuelo,rVuelosToString);
		v = read<Vuelo>(archVuelo);
	}

	collSort<RVuelos>(collVuelos,cmpVueloId,rVuelosFromString,rVuelosToString);
	fclose(archVuelo);

	return collVuelos;
}



Coll<RCiudad> subirCiduades(){
    FILE* archCiudad = fopen("CIUDAD.dat","r+b");

	Ciudad c = read<Ciudad>(archCiudad);
	Coll<RCiudad> collCiudades = coll<RCiudad>();
	while (!feof(archCiudad))
	{
		RCiudad elemRCiudad = rCiudad(c,0);
		collAdd<RCiudad>(collCiudades,elemRCiudad,rCiudadToString);
		c = read<Ciudad>(archCiudad);
	}
	collSort<RCiudad>(collCiudades,cmpCiudadId,rCiudadFromString,rCiudadToString);
	fclose(archCiudad);

	return collCiudades;
}



void procesarClientes(Coll<RCliente>& collClientes,int millas,Reserva regReserva){
	RCliente rc;
	int posId = collFind<RCliente,int>(collClientes,regReserva.idCli,cmpRClienteId,rClienteFromString);
	
	if (posId<0)
	{
		// rc = rCliente(regReserva.idCli,)
		rc.idCliente = regReserva.idCli;
		rc.acuMillas+=millas;
		collAdd<RCliente>(collClientes,rc,rClienteToString);
	}else{
		rc.acuMillas+=millas;
		collSetAt<RCliente>(collClientes,rc,posId,rClienteToString);
	}
}

void mostrarResultados(Coll<RCiudad> collCiudades){
	
	cout<<"******************REPORTES CIUDADES DESTINO***********************"<<endl;
	collReset<RCiudad>(collCiudades);
	while (collHasNext<RCiudad>(collCiudades))
	{
		RCiudad rc=collNext<RCiudad>(collCiudades,rCiudadFromString);
		cout<<"CIUDAD DESTINO: "<<rc.ciudad.descr<<endl;
		cout<<"CANTIDAD DE VECES: "<<rc.cont<<endl;
		cout<<"------------------------------"<<endl;
	}
}


void mostrarResultados(Coll<RVuelos> collVuelos){
	cout<<"******************REPORTES VUELOS***********************"<<endl;
	RVuelos rv;
	string sCap = "";
	string sDes = "";
	for (int i = 0; i < collSize<RVuelos>(collVuelos); i++)
	{
		rv = collGetAt<RVuelos>(collVuelos,i,rVuelosFromString);
		sCap= rv.vuelo.cap==0?"COMPLETO":"INCOMPLETO";
		sDes =rv.vuelo.idDes;
		cout<<"VUELO: "<<sDes<<" PLAZAS RECHAZADAS: "<<rv.acumRechazada<<" "<<"CAPACIDAD DEL VUELO: "<<sCap<<endl;
		cout<<"------------------------------"<<endl;
	}
}


void mostrarResultados(Coll<RCliente> collClientes){
	cout<<"******************REPORTES CLIENTES**********************"<<endl;
	bool enc;
	collReset<RCliente>(collClientes);
	RCliente rc= collNext<RCliente>(collClientes,enc,rClienteFromString);
	while (!enc)
	{
		cout<<"CLIENTE: "<<rc.idCliente<<endl;
		cout<<"TOTAL DE MILLAS ACUMULADAS: "<<rc.acuMillas<<endl;
		rc = collNext<RCliente>(collClientes,enc,rClienteFromString);
		cout<<"------------------------------"<<endl;
	}
}

#endif

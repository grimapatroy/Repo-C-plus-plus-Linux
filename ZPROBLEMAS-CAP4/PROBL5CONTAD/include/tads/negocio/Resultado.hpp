#ifndef RESULTADO
#define RESULTADO
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/tokens.hpp"
#include "../../funciones/files.hpp"
#include "../../tads/Coll.hpp"


using namespace std;

struct Reproduccion
{
	int idUsuario;
	int idAlbum;
	int fecha;
	int minutos;
};

struct Album
{
	int idAlbum;
	int idArtista;
	char titulo[50];
	int duracion;
};

struct Artista
{
	int idArtista;
	char nombre[50];
};

struct Resultado
{
	int idAlbum;
	int idArtista;
	int cont100;
	int cont75;
	int cont50;
	int cont25;
};

struct Contadores
{
	int cont100;
	int cont75;
	int cont50;
	int cont25;
};

struct Resultados
{
	Coll <Resultado> c;
};

string reproduccionToString(Reproduccion x)
{
	char sep = 1;
	string sIdUsuario=to_string(x.idUsuario);
	string sIdAlbum=to_string(x.idAlbum);
	string sFecha=to_string(x.fecha);
	string sMinutos=to_string(x.minutos);
	return sIdUsuario+sep+sIdAlbum+sep+sFecha+sep+sMinutos;
}

Reproduccion reproduccionFromString(string s)
{
	char sep = 1;
	Reproduccion x;
	string t0 = getTokenAt(s,sep,0);
	x.idUsuario=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idAlbum=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.minutos=stoi(t3);
	return x;
}

string reproduccionToDebug(Reproduccion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idAlbum;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

string reproduccionToDebug(string mssg,Reproduccion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idAlbum;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

Reproduccion reproduccion(int idUsuario,int idAlbum,int fecha,int minutos)
{
	Reproduccion a;
	a.idUsuario = idUsuario;
	a.idAlbum = idAlbum;
	a.fecha = fecha;
	a.minutos = minutos;
	return a;
}

bool reproduccionEquals(Reproduccion a,Reproduccion b)
{
	if(a.idUsuario!=b.idUsuario) return false;
	if(a.idAlbum!=b.idAlbum) return false;
	if(a.fecha!=b.fecha) return false;
	if(a.minutos!=b.minutos) return false;
	return true;
}

string albumToString(Album x)
{
	char sep = 2;
	string sIdAlbum=to_string(x.idAlbum);
	string sIdArtista=to_string(x.idArtista);
	string sTitulo=x.titulo;
	string sDuracion=to_string(x.duracion);
	return sIdAlbum+sep+sIdArtista+sep+sTitulo+sep+sDuracion;
}

Album albumFromString(string s)
{
	char sep = 2;
	Album x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlbum=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idArtista=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.titulo,t2.c_str());
	string t3 = getTokenAt(s,sep,3);
	x.duracion=stoi(t3);
	return x;
}

string albumToDebug(Album x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlbum;
	sout << ",";
	sout << x.idArtista;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

string albumToDebug(string mssg,Album x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlbum;
	sout << ",";
	sout << x.idArtista;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

Album album(int idAlbum,int idArtista,string titulo,int duracion)
{
	Album a;
	a.idAlbum = idAlbum;
	a.idArtista = idArtista;
	strcpy(a.titulo,titulo.c_str());
	a.duracion = duracion;
	return a;
}

bool albumEquals(Album a,Album b)
{
	if(a.idAlbum!=b.idAlbum) return false;
	if(a.idArtista!=b.idArtista) return false;
	if(a.duracion!=b.duracion) return false;
	return true;
}

string artistaToString(Artista x)
{
	char sep = 3;
	string sIdArtista=to_string(x.idArtista);
	string sNombre=x.nombre;
	return sIdArtista+sep+sNombre;
}

Artista artistaFromString(string s)
{
	char sep = 3;
	Artista x;
	string t0 = getTokenAt(s,sep,0);
	x.idArtista=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	return x;
}

string artistaToDebug(Artista x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idArtista;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string artistaToDebug(string mssg,Artista x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idArtista;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Artista artista(int idArtista,string nombre)
{
	Artista a;
	a.idArtista = idArtista;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool artistaEquals(Artista a,Artista b)
{
	if(a.idArtista!=b.idArtista) return false;
	return true;
}

string resultadoToString(Resultado x)
{
	char sep = 4;
	string sIdAlbum=to_string(x.idAlbum);
	string sIdArtista=to_string(x.idArtista);
	string sCont100=to_string(x.cont100);
	string sCont75=to_string(x.cont75);
	string sCont50=to_string(x.cont50);
	string sCont25=to_string(x.cont25);
	return sIdAlbum+sep+sIdArtista+sep+sCont100+sep+sCont75+sep+sCont50+sep+sCont25;
}

Resultado resultadoFromString(string s)
{
	char sep = 4;
	Resultado x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlbum=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idArtista=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cont100=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.cont75=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.cont50=stoi(t4);
	string t5 = getTokenAt(s,sep,5);
	x.cont25=stoi(t5);
	return x;
}

string resultadoToDebug(Resultado x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlbum;
	sout << ",";
	sout << x.idArtista;
	sout << ",";
	sout << x.cont100;
	sout << ",";
	sout << x.cont75;
	sout << ",";
	sout << x.cont50;
	sout << ",";
	sout << x.cont25;
	sout<< "]";
	return sout.str();
}

string resultadoToDebug(string mssg,Resultado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlbum;
	sout << ",";
	sout << x.idArtista;
	sout << ",";
	sout << x.cont100;
	sout << ",";
	sout << x.cont75;
	sout << ",";
	sout << x.cont50;
	sout << ",";
	sout << x.cont25;
	sout<< "]";
	return sout.str();
}

Resultado resultado(int idAlbum,int idArtista,int cont100,int cont75,int cont50,int cont25)
{
	Resultado a;
	a.idAlbum = idAlbum;
	a.idArtista = idArtista;
	a.cont100 = cont100;
	a.cont75 = cont75;
	a.cont50 = cont50;
	a.cont25 = cont25;
	return a;
}

bool resultadoEquals(Resultado a,Resultado b)
{
	if(a.idAlbum!=b.idAlbum) return false;
	if(a.idArtista!=b.idArtista) return false;
	if(a.cont100!=b.cont100) return false;
	if(a.cont75!=b.cont75) return false;
	if(a.cont50!=b.cont50) return false;
	if(a.cont25!=b.cont25) return false;
	return true;
}

string contadoresToString(Contadores x)
{
	char sep = 5;
	string sCont100=to_string(x.cont100);
	string sCont75=to_string(x.cont75);
	string sCont50=to_string(x.cont50);
	string sCont25=to_string(x.cont25);
	return sCont100+sep+sCont75+sep+sCont50+sep+sCont25;
}

Contadores contadoresFromString(string s)
{
	char sep = 5;
	Contadores x;
	string t0 = getTokenAt(s,sep,0);
	x.cont100=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cont75=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cont50=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.cont25=stoi(t3);
	return x;
}

string contadoresToDebug(Contadores x)
{
	stringstream sout;
	sout<< "[";
	sout << x.cont100;
	sout << ",";
	sout << x.cont75;
	sout << ",";
	sout << x.cont50;
	sout << ",";
	sout << x.cont25;
	sout<< "]";
	return sout.str();
}

string contadoresToDebug(string mssg,Contadores x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.cont100;
	sout << ",";
	sout << x.cont75;
	sout << ",";
	sout << x.cont50;
	sout << ",";
	sout << x.cont25;
	sout<< "]";
	return sout.str();
}

Contadores contadores(int cont100,int cont75,int cont50,int cont25)
{
	Contadores a;
	a.cont100 = cont100;
	a.cont75 = cont75;
	a.cont50 = cont50;
	a.cont25 = cont25;
	return a;
}

bool contadoresEquals(Contadores a,Contadores b)
{
	if(a.cont100!=b.cont100) return false;
	if(a.cont75!=b.cont75) return false;
	if(a.cont50!=b.cont50) return false;
	if(a.cont25!=b.cont25) return false;
	return true;
}

string resultadosToString(Resultados x)
{
	char sep = 6;
	string sC=collToString<Resultado>(x.c);
	return sC;
}

Resultados resultadosFromString(string s)
{
	char sep = 6;
	Resultados x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<Resultado>(t0);
	return x;
}

string resultadosToDebug(Resultados x)
{
	stringstream sout;
	sout<< "[";
	collReset<Resultado>(x.c);
	int n=collSize<Resultado>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Resultado q = collGetAt<Resultado>(x.c,i,resultadoFromString);
		sout << resultadoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}




string resultadosToDebug(string mssg,Resultados x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<Resultado>(x.c);
	int n=collSize<Resultado>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Resultado q = collGetAt<Resultado>(x.c,i,resultadoFromString);
		sout << resultadoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Resultados resultados(Coll <Resultado> c)
{
	Resultados a;
	a.c = c;
	return a;
}

bool resultadosEquals(Resultados a,Resultados b)
{
	if(collToString<Resultado>(a.c)!=collToString<Resultado>(b.c)) return false;
	return true;
}

Coll<int> conteoInit(){
	Coll<int> conteo = coll<int>();
    collAdd<int>(conteo,0,intToString);
    collAdd<int>(conteo,0,intToString);
    collAdd<int>(conteo,0,intToString);
    collAdd<int>(conteo,0,intToString);
	return conteo;
}


Reproduccion reproduccionLeer(FILE* fReproducion){
	Reproduccion r = read<Reproduccion>(fReproducion);
	return r;
}

Resultados resultadosCreate(){
	return resultados(coll<Resultado>());
}

bool reproduccionSiguiente(FILE* fReproducion){
	return !feof(fReproducion);
}

Album albumBuscar(int idAlbum,FILE*  fAlbum){
	Album alb;
	int i = 0;
	int j = fileSize<Album>(fAlbum)-1;
	bool enc = false;
	while (1<=j && !enc)
	{
		int k = (i+j)/2;
		seek<Album>(fAlbum,k);
		alb = read<Album>(fAlbum);
		if (alb.idAlbum<idAlbum)
		{
			i = k+1;
		}
		else
		{
			if (alb.idAlbum>idAlbum)
			{
				j=k-1;
			}
			else
			{
				enc = true;
			}
		}
	}
	return alb;	
}


void resultadosProcesar(Reproduccion r,Album alb,Resultados& cresults,Coll<int> conteo){
	Resultado re = resultado(r.idAlbum,alb.idArtista,collGetAt<int>(conteo,0,stringToInt),collGetAt<int>(conteo,1,stringToInt),collGetAt<int>(conteo,2,stringToInt),collGetAt<int>(conteo,3,stringToInt));
	collAdd<Resultado>(cresults.c,re,resultadoToString);
}

void ResultadosImprimir(Resultado& cresults){
	// resultadosOrdenarPorAlbum(cresults);
	// ya viene ordenado por album

}

#endif
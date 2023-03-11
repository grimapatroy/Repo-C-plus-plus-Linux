#ifndef _CURSOS
#define _CURSOS
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

struct Curso
{
int idCur;
char turno;
int cap;
char materia[20];
};

struct Cursos
{
Coll <Curso> c;
}; 

string cursoToString(Curso x)
{
	char sep = 2;
	string sIdCur=to_string(x.idCur);
	string sTurno=string(1,x.turno);
	string sCap=to_string(x.cap);
	string sMateria=x.materia;
	return sIdCur+sep+sTurno+sep+sCap+sep+sMateria;
}

Curso cursoFromString(string s)
{
	char sep = 2;
	Curso x;
	string t0 = getTokenAt(s,sep,0);
	x.idCur=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.turno=(char)t1[0];
	string t2 = getTokenAt(s,sep,2);
	x.cap=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.materia,t3.c_str());
	return x;
}

string cursoToDebug(Curso x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCur;
	sout << ",";
	sout << x.turno;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

string cursoToDebug(string mssg,Curso x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCur;
	sout << ",";
	sout << x.turno;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

Curso curso(int idCur,char turno,int cap,string materia)
{
	Curso a;
	a.idCur = idCur;
	a.turno = turno;
	a.cap = cap;
	strcpy(a.materia,materia.c_str());
	return a;
}

bool cursoEquals(Curso a,Curso b)
{
	if(a.idCur!=b.idCur) return false;
	if(a.turno!=b.turno) return false;
	if(a.cap!=b.cap) return false;
	return true;
}


string cursosToString(Cursos x)
{
	char sep = 6;
	string sC=collToString<Curso>(x.c);
	return sC;
}

Cursos cursosFromString(string s)
{
	char sep = 6;
	Cursos x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<Curso>(t0);
	return x;
}

string cursosToDebug(Cursos x)
{
	stringstream sout;
	sout<< "[";
	collReset<Curso>(x.c);
	int n=collSize<Curso>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Curso q = collGetAt<Curso>(x.c,i,cursoFromString);
		sout << cursoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string cursosToDebug(string mssg,Cursos x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<Curso>(x.c);
	int n=collSize<Curso>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Curso q = collGetAt<Curso>(x.c,i,cursoFromString);
		sout << cursoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Cursos cursos(Coll <Curso> c)
{
	Cursos a;
	a.c = c;
	return a;
}

bool cursosEquals(Cursos a,Cursos b)
{
	if(collToString<Curso>(a.c)!=collToString<Curso>(b.c)) return false;
	return true;
}
// ---------------------------------------------------------------------------------------

// void cursosAgregar(Cursos& ccursos,Curso curso){
// 	collAdd<Curso>(ccursos.c,curso,cursoToString);
// }

// bool isCurso(FILE* f){
// 	return !feof(f)?true:false;
// } 

// Curso cursoLeer(FILE* cur){
// 	Curso c = read<Curso>(cur);
// 	return c;
// }


// Cursos cursosSubirConsultas(){
// 	FILE* cur = fopen("CURSOS.dat","r+b");
// 	Coll<Curso> c = coll<Curso>();
// 	Cursos ccursos = cursos(c);
// 	Curso curso = cursoLeer(cur);
// 	while (isCurso(cur))
// 	{
// 		cursosAgregar(ccursos,curso);
// 		curso = cursoLeer(cur);
// 	}
// 	fclose(cur);
// 	return ccursos;
// }

// int cmpCursoId(Curso c, int id){
// 	return c.idCur-id;
// }

// int cursosBuscar(Coll<Curso> c,int idCur){
// 	int pos = collFind<Curso,int>(c,idCur,cmpCursoId,cursoFromString);
// 	return pos;
// }

// Curso cursosObtener(Coll<Curso> c,int pos){
// 	return collGetAt<Curso>(c,pos,cursoFromString);
// }

// bool isCursosCapacidad(Curso cur){
// 	return cur.cap==0?true:false;
// }

// void cursosActualizarInscripcionesCapacidad(Curso& cur,Inscripcion ins){
// 	if (cur.cap>0 && ins.idCur == cur.idCur)
// 	{
// 		cur.cap--;
// 	}
// }

// Curso cursoBuscarCapacidadLibreYActualizar(Cursos cCurso){
// 	Curso cur ;
// 	for (int i = 0; i < collSize<Curso>(cCurso.c) ; i++)
// 	{	
// 		cur = cursosObtener(cCurso.c,i);
// 		if (!isCursosCapacidad(cur))
// 		{
// 			return cur;
// 		}
// 	}
// 	return cur;
// }

#endif
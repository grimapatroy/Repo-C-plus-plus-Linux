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


struct Padron
{
	int idEst;
	int dni;
	char nombre[20];
	char telefono[20];
	char direccion[20];
	int codigoPostal;
	int fechaNacimiento;
	int idEscuela;
	int fechaMatriculacion;
	int idSeguroSocial;
};

struct Inscripcion
{
	int idEst;
	int idEscuela;
	int fecha;
};

struct Inconsistencia
{
	int idTipoProblema;
	char nombreEstudiante[100];
	int idEscuela;
};

string padronToString(Padron x)
{
	char sep = 1;
	string sIdEst=to_string(x.idEst);
	string sDni=to_string(x.dni);
	string sNombre=x.nombre;
	string sTelefono=x.telefono;
	string sDireccion=x.direccion;
	string sCodigoPostal=to_string(x.codigoPostal);
	string sFechaNacimiento=to_string(x.fechaNacimiento);
	string sIdEscuela=to_string(x.idEscuela);
	string sFechaMatriculacion=to_string(x.fechaMatriculacion);
	string sIdSeguroSocial=to_string(x.idSeguroSocial);
	return sIdEst+sep+sDni+sep+sNombre+sep+sTelefono+sep+sDireccion+sep+sCodigoPostal+sep+sFechaNacimiento+sep+sIdEscuela+sep+sFechaMatriculacion+sep+sIdSeguroSocial;
}

Padron padronFromString(string s)
{
	char sep = 1;
	Padron x;
	string t0 = getTokenAt(s,sep,0);
	x.idEst=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.dni=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.nombre,t2.c_str());
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.telefono,t3.c_str());
	string t4 = getTokenAt(s,sep,4);
	strcpy(x.direccion,t4.c_str());
	string t5 = getTokenAt(s,sep,5);
	x.codigoPostal=stoi(t5);
	string t6 = getTokenAt(s,sep,6);
	x.fechaNacimiento=stoi(t6);
	string t7 = getTokenAt(s,sep,7);
	x.idEscuela=stoi(t7);
	string t8 = getTokenAt(s,sep,8);
	x.fechaMatriculacion=stoi(t8);
	string t9 = getTokenAt(s,sep,9);
	x.idSeguroSocial=stoi(t9);
	return x;
}

string padronToDebug(Padron x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEst;
	sout << ",";
	sout << x.dni;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.telefono;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.codigoPostal;
	sout << ",";
	sout << x.fechaNacimiento;
	sout << ",";
	sout << x.idEscuela;
	sout << ",";
	sout << x.fechaMatriculacion;
	sout << ",";
	sout << x.idSeguroSocial;
	sout<< "]";
	return sout.str();
}

string padronToDebug(string mssg,Padron x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEst;
	sout << ",";
	sout << x.dni;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.telefono;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.codigoPostal;
	sout << ",";
	sout << x.fechaNacimiento;
	sout << ",";
	sout << x.idEscuela;
	sout << ",";
	sout << x.fechaMatriculacion;
	sout << ",";
	sout << x.idSeguroSocial;
	sout<< "]";
	return sout.str();
}

Padron padron(int idEst,int dni,string nombre,string telefono,string direccion,int codigoPostal,int fechaNacimiento,int idEscuela,int fechaMatriculacion,int idSeguroSocial)
{
	Padron a;
	a.idEst = idEst;
	a.dni = dni;
	strcpy(a.nombre,nombre.c_str());
	strcpy(a.telefono,telefono.c_str());
	strcpy(a.direccion,direccion.c_str());
	a.codigoPostal = codigoPostal;
	a.fechaNacimiento = fechaNacimiento;
	a.idEscuela = idEscuela;
	a.fechaMatriculacion = fechaMatriculacion;
	a.idSeguroSocial = idSeguroSocial;
	return a;
}

bool padronEquals(Padron a,Padron b)
{
	if(a.idEst!=b.idEst) return false;
	if(a.dni!=b.dni) return false;
	if(a.codigoPostal!=b.codigoPostal) return false;
	if(a.fechaNacimiento!=b.fechaNacimiento) return false;
	if(a.idEscuela!=b.idEscuela) return false;
	if(a.fechaMatriculacion!=b.fechaMatriculacion) return false;
	if(a.idSeguroSocial!=b.idSeguroSocial) return false;
	return true;
}

string inscripcionToString(Inscripcion x)
{
	char sep = 2;
	string sIdEst=to_string(x.idEst);
	string sIdEscuela=to_string(x.idEscuela);
	string sFecha=to_string(x.fecha);
	return sIdEst+sep+sIdEscuela+sep+sFecha;
}

Inscripcion inscripcionFromString(string s)
{
	char sep = 2;
	Inscripcion x;
	string t0 = getTokenAt(s,sep,0);
	x.idEst=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idEscuela=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	return x;
}

string inscripcionToDebug(Inscripcion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEst;
	sout << ",";
	sout << x.idEscuela;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

string inscripcionToDebug(string mssg,Inscripcion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEst;
	sout << ",";
	sout << x.idEscuela;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

Inscripcion inscripcion(int idEst,int idEscuela,int fecha)
{
	Inscripcion a;
	a.idEst = idEst;
	a.idEscuela = idEscuela;
	a.fecha = fecha;
	return a;
}

bool inscripcionEquals(Inscripcion a,Inscripcion b)
{
	if(a.idEst!=b.idEst) return false;
	if(a.idEscuela!=b.idEscuela) return false;
	if(a.fecha!=b.fecha) return false;
	return true;
}

string inconsistenciaToString(Inconsistencia x)
{
	char sep = 3;
	string sIdTipoProblema=to_string(x.idTipoProblema);
	string sNombreEstudiante=x.nombreEstudiante;
	string sIdEscuela=to_string(x.idEscuela);
	return sIdTipoProblema+sep+sNombreEstudiante+sep+sIdEscuela;
}

Inconsistencia inconsistenciaFromString(string s)
{
	char sep = 3;
	Inconsistencia x;
	string t0 = getTokenAt(s,sep,0);
	x.idTipoProblema=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombreEstudiante,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.idEscuela=stoi(t2);
	return x;
}

string inconsistenciaToDebug(Inconsistencia x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idTipoProblema;
	sout << ",";
	sout << x.nombreEstudiante;
	sout << ",";
	sout << x.idEscuela;
	sout<< "]";
	return sout.str();
}

string inconsistenciaToDebug(string mssg,Inconsistencia x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idTipoProblema;
	sout << ",";
	sout << x.nombreEstudiante;
	sout << ",";
	sout << x.idEscuela;
	sout<< "]";
	return sout.str();
}

Inconsistencia inconsistencia(int idTipoProblema,string nombreEstudiante,int idEscuela)
{
	Inconsistencia a;
	a.idTipoProblema = idTipoProblema;
	strcpy(a.nombreEstudiante,nombreEstudiante.c_str());
	a.idEscuela = idEscuela;
	return a;
}

bool inconsistenciaEquals(Inconsistencia a,Inconsistencia b)
{
	if(a.idTipoProblema!=b.idTipoProblema) return false;
	if(a.idEscuela!=b.idEscuela) return false;
	return true;
}



Padron buscarEstudiante(int idEst,FILE* fPadron,bool& enc){
	// buscaremos directamente sobre el archivo padron como esta ordenado por idEst

	Padron regPradron ;
	// aplicamos busqeudad binaria , definimos los indices
	int i = 0; //indice inicial
	int j = fileSize<Padron>(fPadron)-1; //indice final

	enc=false;
	while (i<=j && !enc)
	{
		int k = (i+k)/2;
		// posiciono y leo
		seek<Padron>(fPadron,k);
		regPradron = read<Padron>(fPadron);
		
		if (regPradron.idEst<idEst)
		{
			// actualizo indice i para descartar la aprte anterior
			i=k+1;
		}
		else
		{
			if (regPradron.idEst>idEst)
			{
				j=k-1;
			}
			else
			{
				enc = true;
			}
		}
	}
	return regPradron;
}


int fechaCmp(int regfecha, int padronfech){
	return regfecha-padronfech;
}

void procesarInscripcion(Inscripcion regIns,Padron elemPradon,FILE* fOut,bool& enc){

	Inconsistencia out;

	// asignamos la idEscuela involucrada
	out.idEscuela = regIns.idEscuela;
	// el estudiante no es encontrado
	if (!enc)
	{
		strcpy(out.nombreEstudiante,"desconocido!!");
		out.idTipoProblema = ERR_ESTINEXIST;
		write<Inconsistencia>(fOut,out);
	}
	else
	{
		// guardo el nombre del estudiante 
		strcpy(out.nombreEstudiante,elemPradon.nombre);

		if(regIns.idEscuela!=elemPradon.idEscuela)
		{
		// el estudiante figura matriculado a una escuela diferente a la ques e matriculo
			out.idTipoProblema = ERR_ESCUELADIF;
			write<Inconsistencia>(fOut,out);
		}
		else
		{
			if (fechaCmp(regIns.fecha,elemPradon.fechaMatriculacion)<0)
			{
				out.idTipoProblema = ERR_FECHAANT;
				write<Inconsistencia>(fOut,out);
			}
		}
	}
}











#endif
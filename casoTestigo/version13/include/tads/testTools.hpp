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

struct Idx
{
	int codigoPostal;
	int pos;
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

string idxToString(Idx x)
{
	char sep = 2;
	string sCodigoPostal=to_string(x.codigoPostal);
	string sPos=to_string(x.pos);
	return sCodigoPostal+sep+sPos;
}

Idx idxFromString(string s)
{
	char sep = 2;
	Idx x;
	string t0 = getTokenAt(s,sep,0);
	x.codigoPostal=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.pos=stoi(t1);
	return x;
}

string idxToDebug(Idx x)
{
	stringstream sout;
	sout<< "[";
	sout << x.codigoPostal;
	sout << ",";
	sout << x.pos;
	sout<< "]";
	return sout.str();
}

string idxToDebug(string mssg,Idx x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.codigoPostal;
	sout << ",";
	sout << x.pos;
	sout<< "]";
	return sout.str();
}

Idx idx(int codigoPostal,int pos)
{
	Idx a;
	a.codigoPostal = codigoPostal;
	a.pos = pos;
	return a;
}

bool idxEquals(Idx a,Idx b)
{
	if(a.codigoPostal!=b.codigoPostal) return false;
	if(a.pos!=b.pos) return false;
	return true;
}


// int cmpIntId(int idEst, int id){
// 	return idEst-id;
// }

// Coll<int> idxCrear (FILE* archPadron){
// 	// inicializo la conexion
// 	Coll<int> idx = coll<int>();
// 	// posiciono el marcador de posicion en el registro 0 del archivo
// 	seek<Padron>(archPadron,0);
// 	Padron regPadron = read<Padron>(archPadron);
// 	while (!feof(archPadron))
// 	{
// 		collAdd<int>(idx,regPadron.idEst,intToString);
// 		regPadron = read<Padron>(archPadron);
// 	}
// 	return idx;
// }
// Padron idxBuscar(FILE* archPadron, int regIdEst,bool& enc, Coll<int> idx){
// 	Padron elemPadron;
// 	int pos = collFind<int,int>(idx,regIdEst,cmpIntId,stringToInt);
// 	if (pos>=0)
// 	{
// 		// ubicamos el objeto y lo leemos
// 		seek<Padron>(archPadron,pos);
// 		elemPadron = read<Padron>(archPadron);
// 	}
// 	enc = pos>=0;
// 	return elemPadron;
// }
// Padron buscarEstudiante( FILE* archPadron, int regIdEst,bool& enc, Coll<int> idx){
// 	return idxBuscar( archPadron, regIdEst,enc, idx);
// }
// int cmpFecha(int fecharegInscrip, int fechaMatriPadron){
// 	return fecharegInscrip-fechaMatriPadron;
// }

// void procesarIncripcion(Padron regPadron,bool& enc,FILE* archOut, Inscripcion regInscrip){
// 	// se crea un elemento inconsistencia para grabar en el archivo
// 	Inconsistencia elemOut;
// 	// se guarda el escuela involucrada
// 	elemOut.idEscuela = regInscrip.idEscuela;
// 	if (!enc)
// 	{
// 		strcpy(elemOut.nombreEstudiante,"desconocido");
// 		elemOut.idTipoProblema = ERR_ESTINEXIST;
// 		// grabo el elemento
// 		write<Inconsistencia>(archOut,elemOut);
// 	}
// 	else
// 	{
// 		// guardo el nombre del estudiante
// 		strcpy(elemOut.nombreEstudiante,regPadron.nombre);
// 			if (regPadron.idEst != regInscrip.idEst)
// 			{
// 				elemOut.idTipoProblema = ERR_ESCUELADIF;
// 				write<Inconsistencia>(archOut,elemOut);
// 			}
// 			else
// 			{
// 				if (cmpFecha(regInscrip.fecha,regPadron.fechaMatriculacion)<0)
// 				{
// 					elemOut.idTipoProblema = ERR_FECHAANT;
// 					write<Inconsistencia>(archOut,elemOut);
// 				}
// 		}
// 	}
// }

int cpmIdx ( Idx a , Idx b){
	return a.codigoPostal-b.codigoPostal;
}



Coll<Idx> crearIndexacion(FILE* archPadron) {
	
	// inicializo la coleccion
	Coll<Idx>  collIdx = coll<Idx>();

	// reinicio la lectura de la indicador de  poscion del archivo en la pos = 0
	seek<Padron>(archPadron,0);

	// recorremos el archivo
	Padron p  = read<Padron>(archPadron);
	while (!feof(archPadron))
	{
		// creo un elemento idx para meterlo a la coleccion
		Idx i = idx(p.codigoPostal,filePos<Padron>(archPadron)-1);

		// lo agrego a la coleccion
		collAdd<Idx>(collIdx,i,idxToString);

		// leo el siguiente registro
		p  = read<Padron>(archPadron);
	}
	// ordeno la coleccion por codigo postal
	collSort<Idx>(collIdx,cpmIdx,idxFromString,idxToString);

	return collIdx;
}




Padron leerPadron(FILE* archPadron,int  pos){
	
	seek<Padron>(archPadron,pos);
	
	return read<Padron>(archPadron);
}




#endif
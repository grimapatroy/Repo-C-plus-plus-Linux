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
struct Rendi
{
	int idAsig;
	char comision;
	double califProm;
};

struct Lst1
{
	int idAsig;
	char comMax;
	double max;
	char comMin;
	double min;
};

struct Lst2
{
	int idAsig;
	double promGral;
};

struct LstA
{
	int idAsig;
	double prom2;
	double porc;
};

string rendiToString(Rendi x)
{
	char sep = 1;
	string sIdAsig=to_string(x.idAsig);
	string sComision=string(1,x.comision);
	string sCalifProm=to_string(x.califProm);
	return sIdAsig+sep+sComision+sep+sCalifProm;
}

Rendi rendiFromString(string s)
{
	char sep = 1;
	Rendi x;
	string t0 = getTokenAt(s,sep,0);
	x.idAsig=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.comision=(char)t1[0];
	string t2 = getTokenAt(s,sep,2);
	x.califProm=stod(t2);
	return x;
}

string rendiToDebug(Rendi x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.comision;
	sout << ",";
	sout << x.califProm;
	sout<< "]";
	return sout.str();
}

string rendiToDebug(string mssg,Rendi x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAsig;
	sout << ",";
	sout << x.comision;
	sout << ",";
	sout << x.califProm;
	sout<< "]";
	return sout.str();
}

Rendi rendi(int idAsig,char comision,double califProm)
{
	Rendi a;
	a.idAsig = idAsig;
	a.comision = comision;
	a.califProm = califProm;
	return a;
}

bool rendiEquals(Rendi a,Rendi b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.comision!=b.comision) return false;
	if(a.califProm!=b.califProm) return false;
	return true;
}

string lst1ToString(Lst1 x)
{
	char sep = 2;
	string sIdAsig=to_string(x.idAsig);
	string sComMax=string(1,x.comMax);
	string sMax=to_string(x.max);
	string sComMin=string(1,x.comMin);
	string sMin=to_string(x.min);
	return sIdAsig+sep+sComMax+sep+sMax+sep+sComMin+sep+sMin;
}

Lst1 lst1FromString(string s)
{
	char sep = 2;
	Lst1 x;
	string t0 = getTokenAt(s,sep,0);
	x.idAsig=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.comMax=(char)t1[0];
	string t2 = getTokenAt(s,sep,2);
	x.max=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.comMin=(char)t3[0];
	string t4 = getTokenAt(s,sep,4);
	x.min=stod(t4);
	return x;
}

string lst1ToDebug(Lst1 x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.comMax;
	sout << ",";
	sout << x.max;
	sout << ",";
	sout << x.comMin;
	sout << ",";
	sout << x.min;
	sout<< "]";
	return sout.str();
}

string lst1ToDebug(string mssg,Lst1 x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAsig;
	sout << ",";
	sout << x.comMax;
	sout << ",";
	sout << x.max;
	sout << ",";
	sout << x.comMin;
	sout << ",";
	sout << x.min;
	sout<< "]";
	return sout.str();
	}

Lst1 lst1(int idAsig,char comMax,double max,char comMin,double min)
{
	Lst1 a;
	a.idAsig = idAsig;
	a.comMax = comMax;
	a.max = max;
	a.comMin = comMin;
	a.min = min;
	return a;
}

bool lst1Equals(Lst1 a,Lst1 b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.comMax!=b.comMax) return false;
	if(a.max!=b.max) return false;
	if(a.comMin!=b.comMin) return false;
	if(a.min!=b.min) return false;
	return true;
}

string lst2ToString(Lst2 x)
{
	char sep = 3;
	string sIdAsig=to_string(x.idAsig);
	string sPromGral=to_string(x.promGral);
	return sIdAsig+sep+sPromGral;
}

Lst2 lst2FromString(string s)
{
	char sep = 3;
	Lst2 x;
	string t0 = getTokenAt(s,sep,0);
	x.idAsig=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.promGral=stod(t1);
	return x;
}

string lst2ToDebug(Lst2 x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.promGral;
	sout<< "]";
	return sout.str();
}

string lst2ToDebug(string mssg,Lst2 x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAsig;
	sout << ",";
	sout << x.promGral;
	sout<< "]";
	return sout.str();
}

Lst2 lst2(int idAsig,double promGral)
{
	Lst2 a;
	a.idAsig = idAsig;
	a.promGral = promGral;
	return a;
}

bool lst2Equals(Lst2 a,Lst2 b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.promGral!=b.promGral) return false;
	return true;
}

string lstAToString(LstA x)
{
	char sep = 4;
	string sIdAsig=to_string(x.idAsig);
	string sProm2=to_string(x.prom2);
	string sPorc=to_string(x.porc);
	return sIdAsig+sep+sProm2+sep+sPorc;
}

LstA lstAFromString(string s)
{
	char sep = 4;
	LstA x;
	string t0 = getTokenAt(s,sep,0);
	x.idAsig=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.prom2=stod(t1);
	string t2 = getTokenAt(s,sep,2);
	x.porc=stod(t2);
	return x;
}

string lstAToDebug(LstA x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.prom2;
	sout << ",";
	sout << x.porc;
	sout<< "]";
	return sout.str();
}

string lstAToDebug(string mssg,LstA x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAsig;
	sout << ",";
	sout << x.prom2;
	sout << ",";
	sout << x.porc;
	sout<< "]";
	return sout.str();
}

LstA lstA(int idAsig,double prom2,double porc)
{
	LstA a;
	a.idAsig = idAsig;
	a.prom2 = prom2;
	a.porc = porc;
	return a;
}

bool lstAEquals(LstA a,LstA b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.prom2!=b.prom2) return false;
	if(a.porc!=b.porc) return false;
	return true;
}

void procesar1(Rendi& regRend19,FILE* arch19,Coll<Lst1>& collLista2019){
	// coloco el registro leido como max
	char cComMax = regRend19.comision;
	double dMax = regRend19.comision;

	// coloco el registro leido como min
	char cComMin = regRend19.comision;
	double dMin = regRend19.comision;

	// corte de control
		// variable de control , id sig Anterior
		int idAsingAnt = regRend19.idAsig;
		while (!feof(arch19) && regRend19.idAsig)
		{
			// maximos y minimos
			if (regRend19.califProm>dMax)
			{
				dMax = regRend19.califProm;
				cComMax = regRend19.comision;
			}
			else
			{
				if (regRend19.califProm<dMin)
				{
					dMin = regRend19.califProm;
					cComMin = regRend19.comision;
				}	
			}
			regRend19 = read<Rendi>(arch19);	
		}
		// agregamos a la coleccion la peor y mejor calificacion promedio
		Lst1 elemLst1 = lst1(idAsingAnt,cComMax,dMax,cComMin,dMin);
		collAdd<Lst1>(collLista2019,elemLst1,lst1ToString);
}


double promCC(FILE* arch,Rendi& regX){
	
	int cont = 0;
	double sum = 0;

	int idAsignatura = regX.idAsig;
	while (!feof(arch) && idAsignatura == regX.idAsig)
	{
		sum += regX.califProm;
		cont++;

		regX = read<Rendi>(arch);
	}
	
	double prom = sum/(double)cont;
	return prom;
}



void procesar2(Rendi& regRend20,FILE* arch20,Coll<Lst2>& collLista2020){
	// Aplicar corte de control por que me pide el sub todal de un grupo , agrupado por id
	int idAsingAnt = regRend20.idAsig;//guardo el registro del id por que co conte de control van a seguir avanzando los registros
	double dPromGra = promCC(arch20,regRend20);//corte de cortrol
	
	Lst2 elemLst2 = lst2(idAsingAnt,dPromGra);
	collAdd<Lst2>(collLista2020,elemLst2,lst2ToString);
}


void procesar3(Rendi& regRend19,Rendi& regRend20,FILE* arch19,FILE* arch20,Coll<LstA>& collListaAmbas){

	int idAsignatura =  regRend19.idAsig; // puedes guardar cualquier id(2019-2020) , ya que vienen siendo comparados por el else, y cuando aga conte de control va a cambiar de id
	double prom2019 = promCC(arch19,regRend19);//corte de control
	double prom2020 = promCC(arch20,regRend20); // corte de control
	double porcion = 100-prom2019/prom2020*100;

	LstA elemAmbos = lstA(idAsignatura,prom2020,porcion);
	collAdd<LstA>(collListaAmbas,elemAmbos,lstAToString);

}


void mostrarResultados(Coll<Lst1> collLista2019){
	cout<<"CALIFICACIONES DEL 2019"<<endl;
	collReset<Lst1>(collLista2019);
	while (collHasNext<Lst1>(collLista2019))
	{
		Lst1 elemLst1 = collNext<Lst1>(collLista2019,lst1FromString);
		cout<<"ID ASIGNATURA: "<<elemLst1.idAsig<<endl;
		cout<<"COMISION MAYOR: "<<elemLst1.comMax<<endl;
		cout<<"PROMEDIO MAYOR: "<<elemLst1.max<<endl;
		cout<<"COMISION MENOR: "<<elemLst1.comMin<<endl;
		cout<<"PROMEDIO MENOR: "<<elemLst1.min<<endl;
		cout<<endl;
	}
}


void mostrarResultados(Coll<Lst2> collLista2020){
	cout<<"CALIFICACIONES DEL 2020"<<endl;
	collReset<Lst2>(collLista2020);
	while (collHasNext<Lst2>(collLista2020))
	{
		Lst2 elemLst2 = collNext<Lst2>(collLista2020,lst2FromString);
		cout<<"ID ASIGNATURA: "<<elemLst2.idAsig<<endl;
		cout<<"PROMEDIO GENERAL: "<<elemLst2.promGral<<endl;
		cout<<endl;
	}
}


void mostrarResultados(Coll<LstA> collListaAmbas){
	cout<<"CALIFICACIONES DE AMBOS AÑOS"<<endl;
	collReset<LstA>(collListaAmbas);
	while (collHasNext<LstA>(collListaAmbas))
	{
		LstA elemLstA = collNext<LstA>(collListaAmbas,lstAFromString);
		cout<<"ID ASIGNATURA: "<<elemLstA.idAsig<<endl;
		cout<<"PROMEDIO DEL AÑO 2020: "<<elemLstA.prom2<<endl;
		cout<<"PROCENTAJE DE DIFERENCIA ANTE EL 2019: "<<elemLstA.porc<<endl;
		cout<<endl;
	}
}

#endif
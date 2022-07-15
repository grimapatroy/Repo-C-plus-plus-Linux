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
    int idCiu; //identificador de ciudad
    char descr[20]; // descripcion o nombre de la ciudad
    int millas; //distancia
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



// Coll<Ciudad> subirCiudades()
// {
// 		FILE* f = fopen("CIUDADES.dat","r+b");
		
// 		Coll<Ciudad> collCi = coll<Ciudad>();
// 		Ciudad elem = read<Ciudad>(f);
// 		while(!feof(f))
// 		{
// 			collAdd<Ciudad>(collCi,elem,ciudadToString);
// 			elem = read<Ciudad>(f);
// 		}
// 		fclose(f);
// 	return collCi;
// }

// int cmpIdCiudad (Ciudad c, int cod)
// {
// 	return c.idCiu-cod;
// }


// Ciudad buscarCiudad(Coll<Ciudad> collCiudad, int cod , bool& encontrado){
// 	Ciudad c;
// 	int pos = collFind<Ciudad>(collCiudad,cod,cmpIdCiudad,ciudadFromString);
// 	encontrado = pos>=0;

// 	if (encontrado)
// 	{
//         c = collGetAt<Ciudad>(collCiudad,pos,ciudadFromString);
// 		return c;
// 	}
// 	return c;
// }

Ciudad buscarCiudad(FILE* f,int id,bool& encontrado)
{
	encontrado = false;
	int i = 0; // primer registro
	int j = fileSize<Ciudad>(f)-1; // ultimo registro
	Ciudad ret;
	while( i<=j && !encontrado )
	{
		// posicion intermedia entre i y j
		int k = (i+j)/2;
		// accedo al archivo y veo si encuentro lo que busco
		seek<Ciudad>(f,k);
		ret = read<Ciudad>(f);
		// actualizo los indices
		// i = ret.idCiu<id?k+1:i;
		// j = ret.idCiu>id?k-1:j;
		// encontrado = (i>=j&ret.idCiu==id)?1:0;
			if(ret.idCiu<id){
				i = k+1;
			}else
			{
				if (ret.idCiu>id)
				{
					j=k-1;
				}
				else
				{
					encontrado = true;
				}
			}
	}
	return ret;
}


#endif

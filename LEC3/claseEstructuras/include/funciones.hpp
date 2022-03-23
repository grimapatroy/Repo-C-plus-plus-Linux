#ifndef _TADFecha
#define _TADFecha

#include <iostream>
#include <string.h>
using namespace std;


struct Direccion
{
  string calle;
  int lote;
  int piso;
  char seccion;
  string numero;
};


struct FechaNacimiento
  {
        int dia;
        int mes;
        int anio;
  };

struct Persona
{
      string nombre;
      int dni;
      FechaNacimiento fecha;  //estructura anidada
      Direccion direccion;    //estructura anidada
};

// -----------------------------------FUNCIONES ( PROPIAS DEL TAD)------------------------------------------------------------------------

//funcion de inicializacion de la ESTRUCTURA PERSONA
Persona persona(string n, int dni, FechaNacimiento f, Direccion d)
{
  return {n,dni,f,d};
}

//funcion de inicializacion de la ESTRUCTURA DIRECCION
Direccion direccion(string c, int lote, int piso, char seccion, string num)
{
  return {c,lote,piso,seccion,num};
}


    
//funcion de inicializacion de la ESTRUCTURA FECHA
FechaNacimiento fecha(int d, int m, int a)
{
  // Fecha f;
    // f.dia = 10;
    // f.mes = 12;
    // f.anio = 2020;
    // return f;
  return {d,m,a};
}

// *********************************************************
bool fechaEsAnioBisiesto(FechaNacimiento f)
{
  int a = f.anio;
  return (a%4==0 or a%400==0 and a%100!=0);
}


// es comodo recibir todos los datos de Fecha, aunque solo vamos a querer mes y anios
int fechaDiasDeslMes(FechaNacimiento f)
{
  int nDias =31;
  int m;
    m=f.mes;
  if (m==4 || m==6 || m==9 || m==11)
  { 
    nDias = 30;
  }else
  {
      if (m==2)
      {
       nDias = 28;
       if (fechaEsAnioBisiesto(f))
       {
         nDias= 29;
       }
      }
  } 
  return nDias;
}


bool fechaValidar(FechaNacimiento f)
{
  bool fok = false;
  int d,m,a;
    a=f.dia;
    m=f.mes;
    d=f.anio;
  if (m>=1 and m<=12)
  {
    if (a>0)
    {
      int nDias = fechaDiasDeslMes(f);
      if (d>=1 and d<=nDias)
      {
        fok = true;
      }
    }
  }
  return fok;
}
// *********************************************************
// -----------------------------------------------------------------------------------------------------------


// ---------------------------------------------funcion conversion para poder representarla por consola(salida)-------------------------------------------------------------

//fecha a cadena
string fechaToString(FechaNacimiento f)
{
  string sDia, sMes, sAnio;
  sDia = to_string(f.dia);
  sMes = to_string(f.mes);
  sAnio = to_string(f.anio);
  
  return sDia+"/"+sMes+"/"+sAnio;
}

string direccionToString(Direccion d)
{
  string sLote,sPiso,sSeccion;
  sLote = to_string(d.lote);
  sPiso = to_string(d.piso);
  sSeccion=to_string(d.seccion);
  
  return d.calle+" "+sLote+" "+sPiso+" "+sSeccion+" "+d.numero;
}

string personaToString(Persona p)
{
  string sDNI;
  sDNI = to_string(p.dni);

  return p.nombre+" con el "+sDNI+" "+fechaToString(p.fecha)+" "+direccionToString(p.direccion);
}

// -----------------------------------------------------------------------------------------------------------

#endif
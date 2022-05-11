#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

int GLOBAL =-1, GLOBAL1=-1;




// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------
   struct Persona
   {
      int dni;
      string nombre;
   };
// ------##########FUNCIONES DEL TAD Struct PERSONA##################-------------------------

   Persona persona(int a ,string n){
      return {a,n};
   }
// ---------------------------------------------------------
   string personaToString(Persona p){
      // devuelve addToken
      return intToString(p.dni) + "," + p.nombre;
   }

   Persona personaFromString(string a){
      Persona p;
      p.dni=stringToInt(getTokenAt(a,',',0));// destokenizar a
      p.nombre=getTokenAt(a,',',1);// tokenizar a
      return p;
   }
// ------################################################-------------------------
// ------##########FUNCIONES DEL TAD String##################-------------------------
// ----------------------------------------------------------------
string stringFromString(string cadena){
   return cadena;
}



// ----------------------------------------------------------------
// -------------funciones de comparacion--------------------------------------------

   int cmpPersonaDNI(Persona p,int dni)
   {
      return p.dni-dni;
   }
// ------------------------------------
   int cmpPersonaNombre(Persona p, string k){

      return p.nombre<k?-1:p.nombre>k?1:0;
   }
   // int cmpPersonaNombre2(Persona p1,Persona p2){
   //    return p1.nombre<p2.nombre?-1:p1.nombre>p2.nombre?1:0;
   // }

   int cmpPersonasNomAsc(Persona p1,Persona p2)
   {
      int i = p2.nombre<p1.nombre?-1:p2.nombre>p1.nombre?1:0;
      // int i =p1.nombre>p2.nombre?-1:p1.nombre<p2.nombre?1:0;
      // int i =p1.nombre<p2.nombre?1:p1.nombre<p2.nombre?-1:0;
      return i;
   }

   int cmpPersonasNomDesc(Persona p1,Persona p2)
   {
      int i= p1.nombre<p2.nombre?-1:p1.nombre>p2.nombre?1:0;
      return i;
   }

   int cmpPersonasDNI(Persona p1,Persona p2)
   {
   return p1.dni-p2.dni;
   }


// ----------------------------------------------------------------
   // ascendente
   int cmpInt (int a,int b){
      return b-a;
   }

// ----------------------------------------------------------------
// ----------------------------------------------------------------


template<typename T>
struct Coll
{
   string s;
   char sep;
};

template<typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.s="";
   c.sep='|';
   return c;
}

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s="";
   c.sep=sep;
   return c;
}

template<typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s="";
   // coll();
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   // c.s = getTokenAt();
   removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sep,tToString(t));
   return tokenCount(c.s,c.sep)-1;
}

// obj0 |obj1 |obj2 |obj3 |obj4
template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   // c.s = sub
   removeTokenAt(c.s,c.sep,p);
   setTokenAt(c.s,c.sep,tToString(t));
   // addToken(c.s,) 
}

// obj0 |obj1 |obj2 |obj3 |obj4
template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t;
   t = tFromString(getTokenAt(c.s,c.sep,p));
   return t; 
}


// 33,joel | 44,Pedro | 55,Ramon |15,Lili | 20,Lesli
// obj0 |obj1 |obj2 |obj3 |obj4   -------- k
// coll c
template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   int i;
   for (i = 0; i < collSize(c); i++)
   {
      T t =tFromString(getTokenAt(c.s,c.sep,i)) ;
      if(cmpTK(t,k)==0){
         return i;
      }
   }
   return -1;
}


// 33,Dedro | 44,Bablo | 55,Carlos |15,Auan | 20,Lesli
// obj0 |obj1 |obj2 |obj3 |obj4   -------- k
template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   int j;
   bool ordenado = false;
   // int rondas = 0;
      while (!ordenado)
      {
         ordenado = true;
         for ( j = 0; j <collSize(c)-1; j++)
         {
            int posT1 = j;
            int posT2 = j+1;
            T t1 = tFromString(getTokenAt(c.s,c.sep,posT1));
            T t2 = tFromString(getTokenAt(c.s,c.sep,posT2));
            // maximos y minimos 
               if(cmpTT(t1,t2)<0  or cmpTT(t1,t2)>0 )
               {
                        if (cmpTT(t1,t2)<0)
                        {
                                 T temp = t1;
                                 if (posT1!=0)
                                 {
                                 setTokenAt(c.s,c.sep,tToString(t2),posT1);
                                 // setTokenAt(c.s,c.sep,tToString(temp),posT2);
                                 removeTokenAt(c.s,c.sep,posT2+1);
                                 ordenado = false;
                                 }else
                                 {
                                    setTokenAt(c.s,c.sep,tToString(t2),posT1);
                                    setTokenAt(c.s,c.sep,tToString(temp),posT2);
                                    removeTokenAt(c.s,c.sep,posT2+1);
                                    ordenado = false;
                                 }
                        }else{
                                 continue;
                              }
               }else
                     {
                        continue;
                     }
         }// rondas++;
      }
}


// obj0 |obj1 |obj2 |obj3 |obj4
template<typename T>
bool collHasNext(Coll<T> c)
{
   // static int contador=-1;
   // if (tokenCount(c.s,c.sep)==0)
   // {
   //       return false;
   // }
   // else
   // {
   //    while (++contador<tokenCount(c.s,c.sep))
   //    {
   //       return true;
   //    }
   //    return false;
   // }
   if (tokenCount(c.s,c.sep)==0)
   {
         return false;
   }
   else
   {
      while (++GLOBAL<tokenCount(c.s,c.sep))
      {
         // GLOBAL++;
         return true;
      }
   }
   return false;
}

template<typename T>
int collSgt(Coll<T> c)
{
   static int conteo =-1;
   if(conteo < tokenCount(c.s,c.sep))
   {
      conteo ++;
   }
   return conteo;
}

// obj0 |obj1 |obj2 |obj3 |obj4
template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t = tFromString(getTokenAt(c.s,c.sep,GLOBAL));
   // T t = tFromString(getTokenAt(c.s,c.sep,collSgt<T>(c)));
   return t;
}




// obj0 |obj1 |obj2 |obj3 |obj4
template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   // endOfColl = ++GLOBAL<tokenCount(c.s,c.sep)?true:false;
   if(++GLOBAL1<tokenCount(c.s,c.sep))
   {
      t = tFromString(getTokenAt(c.s,c.sep,GLOBAL1));
   }else{
      endOfColl = 1; 
   }
   
   return t;
}



// obj0 |obj1 |obj2 |obj3 |obj4
template<typename T>
void collReset(Coll<T>& c)
{
   GLOBAL = -1;
   GLOBAL1 = -1;
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------

// ------------------------funciones para coleccion de colecciones de tipo T----------------------------------
// TtoString

string collIntToString(Coll<int> x){
   string r="";
   collReset<int>(x);
   while (collHasNext<int>(x))
   {
      int i = collNext<int>(x,stringToInt);
      addToken(r,',',intToString(i));
   }
   return r;
}

// tFromString
Coll<int>  collIntFromString(string s){
   Coll<int> x = coll<int>(',');  
   for (int i = 0; i < tokenCount(s,','); i++)
   {
      int token = stringToInt(getTokenAt(s,',',i));
      collAdd<int>(x,token,intToString);
   }
   
   return x;
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------


// Colecciones de estructuras que tienen colecciones
   struct Conjunto
   {
      string nombre;
      Coll<int>c;
   };
   
// ----------------------------------------------------------------
// Funciones de Colecciones de estructuras que tienen colecciones


string conjuntoToString(Conjunto cjt){
   
   string token=cjt.nombre+"#";
   // collReset<int>(cjt.c);
   // while (collHasNext<int>(cjt.c))
   // {
   // }
   int size = collSize<int>(cjt.c);
   for (int i = 0; i < size; i++)
   {
      int subTokenInt = collGetAt<int>(cjt.c,i,stringToInt);
      token += intToString(subTokenInt)+(i<size-1?",":"");
   }
   return token;
}

Conjunto conjuntoFromString(string token){
   Conjunto c;
   
   c.nombre = getTokenAt(token,'#',0);

   c.c = coll<int>(',');
   string x = getTokenAt(token,'#',1);
   for (int i = 0; i < tokenCount(x,','); i++)
   {
      int subTokenInt = stringToInt(getTokenAt(x,',',i));
      collAdd<int>(c.c,subTokenInt,intToString);
   }
   return c;
}

void mostrarColeccion(Coll<Persona> c) 
{ 
   collReset<Persona>(c); 
   while( collHasNext<Persona>(c))
   {
      Persona p = collNext<Persona>(c,personaFromString);
      cout<<personaToString(p)<<endl;
   }
} 



#endif

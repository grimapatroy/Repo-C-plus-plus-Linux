#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

int GLOBAL =-1, GLOBAL1=-1;
// ----------------------------------------------------------------
   struct Persona
   {
      int dni;
      string nombre;
   };

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


// ---------------------------------------------------------

   int cmpPersonaDNI(Persona p,int dni)
   {
      return p.dni-dni;
   }
// ------------------------------------
   int cmpPersonaNombre(Persona p, string k){

      return p.nombre<k?-1:p.nombre>k?1:0;
   }
   int cmpPersonaNombre2(Persona p1,Persona p2){
      return p1.nombre<p2.nombre?-1:p1.nombre>p2.nombre?1:0;
   }


// ----------------------------------------------------------------
string stringFromString(string cadena){

   return cadena;
}


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
   T temporal;
   int j;
   bool ordenado = false;
   int rondas = 0;
      while (!ordenado)
      {
         ordenado = true;
         for ( j = 0; j <collSize(c)-1-rondas; j++)
         {
            T t1 = tFromString(getTokenAt(c.s,c.sep,j));
            T t2 = tFromString(getTokenAt(c.s,c.sep,j+1));
            if (cmpTT(t1,t2)<0)
            {
               temporal = t1;
               if (collSize(c)-1==rondas+1)
               {
                  setTokenAt(c.s,c.sep,tToString(t2),j);
                  setTokenAt(c.s,c.sep,tToString(temporal),j+1);
                  removeTokenAt(c.s,c.sep,j+2);
                  ordenado = true;
                  break;
               }
               setTokenAt(c.s,c.sep,tToString(t2),j);
               removeTokenAt(c.s,c.sep,j+2);
                  // removeTokenAt(c.s,c.sep,j+1);
               ordenado = false;
            }
         }
         rondas++;
      }
      
}


// obj0 |obj1 |obj2 |obj3 |obj4
template<typename T>
bool collHasNext(Coll<T> c)
{

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


// obj0 |obj1 |obj2 |obj3 |obj4
template<typename T>
T collNext(Coll<T>& c,T tFromStrGLOBALng(string))
{
   T t = tFromStrGLOBALng(getTokenAt(c.s,c.sep,GLOBAL));
   return t;
}


// obj0 |obj1 |obj2 |obj3 |obj4
template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   endOfColl = ++GLOBAL<tokenCount(c.s,c.sep)?true:false;
   if(endOfColl and ++GLOBAL1<tokenCount(c.s,c.sep))
   {
      t = tFromString(getTokenAt(c.s,c.sep,GLOBAL1));
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

#endif

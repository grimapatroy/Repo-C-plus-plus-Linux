#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

int GLOBAL =-1, GLOBAL1=-1;


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
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sep,tToString(t));
   return tokenCount(c.s,c.sep)-1;
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t;
   t = tFromString(getTokenAt(c.s,c.sep,p));
   return t; 
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.s,c.sep,tToString(t),p);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sep,p);
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   int i;
   int n = collSize<T>(c);
   for (i = 0; i < n; i++)
   {
      string token = getTokenAt(c.s,c.sep,i);
      T t =tFromString(token) ;
      if(cmpTK(t,k)==0){
         return i;
      }
   }
   return -1;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   int j;
   bool ordenado = false;
      while (!ordenado)
      {
         ordenado = true;
         for ( j = 0; j <collSize<T>(c)-1; j++)
         {
            int posT1 = j;
            int posT2 = j+1;
            T t1 = tFromString(getTokenAt(c.s,c.sep,posT1));
            T t2 = tFromString(getTokenAt(c.s,c.sep,posT2));
            if (cmpTT(t1,t2)>0)
            {
                     T temp = t1;
                     setTokenAt(c.s,c.sep,tToString(t2),posT1);
                     setTokenAt(c.s,c.sep,tToString(temp),posT2);
                     ordenado = false;
            }
         }
      }
}


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
   // static int temp = 0 ;
   // if (tokenCount(c.s,c.sep)==0)
   // {
   //    return false;
   // }
   // else
   // {
   //       while (++temp<tokenCount(c.s,c.sep)){
   //       // c.cont = temp;
   //       return true;
   //    }
   // }
   // return false;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t = tFromString(getTokenAt(c.s,c.sep,GLOBAL));
   // static int temp2 = -1 ;
   // T t = tFromString(getTokenAt(c.s,c.sep,++temp2));
   // T t = tFromString(getTokenAt(c.s,c.sep,collSgt<T>(c)));
   return t;
}




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

template<typename T>
string collToString(Coll<T> c)
{
	return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
	Coll<T> c;
	c.sep=s[0];
	c.s=substring(s,1);
	return c;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
// ----------------------------------------------------------------




#endif
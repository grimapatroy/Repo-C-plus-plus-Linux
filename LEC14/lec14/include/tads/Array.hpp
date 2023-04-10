#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "../funciones/arrays.hpp"

using namespace std;

void redimensionar(int*& p,int cap,int nuevaCap){
   // creo un array con la nueva capacidad
   int* b = new int[nuevaCap];
   // copio los datos del array a al array b
   for(int i=0; i<cap; i++){
         b[i]=p[i];
      }
// libero el array p
delete p;
// hago que a apunte al nuevo array
p = b;
}


template<typename T>
struct Array
{
   T* p;
   int cap;
   int len;
};

template<typename T>
Array<T> array(int cap)
{
   Array<T> a ;
   a.p = new T[cap];
   a.cap = cap;
   a.len = 0;
   return a;
}

template<typename T>
Array<T> array()
{
   Array<T> a;
   a.p = new T[0];
   a.cap=0;
   a.len=0;
   return a;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{  
   int pos = 0; 
   if (a.cap!=0)
   {
      if (a.len==a.cap)
      {
         redimensionar(a.p,a.cap,a.cap*2);
         a.cap =a.cap*2;
      }
      // agrego
      pos = add<T>(a.p,a.len,t);
   }
   else
   {
      pos = add<T>(a.p,a.len,t);
      a.cap = a.len;
   }
   return pos;
}

template<typename T>
T* arrayGet(Array<T> a,int pos)
{
   return a.p+pos;
}

template<typename T>
void arraySet(Array<T>& a,int pos,T t)
{
   a.p[pos]=t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int pos)
{
      if (a.cap!=0)
      {
         if (a.len==a.cap)
         {
            redimensionar(a.p,a.cap,a.cap*2);
            a.cap =a.cap*2;
         }
         // inserto
         insert<T>(a.p,a.len,t,pos);
      }
      else
      {
         // agrego
         add<T>(a.p,a.len,t);
         a.cap = a.len;
      }
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int pos)
{
   T t= remove<T>(a.p,a.len,pos);
   return t;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   a = array<T>(a.cap);
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   int i = 0;
   for ( i = 0; i < a.len && cmpTK(a.p[i],k)!=0; i++);
   return i<a.len?i:-1;
}


// revisar 
template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
// retorna la posición donde dicho elemento quedó insertado. El array arr
// debe estar ordenado o vacío.
   int i=0;
   if (a.cap!=0){
         if (a.len==a.cap){
            redimensionar(a.p,a.cap,a.cap*2);
            a.cap =a.cap*2;
         }
         // // ordeno 
         bool ordenado = false;
         while (!ordenado)
         {
            ordenado = true;
            for (int i = 0; i < a.len-1; i++)
            {
               if (cmpTT(a.p[i],a.p[1+i])>0)
               {
                  T aux = a.p[i];
                  a.p[i] = a.p[1+i];
                  a.p[1+i]= aux;
                  ordenado=false;
               }
            }
         }
         // --------------
         // inserto
         a.len++;
         // for (int i = a.len; i >=0 ; i--)
         // {
         //    if (cmpTT(a.p[i],t)==1)
         //    {
         //       /* code */
         //    }else
         //    {
         //       /* code */
         //    }
         
         // }
         for (i=a.len ; cmpTT(a.p[i],t)!=-1; i--)
         {
               a.p[i]=a.p[i-1];
         }
         a.p[++i] = t;
         
   }
   else{
      i = arrayAdd<T>(a,t);
   }
   return i;
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   bool ordenado = false;
         while (!ordenado)
         {
            ordenado = true;
            for (int i = 0; i < a.len-1; i++)
            {
               if (cmpTT(a.p[i],a.p[1+i])>0)
               {
                  T aux = a.p[i];
                  a.p[i] = a.p[1+i];
                  a.p[1+i]= aux;
                  ordenado=false;
               }
            }
         }
}

#endif

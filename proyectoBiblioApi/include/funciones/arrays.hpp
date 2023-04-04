#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>
#include <string.h>
#include <stdio.h>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len] = e;
   return len++;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   if (len!=0)
   {
      len++;
      for (int i=len ; i!=p; i--)
      {
            arr[i]=arr[i-1];
      }
      arr[p] = e;
   }
   else
   {
      add<T>(arr,len,e);
   }
} 


template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret = arr[p];
   for (int i = p; i < len; i++)
   {
      arr[i]= arr[i+1];
   }
   len--;
   return ret;
}


template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int i = 0;
   for ( i = 0; i < len && cmpTK(arr[i],k)!=0; i++);
   return i<len?i:-1;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int i = 0;
   if (len!=0)
   {
      len++;
      for (i=len ; cmpTT(arr[i],e)!=-1; i--)
      {
            arr[i]=arr[i-1];
      }
      arr[++i] = e;
   }
   else
   {
      i = add<T>(arr,len,e);
   }
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   bool ordenado = false;
   while (!ordenado)
   {
      ordenado = true;
      for (int i = 0; i < len-1; i++)
      {
         if (cmpTT(arr[i],arr[1+i])>0)
         {
            T aux = arr[i];
            arr[i] = arr[1+i];
            arr[1+i]= aux;
            ordenado=false;
         }
      }
   }
}

#endif

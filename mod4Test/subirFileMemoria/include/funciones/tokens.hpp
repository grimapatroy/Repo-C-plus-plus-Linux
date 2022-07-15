#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   int result=0;
   if (length(s)>0)
   {
      result =charCount(s,sep)+1;
   }
   return result;
}

void addToken(string& s,char sep,string t)
{
   if (length(s)==0)
   {
      s = s + t;
   }else{
      s=s+sep+t;
   }
}

string getTokenAt(string s,char sep, int i)
{
   // 1|2|2|3|3|2
   string x;
   if (i==0){//cuando es el incio
      // Tengo que ver cuando llega con sep o sin sep
         // if (sep!=isLetter(sep) and sep!=isDigit(sep))
         if (sep>=32 and sep<=127)
         {
            int limite =indexOfN(s,sep,i+1);
            x = substring(s,0,limite);
            return x;
         }
         else
         {
            x = substring(s,i,length(s)); //sin sep
            return x;
         }

   }else{
         if (charCount(s,sep)==i){//cuando es el final
            x = substring(s,indexOfN(s,sep,i)+1,length(s));
            return x;
         }
         if(charCount(s,sep)>i){//cualqueira elemento intermedio
            x = substring(s,indexOfN(s,sep,i)+1,indexOfN(s,sep,i+1));
            return x;
         }
         if (charCount(s,sep)<i){
         return "ERROR";
         }
      }
   return "ERROR POSICION MUY LARGA";
}

void removeTokenAt(string& s,char sep, int i){
   if (i==0)
   {
      //  realizar funcion para tokens (funcion pra token vacios)
      s=substring(s,indexOf(s,sep)+1,length(s));
   }else	{
      int count = charCount(s,sep);
         if (count==i){
      // agregar funcion pra token vacios
            // falla el last ¿?¿? alveces
            s=substring(s,0,lastIndexOf(s,sep));
         }
         if(count>i){
            // usar esta funcion si falla al removertoken vacios
            s= getTokenAt(s,sep,i)!=""?substring(s,0,indexOfN(s,sep,i))+substring(s,indexOfN(s,sep,i+1),length(s)):substring(s,0,indexOfN(s,sep,i))+substring(s,indexOfN(s,sep,i)+1,length(s));
            // s=substring(s,0,indexOfN(s,sep,i))+substring(s,indexOfN(s,sep,i+1),length(s));
         }
         if (count<i)
         {
            cout<<"ERROR POSICION MUY LARGA"<<endl;
         }
   }
}

void setTokenAt(string& s,char sep, string t,int i)
{
   if (i==0)
   {
      s= t+charToString(sep) + substring(s, indexOfN(s,sep,i+1)+1,length(s));
   }else{
            if (charCount(s,sep)==i)
            {
               s= substring(s,0,lastIndexOf(s,sep))+charToString(sep)+ t;
            }
            if (charCount(s,sep)>i){
               s= substring(s,0,indexOfN(s,sep,i)+1)+t+charToString(sep)+substring(s,
               indexOfN(s,sep,i+1)+1,length(s));
            }if(charCount(s,sep)<i){
               cout<<"ERROR POSICION MUY LARGA"<<endl;
            }
   }
}


int findToken(string s,char sep, string t)
{
   int i;
   int n= tokenCount(s,sep);
   for ( i = 0; i<n ; i++){
      if (getTokenAt(s,sep,i)==t)
      {
         return i;
      }
   }
   return -1;
}

#endif

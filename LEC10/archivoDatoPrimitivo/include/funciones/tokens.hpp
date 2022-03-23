#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   int result=0;
   // != cadenavacia
   // que sean una palabracompleta( primero tengo que ver si noesta vacia y si aparece sep en s )
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

// javier|coste|lote|rufus
string getTokenAt(string s,char sep, int i)
{
   if (i==0)
   {
      int pos =indexOfN(s,sep,i+1);
      return substring(s,i,pos-1);
   }else{
      if (i<tokenCount(s,sep)-1)
      {
         return substring(s,indexOfN(s,sep,i)+1,indexOfN(s,sep,i+1)-1);
      }
      if(i==tokenCount(s,sep)-1){

         return  substring(s,indexOfN(s,sep,i)+1,length(s)+1);
      }
      // return substring(s,indexOfN(s,sep,i)+1,indexOfN(s,sep,i+1)>0?indexOfN(s,sep,i+1):length(s)+1);
   }
   return "error";
}

void removeTokenAt(string& s,char sep, int i)
{
   if (i==0)
   {
      s= substring(s,indexOfN(s,sep,i+1)+1,length(s));
   }else	{
      s = substring(s,0,charCount(s,sep)==i?indexOfN(s,sep,i)-1:indexOfN(s,sep,i))+substring(s,indexOfN(s,sep,i+1)+1, charCount(s,sep)==i?length(s)-1:length(s));
   }
}


//revisar set token esta malalgo
void setTokenAt(string& s,char sep, string t,int i)
{
   if (i==0)
   {
      s= t + substring(s, indexOfN(s,sep,i+1),length(s));
      
   }else{
      if (charCount(s,sep)+1==i)
      {
         s= s+charToString(sep) + t;
// error se duplica
      }else{
         s= substring(s,0,indexOfN(s,sep,i))+ t+charToString(sep)+substring(s,
         indexOfN(s,sep,i)+1,length(s));
      }
   }
}

// javier|coste|lote|rufus  //  rufus
int findToken(string s,char sep, string t)
{
   int i,encontrado=-1;
   
   for (i = 0; i < tokenCount(s,sep); i++)
   {
      string aux =getTokenAt(s,sep,i);
      if (aux==t)
      {
         return i;
      }
   }
   return encontrado;
}

#endif

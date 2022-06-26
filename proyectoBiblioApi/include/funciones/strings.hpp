#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_


#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;

int length(string s)
{
   int i ;
   for ( i = 0; s[i] != '\0'; i++);
   return i;
}

int charCount(string s,char c)
{
   int contChar = 0;
   for ( int i = 0; s[i] != '\0'; i++)
   {
      if (s[i]==c)
      {
         contChar ++;
      }
   }
   
   return contChar;
}

string substring(string s,int d,int h)
{
   string sub="";
   for (int i = d;h > i and s[i] !='\0'; i++)
   {
      sub += s[i];
   }
   return sub;
}

string substring(string s,int d) // ok
{
   string sub="";
         for (int i = d;s[i]!='\0'; i++)
         {
               sub += s[i];
         }

   return sub;
}

int indexOf(string s,char c) // ok
{
   int pos=-1;
   for ( int i= 0; s[i] !='\0' ; i++)
   {
      if(s[i] ==c)
      {
         pos = i;
         break;
      }
   }
   return pos;
}

int indexOf(string s,char c,int offSet) // ok
{
   int i;
   for (i = offSet; s[i] !='\0' and s[i]!=c; i++);
   return i;
}

int indexOf(string s,string toSearch) // ok
{
   string sSub;
         int pos =indexOf(s,toSearch[0]);
         while(pos>=0)
         {
               sSub = substring(s,pos,pos+length(toSearch));
               if (sSub==toSearch)
               {
                  return pos;
               }else{
                  pos =indexOf(s,toSearch[0],pos+1);
               }
         }
      return -1;
}

//Esta funcion es la funcion mas dificil
int indexOf(string s,string toSearch,int offset) // ok
{
      string sSub;
      for(int i = offset ;toSearch[i]!='\0'; i++)
      {
            int pos =indexOf(s,toSearch[0],i+1);
            sSub = substring(s,pos,pos+length(toSearch));
            if (sSub==toSearch)
            {
               return pos;
            }
      }
   return -1;
}

int lastIndexOf(string s,char c)
{
   int i;
   int ultimaPos=length(s);
   for ( i = ultimaPos; i>=0 and s[i]!=c; i--);
   return i>=0?i:-1;
}

//John|Paul|George|Po
int indexOfN(string s,char c,int n)
{
   int i=0, cont=0;
   bool stop = 0;
   while (s[i] != '\0' and !stop)
   {
      if (s[i]==c)
      {
         cont++;
      }
      i++;
      if (cont == n)
      {
         stop = 1;
      }
   }
   return i-1;
}

int charToInt(char c)
{
   return c>=48&&c<=57?c-48:int(c);
}

char intToChar(int i)
{
   return  i>=0&&i<=9?48+i:char(i);
}

//1236584 - 10
int getDigit(int n,int i)
{
   int base = int(pow(10,i));
   int partEntera = int(n/base);
   return partEntera%10;
}

//54872
int digitCount(int n)
{
   int cont=0;
   for ( int i = 0; (n/int(pow(10,i))) >=1 ; i++)
   {
      cont++;
   }
   return cont;
}

//1254 ="1254"
string intToString(int i)
{
   int cadena;
   string cadenaCon;
   int aux = digitCount(i)-1;
   for ( int j =aux ; j >= 0; j--)
   {
      int num = getDigit(i,j);
      cadena = 48 + num;
      cadenaCon += char(cadena);
   }
   return cadenaCon;
}

int stringToInt(string s,int b) // ok
{
   int resul = 0;
   int contBase=0;
   for (int i = length(s)-1; i>=0  ; i--)
   {
      int variante = s[i]>='0'&&s[i]<='9'?'0':'A'-10;
      resul += (s[i] - variante )*pow(b,contBase);
      contBase++;
   }
   return resul;
}

// "1235"
int stringToInt(string s) // ok
{
   int res=0;
   for (int i =0; i <=length(s)-1 ; i++)
   {
      res += (charToInt(s[i]))*pow(10,length(s)-1-i);
   }
   return res;
}

string charToString(char c)
{
   string resul = ""; 
   return   resul+c;
}

char stringToChar(string s)
{
   int i = 0;
   char resul = char(s[i]);
   return resul;
}

string stringToString(string s)
{
   return s;
}

//258.25  0.25
string doubleToString(double d)
{
   double mod = d-int(d);
   int resto = mod*int(pow(10,2));
   return intToString(int(d))+"."+intToString(resto) ;
}

//"5482.20" 
double stringToDouble(string s)
{
   string entera="",decimal="";
   entera = substring(s,0,indexOf(s,'.'));
   decimal = substring(s,indexOf(s,'.')+1,length(s));
   int exp = length(decimal);
   double resul = stringToInt(entera) + stringToInt(decimal)/pow(10,exp);
   return resul;
}

bool isEmpty(string s)
{
   return s!=""?false:true;
}

bool startsWith(string s,string x)
{
   int i ;
   for (  i = 0; i <=length(x) and s[i]==x[i]; i++);
   return x[i++]=='\0'?true:false;
}

bool endsWith(string s,string x)
{
   int i;
   for ( i = length(s)-length(x); s[i]==x[i] and s[i]!='\0'; i++);
   return (s[i+length(x)]=='\0')?true:false;
}

bool contains(string s,char c)
{
   return indexOf(s,c)>=0?true:false;
}

//hola mundo ( 'o', 'X')
string replace(string s,char oldChar,char newChar)
{
   for (int i = 0;  indexOf(s,oldChar)>=0 ; i++)
   {
      int pos = indexOf(s,oldChar);
      s[pos]=newChar;        
   }
   return s;
}

string insertAt(string s,int pos,char c)
{
   string part1 = substring(s,0,pos+1)+charToString(c);
   string part2 = substring(s,pos,length(s));
   return part1+part2;
}

string removeAt(string s,int pos)
{
   for ( int i = pos; i <= length(s)-1; i++)
   {
      s[i]=s[i+1];
   }
   return s;
}


// [  Esto es una prueba]/[Esto es una prueba]/[Esto es una prueba   ]
string ltrim(string s)
{
   if (s[0]!=' ')
   {
      return s;
   }else{
      int i=0;
      for (i = 0; s[i]==' ' ; i++);
      return substring(s,i,length(s));
   }
}

// [Esto es una prueba   ]
string rtrim(string s)
{
   int i ;
   for ( i = length(s)-1; s[i]==' ' ; i--);
   return substring(s,0,i+1);
}

string trim(string s)
{
   return ltrim(rtrim(s));
}

string replicate(char c,int n)
{
   string replica = "";
   for (int i = 1; i <=n; i++)
   {
      replica +=c; 
   }
   return replica;
}

string spaces(int n)
{
   string s = "";
   for (int i = 0; i <n; i++)
   {
      s+=" ";
   }
   return s;
}

//[hola],10 ---> [XXXXXXXXXhola]
string lpad(string s,int n,char c)
{
   string complet ="";
   for (int i = n-length(s); i>0; i--)
   {
      complet+=c;
   }
   return complet+s;
}


string rpad(string s,int n,char c)
{
   string complet ="";
   for (int i = n-length(s); i>0; i--)
   {
      complet+=c;
   }
   return s+complet;
}


string cpad(string s,int n,char c)
{
   string complet ="";
   for (int i = n-length(s); i>0; i--)
   {
      complet+=c;
   }
   return length(complet)>0?substring(complet,0,(length(complet)/2))+s+substring(complet,length(complet)/2):s;
}

bool isDigit(char c)
{
   return c>=48&c<=57?true:false;
}

bool isLetter(char c)
{
   return (c>=65&c<=90)|(c>=97&c<=122)?true:false;
}

bool isUpperCase(char c)
{
   return (c>=65&c<=90)?true:false;
}

bool isLowerCase(char c)
{
   return (c>=97&c<=122)?true:false;
}

char toUpperCase(char c)
{
   return isLowerCase(c)?c-32:c;
}

char toLowerCase(char c)
{
   return isUpperCase(c)?c+32:c;
}

string toUpperCase(string s)
{
   string r="";
   int i;
   for ( i = 0; s[i]!='\0'; i++)
   {
      r+= toLowerCase(s[i]);
   }
   return r;
}

string toLowerCase(string s)
{
   string r="";
   int i;
   for ( i = 0; s[i]!='\0'; i++)
   {
      r+= toLowerCase(s[i]);
   }
   return r;
}

int cmpString(string a,string b)
{
   return a<b?-1:a>b?1:0;
}

int cmpDouble(double a,double b)
{
   return a-b;
}

#endif

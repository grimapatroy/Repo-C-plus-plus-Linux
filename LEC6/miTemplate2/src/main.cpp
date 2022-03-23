#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


struct Persona
{
    int dni;
    string nombre;
};

struct coll
{
    /* data */
};


Persona inicializarPersona(int dni,string nom){
    return {dni,nom};
}

int cmpPersonaDNI(Persona a, Persona b){
    return a.dni - b.dni;
}

int cmpPersonaNombre(Persona a, Persona b){
    return a.nombre<b.nombre?-1:a.nombre>b.nombre?1:0;
}

string tIntToString(Persona a){
    return intToString(a.dni);
}

string tStriIntToString(Persona a){
    return  stringToString(a.nombre);
}


int cmpString2(string a, string b){
    return length(a) - length(b);
}

int cmpString1(string a, string b){
    return (a<b)?-1:(a>b)?1:0;
}

int cmpInt(int a, int b){
    return a-b;
}




template<typename T>
void comparaYMuestra(T a, T b, T c, int cmpTT(T,T)){
    T menor,medio, mayor;
    if (cmpTT(a,b)>0 && cmpTT(a,c)>0)
    {
        mayor = a;
            if (cmpTT(a,c)>0)
            {
                medio =b;
                menor= c;
            }else{
                medio = c ;
                menor = b;
            }
    }else{
        if (cmpTT(b,a)>0 && cmpTT(b,c)>0)
        {
            mayor = b;
                if (cmpTT(a,c)>0)
                {
                    medio = a;
                    menor = c;
                }
                else
                {
                    medio =c;
                    menor =a;
                }
            
        }else
        {
            mayor = c;
            if (cmpTT(a,b)>0)
            {
                medio = a;
                menor= b;
            }
            else
            {
                medio =b;
                menor =a;
            }
            
        }
    }
    cout<<"Menor: "<<menor<<endl;
    cout<<"Medio: "<<medio<<endl;
    cout<<"Mayor: "<<mayor<<endl;

}



template<typename T>
void comparaYMuestra(T a, T b, T c, int cmpTT(T,T),string tToString(T)){
    T menor,medio, mayor;
    if (cmpTT(a,b)>0 && cmpTT(a,c)>0)
    {
        mayor = a;
            if (cmpTT(a,c)>0)
            {
                medio =b;
                menor= c;
            }else{
                medio = c ;
                menor = b;
            }
    }else{
        if (cmpTT(b,a)>0 && cmpTT(b,c)>0)
        {
            mayor = b;
                if (cmpTT(a,c)>0)
                {
                    medio = a;
                    menor = c;
                }
                else
                {
                    medio =c;
                    menor =a;
                }
            
        }else
        {
            mayor = c;
            if (cmpTT(a,b)>0)
            {
                medio = a;
                menor= b;
            }
            else
            {
                medio =b;
                menor =a;
            }
            
        }
    }
    cout<<"Menor: "<<tToString(menor)<<endl;
    cout<<"Medio: "<<tToString(medio)<<endl;
    cout<<"Mayor: "<<tToString(mayor)<<endl;

}



int main()
{   
    int i=30,j=10,k=49;
    string a="PABLO",b="JUAN",c="ALBERTO";

    Persona p1 = inicializarPersona(89289827,"JOSEPH");
    Persona p2 = inicializarPersona(12345678,"RAFAEL");
    Persona p3 = inicializarPersona(72879179,"LOLA");
    
    comparaYMuestra<int>(i,j,k,cmpInt);
    cout<<"---------------------------------"<<endl;
    comparaYMuestra<string>(a,b,c,cmpString1);
    cout<<"---------------------------------"<<endl;
    comparaYMuestra<string>(a,b,c,cmpString2);
    cout<<"---------------------------------"<<endl;
    comparaYMuestra<Persona>(p1,p2,p3,cmpPersonaDNI,tIntToString);
    cout<<"---------------------------------"<<endl;
    comparaYMuestra<Persona>(p1,p2,p3,cmpPersonaNombre,tStriIntToString);
    cout<<"---------------------------------"<<endl;

    // coll<int> c1 = collCreate<int>();

    return 0;
}
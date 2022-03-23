#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


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

int cmpString2(string a, string b){
    return length(a) - length(b);
}

int cmpString1(string a, string b){
    return (a<b)?-1:(a>b)?1:0;
}

int cmpInt(int a, int b){
    return a-b;
}


int main()
{   
    int i=30,j=10,k=49;
    string a="PABLO",b="JUAN",c="ALBERTO";
    
    comparaYMuestra<int>(i,j,k,cmpInt);
    comparaYMuestra<string>(a,b,c,cmpString1);
    comparaYMuestra<string>(a,b,c,cmpString2);

    return 0;
}
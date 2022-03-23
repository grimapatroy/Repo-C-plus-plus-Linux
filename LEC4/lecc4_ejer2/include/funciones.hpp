#ifndef _TDATerna_
#define _TDATerna_


#include <iostream>
using namespace std;

struct Terna
{
    int a;
    int b;
    int c;
};


Terna terna(int a, int b, int c){
    return {a,b,c};
}

bool ternaEsNula(Terna t){
    return t.a==0 && t.b==0 && t.c==0;
}

int ternaObtenerMenor(Terna t){
    int a= t.a;
    int b= t.b;
    int c= t.c;

    return  (a<b&&a<c)?a:(b<a&&b<c)?b:c;
}

int ternaObtenerMayor(Terna t){
    int a= t.a;
    int b= t.b;
    int c= t.c;

    return  (a>b&&a>c)?a:(b>a&&b>c)?b:c;
}

int ternaObtenerMedio(Terna t){
    int a= t.a;
    int b= t.b;
    int c= t.c;
    return ((a>b&&a<c)or(a<b&&a>c))?a:((b>a&&b<c)or(b<a&&b>c))?b:c;
}

#endif
#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


int main()
{   
    Collecion c1 = collCreate();

    // Son una coleccion disfrasada de token
    colecionAddString(c1,"Pedro");
    colecionAddString(c1,"Joseph");
    colecionAddString(c1,"Jaime");

    for (int i = 0; i < coleccionSize(c1); i++)
    {
        string s = coleccionGetStringAt(c1,i);
        cout<<s<<endl;
    }

    cout<<"-------------------"<<endl;

    Collecion c2 = collCreate();

    // Son una coleccion disfrasada de token
    colecionAddInt(c2,12);
    colecionAddInt(c2,2);
    colecionAddInt(c2,2);

    for (int i = 0; i < coleccionSize(c2); i++)
    {
        int x = coleccionGetIntAt(c2,i);
        cout<<x<<endl;
    }


    cout<<"-------------------"<<endl;
    cout<<coleccionMostrar(c1);
    

    return 0;
} 
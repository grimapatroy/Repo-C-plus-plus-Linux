#include <iostream>
#include "../include/TDA.hpp"
#include "../include/strings.hpp"
// #include <string.h>
using namespace std;


int main()
{   
    int a,b;
    string lista="";
    int i=0;
    while (true and i<20)
    {
        cout<<"Ingresa numerador y denominador:  " <<endl;
        cin>>a>>b;

        Francion f = fraccion(a,b);
        // lista = fraccionAgregar(fraccion);
        lista+=fraccionToString(f);

        
        bool ingreso;
        cout<<"**************************************************** "<<endl;
        cout<<"DESEA SEGUIR INGRESANDO MAS FRACCIONES (si=1) (no=0): "<<endl;
        cin>>ingreso;
        if (!ingreso)
        {
            cout<<"GRACIAS Y HASTA LUEGO"<<endl;
            cout<<"**************************************************** "<<endl;
            break;
        }
        
    }

    cout<<"["<<lista<<"]"<<endl;
    // for (int i = 0; i < length(lista); i++)
    // {
    //     cout<<"["<<lista[i];
    // }
    //     cout<<"]";
    

    return 0;
}
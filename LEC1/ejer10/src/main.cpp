#include <iostream>
#include "../include/funciones.hpp"
#include "../include/strings.hpp"
using namespace std;


int main()
{     
    bool enter  = true;
    int d,m,a;

    cout<< "ingrese fecha(formarto dd/mm/aa): "  <<endl;
    cin>>d>>m>>a;
    cout<< "ingrese  Siguiente fecha(formarto dd/mm/aa): "  <<endl;
    cin>>d>>m>>a;

    Fecha f1 = fechaInicializar(d,m,a);
    Fecha f2 = fechaInicializar(d,m,a);
    Fecha fActual = fechaInicializar(25,8,2021);



    while(enter){
        
        fechaComprar(fActual,f1,f2);
        
        cout<< "************************************************"  <<endl;
        int seguir;
        cout<< "DESEA SEGUIR INGRESANDO MAS FECHAS (SI= 1)(NO = 0): " <<endl;
        cin>>seguir;
        cout<< "************************************************"  <<endl;
        if (seguir)
        {
            cout<< "ingrese fecha(formarto dd/mm/aa): "  <<endl;
            cin>>d>>m>>a;
            cout<< "ingrese  Siguiente fecha(formarto dd/mm/aa): "  <<endl;
            cin>>d>>m>>a;

            Fecha f1 = fechaInicializar(d,m,a);
            Fecha f2 = fechaInicializar(d,m,a);
        }else{
            enter = false;
        }
        
    }

    return 0;
}
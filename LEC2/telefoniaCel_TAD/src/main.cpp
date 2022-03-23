#include <iostream>
#include "../include/TAD.hpp"
using namespace std;


int main()
{   
    int minutosExcedidos=0,numcel=0,timeUso=0;
    double importeAAbonar=0;
    string nomAbonado="",direcAbonado="";
    char tipoAbono;
    int turno1=1,turno2=2,turno3=3,turno=0;


    Datos d = datosInicializar(numcel,nomAbonado,direcAbonado,datosToMin(timeUso),tipoAbono);
    bool seguir = 0;
    int cont=0;
    while (true)
    {
    cout<<"******************************************************"<<endl;
    cout<<"Bienvenidos al Sistema Telefonico de Registros"<<endl;
    cout<<"******************************************************"<<endl;
    cout<<"Ingrese el turno:(1 , 2 o 3): ";
    cin>>turno;
    
        while (turno==1)
        {
                cout<<"******************************************************"<<endl;
                cout<<"++++++Formulario++++"<<endl;

                cout<<"Ingrese numero de celular: ";
                cin>>numcel;
                cout<<"Ingrese Nombre: ";
                cin>>nomAbonado;
                cout<<"Ingrese Direccion: ";
                cin>>direcAbonado;
                cout<<"Ingrese Tiempo de Uso(4 diguitos hhmm): ";
                cin>>timeUso;
                cout<<"Ingrese TipNo de Abono(A,B,C,D,E): ";
                cin>>tipoAbono;
                cont++;
                cout<<"******************************************************"<<endl;
                    cout<<"Desea seguir (si=1)(no=0): ";
                    cin>>seguir;
                    // while(true){
                

            // }
        }
        while (turno==2)
        {
            /* code */
        }
        while (turno==3)
        {
            /* code */
        }
        




    }
    


    return 0;
}
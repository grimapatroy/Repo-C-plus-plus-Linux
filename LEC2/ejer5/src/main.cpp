#include <iostream>
#include "../include/funciones.hpp"
using namespace std;


int main()
{   
    // entrada
    int numeroCelular, timeUso;
    string nomAbonado ,direccAbonado;
    char tipoAbono;
    int cont=0;

    //*******************
    // datos de contexto
     double precio,valorMinutoExcedente;
     int minLibres;
     int contdDia=0, contTarde=0;   
    //*******************
    // salida
    int converionMin;
    int minutosExcedidos;
    double importeAApagar;
    string turno;
    
    //*******************
    
    //*******************


    cout<<"::::::::::BIENVENIDOS::::::::::::::::"<<endl;
    cout<<"----------------ABONADO"<<cont<<"--------------------------------------"<<endl;
    cout<<"INGRESAR TURNO: ";
    cin>>turno;
    // -----------------------------------------------------------------------------
    cout<<"INGRESAR NUMERO DE CELULAR: ";
    cin>>numeroCelular;
    cout<<"INGRESAR NOMBRE DEL ABONADO: ";
    cin>>nomAbonado;
    cout<<"INGRESAR DIRECCION DEL ABONADO: ";
    cin>>direccAbonado;
    cout<<"INGRESAR TIEMPO DE USO 4 DIGITOS: ";
    cin>>timeUso;
    cout<<"INGRESAR TIPO DE ABONO: ";
    cin>>tipoAbono;
    cout<<"---------------------------------------------------------------------"<<endl;
/*
    while (turno!="")
    {
        
            while (timeUso>0)
            {
                if (turno=="mañana")
                {
                    contdDia++;
                }else
                {
                    if (turno=="tarde")
                    {
                      contTarde++;
                    
                     }
                }

                if(tipoAbono == 'A'){
                    precio = 1500;
                    minLibres = 1000;
                    valorMinutoExcedente = 1;
                }
                else{
                    if(tipoAbono == 'B'){
                    precio = 1000;
                    minLibres = 600;
                    valorMinutoExcedente = 3;
                    }
                    else{
                        if(tipoAbono == 'C'){
                            precio = 700;
                            minLibres = 400;
                            valorMinutoExcedente = 5;
                        }
                        else{
                                if(tipoAbono == 'D'){
                                    precio = 500;
                                    minLibres = 300;
                                    valorMinutoExcedente = 7;
                                }
                                else{
                                    if(tipoAbono == 'E'){
                                    precio = 350;
                                    minLibres = 100;
                                    valorMinutoExcedente = 10;    
                                    }
                                }
                        }
                    }
                }
               
                
                //#TODO falta la implementacion !! eL COMO ! toMin
                int conversionMin = toMin(timeUso);

                //  #TODO falta el ¿como? la implementacion de excedente                   
                excedente(precio,minLibres,valorMinutoExcedente,converionMin,minutosExcedidos,importeAApagar);
                cont++;

                cout<<"----------------ABONADO"<<cont<<"--------------------------------------"<<endl;
                cout<<"INGRESAR TURNO: ";
                cin>>turno;
                cout<<"INGRESAR NUMERO DE CELULAR: ";
                cin>>numeroCelular;
                cout<<"INGRESAR NOMBRE DEL ABONADO: ";
                cin>>nomAbonado;
                cout<<"INGRESAR DIRECCION DEL ABONADO: ";
                cin>>direccAbonado;
                cout<<"INGRESAR TIEMPO DE USO 4 DIGITOS: ";
                cin>>timeUso;
                cout<<"INGRESAR TIPO DE ABONO: ";
                cin>>tipoAbono;
                cout<<"-------------------------------------------------------------------"<<endl;

            }
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
            cout<<"----------------------------REPORTES--------------------------------------------"<<endl;
            cout<<"TURNO: MAÑANA"<<endl;
            cout<<"     ABONADO    "<<"     DIRECCION    "<<"     Min. Libres    "<<"     Min.Exced.    "<<"     Total A Abonar    "<<endl;
            for (int i = 1; i <= contdDia and turno=="mañana"; i++){
            cout<<nomAbonado        <<      direccAbonado <<    minLibres         <<    minutosExcedidos  << importeAApagar<<endl;
            }
            
            cout<<"TURNO: TARDE"<<endl;
            cout<<"     ABONADO    "<<"     DIRECCION    "<<"     Min. Libres    "<<"     Min.Exced.    "<<"     Total A Abonar    "<<endl;
            for (int i = 1; i <= contTarde and turno=="tarde"; i++){
            cout<<nomAbonado        <<      direccAbonado <<    minLibres         <<    minutosExcedidos  << importeAApagar<<endl;
            }
    }
    

*/
    ConsumoAbonados consumoAbona = consumoAbonados(numeroCelular,nomAbonado,direccAbonado,timeUso);
    while (turno != " ")
    {
        // #TODO implementacion validar datos de entrada para que entre al bucle
        while (consumoAbonaValidar(consumoAbona))
        {
            //Validar Turno
             if (turno=="mañana")
                {
                    contdDia++;
                }else
                {
                    if (turno=="tarde")
                    {
                      contTarde++;
                    
                     }
                }

            //  (dentro (funcion que asigna los PLANES))
            // #TODO falta implementacion
            tipoAbonoPlan(tipoAbono);


            // funcion excedente
            // #TODO falta implementacion 
            //excedente();
            //Vuelvo a pedir Datos
        }
        
        // Reportes Turno Mañana 
        // Reportes Turno Tarde 

        //romper el turno
    }
    

    return 0;
}
#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


int main()
{   
    int acMen=0,acMay=0,acMedio=0;
    int cont=0;

    int a,b,c;
    cout<<"INGRESE NUMEROS: "<<endl;
    cin>>a>>b>>c;

    Terna t = terna(a,b,c);
    while (!ternaEsNula(t))
    {
        acMen += ternaObtenerMenor(t);
        acMedio += ternaObtenerMedio(t);
        acMay += ternaObtenerMayor(t);
        // cuento las ternas
        cont++;
        //Siguiente entrada de la TERNA
        cout<<"INGRESE NUMEROS: "<<endl;
        cin>>a>>b>>c;
        t = terna(a,b,c);
    }   

    // calculamos promedios 
    double promMen = acMen/(double)cont;
    double promMed = acMedio/(double)cont;
    double promMay = acMay/(double)cont;

    // mostramos resultados finales
    cout<<"PROMEDIO DE LOS NUMEROS MENORES: "<<promMen<<endl;
    cout<<"PROMEDIO DE LOS NUMEROS MAYORES: "<<promMay<<endl;
    cout<<"PROMEDIO DE LOS NUMEROS MEDIOS: "<<promMed<<endl;


    return 0;
}
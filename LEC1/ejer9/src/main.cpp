#include <iostream>
using namespace std;


int main()
{   
    

    int anio,mes,dia,f;
    cout << "EL INGRESE EL ANIO: " ;
    cin >> anio; 
    cout << "EL INGRESE EL MESS : " ;
    cin >> mes;
    cout << "EL INGRESE EL DIA: " ;
    cin >> dia;

    f = anio*10000 + mes*100 + dia;

    cout << f << endl;



    return 0;
}
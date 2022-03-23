#include <iostream>
#include "../include/TDA.hpp"
#include <math.h>
using namespace std;


// Se ingresan por teclado 3 valores enteros: n, m y d. Se pide mostrar por consola los
// primeros n números naturales que tienen, al menos, m dígitos d. Por ejemplo, si
// n=5, m=3 y d=4, la salida del programa debería ser: 444, 1444, 2444, 3444, 4044

int main()
{   
    int n,m,d;
    cout<<"Ingresar valor n, m y d: ";
    cin>>n>>m>>d;
    int i,j,k;
    char numMagico= intToChar(d);
    string sUnidad,sNumFinal ;
    for ( i = 1; i <= n; i++)
    {
            // primera vuelta , el primer numero con m digitos
            int iUnidad= i*pow(10,(m-2)+i);//falta revisar
            sUnidad= intToString(iUnidad);
            // intercambiar numeros en la cadena por numero magico (d)
                for ( j = length(sUnidad); j >0 ; j--)
                {
                    sUnidad[j]=numMagico;
                    if (charCount(sUnidad,numMagico)==m)
                    {
                        break;
                    }else{
                        if(charCount(sUnidad,numMagico)<m){
                            // el cantidad de veces que falta el diguito
                            int aparacion = charCount(sUnidad,numMagico);
                            int resto = m-aparacion;
                            for ( k = 0; k < resto; k++)
                            {
                            // quiero saber en que posision esta el diguito para cambiar
                                int pos = length(sUnidad);
                                while (pos!=0)
                                {
                                    if(sUnidad[pos]!=numMagico){
                                        sUnidad[pos]=numMagico;
                                        break;
                                    }
                                    pos--;
                                }
                            }
                            cout<<"entro"<<endl;
                            // sUnidad[k]=numMagico;
                        }
                    }
                }
            // imprimo el valor hasta llegar ha n
            cout<<sUnidad<<endl;
    }
    return 0;
}
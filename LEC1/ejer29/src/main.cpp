// Se ingresan n conjuntos de m valores numéricos cada uno. Se pide informar:
// 1. Para cada uno de los n conjuntos:
// a. El valor promedio.
// b. El máximo valor.
// c. Porcentaje de valores positivos.
// 2. Para todo el lote de datos:
// a. Valor promedio.
// b. Porcentaje de valores negativos.
// c. Valor mínimo.

//----- Entrada: n conjuntos  ,  m valores ( nfilas de m valores)
//----- Contexto:   los tipos de datos 
//----- Proceso de transformación: condiciones while hasta m y m ; calculo de promedio maximoValor, porcentaje 
//----- Salida:              
//----- Tipo de Registro:  multiple
//----- Multiplicidad:  multiplicidad variante conocida
//----- Tipo procesamiento:  vertical y y vertical total

#include <iostream>
using namespace std;


int main()
{   
    int n, m;
    int i = 1;
    int j;
    int valor;
    int sum = 0 , sumTotal = 0;
    double promedioConjuntos =0.00, porcPositivos , porcNegativo , promedioTotal ;
    int valorMaxConj=-100, contPositivos = 0, contNegativo= 0 , valorMin = valor;
    
        cout<< " INGRESE EL NUMERO DE CONJUNTOS QUE QUIERE: ";
        cin>>n;
       
        // cout<< " INGRESE VALOR : ";
        // cin>>valor;
         

        while (i<=n)
        {
             cout<<"************************************************"<<endl;
             cout<< " NUMERO DE CONJUNTO : "<<i<<endl;
             cout<<"************************************************"<<endl;
             cout<< " INGRESE NUMERO DE VALORES PARA EL CONUNTO: ";
             cin>>m;
            for ( j = 0; j < m ; j++)
            {
                cout<< " INGRESE VALOR : ";
                cin>>valor;
                if (valor>valorMaxConj)
                {
                    valorMaxConj = valor;
                }
                if (valor<valorMin)
                {
                    valorMin = valor;
                }
                
                if (valor>0)
                {
                    contPositivos++;
                }else
                {
                    contNegativo++;
                }

                 sum = sum + valor;
                 sumTotal = sumTotal + valor;
            } 
                promedioConjuntos = double (sum/m);
                porcPositivos = double((contPositivos*100)/m);
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"RESULTADO DE CONJUNTO" << i << endl;
                cout<<"VALOR PROMEDIO : " << promedioConjuntos<<endl;
                cout<<"MAXIMO VALOR: "<< valorMaxConj<<endl;
                cout<<"PORCENTAJE DE VALORES PSITIVOS: "<< porcPositivos << "%"<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                // INICIALIZAMOS VARIABLES
                porcPositivos = 0;
                promedioConjuntos = 0;
                valorMaxConj=-100;
                contPositivos = 0;
            i++;

        }
        porcNegativo = ((contNegativo*100)/(n*m));
        promedioTotal = sumTotal/(n*m);
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"RESULTADO TOTAL" << endl;
                cout<<"VALOR PROMEDIO TOTAL  : " << promedioTotal<<endl;
                cout<<"MINIMO VALOR: "<< valorMin<<endl;
                cout<<"PORCENTAJE DE VALORES NEGATIVOS: "<< porcNegativo << "%"<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
        
       


   return 0;

}
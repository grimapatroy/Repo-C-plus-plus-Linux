#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/tads/Coll.hpp"
#include "../include/funciones/files.hpp"
using namespace std;


struct Numero
{
    char numeros[40];
};



int numeroObtenerNum (Numero n, int i){
    
    // devuelve la el char del array casteado en int en la  poscicion i
    return charToInt(n.numeros[i]);
}


int numeroObtenerSiguiente (Numero n, int i) {

    return numeroObtenerNum(n,i+1);
}

int numeroStringObtenerSiguiente(string cadena,int pos){

    return stringToInt(getTokenAt(cadena,',',pos));
}

string numeroObtenerNumString(Numero n){
    string cadena =  n.numeros;
    return cadena;
}




int main()
{   
    // Creo ela rchivo de caracteres nmericos
        // FILE* archivoNum = fopen("ejerLeccion10_8-1-2.zz","w+b");

        // Numero n1 = {"23,45,1,4,45,15,7,45,8,12"};
        // write<Numero>(archivoNum,n1);
                    // .-------------------probando con char []---------------------------------------
                    // string numb = "143214324231421";
                    // char numeros[20];
                    // strcpy(numeros,numb.c_str());
                    // write<char[]>(archivoNum,strcpy(numeros,numb.c_str()));
                    // .----------------------------------------------------------
        // fclose(archivoNum);

    // Leemos el archivo para ver el mayor valor y en que posiciones aparece
        FILE* archivoNum = fopen("ejerLeccion10_8-1-2.zz","r+b");
        Numero numerito;
        numerito = read<Numero>(archivoNum);
        int num , max;
        string posResul = "", posRel="";
        int pos,i=0;

        
        // int num = numeroObtenerNum(numerito,i);
        string cadeNum = numeroObtenerNumString(numerito);
        // int max = num;
        // for (i = 0; i < 19; i++)
        // {
        //     if (num>max)
        //     {
        //         max=num;
        //         pos = i;
        //         posRel += intToString(pos);
        //     }
        //     int numSg = numeroObtenerSiguiente(numerito,i);
        //     if(max==numSg){
        //         int posSg = i+1; 
        //         posResul=posResul+","+intToString(posSg);
        //     }
        //     num = numeroObtenerSiguiente(numerito,i);
            
        // }
        // cout<<posResul<<endl;
        for ( i ; i < tokenCount(cadeNum,','); i++)
        {
            int numInt = stringToInt(getTokenAt(cadeNum,',',i));
            int max = numInt;
            if (numInt>max)
            {
                max=numInt;
                pos = i;
                posRel += intToString(pos);
            }
            int numSg = numeroStringObtenerSiguiente(cadeNum,i);
            if(max==numSg){
                int posSg = i+1; 
                posResul=posResul+","+intToString(posSg);
            }
            numInt = numeroStringObtenerSiguiente(cadeNum,i);
        }
        cout<<posResul<<endl;
        fclose(archivoNum);


    return 0;
}


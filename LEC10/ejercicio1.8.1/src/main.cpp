#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/funciones/files.hpp"
using namespace std;


struct Numero
{
    char numeros[20];
};



int numeroObtenerNum (Numero n, int i){
    
    // devuelve la el char del array casteado en int en la  poscicion i
    return charToInt(n.numeros[i]);
}


int numeroObtenerSiguiente (Numero n, int i) {

    return numeroObtenerNum(n,i+1);
}






int main()
{   
    // Creo ela rchivo de caracteres nmericos
        // FILE* archivoNum = fopen("ejerLeccion10_8-1-1.zz","w+b");

        // Numero n1 = {"143214324231421"};
        // write<Numero>(archivoNum,n1);
                    // .-------------------probando con char []---------------------------------------
                    // string numb = "143214324231421";
                    // char numeros[20];
                    // strcpy(numeros,numb.c_str());
                    // write<char[]>(archivoNum,strcpy(numeros,numb.c_str()));
                    // .----------------------------------------------------------
        // fclose(archivoNum);

    // Leemos el archivo para ver el mayor valor y en que posiciones aparece
        FILE* archivoNum = fopen("ejerLeccion10_8-1-1.zz","r+b");
        Numero numerito;
        numerito = read<Numero>(archivoNum);
        // int num , max;
        string posResul = "", posRel="";
        int pos,i=0;
        int num = numeroObtenerNum(numerito,i);
        int max = num;
        for (i = 0; i < 19; i++)
        {
            if (num>max)
            {
                max=num;
                pos = i;
                posRel += intToString(pos);
            }
            int numSg = numeroObtenerSiguiente(numerito,i);
            if(max==numSg){
                int posSg = i+1; 
                posResul=posResul+","+intToString(posSg);
            }
            num = numeroObtenerSiguiente(numerito,i);
            
        }
        cout<<posResul<<endl;

        fclose(archivoNum);


    return 0;
}


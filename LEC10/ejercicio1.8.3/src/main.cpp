#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../include/tads/Coll.hpp"
#include "../include/funciones/files.hpp"
using namespace std;


struct Nombres
{
    char nombres[100];
};


string nombresObtenerNom (Nombres n){
    string s = n.nombres;
    return s;
}


int main()
{   
    // Creo ela rchivo de caracteres nmericos
        // FILE* archiNom = fopen("nombres.dat","w+b");

        // Nombres n1 = {"joseph\njuan\nmacalopu\ngemela\n"};
        // write<Nombres>(archiNom,n1);
        // fclose(archiNom);

    // Leemos el archivo para ver el mayor valor y en que posiciones aparece
        FILE* archiNom = fopen("nombres.dat","r+b");
        Nombres nom = read<Nombres>(archiNom);
        
        string n = nombresObtenerNom(nom);

        // while (!feof(archiNom))
        // {
            
        // }
        for (int i = 0; i < tokenCount(n,'\n'); i++)
        {
            string nombresito =  getTokenAt(n,'\n',i);
            int max = 7; 
            if ( max<length(nombresito))
            {
                cout<<nombresito<<endl;
            }
            
        }

        fclose(archiNom);


    return 0;
}


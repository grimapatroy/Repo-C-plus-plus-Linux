#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
using namespace std;


int main()
{   
    // // para escribir un archivo (write)
    // FILE* arch = fopen("c.xx","w+b");
    
    // // grabo un valor
    // char c = 'A';
    // fwrite(&c,sizeof(char),1,arch);

    // // grabo otro valor
    // c = 'B';
    // fwrite(&c,sizeof(char),1,arch);
    
    // // grabo otro valor
    // c = 'C';
    // fwrite(&c,sizeof(char),1,arch);
    
    // // grabo otro valor mas
    // c = 'D';
    // fwrite(&c,sizeof(char),1,arch);
    
    // // cierro el archivo
    // fclose(arch);

// Leo el archivo que eh generado c.xx
    // abro para lectura
    FILE* f=fopen("c.xx","r+b");
    char c;
    
    // leo el primer byte
    fread(&c,sizeof(char),1,f);
    
    // mientras no llegue el fin
    while( !feof(f) )
    {
        // caracterleido
        cout << c << endl;
        
        // leo caracter
        fread(&c,sizeof(char),1,f);
    }
    
        // cierro el archivo
        fclose(f);

    return 0;
}

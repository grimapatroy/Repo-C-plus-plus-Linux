#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;

// struct Producto
// {
//     int idPro;
//     char descr[8];
//     double precio;
//     int idRub;
// };

// struct Persona
// {
//     int dni;
//     string nombe;
//     string direccion;
// };

// struct RPersona
// {
//     Persona p;
//     int cont;
// };




int main()
{   
    FILE* f = fopen("PRODUCTOS.dat","r+b");
    
    Producto p = read<Producto>(f);
    while (!feof(f))
    {
        cout<<productoToDebug(p)<<endl;
        p = read<Producto>(f);
    }
    

    fclose(f);
    return 0;
}

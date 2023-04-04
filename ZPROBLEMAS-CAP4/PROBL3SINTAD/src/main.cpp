#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

using namespace std;

// Emisión de tickets (4 y 5)



int main()
{
    Coll<RProducto> collProductos = subirProductos();
    Coll<RRubro> collRubros = subirRubros();
    int idCliente {0}, idProducto {0}, cant {0};
    double total {0}, descTotal {0};
    cout<<"INGRESE CODIGO DE CLIENTE: ";
    cin>>idCliente;

    while (idCliente>0)
    {
        cout<<"INGRESE CODIGO DE PRODUCTO: ";
        cin>>idProducto;
        cout<<"INGRESE CANTIDAD DE PRODUCTOS: ";
        cin>>cant;
        
        // creo coleccion vacia de items para cada compra del cliente 
        Coll<Item> collItems = coll<Item>();

        while (idProducto>0)
        {
            procesarItem(collProductos,collRubros,collItems,idProducto,cant,total,descTotal);

            cout<<"INGRESE CODIGO DE PRODUCTO: ";
            cin>>idProducto;
            cout<<"INGRESE CANTIDAD DE PRODUCTOS: ";
            cin>>cant;
        }

        mostrarTikets(collItems);
        cout<<"INGRESE CODIGO DE CLIENTE: ";
        cin>>idCliente;
    }
    

    return 0;
}


// #include <string.h>
#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;


// Para este caso solo se vana ingresar una unica vez los regitros asi que solo abra ID sin serrepetidos

// 1. Para cada ciudad, cantidad de grupos (familias) que la eligieron de destino.
// 2. Por cada vuelo, cantidad de plazas rechazadas, indicando también si el vuelo
// saldrá completo o incompleto.
// 3. Para cada cliente, total de millas acumuladas.

int main()
{   
    FILE* archReserva = fopen("RESERVAS.dat","r+b");
    
    Clientes  cClientes =  clientesCreate();
    Vuelos cVuelos = vuelosCreate();
    Ciudades cCiudades = ciudadesCreate();

    Reserva regReserva = reservaLeer(archReserva);
    while (!feof(archReserva))
    {
        // porcesamos
            Vuelo v = vuelvosProcesar(regReserva.idVue,cVuelos);

            // Ciudad de origen y destino para procesarlos , saar millas, cant de grupso cmo destino, etc
            Ciudad cOrigen = ciudadesProcesarOrigen(v,cCiudades);

            //obtener ciudad destino
            Ciudad cDestino = ciudadesProcesarDestino(cCiudades,v);

            // obtener las millas entre el origen y  destino
            // int millas = rCiuOrigen.ciudad.millas-rCiuDes.ciudad.millas;
            int millas =  cOrigen.millas-cDestino.millas;

            //se acepto la reserva y el vuelo sale
            if (isVueloAceptado(v,regReserva.cant))
            {
                // Actualizo capacidad del vuelo y lo completo si es necesario
                vuelosActulizarCap(v,regReserva.cant,cVuelos);
                // procesarClientes(collClientes,millas,regReserva);
                clientesProcesar(cClientes,millas,regReserva.idCli);
            }else
            {
                vuelosActulizarRecha(v,regReserva,cVuelos);
            }
            ciudadesActulizarDestino(v,cCiudades);
    }
    ciudadesImprimir(cCiudades);
    vuelosImprimir(cVuelos);
    clientesImprimir(cClientes);

    fclose(archReserva);
    return 0;
}
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
    

    //la creo vacia por que no tengo una estrucura parecida en consultas
    Coll<RCliente> collClientes = coll<RCliente>();

    //las creao y le voy metiendo datos
    Coll<RVuelos> collVuelos = subirVuelos();
    Coll<RCiudad> collCiudades = subirCiduades();

    Reserva regReserva = read<Reserva>(archReserva);
    while (!feof(archReserva))
    {
        // porcesamos
            // procesamos el vuelo para obtener ciudad de origen y destino
            int posVuelo = collFind<RVuelos,int>(collVuelos,regReserva.idVue,cmpRVueloId,rVuelosFromString);
            RVuelos rVuelo = collGetAt<RVuelos>(collVuelos,posVuelo,rVuelosFromString);
            
            // Ciudad de origen y destino para procesarlos , saar millas, cant de grupso cmo destino, etc
            // obtener ciudad origen
            int posCiuOri = collFind<RCiudad,int>(collCiudades,rVuelo.vuelo.idOri,cmpRCiudadId,rCiudadFromString);
            RCiudad rCiuOrigen = collGetAt<RCiudad>(collCiudades,posCiuOri,rCiudadFromString);

            //obtener ciudad destino
            int posCiuDes = collFind<RCiudad,int>(collCiudades,rVuelo.vuelo.idDes,cmpRCiudadId,rCiudadFromString);
            RCiudad rCiuDes = collGetAt<RCiudad>(collCiudades,posCiuDes,rCiudadFromString);
            // obtener las millas entre el origen y  destino
            int millas = rCiuOrigen.ciudad.millas-rCiuDes.ciudad.millas;

            //se acepto la reserva y el vuelo sale
            if (rVuelo.vuelo.cap>=regReserva.cant)
            {
                // Actualizo capacidad del vuelo y lo completo si es necesario
                // int restoCap =  rVuelo.vuelo.cap-regReserva.cant;
                rVuelo.vuelo.cap-=regReserva.cant;
                collSetAt<RVuelos>(collVuelos,rVuelo,posVuelo,rVuelosToString);
                procesarClientes(collClientes,millas,regReserva);

            }else
            {
                // Actualizo capacidad del vuelo rechazadas
                // int restoCap =  regReserva.cant-rVuelo.vuelo.cap;
                rVuelo.acumRechazada+=regReserva.cant;
                collSetAt<RVuelos>(collVuelos,rVuelo,posVuelo,rVuelosToString);
            }
            
            //actualizo ciudad de destino por cada registo de reserva leido
            rCiuDes.cont++;
            collSetAt<RCiudad>(collCiudades,rCiuDes,posCiuDes,rCiudadToString);
    }
    
    mostrarResultados(collCiudades);
    mostrarResultados(collVuelos);
    mostrarResultados(collClientes);


    fclose(archReserva);
    return 0;
}
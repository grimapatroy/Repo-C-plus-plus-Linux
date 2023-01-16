#ifndef _FMAIN
#define _FMAIN
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../tads/negocio/productos.hpp"
#include "../tads/negocio/rubros.hpp"
#include "../tads/negocio/tikets.hpp"
#include "../tads/negocio/elementos.hpp"

void procesar(Productos& cproductos,Rubros& crubros,Tikets Tk, int& idProducto,int& cant){

	Producto elemProduct = productosBuscar(cproductos, idProducto);

	Rubro elemRubro = rubrosBuscar(crubros, elemProduct.idRub);

	productosActualizarDemanda(cproductos,idProducto,cant);

	double descto = elemProduct.precio*elemRubro.promo*cant;

	rubrosActualizarDtos(crubros,elemProduct.idRub,descto);

	Item it = {elemProduct.descr,elemProduct.precio,cant,elemRubro.promo,elemProduct.precio*cant};

	tiketsAgregarItems(Tk,it);

}


#endif
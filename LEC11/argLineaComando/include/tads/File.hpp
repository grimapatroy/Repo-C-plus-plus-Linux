#ifndef _TDA_FILE
#define _TDA_FILE

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

template<typename T>
struct File
{
    // char BYTE[8];
};






template<typename T>
File<T> file(string fileName,string modoApertura)
{
// programar aqui...
}







// lee y retorna el registro apuntado por el indicador
// de posicion del archivo, avanzando dicho indicador
// hacia el siguiente registro NO eliminado
template<typename T>
T fileRead(File<T>& f)
{
// programar aqui...
}








// escribe el valor t en el registro apuntado por el
// indicador de posicion del archivo, avanzando dicho
// indicador hacia el siguiente registro NO eliminado
template<typename T>
void fileWrite(File<T>& f,T t)
{
// programar aqui...
}
// retorna la cantidad de registros NO eliminados
// que tiene el archivo
template<typename T>
int fileSize(File<T> f)
{
// programar aqui...
}







// hace que el indicador de posicion del archivo
// pase a apuntar al registro numero p.
// Por ejemplo: si p es 3, pero el registro 1
// esta eliminado, entonces fisicamente el tercer
// registro del archivo sera el que ocupa la pocision 4
template<typename T>
void fileSeek(File<T>& f,int p)
{
// programar aqui...
}




// retorna el valor del indicador de posicion del archivo.
// Por ejemplo: si el registro actual es 4 pero el registro
// 1 esta eliminado, entonces el registro actual es 3
template<typename T>
int filePos(File<T>& f)
{
// programar aqui...
}




// borra el registro apuntado por el indicador
// de posicion del archivo
template<typename T>
void fileDelete(File<T>& f)
{
// programar aqui...
}




// regenera el archivo quitando fisicamente aquellos
// registros que fueron elminados con fileDelete
template<typename T>
void fileRepack(File<T>& f)
{
// programar aqui...
}



// cierra el archivo
template<typename T>
void fileClose(File<T>& f)
{
// programar aqui...
}




#endif

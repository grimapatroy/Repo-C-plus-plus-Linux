#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   fwrite(&t,sizeof(T),1,f);
}

template<typename T> T read(FILE* f)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);

   T t;
   fread(&t,sizeof(T),1,f);
   return t;
}

template<typename T>void seek(FILE* f, int n)
{
   // leo para ver que tipo de datotiene el archivo
   // T t =  fread(&t,sizeof(T),1,f);
   T byteT = sizeof(T)*n;
   fseek(f,byteT,SEEK_SET);
}



template<typename T>int fileSize(FILE* f)
{
   // guardo  indicador de  posicion actual
      int posActual = ftell(f);

    // me muevo al ultimo byte
      fseek(f,0,SEEK_END);

    // guardo indicador en el ultimo byte
      int nroUltimoByte = ftell(f);

    // me muevo a la posicion anterior que guarde
      fseek(f,posActual,SEEK_SET);

   // retorno la cantidad de registros tipo T
   return nroUltimoByte/sizeof(T);
}

template<typename T> int filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}

#endif

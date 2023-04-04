#ifndef _FMAIN
#define _FMAIN
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../tads/negocio/Resultado.hpp"


void calcularYValidarDuracion(int minutosConsumidos,Coll<int>& cCon,int duracionAlbum ){
    float porcentaje = (minutosConsumidos * 100)/(float)duracionAlbum;
    if (porcentaje == 1.0)
    {
        int c100 = collGetAt<int>(cCon,0,stringToInt);
        c100++;
        collSetAt<int>(cCon,c100,0,intToString);
    }else
    {
        if( porcentaje>=0.75 && porcentaje<1.0 )
        {
            int c75 = collGetAt<int>(cCon,1,stringToInt);
            c75++;
            collSetAt<int>(cCon,c75,1,intToString);
        }
        else
        {
            if (porcentaje>=0.5 && porcentaje<0.75)
            {
                int c50 = collGetAt<int>(cCon,2,stringToInt);
                c50++;
                collSetAt<int>(cCon,c50,2,intToString);
            }
            else
            {
                int c25 = collGetAt<int>(cCon,3,stringToInt);
                c25++;
                collSetAt<int>(cCon,c25,3,intToString);
            }
        }
    }
}


#endif
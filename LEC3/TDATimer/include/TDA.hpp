#ifndef _TDATimer_
#define _TDATimer_

#include <iostream>
#include "strings.hpp"
#include<math.h>
using namespace std;

// tipo de entero muy grande
typedef unsigned long long Long;

    struct  Timer
    {
        int inicio;//hora inicio
        int fin;//hora final
    };

    // funcion de inicializacion
    Timer timer()
    {
        return {0,0};
    }   

    // instante inicial (i)
    void timerStart(Timer& t)
    {
        cout<<"Ingrese la hora de incio:";
        cin>>t.inicio;

    }

// instante final (f)
    void timerStop(Timer& t)
    {
        cout<<"Ingrese la hora de fin: ";
        cin>>t.fin;
    }

// retorna el tiempo transcurrido entre f e i,
// expresado en milisegundos
    Long timerElapsedTime(Timer t)
    {
        // Long a;
        return Long(((t.fin - t.inicio)*60*60)/10^3);
    }

    string timerToString(Timer t)
    {
        return intToString(t.inicio)+ "----->"+intToString(t.fin);
    }
#endif
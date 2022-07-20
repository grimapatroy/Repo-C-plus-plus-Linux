#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
#include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"
using namespace std;






int main()
{   
    Coll<Ciudad> collCiudades = subirCiudades(); 

    collSort<Ciudad>(collCiudades,cmpCiudadDesc,ciudadFromString,ciudadToString);

    collReset<Ciudad>(collCiudades);
    while (collHasNext<Ciudad>(collCiudades))
    {
        Ciudad  c = collNext<Ciudad>(collCiudades,ciudadFromString);
        cout<<ciudadToDebug(c)<<endl;
    }
    


    return 0;
}

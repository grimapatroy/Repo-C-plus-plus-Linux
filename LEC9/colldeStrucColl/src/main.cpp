#include <iostream>
// #include "../include/funciones/strings.hpp"
#include "../include/tads/Coll.hpp"
using namespace std;


int main()
{   
    Coll<Conjunto> cc = coll<Conjunto>();

    Conjunto conjuntito1 = {"pares",coll<int>(',')};
    // coll<int> c = coll<int>();
    collAdd<int>(conjuntito1.c,2,intToString);
    collAdd<int>(conjuntito1.c,4,intToString);
    collAdd<int>(conjuntito1.c,6,intToString);
    collAdd<Conjunto>(cc,conjuntito1,conjuntoToString);


    Conjunto conjuntito2 = {"impares",coll<int>(',')};
    collAdd<int>(conjuntito2.c,1,intToString);
    collAdd<int>(conjuntito2.c,3,intToString);
    collAdd<int>(conjuntito2.c,5,intToString);
    collAdd<int>(conjuntito2.c,7,intToString);
    collAdd<int>(conjuntito2.c,9,intToString);
    collAdd<Conjunto>(cc,conjuntito2,conjuntoToString);

    Conjunto conjuntito3 = {"impares",coll<int>(',')};
    collAdd<int>(conjuntito3.c,2,intToString);
    collAdd<int>(conjuntito3.c,3,intToString);
    collAdd<int>(conjuntito3.c,5,intToString);
    collAdd<int>(conjuntito3.c,7,intToString);
    collAdd<int>(conjuntito3.c,11,intToString);
    collAdd<Conjunto>(cc,conjuntito3,conjuntoToString);

    for (int i = 0; i <collSize<Conjunto>(cc); i++)
    {
        Conjunto token = collGetAt<Conjunto>(cc,i,conjuntoFromString);
        cout<<"["; 
        cout<<token.nombre;
        for (int j = 0; j < collSize<int>(token.c); j++)
        {
            int tokenInt = collGetAt<int>(token.c,j,stringToInt);
            cout<<" "; 
            cout<<tokenInt; 
        }
        cout<<"]"; 
    }

    return 0;
}

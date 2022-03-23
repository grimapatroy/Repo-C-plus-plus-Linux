#include <iostream>
// #include "../include/funciones/strings.hpp"
#include "../include/tads/Coll.hpp"
using namespace std;


int main()
{   
    Coll<Coll<int>> collColl = coll<Coll<int>>();

    // collAdd<Coll<int>>(collColl,Coll<int>,);
    Coll<int> coleccioncita = coll<int>(',');
    collAdd<int>(coleccioncita,1,intToString);
    collAdd<int>(coleccioncita,2,intToString);
    collAdd<int>(coleccioncita,3,intToString);

    collAdd<Coll<int>>(collColl,coleccioncita,collIntToString);

    coleccioncita = coll<int>(',');
    collAdd<int>(coleccioncita,4,intToString);
    collAdd<int>(coleccioncita,5,intToString);
    collAdd<int>(coleccioncita,6,intToString);

    collAdd<Coll<int>>(collColl,coleccioncita,collIntToString);

    coleccioncita = coll<int>(',');
    collAdd<int>(coleccioncita,7,intToString);
    collAdd<int>(coleccioncita,8,intToString);
    collAdd<int>(coleccioncita,9,intToString);

    collAdd<Coll<int>>(collColl,coleccioncita,collIntToString);
    
    for (int i = 0; i < collSize<Coll<int>>(collColl); i++)
    {
        cout<<"[";
        Coll<int> coleccioncita = collGetAt(collColl,i,collIntFromString);
        for (int j = 0; j < collSize<int>(coleccioncita); j++)
        {
            int token = collGetAt<int>(coleccioncita,j,stringToInt);
            cout<<token;
        }
            cout<<"]";
    }
    return 0;
}

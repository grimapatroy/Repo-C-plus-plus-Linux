#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/Array.hpp"
// #include "../include/tads/testTools.hpp"
#include "../include/funciones/arrays.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"


int cmpInt (int a,int b){
    return b-a;
}


int main()
{   
    Array<int> a = array<int>();
    // Array<int> b = array<int>(6);
arrayOrderedInsert<int>(a,2,cmpInt);
arrayOrderedInsert<int>(a,1,cmpInt);
arrayOrderedInsert<int>(a,3,cmpInt);
for(int i=0;i<arraySize<int>(a);i++)
{
int* p = arrayGet<int>(a,i);
cout << *p << endl; // SALIDA 1,2,3
}

    cout << "------"<< endl; // SALIDA 1,2,3
    cout << a.len << endl; // SALIDA 1,2,3
    cout << a.cap << endl; // SALIDA 1,2,3


    return 0;
}

#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
// #include "../include/tads/testTools.hpp"
#include "../include/funciones/arrays.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"


void redimensionar(int*& a,int cap,int nuevaCap){
// creo un array con la nueva capacidad
int* b = new int[nuevaCap];

// copio los datos del array a al array b
for(int i=0; i<cap; i++){
    b[i]=a[i];
}
// libero el array a
delete a;

// hago que a apunte al nuevo array
a = b;
}

void cambiarDireccion(int& i,int*& p,int*& z,int**& q){
    p = &i;
    q = &p;
    z = p;
    // p = z;

}


int main()
{   
    // int n;
    // cin>>n;
    
    // int* a = new int[4];
    // redimensionar(a,n,2*n);
    // cout<<size_t(a)<<endl;

    int i = 10;
    int* p = NULL;
    
    int* z = NULL;
    int** q = NULL;

    cambiarDireccion(i,p,z,q);
    cout<<i<<" valor de i"<<endl;
    cout<<*p<<" valor de i(contenido que se aloja en la memoria que esta dicendo direccionada por p)"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"-----------------"<<endl;
    cout<<&i<<" direccion de memoria de i"<<endl;
    cout<<p<<" direccion de memoria de que esta apuntado p"<<endl;
    cout<<*q<<" direccion de memoria a la que esta apuntando osea p, es decir i(ya que p apunta a i)"<<endl;
    cout<<"-----------------"<<endl;
    cout<<&p<<" direccion de memoria de p"<<endl;
    cout<<q<<" la direccion a la que apunta es p"<<endl;
    cout<<**q<<" valor de i(contenido que se aloja en la memoria que esta dicendo direccionada por p"<<endl;
    cout<<"-----------------"<<endl;
    cout<<z<<" la direccion a la que apunta es decir p, es decir i, ya qeu p aputa a i como variable "<<endl;
    cout<<*z<<" valor de i(contenido que se aloja en la memoria que esta dicendo direccionada por p)"<<endl;

    return 0;
}

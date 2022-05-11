#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
using namespace std;


unsigned char x(unsigned char c){
    unsigned char t = c<<4;
    c=c>>4;
    return t|c;
}

void f (unsigned char& c){

        unsigned char x=(c&128)>>7;
        c=(c<<1)|x;
}

int main()
{   

    // unsigned short a = 3598; // a => |00001101|11001100|
    // unsigned short b = a<<1; // b => |00011011|10011000| => 7064
    // unsigned short c = b>>3; // c => |00000011|01110011| => 441
    
    // // 101|101|000|011|010|010|000|101|100|010
    // // 5    5  0   3    2   2  0   5    4   2
    // unsigned int octal = 05503220542;
    
    // // 0010|1101|0000|1101|0010|0001|0110|0010
    // // 2    D     0     D    2    1    6   2
    // unsigned int hexadecimal = 0x2D0D2162;


    // cout<<a<<endl;
    // cout<<b<<endl;
    // cout<<c<<endl;
    // cout<<octal<<endl;
    // cout<<hexadecimal<<endl;



    // // operadores logicos " 0 = False" "1 = Verdad"
    // // &(and) --> 1 - 1 = 1    // 0-1 - 1-0 - 0 -0 (va 0 si existe almenosun cero)
    
    // unsigned short a = 3532;    // a => |00001101|11001100|
    // unsigned short b = 0x0F00;  // b => |00001111|00000000|
    // unsigned short c = a&b;     // c => |00001101|00000000| => 3328

    // // |(or) 

    // unsigned char t = 0x0F;
    // int rtdo = x(x(t));
    // cout<<rtdo<<endl;

    // int a = 1234;
    // int b = 0761;
    // int c = 0005;
    // cout<<a+b+c<<endl;


    unsigned char t = 0x0F;
    f(t);
    cout<<t;

    return 0;
}

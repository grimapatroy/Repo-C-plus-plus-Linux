#ifndef _TADBigInt_
#define _TADBigInt_

#include <iostream>
#include "strings.hpp"
using namespace std;

struct BigInt
{
    string s;
};

BigInt bigInt(string n){
    return {n};
}

int numBigIntToInt(BigInt a){
    return stringToInt(a.s);
}

BigInt bigIntSumar(BigInt a , BigInt b){
    int a1 = numBigIntToInt(a);
    int b1 = numBigIntToInt(b);
    int suma = a1 + b1;
    BigInt sum = bigInt(intToString(suma));
    return sum;
}

#endif
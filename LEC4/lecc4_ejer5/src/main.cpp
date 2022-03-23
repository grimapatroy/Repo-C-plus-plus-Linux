#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


int main()
{   
    string num1,num2;
    cout<<"Ingrese minuendo: ";
    cin>>num1;
    cout<<"Ingrese sustraendo: ";
    cin>>num2;

    BigInt a = bigInt(num1);
    BigInt b = bigInt(num2);

    cout<<numBigIntToInt(bigIntSumar(a,b));
    return 0;
}
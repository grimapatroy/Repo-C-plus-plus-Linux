#include <iostream>
using namespace std;


int main()
{   
    int n;
    int i= 0;
    int acum5=0;
    cout<<"INGRESE CANTIDAD: ";
    cin>>n;


    while (n>0 and i<n)
    {
        acum5=acum5+5;
        if (acum5%5==0 and acum5%3!=0)
        {
            cout<<acum5<<endl;
            i++;
        }
    }
    
    return 0;
}
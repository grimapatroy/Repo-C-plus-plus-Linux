#include <iostream>
using namespace std;


int main()
{   

    int cont1 = 0,cont2= 0,cont3= 0,cont4=0;
    int valor;
    cout<<"INGRESE VALOR: ";
    cin>>valor;

    while (valor>=0)
    {
        if (valor==0)
        {
            cont4++;
        }
        else
        {
            if (valor<=12)
            {
               cont1++;
            }
            else
            {
                if (valor>12 and valor<=24)
                {
                    cont2++;
                }
                else
                {
                    if (valor>24 and valor<=36)
                    {
                        cont3++;
                    }
                   
                    
                }
                
            }
            
        }

        cout<<"INGRESE VALOR: ";
        cin>>valor;
    }
    
    cout<< "TOTAL valor<=12 : " << cont1 << endl;
    cout<< "TOTAL 12<valor<=24 : " << cont2 << endl;
    cout<< "TOTAL 24<valor<=36 : " << cont3 << endl;
    cout<< "TOTAL valor==0 : " << cont4 << endl;

    return 0;
}
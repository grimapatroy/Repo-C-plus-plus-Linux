#include <iostream>
#include "../include/TDA.hpp"
using namespace std;


int main()
{   
    bool seguir=true;
    Timer t = timer();
    
    while (true)
    {
        timerStart(t);
        timerStop(t);
        cout<<timerElapsedTime(t)<<endl;
        // cout<<timerToString(t)<<endl;
        cout<<"Desea seguir calculando el tiempo:(si=1)(no=0): ";
        cin>>seguir;
        if(!seguir){
            cout<<"GRACIAS, HASTA LUEGO"<<endl;
            break;
        }
    }
    


    return 0;
}
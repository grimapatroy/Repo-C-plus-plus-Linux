#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tads/Coll.hpp"
using namespace std;




int main(int argc, char** argv)
{   
    for (int i = 0; i < argc; i++)
    {
        string s = argv[i];
        cout<<s<<endl;
    }
    
    return 0;
}

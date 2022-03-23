#ifndef __Anagrama__
#define __Anagrama__


#include <iostream>
#include <strings.h>
using namespace std;


// Alegan – Ángela
bool esAnagrama(string a,string b){
    int i;
    int dis = length(a)-1;
    a,b=toUpperCase(a),toUpperCase(b);
    // b=toUpperCase(b);
    for ( i = 0;  a[i] == b[dis] and i<length(a) and dis>=0 ; i++){
   
        dis--;
    }
    return i==length(a)?true:false;
}

#endif
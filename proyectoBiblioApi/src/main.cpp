// #include <string.h>
#include <stdio.h>
#include "../include/funciones/strings.hpp"
#include "../include/funciones/tokens.hpp"
#include "../include/funciones/files.hpp"
#include "../include/tads/BitReader.hpp"
#include "../include/tads/BitWriter.hpp"
// #include "../include/tads/test.hpp"
using namespace std;





int main()
{   
    // string s = "John|Paul|George|Ringo|| |Joselito";
    // char sep = '|';
    // string t = "McCartney";
    // cout<<s<<endl;
    // setTokenAt(s,sep,t,1);
    // cout << s << endl; // Salida: John|McCartney|George|Ringo
    // setTokenAt(s,sep,"",2);
    // cout << s << endl;
    // setTokenAt(s,sep,"Super",0);
    // cout << s << endl;
    // setTokenAt(s,sep," ",3);
    // cout << s << endl;
    // setTokenAt(s,sep," ",4);
    // cout << s << endl;
    // setTokenAt(s,sep,"JABALI",0);
    // cout << s << endl;
    // setTokenAt(s,sep,"KOKODRILO",10);
    // cout << s << endl;
    // setTokenAt(s,sep,"Zorro",1);
    // cout << s << endl;
    // setTokenAt(s,sep,"Perro",2);
    // cout << s << endl;
    // setTokenAt(s,sep,"Gato",3);
    // cout << s << endl;
    // setTokenAt(s,sep,"Leon",4);
    // cout << s << endl;
    // setTokenAt(s,sep,"Torutuga",5);
    // cout << s << endl;
    // setTokenAt(s,sep,"Asno",6);
    // cout << s << endl;
    // setTokenAt(s,sep,"KOKODRILO",7);
    // cout << s << endl;
    // cout << "Metoodo GET" << endl;
    // for (int i = 0; i < tokenCount(s,sep); i++)
    // {
    //     removeTokenAt(s,sep,i);
    //     cout << s << endl;
    // }
    //     cout << getTokenAt(s,sep,10) << endl;
    // cout << "----------------------------" << endl;
    
    string s = "John|Paul|George|Ringo";
    char sep = '|';
    string t = "Paul";
    int p = findToken(s,sep,t);
    cout << p << endl; // Salida: 1
    t = "John";
    p = findToken(s,sep,t);
    cout << p << endl; // Salida: 0
    cout << findToken(s,sep,"jamon") << endl; // Salida: -1
    cout << findToken(s,sep,"-") << endl; // Salida: -1
    cout << findToken(s,sep,"") << endl; // Salida: -1
    cout << findToken(s,sep," ") << endl; // Salida: -1



    return 0;
}
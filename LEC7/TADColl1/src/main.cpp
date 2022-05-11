#include <iostream>
// #include "../include/funciones/strings.hpp"
#include "../include/tads/Coll.hpp"
using namespace std;



int main()
{   
    // string s = "javier|coste|lote|rufus";
    // cout<<"La posicion es: "<<endl;
    // setTokenAt(s,'|',"cero",0);
    // setTokenAt(s,'|',"uno",2);
    // setTokenAt(s,'|',"dos",1);
    // setTokenAt(s,'|',"tres",4);
    // setTokenAt(s,'|',"cuatro",5);
    // setTokenAt(s,'|',"cinco",tokenCount(s,'|'));

    // cout<<s<<endl;

    // removeTokenAt(s,'|',0);
    // cout<<s<<endl;
    // removeTokenAt(s,'|',2);
    // cout<<s<<endl;
    // removeTokenAt(s,'|',1);
    // cout<<s<<endl;
    // removeTokenAt(s,'|',4);
    // cout<<s<<endl;
    // removeTokenAt(s,'|',4);
    // cout<<s<<endl;

    // Coll<int> c1 = coll<int>();
    // collAdd<int>(c1,102,intToString);
    // collAdd<int>(c1,202,intToString);
    // collAdd<int>(c1,302,intToString);

    // for (int i = 0; i < collSize<int>(c1); i++)
    // {
    // }
    // collMostrar(c1);
        // int p = collGetAt<int>(c,i,stringToInt);

    // -------------------------------------coleccion de personas
    // Coll<Persona> c = coll<Persona>();
    // collAdd<Persona>(c,persona(44,"Wedro"),personaToString);
    // collAdd<Persona>(c,persona(44,"Dedro"),personaToString);
    // collAdd<Persona>(c,persona(22,"Bablo"),personaToString);
    // collAdd<Persona>(c,persona(12,"Ziian"),personaToString);
    // collAdd<Persona>(c,persona(33,"Carlos"),personaToString);
    // collAdd<Persona>(c,persona(11,"Auan"),personaToString);
    // collAdd<Persona>(c,persona(15,"Xuan"),personaToString);
    // int dni=33;
    // string h="Pedro";
    // int pos = collFind<Persona,int>(c,dni,cmpPersonaDNI,personaFromString);
    // int pos = collFind<Persona,string>(c,h,cmpPersonaNombre,personaFromString);
// ----------------ordenar-----------------------------------------------------
    // collSort<Persona>(c,cmpPersonaNombre2,personaFromString,personaToString);
    
    // for (int i = 0; i < collSize<Persona>(c); i++)
    // {
    //     Persona p = collGetAt<Persona>(c,i,personaFromString);
    //     cout<<personaToString(p)<<endl;
    // }

    // Persona p = collGetAt<Persona>(c,pos,personaFromString);
    // cout << personaToString(p) << endl;
// mostrarColeccion(c);
// -----------------------------------------------------------------------------

    // Coll<Persona> micoll = coll<Persona>();
    // collAdd<string>(micoll,"JUAN",stringToString);
    // collAdd<string>(micoll,"PEDRO",stringToString);
    // collAdd<string>(micoll,"PABLO",stringToString);
    // collAdd<string>(micoll,"MATIAS",stringToString);
    
    
    // collAdd<Persona>(micoll,{87654,"ALAIN"},personaToString);
    // collAdd<Persona>(micoll,{12345,"JOSE"},personaToString);
    // collAdd<Persona>(micoll,{2345,"KIKO"},personaToString);
    // collAdd<Persona>(micoll,{2345,"KIKO"},personaToString);
    // collAdd<Persona>(micoll,{23154,"ALAIN"},personaToString);
    // collAdd<Persona>(micoll,{23154,"ZATIR"},personaToString);
    // collAdd<Persona>(micoll,{23154,"KARMELA"},personaToString);
    // collAdd<Persona>(micoll,{23154,"LOLA"},personaToString);
    // collAdd<Persona>(micoll,{23154,"ALAN"},personaToString);
    // collAdd<Persona>(micoll,{23154,"JESUS"},personaToString);

    Coll<int> c1 = coll<int>();
    collAdd<int>(c1,102,intToString);
    collAdd<int>(c1,202,intToString);
    collAdd<int>(c1,302,intToString);

    // collReset<string>(micoll);
    // bool endOfColl=false;
    // string s = collNext<string>(micoll,endOfColl,stringFromString);

    // while (endOfColl)
    // {
    //     cout<<s<<endl;
    //     s = collNext<string>(micoll,endOfColl,stringFromString);
    // // }
    // string buscar = "PEDRO";
    // int pos = collFind<Persona>(micoll,buscar,cmpPersonaNombre,personaFromString);
    // cout<<pos;
    // bool endOfColl=0;  
    // collReset<Persona>(micoll);
    // collSort<Persona>(micoll,cmpPersonasNomDesc,personaFromString,personaToString);


    // mostrarColeccion(c1);
    collSort<int>(c1,cmpInt,stringToInt,intToString);
    
    // Persona p = collNext<Persona>(micoll,endOfColl,personaFromString);
    for (int i = 0; i < collSize<int>(c1); i++)
    {
        int c = collGetAt<int>(c1,i,stringToInt);
        cout<<c<<endl;
    }
    
    
    // while (!endOfColl)
    // {
    //     cout<<personaToString(p)<<endl;
    //     p = collNext<Persona>(micoll,endOfColl,personaFromString);
    // }

    return 0;
}
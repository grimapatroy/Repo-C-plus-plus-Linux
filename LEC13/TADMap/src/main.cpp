#include <iostream>
#include <stdio.h>
// #include <unordered_map> //mapa sin oreden tal cual su ingreso
#include <map>
#include <string>
#include <list>


#include "../include/tads/Coll.hpp"
// #include "../include/tads/Array.hpp"
// #include "../include/tads/Map.hpp"
// #include "../include/tads/testTools.hpp"
#include "../include/funciones/arrays.hpp"



int main()
{
    // Para datos simples o nativos

            // // para diccionarios sin ordenar tal cual si ingreso
            // unordered_map<string,string> myDictionary;

            // para diccionario ordenados alfabeticamente
            map<string,string> myDictionary;
            myDictionary.insert(pair<string,string>("banana","die Banane"));
            myDictionary.insert(pair<string,string>("apple","de apfer"));
            myDictionary.insert(pair<string,string>("orange","die Orange, die Apfesine"));
            myDictionary.insert(pair<string,string>("filemon","almodas"));

            // opcional agregamos con pair y luego con insert
            // pair<string,string> p1("limon","verde como el color");


            // // para modificar/ set
            // myDictionary["filemon"] = "Die Erbeere";

            // // para ver el tamaño
            // cout<<myDictionary.size()<<endl;


            // // para vacio todo el diccionario
            // // myDictionary.clear();

            // // para eliminar elemento por clave
            // myDictionary.erase("banana");
            // myDictionary.erase("banana".first);

            // para ver si el mapa esta vacio devuelve 1 sino esta vacio 0
            // myDictionary.empty();



            // for (auto itr = myDictionary.begin(); itr != myDictionary.begin(); ++itr)
            // {
            //     /* code */
            // }

            for (map<string,string>::iterator itr = myDictionary.begin(); itr != myDictionary.end(); ++itr)
            {
                cout<<(*itr).first<< " - " << itr->second<<endl  ;
            }

             // foreach( mas emcamsulado)
            // for(auto pair:myDictionary){
            //     cout<<pair.first << " - " << pair.second<<endl;
            // }

        // std::map<char,int> mymap;
        // std::map<char,int>::iterator it;

        // mymap['a']=50;
        // mymap['b']=100;
        // mymap['c']=150;
        // mymap['d']=200;
        // it = mymap.find('b');
        // if (it != mymap.end())
        //     mymap.erase (it);


    // -------------------------------------------------------------------------------------------------

// para datos complejos
    // map<string,list<string>> pokedex;
    // list<string> pikachuAtack {"Kariyushi","ataque rápido","Thunder Shock","La electrobanda"};
    // list<string> snorladAtack {"Kariyushi","ataque rápido","Thunder Shock","La electrobanda"};
    // list<string> volvarsourtAtack {"Kariyushi","ataque rápido","Thunder Shock","La electrobanda"};
// -------------------------------------
    // pokedex.insert(pair<string,list<string>>("Pikachu",pikachuAtack));
    // pokedex.insert(pair<string,list<string>>("Snorlad",snorladAtack));
    // pokedex.insert(pair<string,list<string>>("Volvasourd",volvarsourtAtack));
// ------------
    // for (auto pair : pokedex)
    // {
    //     cout<< pair.first<< " - ";
    //     for (auto attack : pair.second)
    //     {
    //         cout<< attack << ", ";
    //     }
    //     cout<< endl;
    // }



    return 0;
}

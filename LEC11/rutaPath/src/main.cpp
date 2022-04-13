#include <iostream>
#include <stdio.h>
#include <string>
#include <filesystem>
#include <unistd.h>
#include "../include/tads/Coll.hpp"
using namespace std;

// using std::cout; using std::cin;
// using std::endl; using std::string;
// using std::filesystem::current_path;
// using filesystem::current_path;


string getDirectory()
{
    char abs_path[1024];
    int cnt = readlink("/proc/self/exe", abs_path, 1024);// Obtener la ruta absoluta del programa ejecutable
    if(cnt < 0|| cnt >= 1024)
    {
        return NULL;
    }
    // El último '/' va seguido del nombre del programa ejecutable, elimine devel / lib / m100 / exe y solo conserve la primera parte de la ruta
    for(int i = cnt; i >= 0; --i)
    {
        if(abs_path[i]=='/')
        {
            abs_path[i + 1]='\0';
            break;
        }
    }
    string path(abs_path);
    return path;
}







int main()
{   
    // char path[1024];
    // string path;
    cout << "*******************+RUTA ACTUAL DEL EJECUTABLE: "<<getDirectory() << endl;
    return 0;
}

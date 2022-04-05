#include <string.h>
#include <stdio.h>
#include "../include/funciones/strings.hpp"
#include "../include/funciones/tokens.hpp"
#include "../include/funciones/files.hpp"
#include "../include/tads/BitReader.hpp"
#include "../include/tads/BitWriter.hpp"
using namespace std;





int main()
{   
    FILE* f = fopen("archivox.dat","w+b");
    BitWriter bw=bitWriter(f);
    // bitWriterWrite(bw,200);
    bitWriterWrite(bw,1);
    bitWriterFlush(bw);
    // bitWriterWrite(bw,0);
    // bitWriterWrite(bw,0);
    // bitWriterWrite(bw,1);
    // bitWriterWrite(bw,1);
    // bitWriterWrite(bw,1);
    // bitWriterWrite(bw,1);
    // ----------------------------------
    // FILE* f = fopen("archivox.dat","r+b");
    fseek(f,0,SEEK_SET);
    BitReader br = bitReader(f);

    int bit = bitReaderRead(br);
    while( !feof(f) )
    {
        cout << bit << endl;
        bit = bitReaderRead(br);
    }

    fclose(f);
    return 0;
}
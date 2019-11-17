#include <stdio.h>
#define N 2048
/* File copy command line mode */
int main(int argc, char *argv[])
{
    FILE *pFile1, *pFile2;
    char buffer[N];
    size_t lSize;

    //command line mode exec .exe file, and add other two parameter so as to transform the variable
    //obtain command line parameter counts, at lease 3 para:
    if(argc<3) {fputs("Argc error", stderr); exit(0);}
    pFile1 = fopen(argv[1], "rb");
    pFile2 = fopen(argv[2], "wb");
    if(pFile1==NULL || pFile2==NULL) {fputs("File error", stderr); exit(1);}

    lSize = fread(buffer, 1, N, pFile1);
    while(lSize>0)
    {
        fwrite(buffer, 1, lSize, pFile2);
        lSize = fread(buffer, 1, N, pFile1);
    }
    //terminate
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}



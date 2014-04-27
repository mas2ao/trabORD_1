#include <string.h>
#include "fileIO.h"
#include "struct.h"

int binarySearch(tsecNome **secNome, char chave[], int tamTotal){
    int inf = 0;
    int sup = tamTotal-1;
    int meio;
    
    while (inf <= sup){
        meio = inf+(sup-inf)/2;
        if (strcmp(chave, secNome[meio]->string) == 0){
            return meio;
        }else if (strcmp(chave, secNome[meio]->string) < 0){
            sup = meio-1;
        }else{
            inf = meio+1;
        }
    }
    return -1;
}

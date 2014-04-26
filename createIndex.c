#include "fileIO.h"

void criaIndicePrimario(int **indexPrim, int tamTotal){
    FILE *fd, *reg;
    int i, j, k, tamReg;
    char tam[2], string[MAX_REC_SIZE], quant_delim, c;
    
    reg = fopen("reg.txt", "r");
    fd = fopen("indexPrim.txt", "w");
    
    fseek(fd, TAM_HEADER+1, 0);
    putc(START_REC, fd);
    for (i=0; i<tamTotal; i++){
//        printf("%d => %d\n",i,  indexPrim[i][1]);
        fseek(reg, indexPrim[i][1], 0);
        quant_delim = 0;
        c = getc(reg);
        do{
            if (c == DELIM_CHR){
                quant_delim++;
            }
            putc(c, fd);
            c = getc(reg);
        }while(quant_delim < 4 );
    }
}

void criaIndiceSecAluno(int **indexPrim, char **indexSecNome, int tamTotal){
    FILE *fd, *reg;
    
    reg = fopen("reg.txt", "r");
    fd = fopen("indexSecAluno.txt", "w");
    
    
    fclose(reg);
    fclose(fd);
    
}
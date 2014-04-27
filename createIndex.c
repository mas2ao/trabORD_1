#include "fileIO.h"
#include "struct.h"

void criaIndicePrimario(liPrimCod **primCod, int tamTotal){         //cria arquivo de indice primario(ORDENADO)
    FILE *fd, *reg;
    int i, j, k, tamReg;
    char tam[2], string[MAX_REC_SIZE], quant_delim, c;
    
    reg = fopen("reg.txt", "r");
    fd = fopen("indexPrim.txt", "w");
    
    fseek(fd, TAM_HEADER+1, 0);
    putc(START_REC, fd);
    for (i=0; i<tamTotal; i++){
        fseek(reg, primCod[i]->cp.offset, 0);
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

void criaIndiceSecNome(tliNome **linome, tsecNome **secNome, liPrimCod **primCod, int tamTotal){
    FILE *fd, *reg;
    int i, j, codigo;
    
    for (i=0; i<tamTotal; i++){
        strcpy(linome[i]->string, secNome[i]->string);
        linome[i]->rrn = NULL;
    }
    
    for (i=0; i<tamTotal; i++){
        j = binarySearch(secNome, linome[i]->string ,tamTotal);
        if (j != -1){
            codigo = tsecNome[j].codigo;
        }
        
        
    }
   
    
    
    
        
  
   
    
    
    
}
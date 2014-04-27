#include "fileIO.h"




//void criaMatSecAluno(char **matSec, int tamTotal){
//    FILE *reg, *regOffset;
//    int i, j, tamOffset;
//    char c, string[10], nome[MAX_REC_SIZE];
//    
//    reg = fopen("dados.txt", "r");
//    regOffset = fopen("regOffset.txt", "r");
//    
//    for (i=0; i<tamTotal; i++){
//        c = getc(regOffset);
//        j=0;
//        do{                             //pega a pocisao do offset no arquivo regOffset.txt
//            string[j] = c;
//            j++;
//            c = getc(regOffset);
//        }while (c != DELIM_CHR);
//        tamOffset = atoi(string);
//        matSec[i][1] = (char) 0;
//        fseek(reg, tamOffset+10, 0);
//        
//        c = getc(reg);
//        j=0;
//        do{
//            nome[j] = c;
//            j++;
//            c = getc(reg);
//        }while (c != DELIM_CHR);
//        nome[j] = '\0';
//        matSec[i][0] = nome;
//    } 
//    
//}

void criaListaNomes(int **indexPrim, char **listaNomes, int tamTotal){
    FILE *reg;
    int i, j, offset, tam;
    char c, buffer[MAX_REC_SIZE];
    
    reg = fopen("reg.txt", "r");
    for (i=0; i<tamTotal; i++){
        fseek(reg, indexPrim[i][1]+9, 0);
        buffer[i] = '\0';
        j=0;
        c = getc(reg);
        do{
            buffer[j] = c;
            j++;
            c = getc(reg);
        }while (c!=DELIM_CHR);
        buffer[j] = '\0';
        strcpy(listaNomes[i], buffer);
        
//        printf("tamanho do buffer: %d\n", strlen(buffer));
//        for(j=0; j<strlen(listaNomes[i]); j++){
//            printf("%c", listaNomes[i][j]); 
//        }
//        printf("\n");
    }
        
//    for (i=0; i<tamTotal; i++){
//        printf("tamanho da string: %d\n", strlen(listaNomes[0]));
//        for (j=0; j<strlen(listaNomes[0]); j++){
//            printf("%c", listaNomes[0][j]);
//        }
//        printf("\n");
//    }
    
    fclose(reg);    
}
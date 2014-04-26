#include "fileIO.h"


void criaMatPrim(int **mat,int tamTotal){
    char tam[1], tam1[1], tam2[1], cod[6], cod1[1], string[10], carac, offset;
    int i, j, tamReg, codReg, tamOffset, proxOffset;
    FILE *reg, *regOffset;
    
    reg = fopen("reg.txt", "r");
    regOffset = fopen("regOffset.txt", "r"); 
    
    for (i=0; i<tamTotal; i++){
        carac = getc(regOffset);
        j=0;
        do{
            string[j] = carac;
            carac = getc(regOffset);
            j++;
        } while(carac != DELIM_CHR);
        tamOffset = atoi(string);
        mat[i][1] = tamOffset;
        
        fseek(reg, tamOffset+2, 0);   //sem "+i" nao funciona
        for (j=0; j<6; j++){
                cod[j] = getc(reg);
        }
        codReg = atoi(cod);
        mat[i][0] = codReg;
    }
//    //imprime codigo+offset
//    for (i=0; i<tamTotal; i++){
//        printf("%d  => %d | %d\n", i, mat[i][0], mat[i][1]);
//    }
    fclose(reg);
    fclose(regOffset);
}

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
    char c;
    
    reg = fopen("reg.txt", "r");
    
    for (i=0; i<tamTotal; i++){
        fseek(reg, indexPrim[i][1]+9, 0);
        j=0;
        c = getc(reg);
        printf("%d => %d => ",indexPrim[i][1], i);
        do{
            printf("%c", c);
            listaNomes[i][j] = c;
            j++;
            c = getc(reg);
        }while (c != DELIM_CHR);
        listaNomes[i][j] = '\0';
        printf("\n");
    }
    
//    for (i=0; i<tamTotal; i++){
//        tam = (strlen(listaNomes[i]));
//        for (j=0; i<tam; j++){
//            printf("%c", listaNomes[i][j]);
//        }
//        printf("\n");
//    }
    fclose(reg);
    
}
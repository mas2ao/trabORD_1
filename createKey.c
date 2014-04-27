#include <string.h>

#include "fileIO.h"
#include "struct.h"

void criaChavePrimCod(liPrimCod **primCod,int tamTotal){     //chave primaria
    char c, offset[TAM_OFFSET], cod[TAM_COD];
    int i, j, codReg, tamOffset;
    FILE *reg, *regOffset;
    
    reg = fopen("reg.txt", "r");
    regOffset = fopen("regOffset.txt", "r"); 
    
    for (i=0; i<tamTotal; i++){
        c = getc(regOffset);
        j=0;
        do{
            offset[j] = c;
            j++;
            c = getc(regOffset);
        }while (c != DELIM_CHR);
        offset[j] = '\0';
        tamOffset = atoi(offset);
        primCod[i]->cp.offset = tamOffset;
        
        fseek(reg, tamOffset+2, 0);
        for (j=0; j<6; j++){
            c = getc(reg);
            cod[j] = c;
        }
        codReg = atoi(cod);
        primCod[i]->cp.codigo = codReg;
        
    }
    
//    //imprime codigo+offset
//    for (i=0; i<tamTotal; i++){
//        printf("%d  => %d | %d\n", i, primCod[i]->codigo, primCod[i]->offset);
//    }
    fclose(reg);
    fclose(regOffset);
}

void criaChaveSecNome(liPrimCod **primCod, tsecNome **secNome, int tamTotal){
    FILE *reg;
    int i, j;
    char c, nome[MAX_REC_SIZE];
    
    reg = fopen("reg.txt", "r");
    for (i=0; i<tamTotal; i++){
        fseek(reg, primCod[i]->cp.offset+9, 0);
        c = getc(reg);
        j = 0;
        do{
            nome[j] = c;
            j++;
            c = getc(reg);
        }while (c != DELIM_CHR);
        nome[j] = '\0';
        strcpy(secNome[i]->string, nome);
        secNome[i]->codigo = primCod[i]->cp.codigo;
    }
    
//    //imprime nome+codigo
//    for (i=0; i<tamTotal; i++){
//        for (j=0; j<strlen(secNome[i]->string); j++){
//            printf("%c", secNome[i]->string[j]);
//        }
//        printf(" => %d\n", secNome[i]->codigo);
//    }
    
    fclose(reg);
}

void criaChaveSecCurso(liPrimCod **primCod, tsecCurso **secCurso, int tamTotal){
    FILE *reg;
    int i, j;
    char c, curso[MAX_CURSO_SIZE];
    for (i=0; i<tamTotal; i++){
        reg = fopen("reg.txt", "r");
        fseek(reg, primCod[i]->cp.offset+9, 0);
        do{
            c = getc(reg);
        }while (c != DELIM_CHR);

        c = getc(reg);
        j = 0;
        do{
            curso[j] = c;
            j++;
            c = getc(reg);
        }while (c != DELIM_CHR);
        curso[j] = '\0';
        strcpy(secCurso[i]->curso, curso);
        secCurso[i]->codigo = primCod[i]->cp.codigo;
    }
     
//    //imprime curso+codigo
//    for (i=0; i<tamTotal; i++){
//        for (j=0; j<strlen(secCurso[i]->curso); j++){
//            printf("%c", secCurso[i]->curso[j]);
//        }
//        printf(" => %d\n", secCurso[i]->codigo);
//    }
    
    fclose(reg);
}
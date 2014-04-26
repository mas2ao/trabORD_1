#include <stdio.h>
#include <stdlib.h>

#include "fileIO.h"
#include "importFile.h"

void importFile(char arquivo[]){
    FILE *original, *reg, *regOffset;
    int i, tamHeader, offset, tamReg;
    char carac, string[MAX_REC_SIZE];
    
    original = fopen(arquivo, "r");
    reg = fopen("reg.txt", "w");
    regOffset = fopen("regOffset.txt", "w");
    tamHeader = TAM_HEADER+1;
    carac = getc(original);
    fseek(reg, tamHeader, 0);
    putc(START_REC, reg);
    offset = tamHeader+1;
    fprintf(regOffset, "%d", offset);
    fputs(DELIM_STR, regOffset);
    do{
        i=0;
        fseek(reg, TAM_REG, 1);         //pula espaco para tamanho do registro  
        tamReg = 0;
        do{                             //cria string codigo
            string[i] = carac;
            i++;
            carac = getc(original);
        }while(carac != '\t');  
        string[i++] = DELIM_CHR;
        string[i++] = '\0';
        tamReg = tamReg + i-1;
        fputs(string, reg);
        
        i=0;
        carac = getc(original);
        do{                             //cria string nome
            string[i] = carac;
            i++;
            carac = getc(original);
        }while(carac != '\t');  
        string[i++] = DELIM_CHR;
        string[i++] = '\0';
        tamReg = tamReg + i-1;
        fputs(string, reg);
        
        i=0;
        carac = getc(original);
        do{                             //cria string curso
            string[i] = carac;
            i++;
            carac = getc(original);
        }while(carac != '\t');  
        string[i++] = DELIM_CHR;
        string[i++] = '\0';
        tamReg = tamReg + i-1;
        fputs(string, reg);
        
        i=0;
        carac = getc(original);
        do{                             //cria string nota
            string[i] = carac;
            i++;
            carac = getc(original);
        }while(carac != '\n');  
        string[i-1] = DELIM_CHR;
        string[i++] = '\0';
        tamReg = tamReg + i-1;
        fputs(string, reg);
                                        
        fseek(reg, -(tamReg+TAM_REG), 1);       //volta para o espaco alocado
        fprintf(reg, "%d", tamReg);             //para o tamanho do registro
        fseek(reg, tamReg, 1);                  //volta para posicao
        
        tamReg = tamReg+2;                      //calcula e escreve o offset do 
        offset = offset + tamReg;               //do registro no arquivo regOffset.txt
        fprintf(regOffset, "%d", offset);
        fputs(DELIM_STR, regOffset);
        
        carac = getc(original);
    }while(carac != EOF);
    fclose(original);
    fclose(reg);
    fclose(regOffset);
}

/* 
 * File:   main.c
 * Author: shaolin
 *
 * Created on April 24, 2014, 10:44 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "fileIO.h"
#include "importFile.h"
#include "algOrd.h"
#include "createIndex.h"
#include "createMatrix.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    int tamTotal, i;
    tamTotal = QUANT_INI;
    
    int **indexPrim = (int**) malloc(sizeof(int)*tamTotal);     //matriz que de indice primario (codigo x offset)
    for (i=0; i<tamTotal; i++){
        indexPrim[i] = (int*) malloc(sizeof(int)*2);            //precisa ser 2??
    }
    
    char **listaNomes = (char**) malloc(sizeof(char)*tamTotal+1);
    for (i=0; i<tamTotal; i++){
        listaNomes[i] = (char*) malloc(sizeof(char)*MAX_REC_SIZE);
    }
    
    char **indexSecNome = (char**) malloc(sizeof(char)*tamTotal);     //matriz que de indice secundario por nome (nome x RRN)
    for (i=0; i<tamTotal; i++){
        indexSecNome[i] = (char*) malloc(sizeof(char)*2);
    }
    
    int **chavePrimNome = (int**) malloc(sizeof(int)*tamTotal);     //matriz que de chave primaria para nome (nome x prox)
    for (i=0; i<tamTotal; i++){
        chavePrimNome[i] = (int*) malloc(sizeof(int)*2);
    }
    
    int **indexSecCurso = (int**) malloc(sizeof(int)*tamTotal);     //matriz que de indice secundario por curso (curso x RRN)
    for (i=0; i<tamTotal; i++){
        indexSecCurso[i] = (int*) malloc(sizeof(int)*2);
    }
    
    int **chavePrimCurso = (int**) malloc(sizeof(int)*tamTotal);     //matriz que de indice secundario por curso (curso x prox)
    for (i=0; i<tamTotal; i++){
        chavePrimCurso[i] = (int*) malloc(sizeof(int)*2);
    }
    
    importFile("dados.txt");
    
    criaMatPrim(indexPrim, tamTotal);
    
//    for (i=0; i<tamTotal; i++){       //imprime sem ordenadar
//        printf("%d  => %d | %d\n", i, indexPrim[i][0], indexPrim[i][1]);
//    }
//    printf("\n--------------------------------------\n");
    insertionSort(indexPrim, tamTotal);
    criaIndicePrimario(indexPrim, tamTotal);
    criaListaNomes(indexPrim, listaNomes, tamTotal);
//    criaMatSecAluno(indexSecNome, tamTotal);
    
//    for (i=0; i<tamTotal; i++){       //imprime apos ordenado
//        printf("%d  => %d | %d\n", i, indexPrim[i][0], indexPrim[i][1]);
//    }
    
//    FILE *teste;
//    char dado;
    
//    //verifica calculo offset
//    teste = fopen("reg.txt", "r");
//    fseek(teste, 153, 0);
//    dado = getc(teste);
//    printf("%c", dado);
//    dado = getc(teste);
//    printf("%c", dado);
//    dado = getc(teste);
//    printf("%c", dado);
//    dado = getc(teste);
//    printf("%c", dado);
    
    
    return (EXIT_SUCCESS);
}


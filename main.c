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
#include "struct.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    int tamTotal, i;
    tamTotal = QUANT_INI;
    
    liPrimCod *primCod[tamTotal];
    for (i=0; i<tamTotal; i++){
        primCod[i] = (liPrimCod*) malloc(sizeof(liPrimCod));
    }
    
    tsecNome *secNome[tamTotal];
    for (i=0; i<tamTotal; i++){
        secNome[i] = (tsecNome*) malloc(sizeof(tsecNome));
    }
    
    tsecCurso *secCurso[tamTotal];
    for (i=0; i<tamTotal; i++){
        secCurso[i] = (tsecCurso*) malloc(sizeof(tsecCurso));
    }
    
//    char *listaNomes[tamTotal];
//    for (i=0; i<tamTotal; i++){
//        listaNomes[i] = (char*) malloc(sizeof(char)*MAX_REC_SIZE);
//    }
    
    tliNome *liNome[tamTotal];
    for (i=0; i<tamTotal; i++){
        liNome[i] = (tliNome*) malloc(sizeof(tliNome));
    }
    
//    int *chaveSecNome[tamTotal];
//    for (i=0; i<tamTotal; i++){
//        chaveSecNome[i] = (int*) malloc(sizeof(int));
//    }
    
    importFile("dados.txt");                    //importa dados - ok
    
    criaChavePrimCod(primCod, tamTotal);         //cria chave primaria(CODIGO) - ok
    criaChaveSecNome(primCod, secNome, tamTotal);             //cria chave secundaria(NOTA) - ok
    criaChaveSecCurso(primCod, secCurso, tamTotal);           //cria chave secundaria(CURSO) - ok
    
    
    
//    for (i=0; i<tamTotal; i++){       //imprime sem ordenadar
//        printf("%d  => %d | %d\n", i, indexPrim[i][0], indexPrim[i][1]);
//    }
//    printf("\n--------------------------------------\n");
    
    insertionSort(primCod, tamTotal);                 //ordena chave primaria(codigo) - ok
    criaIndicePrimario(primCod, tamTotal);            //cria arquivo indice primario(ARQUIVO) - ok
    insertionSortNome(secNome, tamTotal);             //ordena chave secundaria(nome) - ok
    insertionSortCurso(secCurso, tamTotal);             //ordena chave secundaria(curso) - ok
   
    criaIndiceSecNome(liNome, secNome, tamTotal);
    
//    criaListaNomes(indexPrim, listaNomes, tamTotal);
//    insertionSortString(listaNomes, tamTotal);
//    criaIndiceSecAluno(chavePrim, listaNomes, chaveSecNome, tamTotal);
    

    
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


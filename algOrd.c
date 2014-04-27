#include <stdlib.h>

#include "fileIO.h"
#include "struct.h"

void merge(int **vet, int tam){
    int meio, i, j, k;
    
    int **tmp = (int**) malloc(sizeof(int)*tam);
    for (i=0; i<tam; i++){
        tmp[i] = (int*) malloc(sizeof(int)*2);
    }
    if (tmp == NULL){
        exit(1);
    }
    meio = tam/2;
    
    i = 0;
    j = meio;
    k = 0;
    while ((i<meio) && (j<tam)){
        if (vet[i][0] <= vet[j][0]){
            tmp[k][0] = vet[i++][0];
            tmp[k][1] = vet[i++][1];
        } else{
            tmp[k][0] = vet[j++][0];
            tmp[k][1] = vet[j++][1];
        }
        ++k;
    }
    
    if (i==meio){
        while (j<tam){
            tmp[k++][0] = vet[j++][0];
            tmp[k++][1] = vet[j++][1];
        }
    } else{
        while (i<meio){
            tmp[k++][0] = vet[i++][0];
            tmp[k++][1] = vet[i++][1];
        }
    }
    
    for (i=0; i<tam; i++){
        vet[i][0] = tmp[i][0];
        vet[i][1] = tmp[i][1];
    }
    free(tmp);
}

void mergeSort(int **vet, int tam){
    int meio;
    
    if (tam>1){
        meio = tam/2;
        mergeSort(vet, meio);
        mergeSort(vet+meio, tam-meio);
        merge(vet, tam);
    }
}

void selectionSort(int **vet, int tam){
    int i, j, menor, aux0, aux1;
    
    for (i=0; i<tam; i++){
        menor = i;
        for (j=i+1; j<tam; j++){
            if (vet[j][0] < vet[i][0]){
                menor = j;
            }
        }
        if (i!=menor){
            aux0 = vet[i][0];
            aux1 = vet[i][1];
            vet[i][0] = vet[menor][0];
            vet[i][1] = vet[menor][1];
            vet[menor][0] = aux0;
            vet[menor][1] = aux1;
        }
    }
}

void insertionSort(tprimCod **primCod, int tam){
    int i, j, cod, offset;
    
    for (i=0; i<tam; i++){
        cod = primCod[i]->codigo;
        offset = primCod[i]->offset;
        j = i-1;
        while ((j>=0) && (cod<primCod[j]->codigo)){
            primCod[j+1]->codigo = primCod[j]->codigo;
            primCod[j+1]->offset = primCod[j]->offset;
            j--;
        }
        primCod[j+1]->codigo = cod;
        primCod[j+1]->offset = offset;
    }
//    //ordenado(CODIGO)
//    for (i=0; i<tam; i++){
//        printf("%d => %d\n", primCod[i]->codigo, primCod[i]->offset);
//    }
    
}

void insertionSortNome(tsecNome **lista, int tam){
    int i, j, menor, cod;
    char aux[MAX_REC_SIZE];
    
    for (i=0; i<tam; i++){
        strcpy(aux, lista[i]->string);
        cod = lista[i]->codigo;
        j = i-1;
        while((j >= 0) && (strcmp(aux, lista[j]->string)<0)){
            strcpy(lista[j+1]->string, lista[j]->string);
            lista[j+1]->codigo = lista[j]->codigo;
            j--;
        }
        strcpy(lista[j+1]->string, aux);
        lista[j+1]->codigo = cod;
    }
//    //ordenado(NOME)
//    for (i=0; i<tam; i++){
//        for (j=0; j<strlen(lista[i]->string); j++){
//            printf("%c", lista[i]->string[j]);
//        }
//        printf(" => %d\n", lista[i]->codigo);
//    }
}

void insertionSortCurso(tsecCurso **lista, int tam){
    int i, j, menor, cod;
    char aux[MAX_CURSO_SIZE];
    
    for (i=0; i<tam; i++){
        strcpy(aux, lista[i]->curso);
        cod = lista[i]->codigo;
        j = i-1;
        while((j >= 0) && (strcmp(aux, lista[j]->curso)<0)){
            strcpy(lista[j+1]->curso, lista[j]->curso);
            lista[j+1]->codigo = lista[j]->codigo;
            j--;
        }
        strcpy(lista[j+1]->curso, aux);
        lista[j+1]->codigo = cod;
    }
//    //ordenado(CURSO)
//    for (i=0; i<tam; i++){
//        for (j=0; j<strlen(lista[i]->curso); j++){
//            printf("%c", lista[i]->curso[j]);
//        }
//        printf(" => %d\n", lista[i]->codigo);
//    }
}

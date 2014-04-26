#include <stdlib.h>

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

void insertionSort(int **mat, int tam){
    int i, j, atual, atual2;
    for (i=0; i<tam; i++){
        atual = mat[i][0];
        atual2 = mat[i][1];
        j = i-1;
        while ((j>=0) && (atual<mat[j][0])){
            mat[j+1][0] = mat[j][0];
            mat[j+1][1] = mat[j][1];
            j--;
        }
        mat[j+1][0] = atual;
        mat[j+1][1] = atual2;
    }
}

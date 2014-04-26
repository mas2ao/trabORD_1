/* 
 * File:   algOrd.h
 * Author: shaolin
 *
 * Created on April 26, 2014, 11:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileIO.h"

#ifndef ALGORD_H
#define	ALGORD_H

#ifdef	__cplusplus
extern "C" {
#endif

void merge(int **vet, int tam);    
    
void mergeSort(int **vet, int tam);    
    
void selectionSort(int **vet, int tam);    
    
void insertionSort(int **mat, int tam);



#ifdef	__cplusplus
}
#endif

#endif	/* ALGORD_H */


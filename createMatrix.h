/* 
 * File:   createMatrix.h
 * Author: shaolin
 *
 * Created on April 26, 2014, 12:01 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileIO.h"

#ifndef CREATEMATRIX_H
#define	CREATEMATRIX_H

#ifdef	__cplusplus
extern "C" {
#endif

void criaMatPrim(int **mat,int tamTotal);    
    
void criaListaNomes( int **indexPrim, char **listaNomes, int tamTotal);


#ifdef	__cplusplus
}
#endif

#endif	/* CREATEMATRIX_H */


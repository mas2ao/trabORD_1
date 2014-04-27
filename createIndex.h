/* 
 * File:   createIndex.h
 * Author: shaolin
 *
 * Created on April 26, 2014, 12:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileIO.h"
#include "struct.h"

#ifndef CREATEINDEX_H
#define	CREATEINDEX_H

#ifdef	__cplusplus
extern "C" {
#endif

void criaIndicePrimario(liPrimCod **indexPrim, int tamTotal);

#ifdef	__cplusplus
}
#endif

#endif	/* CREATEINDEX_H */


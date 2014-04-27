/* 
 * File:   struct.h
 * Author: shaolin
 *
 * Created on April 27, 2014, 12:54 AM
 */
#include "fileIO.h"


#ifndef STRUCT_H
#define	STRUCT_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct{                         //struct para chave primaria(CODIGO)
    int codigo;
    int offset;
}tprimCod;   

typedef struct{
    tprimCod cp;
    tprimCod *prox;
}liPrimCod;

typedef struct{                         //struct para chave secundaria(NOME)
    char string[MAX_REC_SIZE];
    int codigo;
}tsecNome;

typedef struct{                         //struct para lista invertida(NOME)
    char string[MAX_REC_SIZE];
    liPrimCod *rrn;
}tliNome;

typedef struct{                         //struct para chave secundaria(CURSO)
    int codigo;
    char curso[MAX_CURSO_SIZE];
}tsecCurso;

#ifdef	__cplusplus
}
#endif

#endif	/* STRUCT_H */


/* 
 * File:   createKey.h
 * Author: shaolin
 *
 * Created on April 27, 2014, 4:07 AM
 */

#include "struct.h"
#include "fileIO.h"

#ifndef CREATEKEY_H
#define	CREATEKEY_H

#ifdef	__cplusplus
extern "C" {
#endif

void criaChavePrimCod(liPrimCod **primCod,int tamTotal);

void criaChaveSecNome(liPrimCod **indexPrim, tsecNome **secNome, int tamTotal);

void criaChaveSecCurso(liPrimCod **indexPrim, tsecCurso **secCurso, int tamTotal);


#ifdef	__cplusplus
}
#endif

#endif	/* CREATEKEY_H */


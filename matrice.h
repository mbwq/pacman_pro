/*le fichier matrice.h*/
#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct matrice_ {
  int lig;
  int col;
  char ** elt;
  } matrice;

matrice * matrice_create(int n, int m);

void matrice_free(matrice * M);

void matrice_null(matrice * M);

void matrice_set(matrice * M, int i, int j, char x);

void matrice_print (matrice * M);

matrice * matrice_file(FILE * fp);

#endif // MATRICE_H_INCLUDED
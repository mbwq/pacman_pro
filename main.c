#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

int matrice_test();

int main() {
    matrice_test();
    return 0;
}

int matrice_test(){

FILE *fp = fopen("carte.txt", "r");
if(fp == NULL) {
    printf("Erreur fichier\n");
    return 1;
}
/*
matrice * M = matrice_create(3,3);
matrice_null(M);
matrice_print(M);
matrice_set(M, 1, 2, '<');
matrice_print(M);
*/

matrice *M2 = matrice_file(fp);
matrice_print(M2);


//matrice_free(M);
matrice_free(M2);
fclose(fp);
return 0;
}
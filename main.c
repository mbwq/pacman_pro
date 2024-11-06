#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

int matrice_test();

int main() {
    matrice_test();
    return 0;
}

int matrice_test(){

FILE *fp = fopen("carte2.txt", "r");
if(fp == NULL) {
    printf("Erreur fichier\n");
    return 1;
}

matrice *M2 = matrice_file(fp);
matrice_print(M2);


matrice_free(M2);
fclose(fp);
return 0;
}
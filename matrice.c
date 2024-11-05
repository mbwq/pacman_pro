/*le fichier matrice.c*/
#include "matrice.h"

matrice* matrice_create(int n, int m){
  int i;
  matrice* M = (matrice *) malloc(sizeof(matrice));
  M->lig = n;
  M->col = m;
  M->elt = (char **) malloc(n*sizeof(char *));
  for(i=0; i<n; i++)
    M->elt[i] = (char *) malloc(m*sizeof(char));

  return M;
}

void matrice_free(matrice* M){
  int i;
  for(i=0; i < M->lig; i++)
    free(M->elt[i]);
  free(M->elt);
  free(M);
}

void matrice_null(matrice* M){
  int i, j;
  for(i=0; i < M->lig ;i++)
    for(j=0; j < M->col; j++)
      M->elt[i][j]=' ';
}

void matrice_print(matrice * M){
  int i, j;
  for(i=0; i < M->lig ;i++){
    for(j=0; j < M->col; j++){
      printf("%d %d %c - ", i,j,M->elt[i][j]);
    }
  }
  printf("\n");
}

void matrice_set(matrice* M, int i, int j, char x){
  M->elt[i][j] = x;
}

matrice* matrice_file(FILE * fp){
  int i, j, n, m;
  fscanf(fp, "%d", &n);
  fscanf(fp, "%d", &m);
  matrice * M = matrice_create(n,m);
  for(i=0; i < M->lig ;i++){
    for(j=0; j < M->col; j++){
      fscanf(fp, "%c", (M->elt[i])+j);
       //printf("char : %d %d %s fin\n", i,j, (M->elt[i])+j);
    }
  }
  return M;
}

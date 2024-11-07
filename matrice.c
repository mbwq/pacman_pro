/*le fichier matrice.c*/
#include "matrice.h"
#include "player.h"

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
  player player;

  player.x = 0;
  player.y = 2;
  player.value = '<';
  char buffer[10]; //tampon pour éviter les téléportations
  char direction;

  do{
  for(i=0; i < M->lig ;i++){
    for(j=0; j < M->col; j++){
      if(i == player.y && j == player.x){
          printf("%c", player.value);
        } else {
          printf("%c", M->elt[i][j]);
        }
      //printf("%c",M->elt[i][j]);
    }
    printf("\n");
  }
  // lecture de direction
  printf("entrez une direction (o, k, m, l) ou q pour quitter: ");
  fgets(buffer, sizeof(buffer), stdin);
  direction = buffer[0];

  //appelle de la fonction movePlayer
  movePlayer(&player, direction);

  } while(direction != 'q');
}

void matrice_set(matrice* M, int i, int j, char x){
  M->elt[i][j] = x;
}

/*matrice* matrice_file(FILE * fp){
  int i, j, n, m;
  int c = fgetc(fp);
  fscanf(fp, "%d", &n);
  fscanf(fp, "%d", &m);
  matrice * M = matrice_create(n, m);
  for(i=0; i < M->lig ;i++){
    for(j=0; j < M->col; j++){
      while(c == '\n'){ // condition pour ignore retour à la ligne
        c = fgetc(fp);
      }
      //M->elt[i][j] = c;
      fscanf(fp, "%c", (M->elt[i])+j);
       //printf("char : %d %d %s fin\n", i,j, (M->elt[i])+j);
    }
  }
  return M;
}*/

matrice* matrice_file(FILE * fp){
    int i, j, n, m;
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);
    matrice * M = matrice_create(n, m);

    char ch;
    for(i = 0; i < M->lig; i++){
      ch = fgetc(fp);
        for(j = 0; j < M->col; j++){
            do {
                ch = fgetc(fp); // Lire chaque caractère
            } while(ch == '\n'); // Ignorer les retours à la ligne

            M->elt[i][j] = ch; // Stocker le caractère dans la matrice
        }
    }

    return M;
}



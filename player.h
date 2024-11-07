#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct player_ {
    int x, y;
    char value;
    //int lig;
    //int col;
} player;

void movePlayer(player * player, char direction);

#endif // PLAYER_H_INCLUDED

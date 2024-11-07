#include "player.h"

// gère le deplacement du joueur(pacman)
void movePlayer(player * player, char direction) {
    switch (direction) {
        case 'o': // Haut
            player->y--;
            break;
        case 'k': // Gauche
            player->x--;
            break;
        case 'm': // Droite
            player->x++;
            break;
        case 'l': // Bas
            player->y++;
            break;
        default:
            break;
    }
}
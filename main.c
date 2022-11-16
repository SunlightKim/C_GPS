// PSEUDO GPS

/* PSEUDO CODE
 * Soit départ au point A pour arrivée au point E
 * -> S'il existe un chemin direct entre les 2 pts -> ajouter chemin à liste de chemins -> passer au pt suivant
 * et ainsi de suite
 * -> on comptera pas les chemins identiques de sens inverses (ex: A-B = B-A)
 * ALGO POSSIBLE : ALGO DFS
*/

#include <stdio.h>

/* Structure POINT */
typedef struct Point {
    char letter;                // Définie par une lettre (A, B, C, D ou E)
    struct Point *next;         // par le point suivant
    struct Point *previous;     // par le point précédent
} point;

/* Structure CHEMIN */
typedef struct Path {
    point start;                // Définie par un point de départ
    point end;                  // et un point d'arrivée
    struct Path *next;          // Un chemin est suivie d'un autre chemin (next)
    struct Path *previous;      // Un chemin est précédé d'un autre chemin (previous)
} path;

/* TODO: Créer une liste de chemins
 * TODO: Créer tous les points
 * TODO: Créer tous les chemins
 * TODO: Créer les fonctions intermédiaires
 * TODO: Créer la fonction primaire
*/
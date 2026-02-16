
#ifndef MATRICE_FLOAT_H
#define MATRICE_FLOAT_H
#include <stdio.h>


typedef struct matrice_t{
    int l; // les lignes
    int c; // colonne
    int **m; // chaque ligne sera un pointeur de pointeur,
             //on alloue juste un tableau de l lignes, a l interieur il yaura aussi c colonnes d ou m est pointeur de pointeur 
}matrice_t;


matrice_t * allouer_matrice(int l,int c);
void saisir_coeffs_matrice(matrice_t *mat);
void affiche_matrice(matrice_t *mat);
matrice_t * produit_matrices(matrice_t *A, matrice_t *B);
void desallouer_matrice(matrice_t **mat);





#endif
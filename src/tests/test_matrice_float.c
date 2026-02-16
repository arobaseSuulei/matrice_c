#include <stdio.h>
#include <stdlib.h>
#include "../include/matrice_float.h"




int test_matrice(){

     int l=2,c=2;
     
     matrice_t *A=allouer_matrice(l,c);
     matrice_t *B=allouer_matrice(c,l);

     saisir_coeffs_matrice(A);
     saisir_coeffs_matrice(B);

     affiche_matrice(A);
     affiche_matrice(B);

     matrice_t *C = produit_matrices(A,B);

     affiche_matrice(C);

     desallouer_matrice(&A);
     desallouer_matrice(&B);
     desallouer_matrice(&C);

     



    

    printf("hello");

   

    //matrice_t *mat=allouer_matrice(l,c);
    //saisir_coeffs_matrice(mat);
    //affiche_matrice(mat);
    
    
    

    

    return 0;

    
}



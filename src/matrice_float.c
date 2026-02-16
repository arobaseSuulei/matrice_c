#include <stdio.h>
#include <stdlib.h>
#include "include/matrice_float.h"

matrice_t * allouer_matrice(int l,int c){

    matrice_t *mat;
    mat = malloc(sizeof(matrice_t));


    mat->l=l;
    mat->c=c;
    
    mat->m=malloc(l*sizeof(int*)); //on alloue juste un tableau de l lignes, a l interieur il yaura aussi c colonnes d ou m est pointeur de pointeur 

   
    if(mat->m==NULL){
        printf("ECHEC D ALLOCATION ");
    }

    for(int i = 0; i < l; i++){
        mat->m[i]=(int*)malloc(c*sizeof(int)); // pour chaque ligne on alloue un tableau c, c est les colonnes


        if(mat->m[i]==NULL){
            printf("ECHEC D ALLOCATION ");

    }

    }

    return mat;
}



// ---------assigner des valeurs-----------------------

void saisir_coeffs_matrice(matrice_t *mat){ 

    // on passe un pointeur de type matrice en params

    for(int i=0;i<mat->l;i++){
        for(int j=0;j<mat->c;j++){
        
            printf("Elements %d - %d",i,j);
            scanf("%d",&mat->m[i][j]);
    }

    }

        
    }

//--------afficher la matrice----------------------------

void affiche_matrice(matrice_t *mat){

    printf("----- MATRICE -----");

    for(int i=0;i<mat->l;i++){
        for(int j=0;j<mat->c;j++){
        
            printf("%d  ",mat->m[i][j]); // m c est ou tu as stocké ta valeur, il pointe sur ta valeur du coup
    }
    printf("\n");
    }
}

//--------le produit de ma matrice----------------------------


matrice_t * produit_matrices(matrice_t *A, matrice_t *B){
    
    if(A->c != B->l){
        printf("impossible");
        return NULL;
    }
    
  




    matrice_t *C = allouer_matrice(A->l, B->c);
    
    
    for(int i=0; i<A->l; i++){         
        for(int j =0; j<B->c; j++){       
            
            C->m[i][j] = 0;
            
            for(int k = 0; k < A->c; k++){  
                C->m[i][j] += A->m[i][k] * B->m[k][j];
            }
        }
    }

    
    
    return C;
}


// ----------- desallouer la matrice-----------------

void desallouer_matrice(matrice_t** mat){

    for(int i=0;i<(*mat)->l;i++){
        free((*mat)->m[i]);
    }

    free( (*mat)->m );
    free(*mat);

}
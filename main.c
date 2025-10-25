#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "function.h"

int main(){

    srand(time(NULL)); 

    char**tab_arene=create_grille();    

    positionperso *personnage=malloc(sizeof(*personnage));
    positioncaisse *caisse=malloc(sizeof(*caisse));
    positiongoal *goal=malloc(sizeof(*goal));    

    position_debut_jeu(tab_arene,personnage, caisse, goal);

    affichage_grille(tab_arene,personnage, caisse, goal);

    char move;

    while (condi_victoire(caisse, goal)!=1 && condi_defaite(caisse,goal)!=1){

        
        scanf("%c",&move);

        move_perso(tab_arene,personnage,move);

        if((personnage->x==caisse->x) && (personnage->y==caisse->y)){

            move_caisse(tab_arene,caisse, move);   

        }        

        condi_victoire(caisse, goal);
        condi_defaite(caisse, goal);

        affichage_grille(tab_arene,personnage, caisse, goal);
        

    }   


    int i=0;

    while(i<8){

    free(tab_arene[i]);
    i++;
    }

    free(tab_arene);

    return 0;

}
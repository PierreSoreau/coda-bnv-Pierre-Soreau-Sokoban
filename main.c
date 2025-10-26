#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "function.h"

int main(){

    srand(time(NULL)); 

    //On crée l'arène de 10x10 sans les logos
    char**tab_arene=create_grille();    

    //On alloue de la mémoire pour les structures représentant les logos
    positionperso *personnage=malloc(sizeof(*personnage));
    positioncaisse *caisse=malloc(sizeof(*caisse));
    positiongoal *goal=malloc(sizeof(*goal)); 

    //On positionne les logos dans la grille de manière aléatoire pour débuter le jeu
    position_debut_jeu(tab_arene,personnage, caisse, goal);

    //On affiche la grille avec les logos sur le terminal
    affichage_grille(tab_arene,personnage, caisse, goal);

    char move;//variable de déplacement du joueur


    //Tant qu'il n'y a ni de victoire ni de défaite:
    //1)On demande à l'utilisateur de rentrer un deplacement du joueur
    //2)Si le logo du joueur est collé à la caisse et que l'utilisateur demande de se déplacer vers la caisse alors dans ce cas la caisse est poussé par le joueur dans le sens que l'utilisateur a demandé
    //3)A chaque déplacement on vérifie s'il y a victoire ou défaite
    //4)On affiche sur le terminal la nouvelle arène avec le joueur ou le joueur et la caisse qui sont déplacés.
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

    FILE *fp;

    //On enregistre le plateau de jeu final dans le fichier end.txt 
    arenefinale_fichier(fp,tab_arene);

    int i=0;
    //Le jeu est terminé on libère la mémoire allouée pour l'arène au global, les lignes de l'arène et les structures des logos.
    
    free(personnage);
    free(caisse);
    free(goal);

    while(i<8){

    free(tab_arene[i]);
    i++;
    }

    free(tab_arene);

    return 0;

}
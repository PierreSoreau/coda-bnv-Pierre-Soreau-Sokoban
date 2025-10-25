#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"




char** create_grille(){

    char **tab_arene=malloc(9*sizeof(char*));
    

    int i=0;

    while (i<8){
        tab_arene[i]=malloc(9*sizeof(char));
        tab_arene[i][8]='\0';
        strcpy(tab_arene[i], "        ");        
        i++;

    }
    

    tab_arene[8]=NULL;

    return tab_arene;

}

void affichage_grille(char**tab_arene,positionperso *personnage, positioncaisse *caisse, positiongoal *goal){

    
    printf("\nPersonnage: %d %d\nCaisse: %d %d\nBut: %d %d\n", personnage->x, personnage->y, caisse->x, caisse->y, goal->x, goal->y);

    int i=0;

    printf("##########\n");    

    while (i<8){
    printf("#%s#\n",tab_arene[i]);
    i=i+1;
    }

    printf("##########\n\n");

    printf("Choisissez un mouvement: haut(t) bas(b) gauche(l) droite(r)\n\n");
}

char** position_debut_jeu(char**tab_arene,positionperso *personnage, positioncaisse *caisse, positiongoal *goal){    


    while( ((personnage->y==caisse->y) && (personnage->x==caisse->x)) || ((goal->y==caisse->y) && (goal->x==caisse->x)) || ((goal->y==personnage->y) && (goal->x==personnage->x))){

    
    personnage->y=rand() % 7;
    personnage->x=rand() % 7;
    caisse->y=(rand() % 6) + 1;
    caisse->x=(rand() % 6) + 1;
    goal->y=rand() % 7;
    goal->x=rand() % 7;


    }
    

    tab_arene[caisse->x][caisse->y]=CAISSE;
    tab_arene[goal->x][goal->y]=DOTGOAL;
    tab_arene[personnage->x][personnage->y]=PERSO;


    

    return tab_arene;


}

char** move_perso(char**tab_arene,positionperso *personnage,char move){
    
    tab_arene[(personnage->x)][personnage->y]=' ';

    if(move=='t'){
        personnage->x=(personnage->x)-1;  
        

    }

    else if(move=='b'){

        personnage->x=(personnage->x)+1;        

    }

    else if(move=='l'){
        personnage->y=(personnage->y)-1;       

    }

    else if(move=='r'){
        personnage->y=(personnage->y)+1;       

    }

    tab_arene[(personnage->x)][personnage->y]=PERSO;

    return tab_arene;

}

char** move_caisse(char**tab_arene,positioncaisse *caisse,char move){   
    

    if(move=='t'){
        caisse->x=(caisse->x)-1; 
        
    }

    else if(move=='b'){

        caisse->x=(caisse->x)+1;        

    }

    else if(move=='l'){
        caisse->y=(caisse->y)-1;

    }

    else if(move=='r'){
        caisse->y=(caisse->y)+1;       

    }

    tab_arene[(caisse->x)][caisse->y]=CAISSE;

    return tab_arene;

}


int condi_defaite(positioncaisse *caisse, positiongoal *goal){


    //le but est dans un angle
    if(((goal->x==0) && (goal->y==0)) || ((goal->x==0) && (goal->y==7)) || ((goal->x==7) && (goal->y==0)) || ((goal->x==7) && (goal->y==7))){

        
        //bordure opposée

        if(((caisse->x==0) && (goal->x==7)) || ((caisse->x==7) && (goal->x==0)) || ((caisse->y==7) && (goal->y==0)) || ((caisse->y==0) && (goal->y==7))){
            printf("Vous avez perdu\n!");
            return 1;
        }

    }

    //Si la caisse touche un mur et que ce mur n’est pas celui du but
    else if(caisse->x == 0 || caisse->x == 7 || caisse->y == 0 || caisse->y == 7) {
        if (!(caisse->x == goal->x && caisse->y == goal->y)) {
            printf("Vous avez perdu\n!\n");
            return 1;
        }
    }


    /*//bordure opposée

    else if(((caisse->x==0) && (goal->x==7)) || ((caisse->x==7) && (goal->x==0)) || ((caisse->y==7) && (goal->y==0)) || ((caisse->y==0) && (goal->y==7))){
        printf("Vous avez perdu\n!");
        return 1;
    }

    //bordures adjacentes

    else if((caisse->x==goal->y) || (goal->x==caisse->y) || ((caisse->x==7) && (goal->y==0)) || ((caisse->y==7) && (goal->x==0)) || ((caisse->x==0) && (goal->y==7)) || ((caisse->y==0) && (goal->x==7))){
        printf("Vous avez perdu\n!");
        return 1;
    }*/


    else{
        return 0;
    }
}

int condi_victoire(positioncaisse *caisse, positiongoal *goal){

    if( (caisse->x==goal->x) && (caisse->y==goal->y)){
        printf("Vous avez gagné\n!");
        return 1;
    }

    else{
        return 0;
    }
}


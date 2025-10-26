#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"



//Fonction de création de l'arene 10x10
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

//Fonction pour afficher l'arène 10x10
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

//Fonction qui permet d'afficher dans l'arène le joueur, la caisse et le point à l'ouverture du jeu
char** position_debut_jeu(char**tab_arene,positionperso *personnage, positioncaisse *caisse, positiongoal *goal){    


    while( ((personnage->y==caisse->y) && (personnage->x==caisse->x)) || ((goal->y==caisse->y) && (goal->x==caisse->x)) || ((goal->y==personnage->y) && (goal->x==personnage->x))){

    
    personnage->y=rand() % 7;
    personnage->x=rand() % 7;
    caisse->y=(rand() % 6) + 1;//la caisse ne peut pas s'afficher contre un mur au début du jeu
    caisse->x=(rand() % 6) + 1;
    goal->y=rand() % 7;
    goal->x=rand() % 7;


    }
    

    tab_arene[caisse->x][caisse->y]=CAISSE; 
    tab_arene[goal->x][goal->y]=DOTGOAL;
    tab_arene[personnage->x][personnage->y]=PERSO;


    

    return tab_arene;


}

//Fonction qui permet de déplacer le joueur (le logo 'o') en haut, en bas, à droite, à gauche en fonction de la lettre qu'on rentre dans le terminal.
//'t' le joueur déplace vers le haut
//'b' le joueur se déplace vers le bas
//'r' le joueur se déplace vers la droite
//'l' le joueur se déplace vers la gauche
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

//Fonction qui permet de déplacer la caisse (le logo 'X') en haut, en bas, à droite, à gauche en fonction de la lettre qu'on rentre dans le terminal.
//'t' la caisse déplace vers le haut
//'b' la caisse se déplace vers le bas
//'r' la caisse se déplace vers la droite
//'l' la caisse se déplace vers la gauche
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

//Fonction qui détaille les cas de figure de défaite du jeu et renvoie sur le terminal Vous avez perdu! en cas de défaite
int condi_defaite(positioncaisse *caisse, positiongoal *goal){     
        
    //La caisse est contre un mur opposé au mur sur lequel est le but
    if(((caisse->x==0 && goal->x==7) || (caisse->x==7 && goal->x==0) || (caisse->y==7 && goal->y==0) || (caisse->y==0 && goal->y==7))){
        printf("Vous avez perdu\n!");
        return 1;
    }

    

    //Le but est collé au mur du haut et pas dans un angle et la caisse est collée à un mur vertical.
    if (goal->x == 0 && (goal->y > 0 && goal->y < 7)) {        
        if (caisse->y == 0 || caisse->y == 7) {
            printf("Vous avez perdu !\n");
            return 1;
        }
    }

    //Le but est collé au mur du bas et pas dans un angle et la caisse est collée à un mur vertical.
    if (goal->x == 7 && (goal->y > 0 && goal->y < 7)) {
        if (caisse->y == 0 || caisse->y == 7) {
            printf("Vous avez perdu !\n");
            return 1;
        }
    }

    //Le but est collé à au mur gauche et pas dans un angle et la caisse est collée à un mur horizontal.
    if (goal->y == 0 && (goal->x > 0 && goal->x < 7)) {
        if (caisse->x == 0 || caisse->x == 7) {
            printf("Vous avez perdu ! La caisse est bloquée contre un mur adjacent au but (gauche).\n");
            return 1;
        }
    }

    //Le but est collé au mur de droite et pas dans un angle et la caisse est collée à un mur horizontal.
    if (goal->y == 7 && (goal->x > 0 && goal->x < 7)) {
        if (caisse->x == 0 || caisse->x == 7) {
            printf("Vous avez perdu ! La caisse est bloquée contre un mur adjacent au but (droite).\n");
            return 1;
        }
    }
    
    //La caisse est dans un coin qui n'est pas le coin du but
    if (((caisse->x ==0  && caisse->y ==0) || (caisse->x ==0  && caisse->y ==7) || (caisse->x ==7  && caisse->y ==0) || (caisse->x ==7  && caisse->y ==7)) && !(caisse->x == goal->x && caisse->y == goal->y)) {
        printf("Vous avez perdu !\n");
        return 1;
        
    }

    //La caisse est contre un mur et le but n'est pas contre un mur
    if((caisse->x ==0 || caisse->x ==7 || caisse->y ==0 || caisse->y ==7) && ((goal->x>0 && goal->x<7) && (goal->y>0 && goal->y<7))){
        printf("Vous avez perdu !\n");
        return 1;
    }
    
    else{
        return 0;
    }
}

//Fonction qui détaille le cas de figure de victoire du jeu et renvoie sur le terminal Vous avez gagné! en cas de victoire
int condi_victoire(positioncaisse *caisse, positiongoal *goal){

    if( (caisse->x==goal->x) && (caisse->y==goal->y)){
        printf("Vous avez gagné\n!");
        return 1;
    }

    else{
        return 0;
    }
}

//Fonction qui permet d'enregistrer l'état du plateau de jeu dans un fichier end.txt à chaque fin de partie. A chaque fin de partie le contenu de ce fichier est remplacé par le nouveau plateau de jeu de fin.
void arenefinale_fichier(FILE *fp, char**tab_arene){

fp = fopen("end.txt", "w+");

    if (fp == NULL)
    {
        printf("Le fichier end.txt n'a pas pu être ouvert\n");        
    }

    int j=0;    

    fprintf(fp,"##########\n");
    
    while(j<8){
        fprintf(fp, "#%s#\n", tab_arene[j]);
    	j++;
    }

    fprintf(fp,"##########\n");
    fclose(fp);

}



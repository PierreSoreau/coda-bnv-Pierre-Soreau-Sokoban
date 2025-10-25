#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#define CAISSE 'X'
#define PERSO 'o'
#define DOTGOAL '.'

struct s_perso {    
    int x;
    int y;
};

typedef struct s_perso positionperso;

struct s_caisse {    
    int x;
    int y;
};

typedef struct s_caisse positioncaisse;

struct s_goal {    
    int x;
    int y;
};

typedef struct s_goal positiongoal;

char** create_grille();
void affichage_grille(char**tab_arene,positionperso *personnage, positioncaisse *caisse, positiongoal *goal);
char** position_debut_jeu(char**tab_arene,positionperso *personnage, positioncaisse *caisse, positiongoal *goal);
char** move_perso(char**tab_arene,positionperso *personnage,char move);
char** move_caisse(char**tab_arene,positioncaisse *caisse,char move);
int condi_victoire(positioncaisse *caisse, positiongoal *goal);
int condi_defaite(positioncaisse *caisse, positiongoal *goal);



#endif
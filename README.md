# Sokoban

Sokoban est un jeu qui se joue sur un terminal.  
C'est un jeu dans lequel un personnage doit pousser une boite jusqu'à un emplacement précis. Le personnage est symbolisé par un rond "o" et la boîte par une croix "X".  
Si la boîte arrive au bon emplacement symbolisé par un point "." le joueur a gagné.  
Si la boite ne peut plus bouger (par exemple si elle est collée à un mur ou dans un coin) la partie est perdue.  
Le personnage peut pousser une caisse, mais jamais la tirer.

## Technologies utilisées

Langage C

## Installation et lancement du jeu
### 1. Construire l'image Docker

Placer le `Dockerfile` à la racine du dossier du projet (où se trouve le code C que vous avez enregistré).  
Puis dans un terminal, positionnez-vous dans le dossier en question puis lancez la commande :

docker build -t mon-jeu-c .

### 2. Lancer un container Docker

Ecrire la commande ci-dessous dans le terminal:

docker run -it --rm --name jeu-c-container mon-jeu-c

### 3. Lancer le jeu

Ecrire la commande ci-dessous dans le terminal:

./sokoban


## Fonctionnalités

![gif du jeu](photo/sokoban.gif)





















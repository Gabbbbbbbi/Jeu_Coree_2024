//
// Created by gabri on 14/10/2024.
//

#ifndef JEUTROPBIEN_MENU_H
#define JEUTROPBIEN_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#define zoom_y 100
#define zoom_x 200
#define deplacement 5
#define deplacement_grotte 4


typedef struct Joueur{
    char nom[20] ;
}t_joueur;

typedef struct{
    int x_map;
    int y_map;
    int X_mario;
    int Y_mario;
    int Perso;
}Coord;

typedef struct{
    int barriere;
    int interieur;
    int surf;
    int surfage;
    int fleur[12];
    int poisson[5];
    int sel;
    int poivre;
    int commencement;
    int dialogue;
    int cle1;
    int cle2;
    int cle3;
    int nature1;
    int nature2;
    int nature3;
}Modification;

typedef struct{
    int X_mario_int;
    int Y_mario_int;
    int numero;
    int sel;
    int poivre;
}Maison;

typedef struct{
    int x_map_grotte;
    int y_map_grotte;
    int X_mario_grotte;
    int Y_mario_grotte;
    int saut;
    int sol;
    int echelle;
}Grotte;

typedef struct{
    int x_map_fin;
    int y_map_fin;
    int X_mario_fin;
    int Y_mario_fin;
}Fin;

void zoom(BITMAP *map,BITMAP *dessus,BITMAP *affiche,Coord *coord,Modification *modif);
int collisionjoueur(int n,Modification *modif,BITMAP *collision,Coord *coord);
void verification_action(BITMAP *collision,Coord *coord,Modification *modif);
int changement(BITMAP *buffer,BITMAP *obstacle[4],Modification *modif);
void dialogue(Modification *modification);
int verification_fleur(Modification *modif);
int verification_poisson(Modification *modif);
void dialogue_demarrage(Modification *modif);
void dialogue_arbre(Modification *modif);
void dialogue_coffre(Modification *modif);

void lecture_joueur(Modification *modif,Coord *coord);
void enregistrement_joueur(Modification *modif,Coord *coord);

int ecran_acceuil(Modification *modif,Coord *coord);



// Dans la maison

int function_maison(int depart,Modification *modif);
void interieur(BITMAP *affiche,BITMAP *inside,Maison *maison);
int collisionjoueur_interieur(int n, BITMAP *collision, Maison *maison);
int verification_interieur(BITMAP *collision, Maison *maison);
void dialogue_int(Maison *maison);

//Dans la grotte

int jeu_grotte(Modification *modification);
void zoom_grotte(BITMAP *map,BITMAP *affiche,Grotte *grotte);
int collisionjoueur_grotte(int n, Grotte*grotte, BITMAP *collision, Modification *modif);
void dialogue_grotte();

int finition();
void verification_action_fin(BITMAP *collision,Fin *fin);
int collisionjoueur_fin(int n, BITMAP *collision, Fin *fin);
void zoom_fin(BITMAP *map,BITMAP *affiche,Fin *fin);
#endif //JEUTROPBIEN_MENU_H




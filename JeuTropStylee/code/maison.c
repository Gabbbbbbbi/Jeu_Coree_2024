//
// Created by gabri on 18/10/2024.
//
#include "menu.h"

int function_maison(int depart,Modification *modif){
    BITMAP *buffer;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    BITMAP *inside[5],*Normal[4],*Coursedroite[2],*Coursegauche[2],*Coursehaut[2],*Coursebas[2],*collision_int[2];
    inside[0]=load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/interieur.bmp",NULL);
    inside[1]=load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/interieur2.bmp",NULL);
    inside[2]=load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/interieur_cuisine.bmp",NULL);
    inside[3]=load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/interieur_cuisine2.bmp",NULL);
    Normal[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/normal_d.bmp",NULL);
    Normal[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/normal_q.bmp",NULL);
    Normal[2]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/normal_z.bmp",NULL);
    Normal[3]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/normal_s.bmp",NULL);
    Coursedroite[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_d_1.bmp",NULL);
    Coursedroite[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_d_2.bmp",NULL);
    Coursegauche[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_q_1.bmp",NULL);
    Coursegauche[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_q_2.bmp",NULL);
    Coursehaut[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_z_1.bmp",NULL);
    Coursehaut[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_z_2.bmp",NULL);
    Coursebas[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_s_1.bmp",NULL);
    Coursebas[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_s_2.bmp",NULL);
    collision_int[0] = load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/collision_interieur.bmp",NULL);
    collision_int[1] = load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/collision_interieur_cuisine.bmp",NULL);

    Maison* maison = malloc(sizeof (Maison));
    int current_frame = 0;
    int position=2;
    int vitesse=2;
    maison->X_mario_int = 616;
    maison->Y_mario_int = 640;
    maison->numero=modif->interieur;
    maison->sel=modif->sel;
    maison->poivre=modif->poivre;
    int etat = 0;

    if (depart==0){
        maison->X_mario_int = 370;
        maison->Y_mario_int = 170;
        position =3;
        modif->interieur=1;
    }
    if(modif->interieur==3 || modif->interieur==4){
        etat = 1;
    }


    while (!(key[KEY_ESC]) && !(key[KEY_S] && maison->Y_mario_int + 60 > 700 && maison->Y_mario_int + 60 < 720 && maison->X_mario_int > 578 && maison->X_mario_int - 45 < 615)) { // Boucle principale
        clear_bitmap(buffer);

        if (key[KEY_D]) {
            if (collisionjoueur_interieur(1,collision_int[etat],maison)==0) {
                maison->X_mario_int += vitesse;
                interieur(Coursedroite[current_frame],inside[modif->interieur-1],maison);
                current_frame = (current_frame + 1) % 2;
                position = 0;
                //key[KEY_D] = 0;
            }
        }
        if (key[KEY_A]) {
            if (collisionjoueur_interieur(2,collision_int[etat],maison)==0) {
                maison->X_mario_int -= vitesse;
                interieur(Coursegauche[current_frame],inside[modif->interieur-1],maison);
                current_frame = (current_frame + 1) % 2;
                position=1;
                //key[KEY_A] = 0;
            }
        }
        if (key[KEY_W]) {
            if (collisionjoueur_interieur(3,collision_int[etat],maison)==0) {
                maison->Y_mario_int -= vitesse;
                interieur(Coursehaut[current_frame],inside[modif->interieur-1],maison);
                current_frame = (current_frame + 1) % 2;
                position = 2;
                //key[KEY_W] = 0;
            }
        }
        if (key[KEY_S]) {
            if (collisionjoueur_interieur(4,collision_int[etat],maison)==0) {
                maison->Y_mario_int += vitesse;
                interieur(Coursebas[current_frame],inside[modif->interieur-1],maison);
                current_frame = (current_frame + 1) % 2;
                position = 3;
                //key[KEY_S] = 0;
            }
        }
        if (!key[KEY_D]&&!key[KEY_A]&&!key[KEY_W]&&!key[KEY_S]){
            interieur(Normal[position],inside[modif->interieur-1],maison);
        }
        if (key[KEY_E]) {
            verification_interieur(collision_int[etat],maison);
        }
    }
    modif->sel=maison->sel;
    modif->poivre=maison->poivre;



    free(maison);
    destroy_bitmap(inside[0]);
    destroy_bitmap(buffer);
    destroy_bitmap(Normal[0]);
    destroy_bitmap(Normal[1]);
    destroy_bitmap(Normal[2]);
    destroy_bitmap(Normal[3]);
    destroy_bitmap(Coursedroite[0]);
    destroy_bitmap(Coursedroite[1]);
    destroy_bitmap(Coursegauche[0]);
    destroy_bitmap(Coursegauche[1]);
    destroy_bitmap(Coursehaut[0]);
    destroy_bitmap(Coursehaut[1]);
    destroy_bitmap(Coursebas[0]);
    destroy_bitmap(Coursebas[1]);
    return 0;
}


void interieur(BITMAP *affiche,BITMAP *inside,Maison *maison){
    BITMAP *buffer,*png[2];
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    png[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/sel.bmp",NULL);
    png[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/poivre.bmp",NULL);
    //printf("Avant déplacement : X_mario_int = %d, Y_mario_int = %d\n", coord->X_mario_int, coord->Y_mario_int);

    blit(inside,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    if(maison->numero==3){
        masked_stretch_blit(png[0],buffer,0,0,png[0]->w,png[0]->h,400,150,45,60);
    }
    if(maison->numero==4){
        masked_stretch_blit(png[1],buffer,0,0,png[1]->w,png[1]->h,400,150,45,60);
    }
    masked_stretch_blit(affiche, buffer, 0, 0, affiche->w,
                        affiche->h, maison->X_mario_int, maison->Y_mario_int, 45, 60);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    destroy_bitmap(buffer);
    destroy_bitmap(png[0]);
    destroy_bitmap(png[1]);
}

int collisionjoueur_interieur(int n, BITMAP *collision, Maison *maison) {
    int red_color = makecol(189, 106, 98); // Couleur rouge

    for (int i = 0; i < 2; i++) {
        int couleur = 0;

        if (n == 1) {
            couleur = getpixel(collision, maison->X_mario_int + 45 + i, maison->Y_mario_int + 45);
        } else if (n == 2) {
            couleur = getpixel(collision, maison->X_mario_int - i, maison->Y_mario_int + 45);
        } else if (n == 3) {
            couleur = getpixel(collision, maison->X_mario_int + 23, maison->Y_mario_int +15 - i);
        } else if (n == 4) {
            couleur = getpixel(collision, maison->X_mario_int + 23, maison->Y_mario_int + 60 + i);
        }
        if (couleur == red_color) {
            return 1; // Collision avec rouge, retour immédiat
        }
    }
    return 0; // Pas de collision détectée
}

int verification_interieur(BITMAP *collision, Maison *maison){
    int green_color = makecol(99, 171, 63); // Couleur verte
    int couleur = getpixel(collision, maison->X_mario_int + 23, maison->Y_mario_int + 30);

    if (couleur==green_color){
        if(maison->X_mario_int>0 && maison->X_mario_int<1280 && maison->Y_mario_int>0 && maison->Y_mario_int<720){
            dialogue_int(maison);
        }
    }
}

void dialogue_int(Maison *maison){
    BITMAP *buffer,*dialogue[2];
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    dialogue[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/dialogue_sel.bmp",NULL);
    dialogue[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/dialogue_poivre.bmp",NULL);
    while (!key[KEY_F]) {
        if (maison->numero==3){
            blit(dialogue[0], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            maison->sel=1;
        }
        if (maison->numero==4){
            blit(dialogue[1], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            maison->poivre=1;
        }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(buffer);
    destroy_bitmap(dialogue[0]);
    destroy_bitmap(dialogue[1]);
}
//
// Created by gabri on 23/10/2024.
//
#include "menu.h"

int jeu_grotte(Modification *modif){
    BITMAP *buffer,*map,*collision,*Normal[2],*Coursedroite[2],*Coursegauche[2],*Surf[2],*pnj,*dialogue;
    int taille_map_x = 1920;
    int taille_map_y = 2880;
    buffer = create_bitmap(taille_map_x, taille_map_y);
    clear_to_color(buffer, makecol(255, 255, 255));
    map = load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/grotte.bmp",NULL);
    collision = load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/collision_grotte.bmp",NULL);
    Normal[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/normal_d.bmp",NULL);
    Normal[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/normal_q.bmp",NULL);
    Coursedroite[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_d_1.bmp",NULL);
    Coursedroite[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_d_2.bmp",NULL);
    Coursegauche[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_q_1.bmp",NULL);
    Coursegauche[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/cour_q_2.bmp",NULL);
    Surf[0]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/surf_d.bmp",NULL);
    Surf[1]=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/surf_q.bmp",NULL);



    Grotte* grotte = malloc(sizeof (Grotte));
    grotte->x_map_grotte=0;
    grotte->y_map_grotte=0;
    grotte->X_mario_grotte=130;
    grotte->Y_mario_grotte=2700;
    grotte->saut=0;
    grotte->sol=1;
    grotte->echelle=0;

    int current_frame=0;
    int position=0;


    while (!key[KEY_ESC]) { // Boucle principale
        clear_bitmap(buffer);

        if (key[KEY_D]) {
            if (collisionjoueur_grotte(1,grotte,collision,modif)==0) {
                grotte->X_mario_grotte += deplacement_grotte;
                if (modif->surfage==1){
                    zoom_grotte(map, Surf[0], grotte);
                }
                else {
                    zoom_grotte(map, Coursedroite[current_frame], grotte);
                    current_frame = (current_frame + 1) % 2;
                    position = 0;
                }
            }
        }
        if (key[KEY_A]) {
            if (collisionjoueur_grotte(2,grotte,collision,modif)==0) {
                grotte->X_mario_grotte -= deplacement_grotte;
                if (modif->surfage==1){
                    zoom_grotte(map, Surf[1], grotte);
                }
                else {
                    zoom_grotte(map, Coursegauche[current_frame], grotte);
                    current_frame = (current_frame + 1) % 2;
                    position = 1;
                }
            }
        }
        if(key[KEY_W]){
            if(modif->surfage==0) {
                if (grotte->echelle == 0) {
                    if (grotte->sol == 1) {
                        grotte->saut = 13;
                        grotte->sol = 0;
                    }
                }
            }
        }
        if (collisionjoueur_grotte(3,grotte,collision,modif)==1) {
            grotte->saut=0;
        }
        if (grotte->saut != 0){
                grotte->Y_mario_grotte -= 1 + grotte->saut/2;
                zoom_grotte(map, Normal[position], grotte);
                collisionjoueur_grotte(0, grotte, collision,modif);
                grotte->saut--;
        }
        if (!key[KEY_D] && !key[KEY_A]) {
            zoom_grotte(map, Normal[position], grotte);
            collisionjoueur_grotte(0, grotte, collision,modif);
        }
        if(key[KEY_E]){
            if(grotte->x_map_grotte>=1281 && grotte->x_map_grotte<=1313 && grotte->y_map_grotte>=570 && grotte->y_map_grotte<=590) {
                dialogue_grotte();
                modif->surf=1;
            }
        }
        if(grotte->X_mario_grotte>=100 && grotte->X_mario_grotte<=136 && grotte->y_map_grotte>=570 && grotte->y_map_grotte<=590) {
            return 1;
        }
        if(grotte->X_mario_grotte>=100 && grotte->X_mario_grotte<=126 && grotte->y_map_grotte>=2590 && grotte->y_map_grotte<=2610) {
            return 0;
        }
    }
    destroy_bitmap(buffer);
    destroy_bitmap(map);
    destroy_bitmap(Coursedroite[0]);
    destroy_bitmap(Coursedroite[1]);
    destroy_bitmap(Coursegauche[0]);
    destroy_bitmap(Coursegauche[1]);
    destroy_bitmap(Normal[0]);
    destroy_bitmap(Normal[1]);
    free(grotte);
    return 0;
}


void zoom_grotte(BITMAP *map,BITMAP *affiche,Grotte *grotte){
    BITMAP *buffer,*pnj,*dialogue;
    pnj=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/pnj_grotte.bmp",NULL);
    dialogue=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/dialogue_pnj_grotte.bmp",NULL);
    int taille_map_x = 1920;
    int taille_map_y = 2880;
    buffer = create_bitmap(taille_map_x, taille_map_y);

    int pb_x=0;
    int pb_y=0;
    blit(map,buffer,0,0,0,0,taille_map_x,taille_map_y);
    masked_stretch_blit(pnj, buffer, 0, 0, pnj->w, pnj->h, 1496, 684, 15, 20);
    masked_stretch_blit(affiche, buffer, 0, 0, affiche->w, affiche->h, grotte->X_mario_grotte, grotte->Y_mario_grotte, 15, 20);
    if (grotte->X_mario_grotte-zoom_x<0){
        grotte->x_map_grotte=0;
        pb_x=1;
    }
    if (grotte->X_mario_grotte+zoom_x>taille_map_x){
        grotte->x_map_grotte=taille_map_x-2*zoom_x;
        pb_x=1;
    }
    if (grotte->Y_mario_grotte-zoom_y<0){
        grotte->y_map_grotte=0;
        pb_y=1;
    }
    if (grotte->Y_mario_grotte+zoom_y>taille_map_y){
        grotte->y_map_grotte=taille_map_y-2*zoom_y;
        pb_y=1;
    }
    if(pb_x!=1){
        grotte->x_map_grotte=grotte->X_mario_grotte-zoom_x;
    }
    if(pb_y!=1){
        grotte->y_map_grotte= grotte->Y_mario_grotte-zoom_y;
    }
    stretch_blit(buffer,screen,grotte->x_map_grotte,grotte->y_map_grotte,2*zoom_x,2*zoom_y,0,0,SCREEN_W,SCREEN_H);
    destroy_bitmap(buffer);
    destroy_bitmap(pnj);
    destroy_bitmap(dialogue);
}

int collisionjoueur_grotte(int n, Grotte*grotte, BITMAP *collision, Modification *modif) {
    int red_color = makecol(189, 106, 98); // Couleur rouge
    int green_color = makecol(99, 171, 63); // Couleur verte
    int blue_color = makecol(79, 164, 184); // Couleur bleu
    int bleu = makecol(0, 0, 255); // bleu bleu
    int couleur = 0;
    couleur = getpixel(collision, grotte->X_mario_grotte + 8, grotte->Y_mario_grotte + 20 );
    if(grotte->saut==0) {
        if (couleur != red_color) {
            grotte->sol=0;
            grotte->Y_mario_grotte+=2;
        }
        else grotte->sol=1;
    }
    for (int i = 0; i < 5; i++) {
        if (n == 1) {
            couleur = getpixel(collision, grotte->X_mario_grotte + 15 + i, grotte->Y_mario_grotte + 15);
        } else if (n == 2) {
            couleur = getpixel(collision, grotte->X_mario_grotte - i, grotte->Y_mario_grotte + 15);
        } else if (n == 3) {
            couleur = getpixel(collision, grotte->X_mario_grotte + 8, grotte->Y_mario_grotte - i);
        }
        if (couleur == red_color) {
            return 1; // Collision avec rouge, retour immédiat
        }
        if(couleur==bleu && modif->surf==0){
            return 1;
        }
        else if (couleur==bleu && modif->surf==1){
            modif->surfage=1;
        }
        else if (couleur!=bleu){
            modif->surfage=0;
        }
    }
    couleur = getpixel(collision, grotte->X_mario_grotte + 8, grotte->Y_mario_grotte + 10 );
    if(couleur==blue_color){
        grotte->echelle=1;
        if (key[KEY_W]){
            grotte->Y_mario_grotte-=3;
        }
    }
    else grotte->echelle=0;
    couleur = getpixel(collision, grotte->X_mario_grotte + 8, grotte->Y_mario_grotte + 10 );
    if(couleur==green_color){
        grotte->X_mario_grotte=200;
        grotte->Y_mario_grotte=2650;
    }
    return 0; // Pas de collision détectée
}

void dialogue_grotte() {
    BITMAP *buffer, *dialogue;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    dialogue = load_bitmap("D:/JeuTropStylee/decor_map/Sprite/dialogue_pnj_grotte.bmp", NULL);
    while (!key[KEY_F]) {
        blit(dialogue, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}
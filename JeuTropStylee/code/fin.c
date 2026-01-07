//
// Created by gabri on 14/11/2024.
//
#include "menu.h"

int finition(){
    BITMAP *buffer,*buffer2,*map_fin,*collision_fin,*Normal[4],*Coursedroite[2],*Coursegauche[2],*Coursehaut[2],*Coursebas[2],*Texte_fin;

    int taille_map_x = 640;
    int taille_map_y = 1600;

    buffer = create_bitmap(taille_map_x, taille_map_y);
    buffer2 =create_bitmap(1280, 720);
    clear_to_color(buffer, makecol(255, 255, 255));
    map_fin = load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/map_fin.bmp",NULL);
    collision_fin = load_bitmap("D:/JeuTropStylee/decor_map/Mappourallegro/collision_fin.bmp",NULL);
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
    Texte_fin=load_bitmap("D:/JeuTropStylee/decor_map/Sprite/texte_fin.bmp",NULL);

    int current_frame=0;
    int position=0;
    int mouvement =1;
    Fin* fin = malloc(sizeof (Fin));
    fin->X_mario_fin=314;
    fin->Y_mario_fin=1330;
    fin->x_map_fin=0;
    fin->y_map_fin=0;

    int delay = 0;
    int max_delay = 100;
    while(delay < max_delay){
        zoom_fin(map_fin, Normal[position], fin);;
        position = (position + 1) % 4;
        rest(delay);
        delay += 4;
    }
    position=2;

    while (!key[KEY_ESC]) {
        if (key[KEY_D]) {
            if (collisionjoueur_fin(1, collision_fin, fin) == 0) {
                fin->X_mario_fin += mouvement;
                zoom_fin(map_fin,Coursedroite[current_frame], fin);
                current_frame = (current_frame + 1) % 2;
                position = 0;
                //key[KEY_D] = 0;
            }
        }
        if (key[KEY_A]) {
            if (collisionjoueur_fin(2, collision_fin, fin) == 0) {
                fin->X_mario_fin -= mouvement;
                zoom_fin(map_fin, Coursegauche[current_frame], fin);
                current_frame = (current_frame + 1) % 2;
                position = 1;
                //key[KEY_A] = 0;
            }


        }
        if (key[KEY_W]) {
            if (collisionjoueur_fin(3, collision_fin, fin) == 0) {
                fin->Y_mario_fin -= mouvement;
                zoom_fin(map_fin, Coursehaut[current_frame], fin);
                current_frame = (current_frame + 1) % 2;
                position = 2;
                //key[KEY_W] = 0;

            }

        }
        if (key[KEY_S]) {
            if (collisionjoueur_fin(4, collision_fin, fin) == 0) {
                fin->Y_mario_fin += mouvement;
                zoom_fin(map_fin, Coursebas[current_frame], fin);
                current_frame = (current_frame + 1) % 2;
                position = 3;
                //key[KEY_S] = 0;

            }
        }
        if (!key[KEY_D] && !key[KEY_A] && !key[KEY_W] && !key[KEY_S]) {
            zoom_fin(map_fin, Normal[position], fin);
        }
        if (key[KEY_E]) {
            int green_color = makecol(99, 171, 63); // Couleur verte
            int couleur = getpixel(collision_fin, fin->X_mario_fin + 8, fin->Y_mario_fin + 10);
            if (couleur == green_color){
                while (!key[KEY_F]) {
                    blit(Texte_fin, buffer2, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                    blit(buffer2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                }
            }
        }
    }

    destroy_bitmap(map_fin);
    destroy_bitmap(buffer);
    destroy_bitmap(buffer2);
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
    destroy_bitmap(collision_fin);
    destroy_bitmap(Texte_fin);
    return 0;
}



int collisionjoueur_fin(int n, BITMAP *collision, Fin *fin) {
    int red_color = makecol(189, 106, 98); // Couleur rouge

    for (int i = 0; i < 5; i++) {
        int couleur = 0;

        if (n == 1) {
            couleur = getpixel(collision, fin->X_mario_fin + 15 + i, fin->Y_mario_fin + 15);
        } else if (n == 2) {
            couleur = getpixel(collision, fin->X_mario_fin - i, fin->Y_mario_fin + 15);
        } else if (n == 3) {
            couleur = getpixel(collision, fin->X_mario_fin + 8, fin->Y_mario_fin - i);
        } else if (n == 4) {
            couleur = getpixel(collision, fin->X_mario_fin + 8, fin->Y_mario_fin + 20 + i);
        }
        if (couleur == red_color) {
            return 1; // Collision avec rouge, retour immédiat
        }
    }
    return 0; // Pas de collision détectée
}



void zoom_fin(BITMAP *map,BITMAP *affiche,Fin *fin){
    BITMAP *buffer;
    int taille_map_x = 3200;
    int taille_map_y = 2560;
    buffer = create_bitmap(taille_map_x, taille_map_y);

    int pb_x=0;
    int pb_y=0;
    blit(map,buffer,0,0,0,0,taille_map_x,taille_map_y);
    masked_stretch_blit(affiche, buffer, 0, 0, affiche->w, affiche->h, fin->X_mario_fin, fin->Y_mario_fin, 15, 20);

    if (fin->X_mario_fin-zoom_x<0){
        fin->x_map_fin=0;
        pb_x=1;
    }
    if (fin->X_mario_fin+zoom_x>taille_map_x){
        fin->x_map_fin=taille_map_x-2*zoom_x;
        pb_x=1;
    }
    if (fin->Y_mario_fin-zoom_y<0){
        fin->y_map_fin=0;
        pb_y=1;
    }
    if (fin->Y_mario_fin+zoom_y>taille_map_y){
        fin->y_map_fin=taille_map_y-2*zoom_y;
        pb_y=1;
    }
    if(pb_x!=1){
        fin->x_map_fin=fin->X_mario_fin-zoom_x;
    }
    if(pb_y!=1){
        fin->y_map_fin=fin->Y_mario_fin-zoom_y;
    }
    stretch_blit(buffer,screen,fin->x_map_fin,fin->y_map_fin,2*zoom_x,2*zoom_y,0,0,SCREEN_W,SCREEN_H);
    destroy_bitmap(buffer);
}
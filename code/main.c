//
// Created by gabri on 14/10/2024.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>



int main() {
    allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_NONE, "");
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 720, 0, 0);
    BITMAP *buffer,*map,*collision,*Normal[4],*Coursedroite[2],*Coursegauche[2],*Coursehaut[2],*Coursebas[2],*dessus,*marchand,*surf[4],*e;
    int taille_map_x = 3200;
    int taille_map_y = 2560;
    buffer = create_bitmap(taille_map_x, taille_map_y);
    clear_to_color(buffer, makecol(255, 255, 255));
    map = load_bitmap("D:/Jeu_Coree_2024/decor_map/Mappourallegro/map.bmp",NULL);
    collision = load_bitmap("D:/Jeu_Coree_2024/decor_map/Mappourallegro/collision.bmp",NULL);
    dessus=load_bitmap("D:/Jeu_Coree_2024/decor_map/Mappourallegro/dessus.bmp",NULL);
    Normal[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/normal_d.bmp",NULL);
    Normal[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/normal_q.bmp",NULL);
    Normal[2]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/normal_z.bmp",NULL);
    Normal[3]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/normal_s.bmp",NULL);
    Coursedroite[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_d_1.bmp",NULL);
    Coursedroite[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_d_2.bmp",NULL);
    Coursegauche[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_q_1.bmp",NULL);
    Coursegauche[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_q_2.bmp",NULL);
    Coursehaut[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_z_1.bmp",NULL);
    Coursehaut[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_z_2.bmp",NULL);
    Coursebas[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_s_1.bmp",NULL);
    Coursebas[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cour_s_2.bmp",NULL);
    marchand=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/marchand.bmp",NULL);
    surf[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/surf_d2.bmp",NULL);
    surf[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/surf_q2.bmp",NULL);
    surf[2]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/surf_z2.bmp",NULL);
    surf[3]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/surf_s2.bmp",NULL);
    e=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/e.bmp",NULL);







    Coord* coord = malloc(sizeof (Coord));
    Modification* modif = malloc(sizeof (Modification));
    modif->barriere=0;
    coord->x_map=0;
    coord->y_map=0;
    coord->X_mario=335;
    coord->Y_mario=205;

    int current_frame = 0;
    int position=3;
    int depart=0;
    modif->interieur=0;
    modif->surf=0;
    modif->surfage=0;
    modif->dialogue=0;
    modif->sel=0;
    modif->poivre=0;
    modif->cle1=1;
    modif->cle2=1;
    modif->cle3=1;
    modif->nature1=0;
    modif->nature2=0;
    modif->nature3=0;
    modif->commencement=0;
    for(int i=0;i<12;i++){
        modif->fleur[i]=0;
    }
    for(int i=0;i<5;i++){
        modif->poisson[i]=0;
    }
    int show_map = 0;

    depart=ecran_acceuil(modif,coord);
    if (depart==0){
        function_maison(depart,modif);
        modif->interieur = 0;
        depart=1;
    }


    while (!key[KEY_ESC]) { // Boucle principale
        clear_bitmap(buffer);
        //CARTE
        if (key[KEY_TAB]) {
            show_map = 1; // Activer l'affichage de la carte
        } else {
            show_map = 0; // Désactiver l'affichage de la carte
        }

        if (show_map) {
            // Afficher la carte à 100 % de la taille de l'écran
            stretch_blit(map, buffer, 0, 0, map->w, map->h, 0, 0, SCREEN_W, SCREEN_H);

            // Calculer la position du personnage sur la carte
            float scale_x = (float)SCREEN_W / map->w;
            float scale_y = (float)SCREEN_H / map->h;
            int point_x = coord->X_mario * scale_x;
            int point_y = coord->Y_mario * scale_y;

            // Dessiner un point pour la position du personnage
            circlefill(buffer, point_x, point_y, 10, makecol(255, 0, 0));
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        } else {        //MOUVEMENT

            int green_color = makecol(99, 171, 63); // Couleur verte
            int couleur = getpixel(collision, coord->X_mario + 8, coord->Y_mario + 10);

            if (key[KEY_D]) {
                if (collisionjoueur(1, modif, collision, coord) == 0) {
                    coord->X_mario += deplacement;
                    if (modif->surfage == 1) {
                        zoom(map, dessus, surf[position], coord, modif);
                    } else zoom(map, dessus, Coursedroite[current_frame], coord, modif);
                    current_frame = (current_frame + 1) % 2;
                    position = 0;
                    //key[KEY_D] = 0;
                }
            }
            if (key[KEY_A]) {
                if (collisionjoueur(2, modif, collision, coord) == 0) {
                    coord->X_mario -= deplacement;
                    if (modif->surfage == 1) {
                        zoom(map, dessus, surf[position], coord, modif);
                    } else zoom(map, dessus, Coursegauche[current_frame], coord, modif);
                    current_frame = (current_frame + 1) % 2;
                    position = 1;
                    //key[KEY_A] = 0;
                }
            }
            if (key[KEY_W]) {
                if (collisionjoueur(3, modif, collision, coord) == 0) {
                    coord->Y_mario -= deplacement;
                    if (modif->surfage == 1) {
                        zoom(map, dessus, surf[position], coord, modif);
                    } else zoom(map, dessus, Coursehaut[current_frame], coord, modif);
                    current_frame = (current_frame + 1) % 2;
                    position = 2;
                    //key[KEY_W] = 0;

                }

            }
            if (key[KEY_S]) {
                if (collisionjoueur(4, modif, collision, coord) == 0) {
                    coord->Y_mario += deplacement;
                    if (modif->surfage == 1) {
                        zoom(map, dessus, surf[position], coord, modif);
                    } else zoom(map, dessus, Coursebas[current_frame], coord, modif);
                    current_frame = (current_frame + 1) % 2;
                    position = 3;
                    //key[KEY_S] = 0;

                }
            }
            if (!key[KEY_D] && !key[KEY_A] && !key[KEY_W] && !key[KEY_S]) {
                if (modif->surfage == 1) {
                    zoom(map, dessus, surf[position], coord, modif);
                } else zoom(map, dessus, Normal[position], coord, modif);
            }
            if (key[KEY_E]) {
                verification_action(collision, coord, modif);
                if (modif->interieur != 0) {
                    function_maison(depart, modif);
                    modif->interieur = 0;
                }
                if(couleur==green_color) {
                    if (coord->x_map > 1325 && coord->x_map < 1440 && coord->y_map > 80 &&
                        coord->y_map < 150) { // le pnj du début
                        coord->X_mario = 1578;
                        coord->Y_mario = 212;
                        int delay = 100;
                        int min_delay = 10;
                        while (delay > min_delay) {
                            zoom(map, dessus, Normal[position], coord, modif);;
                            position = (position + 1) % 4;
                            rest(delay);
                            delay -= 4;
                        }
                        finition();
                    }
                }
            }
            if (key[KEY_LCONTROL]&& key[KEY_S]) {
                enregistrement_joueur(modif,coord);
            }
            if(couleur==green_color){
                masked_blit(e,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }
        }
    }
    
    free(coord);
    free(modif);
    destroy_bitmap(map);
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
    destroy_bitmap(collision);
    destroy_bitmap(dessus);
    destroy_bitmap(marchand);
    remove_sound();
    remove_keyboard();
    remove_mouse();
    allegro_exit();
    return 0;
}END_OF_MAIN();
/*
int rayon = 0;
for (int j=0;j<100;j++){
rayon+=10;
drawing_mode(DRAW_MODE_COPY_PATTERN, map, 0, 0);
circlefill(buffer, 640, 360, rayon, makecol(0, 0, 0));
blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
rest(10);
}*/
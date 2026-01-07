//
// Created by gabri on 17/10/2024.
//
#include "menu.h"


void verification_action(BITMAP *collision,Coord *coord,Modification *modif){

    int green_color = makecol(99, 171, 63); // Couleur verte

    int couleur = getpixel(collision, coord->X_mario + 8, coord->Y_mario + 10);
    //printf("\n %d // %d",coord->x_map,coord->y_map);


    if (couleur == green_color){
        if(coord->x_map>0 && coord->x_map<500 && coord->y_map>0 && coord->y_map<500){
            modif->interieur=1;
        }
        if(coord->x_map>1335 && coord->x_map<1405 && coord->y_map>1175 && coord->y_map<1225){
            modif->interieur=2;
        }
        if(coord->x_map>255 && coord->x_map<365 && coord->y_map>355 && coord->y_map<415){
            modif->interieur=3;
        }
        if(coord->x_map>2105 && coord->x_map<2225 && coord->y_map>2255 && coord->y_map<2315){
            modif->interieur=4;
        }

        if(coord->x_map>1175 && coord->x_map<1325 && coord->y_map>925 && coord->y_map<1035){
            dialogue(modif);
        }

        if(coord->x_map>1480 && coord->x_map<1550 && coord->y_map>475 && coord->y_map<535){ // le pnj du début
            dialogue_demarrage(modif);
        }

        if(coord->x_map>1800 && coord->x_map<1845 && coord->y_map>315 && coord->y_map<370){ // le pnj du début
            dialogue_coffre(modif);
        }

        if(coord->x_map>2400 && coord->x_map<2800 && coord->y_map>0&& coord->y_map<100){//grotte
            int sortie=0;
            sortie=jeu_grotte(modif);
            if(sortie==1){
                coord->X_mario=35;
                coord->Y_mario=2520;
            }
        }

        if(coord->x_map>=1935 && coord->x_map<=2045 && coord->y_map>=2335 && coord->y_map<=2360) {
            modif->fleur[0]=1;
        }
        if(coord->x_map>=2435 && coord->x_map<=2525 && coord->y_map>=2215 && coord->y_map<=2285) {
            modif->fleur[1]=1;
        }
        if(coord->x_map>=2675 && coord->x_map<=2775 && coord->y_map>=2275 && coord->y_map<=2355) {
            modif->fleur[2]=1;
        }
        if(coord->x_map>=2755 && coord->x_map<=2800 && coord->y_map>=2005 && coord->y_map<=2085) {
            modif->fleur[3]=1;
        }
        if(coord->x_map>=2800 && coord->x_map<=2800 && coord->y_map>=1545 && coord->y_map<=1635) {
            modif->fleur[4]=1;
        }
        if(coord->x_map>=2715 && coord->x_map<=2800 && coord->y_map>=1425 && coord->y_map<=1505 ) {
            modif->fleur[5]=1;
        }
        if(coord->x_map>=2800 && coord->x_map<=2800 && coord->y_map>=1255 && coord->y_map<=1325) {
            modif->fleur[6]=1;
        }
        if(coord->x_map>=2705 && coord->x_map<=2795 && coord->y_map>=1185 && coord->y_map<=1245) {
            modif->fleur[7]=1;
        }
        if(coord->x_map>=2195 && coord->x_map<=2265 && coord->y_map>=1135 && coord->y_map<=1195) {
            modif->fleur[8]=1;
        }
        if(coord->x_map>=1845 && coord->x_map<=1965 && coord->y_map>=1155 && coord->y_map<=1225) {
            modif->fleur[9]=1;
        }
        if(coord->x_map>=1585 && coord->x_map<=1655 && coord->y_map>=1425 && coord->y_map<=1475) {
            modif->fleur[10]=1;
        }
        if(coord->x_map>=1565 && coord->x_map<=1675 && coord->y_map>=1695 && coord->y_map<=1775) {
            modif->fleur[11]=1;
        }

        if(coord->x_map>=235 && coord->x_map<=345 && coord->y_map>=1845 && coord->y_map<=1935) {
            modif->poisson[0]=1;
        }
        if(coord->x_map>=85 && coord->x_map<=175 && coord->y_map>=1975 && coord->y_map<=2065) {
            modif->poisson[1]=1;
        }
        if(coord->x_map>=285 && coord->x_map<=375 && coord->y_map>=2005 && coord->y_map<=2085) {
            modif->poisson[2]=1;
        }
        if(coord->x_map>=505 && coord->x_map<=615 && coord->y_map>=2015 && coord->y_map<=2085) {
            modif->poisson[3]=1;
        }
        if(coord->x_map>=285 && coord->x_map<=415 && coord->y_map>=2175 && coord->y_map<=2245) {
            modif->poisson[4]=1;
        }
        if(coord->x_map>=410 && coord->x_map<=505 && coord->y_map>=1020 && coord->y_map<=1085) {
            modif->cle2=1;
        }
        if(coord->x_map>=2175 && coord->x_map<=2285 && coord->y_map>=1675 && coord->y_map<=1750) {
            modif->cle3=1;
        }
        if(coord->x_map>=0 && coord->x_map<=0 && coord->y_map>=540 && coord->y_map<=600) {
            modif->nature1=1;
        }
        if(coord->x_map>=1895 && coord->x_map<=2040 && coord->y_map>=645 && coord->y_map<=740) {
            modif->nature2=1;
        }
        if(coord->x_map>=2795 && coord->x_map<=2800 && coord->y_map>=2315 && coord->y_map<=2360) {
            modif->nature3=1;
        }
        if(coord->x_map>=985 && coord->x_map<=1130 && coord->y_map>=1420 && coord->y_map<=1480) {
            dialogue_arbre(modif);
        }
    }
}

int collisionjoueur(int n, Modification *modif, BITMAP *collision, Coord *coord) {
    int red_color = makecol(189, 106, 98); // Couleur rouge
    int blue_color = makecol(79, 183, 155); // Couleur bleu
    int grey= makecol(107, 94, 95);
    int bleu= makecol(0, 0, 255);

    for (int i = 0; i < 5; i++) {
        int couleur = 0;

        if (n == 1) {
            couleur = getpixel(collision, coord->X_mario + 15 + i, coord->Y_mario + 15);
        } else if (n == 2) {
            couleur = getpixel(collision, coord->X_mario - i, coord->Y_mario + 15);
        } else if (n == 3) {
            couleur = getpixel(collision, coord->X_mario + 8, coord->Y_mario - i);
        } else if (n == 4) {
            couleur = getpixel(collision, coord->X_mario + 8, coord->Y_mario + 20 + i);
        }
        if (couleur == red_color) {
            return 1; // Collision avec rouge, retour immédiat
        }

        if (couleur == blue_color && coord->x_map>=1510 && coord->x_map<=1635 && coord->y_map>=475 && coord->y_map<=520) {
            if(!(modif->cle1==1 && modif->cle2==1 && modif->cle3==1)){
                return 1;
            }
            else return 0;
        }
        if (couleur == blue_color && coord->x_map>=585 && coord->x_map<=630 && coord->y_map>=415 && coord->y_map<=555) {
            if(modif->commencement==0){
                return 1;
            }
            else return 0;
        }
        if (couleur == blue_color && coord->x_map>=310 && coord->x_map<=545 && coord->y_map>=1270 && coord->y_map<=1320) {
            if(modif->barriere==0){
                return 1;
            }
            else return 0;
        }
        if (couleur == blue_color && coord->x_map>=0 && coord->x_map<=25 && coord->y_map>=2345 && coord->y_map<=2360) {//sortie grotte
            if(key[KEY_D]){
                return 0;
            }
            else return 1;
        }

        if(modif->surfage==0) {
            if (couleur == grey) {
                if (modif->surf==1 && key[KEY_E]) {
                    modif->surfage=1;
                }
                else return 1; // Collision avec bleu si `active` est désactivé
            }
        }
        if(modif->surfage==1) {
            if (couleur == bleu) {
                if (key[KEY_E]) {
                    modif->surfage = 0;
                }
                else return 1;
            }
        }

    }
    return 0; // Pas de collision détectée
}



void zoom(BITMAP *map, BITMAP *dessus,BITMAP *affiche,Coord *coord,Modification *modif){
    BITMAP *buffer,*obstacle[6],*pnj,*e;
    int taille_map_x = 3200;
    int taille_map_y = 2560;
    buffer = create_bitmap(taille_map_x, taille_map_y);
    obstacle[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/barriere.bmp",NULL);
    obstacle[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/marchand.bmp",NULL);
    obstacle[2]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/cle.bmp",NULL);
    obstacle[3]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/flower.bmp",NULL);
    obstacle[4]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/poisson.bmp",NULL);
    obstacle[5]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/nature.bmp",NULL);
    pnj=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/pnj.bmp",NULL);
    e=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/e.bmp",NULL);

    int pb_x=0;
    int pb_y=0;
    blit(map,buffer,0,0,0,0,taille_map_x,taille_map_y);
    changement(buffer,obstacle,modif);
    masked_stretch_blit(obstacle[1], buffer, 0, 0, obstacle[1]->w,
                        obstacle[1]->h, 1460, 1000, 18, 23);
    masked_stretch_blit(pnj, buffer, 0, 0, pnj->w,
                        pnj->h, 1710, 590, 15, 20);
    if (modif->surfage==1){
        masked_stretch_blit(affiche, buffer, 0, 0, affiche->w, affiche->h, coord->X_mario, coord->Y_mario, 20, 25);
    }
    else masked_stretch_blit(affiche, buffer, 0, 0, affiche->w, affiche->h, coord->X_mario, coord->Y_mario, 15, 20);
    masked_blit(dessus,buffer,0,0,0,0,taille_map_x,taille_map_y);


    if (coord->X_mario-zoom_x<0){
        coord->x_map=0;
        pb_x=1;
    }
    if (coord->X_mario+zoom_x>taille_map_x){
        coord->x_map=taille_map_x-2*zoom_x;
        pb_x=1;
    }
    if (coord->Y_mario-zoom_y<0){
        coord->y_map=0;
        pb_y=1;
    }
    if (coord->Y_mario+zoom_y>taille_map_y){
        coord->y_map=taille_map_y-2*zoom_y;
        pb_y=1;
    }
    if(pb_x!=1){
        coord->x_map=coord->X_mario-zoom_x;
    }
    if(pb_y!=1){
        coord->y_map=coord->Y_mario-zoom_y;
    }
    stretch_blit(buffer,screen,coord->x_map,coord->y_map,2*zoom_x,2*zoom_y,0,0,SCREEN_W,SCREEN_H);
    destroy_bitmap(buffer);
    destroy_bitmap(obstacle[0]);
    destroy_bitmap(obstacle[1]);
    destroy_bitmap(obstacle[2]);
    destroy_bitmap(obstacle[3]);
    destroy_bitmap(obstacle[4]);
    destroy_bitmap(obstacle[5]);
    destroy_bitmap(pnj);
}

int changement(BITMAP *buffer,BITMAP *obstacle[6],Modification *modif){
    if (modif->fleur[0]==0) {
        masked_blit(obstacle[3], buffer, 0, 0, 2179, 2482, SCREEN_W, SCREEN_H);//2176,2480
    }
    if (modif->fleur[1]==0) {
        masked_blit(obstacle[3], buffer, 0, 0, 2690, 2354, SCREEN_W, SCREEN_H);// +3,+2
    }
    if (modif->fleur[2]==0) {
        masked_blit(obstacle[3],buffer,0,0,2931,2418,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[3]==0) {
        masked_blit(obstacle[3],buffer,0,0,2995,2146,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[4]==0) {
        masked_blit(obstacle[3],buffer,0,0,3075,1682,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[5]==0) {
        masked_blit(obstacle[3],buffer,0,0,3011,1570,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[6]==0) {
        masked_blit(obstacle[3],buffer,0,0,3059,1394,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[7]==0) {
        masked_blit(obstacle[3],buffer,0,0,2947,1314,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[8]==0) {
        masked_blit(obstacle[3],buffer,0,0,2435,1266,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[9]==0) {
        masked_blit(obstacle[3],buffer,0,0,2099,1298,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[10]==0) {
        masked_blit(obstacle[3],buffer,0,0,1827,1554,SCREEN_W,SCREEN_H);
    }
    if (modif->fleur[11]==0) {
        masked_blit(obstacle[3],buffer,0,0,1827,1842,SCREEN_W,SCREEN_H);
    }
    if (modif->poisson[0]==0){
        masked_blit(obstacle[4],buffer,0,0,480,1984,SCREEN_W,SCREEN_H);
    }
    if (modif->poisson[1]==0){
        masked_blit(obstacle[4],buffer,0,0,320,2128,SCREEN_W,SCREEN_H);
    }
    if (modif->poisson[2]==0){
        masked_blit(obstacle[4],buffer,0,0,528,2144,SCREEN_W,SCREEN_H);
    }
    if (modif->poisson[3]==0){
        masked_blit(obstacle[4],buffer,0,0,768,2160,SCREEN_W,SCREEN_H);
    }
    if (modif->poisson[4]==0){
        masked_blit(obstacle[4],buffer,0,0,544,2320,SCREEN_W,SCREEN_H);
    }
    if(modif->nature1==0){
        masked_blit(obstacle[5],buffer,0,0,88,660,SCREEN_W,SCREEN_H);
    }
    if(modif->nature2==0){
        masked_blit(obstacle[5],buffer,0,0,2112,752,SCREEN_W,SCREEN_H);
        masked_blit(obstacle[5],buffer,0,0,2112,802,SCREEN_W,SCREEN_H);
        masked_blit(obstacle[5],buffer,0,0,2162,768,SCREEN_W,SCREEN_H);
    }
    if(modif->nature3==0){
        masked_blit(obstacle[5],buffer,0,0,3032,2444,SCREEN_W,SCREEN_H);
    }
    if (modif->barriere==0) {// LA
        masked_stretch_blit(obstacle[0], buffer, 0, 0, obstacle[0]->w,
                            obstacle[0]->h, 635, 1390, 60, 20);
    }
    if (modif->cle2==0){
        masked_blit(obstacle[2],buffer,0,0,646,1150,SCREEN_W,SCREEN_H);
    }
    if (modif->cle3==0){
        masked_blit(obstacle[2],buffer,0,0,2420,1800,SCREEN_W,SCREEN_H);
    }
    if(!(modif->cle1==1 && modif->cle2==1 && modif->cle3==1)){
        masked_stretch_blit(obstacle[0], buffer, 0, 0, obstacle[0]->w,
                            obstacle[0]->h, 1734, 600, 80, 20);
    }

    if (modif->commencement==0) {
        masked_stretch_blit(obstacle[0], buffer, 0, 0, obstacle[0]->w,
                            obstacle[0]->h, 786, 577, 60, 20);
    }
    return 0;
}

void dialogue(Modification *modif){
    BITMAP *buffer,*dialogue[4],*dialoguepnj;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    dialogue[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/dialogue.bmp",NULL);
    dialogue[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/dialogue2.bmp",NULL);
    dialogue[2]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/dialogue3.bmp",NULL);
    dialogue[3]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/dialogue4.bmp",NULL);


    if(modif->dialogue==0) {
        modif->dialogue = verification_fleur(modif);
    }
    if (modif->dialogue==1) {
        modif->dialogue = verification_poisson(modif);
    }
    if (modif->dialogue==2 && modif->sel == 1 && modif->poivre==1){
        modif->dialogue=3;
    }
    while (!key[KEY_F]) {
            if (modif->dialogue == 0) {
                blit(dialogue[0], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            if (modif->dialogue == 1) {
                blit(dialogue[1], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            if (modif->dialogue == 2) {
                blit(dialogue[2], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
            if (modif->dialogue == 3) {
                blit(dialogue[3], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                modif->cle1 = 1;
            }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(buffer);
    destroy_bitmap(dialogue[0]);
    destroy_bitmap(dialogue[1]);
    destroy_bitmap(dialogue[2]);
    destroy_bitmap(dialogue[3]);
}

int verification_fleur(Modification *modif) {
    for (int i = 0; i < 12; i++) {
        if (modif->fleur[i] != 1) {
            return 0;
        }
    }
    return 1;
}

int verification_poisson(Modification *modif) {
    for (int i = 0; i < 5; i++) {
        if (modif->poisson[i] != 1) {
            return 1;
        }
    }
    return 2;
}

void dialogue_demarrage(Modification *modif){
    BITMAP *buffer,*dialoguepnj,*dialoguepnj2;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    dialoguepnj=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/dialogue_pnj.bmp",NULL);
    dialoguepnj2=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/dialogue_pnj2.bmp",NULL);
    while (!key[KEY_F]) {
        if(modif->cle1!=1 && modif->cle2!=1 && modif->cle3!=1){
            blit(dialoguepnj, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        else blit(dialoguepnj2, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    modif->commencement=1;
    destroy_bitmap(buffer);
    destroy_bitmap(dialoguepnj);
    destroy_bitmap(dialoguepnj2);
}

void dialogue_arbre(Modification *modif){
    BITMAP *buffer,*Foret[2];
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    Foret[0]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Mappourallegro/Foret.bmp",NULL);
    Foret[1]=load_bitmap("D:/Jeu_Coree_2024/decor_map/Mappourallegro/Foret2.bmp",NULL);
    while (!key[KEY_F]) {
        if (!(modif->nature1==1 && modif->nature2==1 && modif->nature3==1)) {
            blit(Foret[0], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        else {
            blit(Foret[1], buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            modif->barriere=1;
        }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(buffer);
    destroy_bitmap(Foret[0]);
    destroy_bitmap(Foret[1]);
}

void dialogue_coffre(Modification *modif){
    BITMAP *buffer,*Moche;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    Moche=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/Moche.bmp",NULL);
    while (!key[KEY_F]) {
        blit(Moche, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(buffer);
    destroy_bitmap(Moche);
}


void enregistrement_joueur(Modification *modif,Coord *coord){
    FILE *fichier;
    fichier = fopen("sauv.txt", "w");
    if (fichier != NULL){
        fprintf(fichier,"%d\n",modif->barriere);
        fprintf(fichier,"%d\n",modif->interieur);
        fprintf(fichier,"%d\n",modif->surf);
        fprintf(fichier,"%d\n",modif->surfage);
        fprintf(fichier,"%d\n",modif->sel);
        fprintf(fichier,"%d\n",modif->poivre);
        fprintf(fichier,"%d\n",modif->commencement);
        fprintf(fichier,"%d\n",modif->dialogue);
        fprintf(fichier,"%d\n",modif->cle1);
        fprintf(fichier,"%d\n",modif->cle2);
        fprintf(fichier,"%d\n",modif->cle3);
        fprintf(fichier,"%d\n",modif->nature1);
        fprintf(fichier,"%d\n",modif->nature2);
        fprintf(fichier,"%d\n",modif->nature3);
        for(int i=0;i<12;i++){
            fprintf(fichier,"%d\n",modif->fleur[i]);
        }
        for(int i=0;i<5;i++){
            fprintf(fichier,"%d\n",modif->poisson[i]);
        }
        fprintf(fichier,"%d\n",coord->X_mario);
        fprintf(fichier,"%d\n",coord->Y_mario);
        fprintf(fichier,"%d\n",coord->x_map);
        fprintf(fichier,"%d\n",coord->y_map);
        fprintf(fichier,"%d\n",coord->Perso);
        fclose(fichier);
    }
    else{
        printf("erreur");
        exit(1);
    }
}
void lecture_joueur(Modification *modif,Coord *coord){
    FILE *fichier;
    fichier = fopen("sauv.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier,"%d\n",&modif->barriere);
        fscanf(fichier,"%d\n",&modif->interieur);
        fscanf(fichier,"%d\n",&modif->surf);
        fscanf(fichier,"%d\n",&modif->surfage);
        fscanf(fichier,"%d\n",&modif->sel);
        fscanf(fichier,"%d\n",&modif->poivre);
        fscanf(fichier,"%d\n",&modif->commencement);
        fscanf(fichier,"%d\n",&modif->dialogue);
        fscanf(fichier,"%d\n",&modif->cle1);
        fscanf(fichier,"%d\n",&modif->cle2);
        fscanf(fichier,"%d\n",&modif->cle3);
        fscanf(fichier,"%d\n",&modif->nature1);
        fscanf(fichier,"%d\n",&modif->nature2);
        fscanf(fichier,"%d\n",&modif->nature3);
        for(int i=0;i<12;i++){
            fscanf(fichier,"%d\n",&modif->fleur[i]);
        }
        for(int i=0;i<5;i++){
            fscanf(fichier,"%d\n",&modif->poisson[i]);
        }
        fscanf(fichier,"%d\n",&coord->X_mario);
        fscanf(fichier,"%d\n",&coord->Y_mario);
        fscanf(fichier,"%d\n",&coord->x_map);
        fscanf(fichier,"%d\n",&coord->y_map);
        fscanf(fichier,"%d\n",&coord->Perso);
        fclose(fichier);
    }
    else{
        printf("erreur");
        exit(1);
    }
}



int ecran_acceuil(Modification *modif,Coord *coord){
    BITMAP *buffer,*fond,*souris;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    fond=load_bitmap("D:/Jeu_Coree_2024/decor_map/Mappourallegro/ecran_accueil.bmp",NULL);
    souris=load_bitmap("D:/Jeu_Coree_2024/decor_map/Sprite/souris.bmp",NULL);
    while (!key[KEY_ESC]) {
        blit(fond, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        show_mouse(buffer);
        masked_blit(souris, buffer, 0, 0, mouse_x - 20, mouse_y - 20, SCREEN_W, SCREEN_H);
        int click_x = mouse_x;
        int click_y = mouse_y;
        if ((mouse_b & 1) && (click_x >= 448 && click_x <= 850 && click_y >= 306 && click_y <= 400)) {
            return 0;
        }
        if ((mouse_b & 1) && (click_x >= 464 && click_x <= 830 && click_y >= 448 && click_y <= 545)) {
            lecture_joueur(modif,coord);
            return 1;
        }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(buffer);
    destroy_bitmap(fond);
    return 0;
}
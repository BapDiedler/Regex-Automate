#include "graphe.h"

noeud_t init_noeud(){
    noeud_t tete = malloc(sizeof(noeud_s));
    tete->id = 0;
    tete->ponderation = '0';
    tete->sommet = '0';
    return tete;
}

liste_t init_liste(){
    liste_t liste = malloc(sizeof(liste_s));
    liste->tete = NULL;
    liste->succ = NULL;
    return liste;
}

graphe_t init_graphe(){
    graphe_t graphe = malloc(sizeof(graphe_s));
    graphe->id = 0;
    return graphe;
}

int pos_sommet(graphe_t graphe, char sommet){
    for(int i=0; i<graphe->id || graphe->sommets[i] != sommet; i++)
    return i;
}

void add_liste(liste_t* liste, char sommet, char ponderation, int id){
    noeud_t tete = init_noeud();
    tete->ponderation = ponderation;
    tete->sommet = sommet;
    tete->id = id;
    liste_t L = init_liste();
    L->succ = (*liste);
    L->tete = tete;
    *liste = L;
}

void add_graphe(graphe_t* graphe, char val){
    (*graphe)->sommets[(*graphe)->id] = val;
    (*graphe)->id++;
}

void add_succ(graphe_t* graphe, char sommet, char succ, int pond){
    int pos = pos_sommet((*graphe), sommet);
    add_liste(&(*graphe)->successeurs[pos],succ,pond,pos_sommet((*graphe), succ));
}

void free_noeud(noeud_t noeud){
    free(noeud);
}

void free_liste(liste_t liste){
    if(liste != NULL){
        free_liste(liste->succ);
        free_noeud(liste->tete);
        free(liste);
    }
}

void free_graphe(graphe_t graphe){
    for(int i=0; i<graphe->id; i++){
        free_liste(graphe->successeurs[i]);
    }
    free(graphe);
}

int taille(liste_t liste){
    if(liste == NULL){
        return 0;
    }
    return 1 + taille(liste->succ);
}

void afficher_liste(liste_t liste){
    liste_t next;
    next = liste; 
    while(taille(next) != 0){
        printf("%c %d| ",next->tete->sommet,next->tete->ponderation);
        next = next->succ;
    }
}

void afficher_graphe(graphe_t graphe){
    for(int i=0; i<graphe->id; i++){
        printf("%c : ",graphe->sommets[i]);
        afficher_liste(graphe->successeurs[i]);
        printf("\n");
    }
}
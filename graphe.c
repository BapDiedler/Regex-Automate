#include "graphe.h"

noeud_t init_noeud(){
    noeud_t tete = malloc(sizeof(noeud_s));
    return tete;
}

liste_t init_liste(){
    liste_t liste = malloc(sizeof(liste_s));
    return liste;
}

graphe_t init_graphe(){
    graphe_t graphe = malloc(sizeof(graphe_s));
    return graphe;
}

void add_liste(liste_t* liste, char sommet, char ponderation){
    noeud_t tete = init_noeud();
    tete->ponderation = ponderation;
    tete->sommet = sommet;
    liste_t L = init_liste();
    L->succ = (*liste);
    L->tete = tete;
    *liste = L;
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


int main(void){
    noeud_t noeud = init_noeud();
    noeud->ponderation = 'a';
    noeud->sommet = 'a';
    printf("la pondération est %c et la valeur du sommet est %c\n",noeud->ponderation,noeud->sommet);
    free_noeud(noeud);

    liste_t liste = init_liste();
    add_liste(&liste,'a','2');
    add_liste(&liste,'b','3');
    printf("la pondération est %c et la valeur du sommet est %c\n",liste->tete->ponderation,liste->tete->sommet);
    free_liste(liste);
}
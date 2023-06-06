#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
//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
#ifndef GRAPHE_H

#define MAX_SOMMETS 200

struct noeud_s{
    char ponderation;
    char sommet;
    int id;
};
typedef struct noeud_s noeud_s,* noeud_t;

struct liste_s
{
    noeud_t tete;
    struct liste_s* succ;
};
typedef struct liste_s liste_s,* liste_t;


struct graphe_s
{
    int id;
    char sommets[MAX_SOMMETS];
    liste_t successeurs[MAX_SOMMETS];
};
typedef struct graphe_s graphe_s,* graphe_t;

noeud_t init_noeud();
liste_t init_liste();
graphe_t init_graphe();

int pos_sommet(graphe_t graphe, char sommet);

void add_liste(liste_t* liste, char sommet, char ponderation, int id);
void add_graphe(graphe_t* graphe, char val);

void add_succ(graphe_t* graphe, char sommet, char succ, int pond);

void free_noeud(noeud_t);
void free_liste(liste_t);
void free_graphe(graphe_t);

void afficher_graphe(graphe_t graphe);


#endif
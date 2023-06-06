#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
//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
#ifndef GRAPHE_H

struct noeud_s{
    char ponderation;
    char sommet;
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
    char* sommets;
    liste_t* successeurs;
};
typedef struct graphe_s graphe_s,* graphe_t;

noeud_t init_noeud();
liste_t init_liste();
graphe_t init_graphe();

void add_liste(liste_t* liste, char sommet, char ponderation);
void add_graphe(graphe_t graphe, char val);

void add_succ(graphe_t graphe, char sommet, char succ);

void free_noeud(noeud_t);
void free_liste(liste_t);
void free_graphe(graphe_t);


#endif
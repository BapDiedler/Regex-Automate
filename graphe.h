#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

#ifndef GRAPHE_H

//nombre maximal de sommet dans le graphe
#define MAX_SOMMETS 200

/// @brief noeud d'un graphe
struct noeud_s{
    char ponderation;
    char sommet;
    int id;
};
typedef struct noeud_s noeud_s,* noeud_t;

/// @brief  @brief liste de successeurs d'un sommet
struct liste_s
{
    noeud_t tete;
    struct liste_s* succ;
};
typedef struct liste_s liste_s,* liste_t;

/// @brief  @brief représentation d'un graphe
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

int taille(liste_t liste);

int pos_sommet(graphe_t graphe, char sommet);

void add_liste(liste_t* liste, char sommet, char ponderation, int id);
void add_graphe(graphe_t* graphe, char val);

void add_succ(graphe_t* graphe, char sommet, char succ, int pond);

void free_noeud(noeud_t);
void free_liste(liste_t);
void free_graphe(graphe_t);

void afficher_liste(liste_t liste);
void afficher_graphe(graphe_t graphe);


#endif
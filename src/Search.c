#include <stdio.h>
#include <string.h>
#include "../head/Search.h"

noeud* recherche(noeud* tete, char *nom) {
    if (tete == NULL) {
        printf("Liste vide - impossible de chercher\n");
        return NULL;
    }
    
    noeud* tmp = tete;
    while (tmp != NULL) {
        if (strcmp(tmp->data.name, nom) == 0) {
            return tmp;
        }
        tmp = tmp->suivant;
    }
    
    printf("Contact '%s' non trouve\n", nom);
    return NULL;
}

void afficherContact(noeud* contact) {
    if (contact == NULL) {
        printf("Aucun contact a afficher\n");
        return;
    }
    printf("||Nom :%s==Contact: %s||\n", contact->data.name, contact->data.tel);
}
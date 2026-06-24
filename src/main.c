#include <stdio.h>
#include <stdlib.h>
#include "../include/Contact.h"
#include "../include/Tri.h"
#include "../include/Search.h"
#include "../include/Interface.h"
int main() {

    FILE *flux = fopen("liste.txt","w");
    if (flux == NULL) {
        printf("Le fichier n'a pas pu etre ouvert");
        return 1;
    }
    noeud* tete = NULL;
    init(&tete);
    tri(&tete);
    afficher(tete);
    printf("\nRecherche du contact 'Rakoto':\n");
    afficherContact(recherche(tete,"Rakoto"));
    down(tete,flux);
    fclose(flux);
    libereListe(tete);
    return 0;
}

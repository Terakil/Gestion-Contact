#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"
#include "Tri.h"
int main() {

    FILE *flux = fopen("liste.txt","w");
    if (flux == NULL) {
        printf("Le fichier n'a pas pu etre ouvert");
        return 1;
    }
    contact* tete = NULL;
    char nom[50]="Ter";
    char contact[20]="+2611212121";
    tete=ajoutNoeud(tete,nom,contact);
    tete=ajoutNoeud(tete,"You",contact);
    tete=ajoutNoeud(tete,"Rakoto","+23464564645444");
    tete=ajoutNoeud(tete,"Aro","+23464564645444");
    tete=ajoutNoeud(tete,"Tsikiniaina","+23464564645444");
    tri(&tete);
    afficher(tete);
    down(tete,flux);
    fclose(flux);
    libereListe(tete);
    return 0;
}

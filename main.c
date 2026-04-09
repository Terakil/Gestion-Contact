#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"

int main() {
    FILE *flux = fopen("liste","w");
    contact* tete = NULL;
    char nom[50]="Ter";
    char contact[20]="+2611212121";
    tete=ajoutNoeud(tete,nom,contact);
    tete=ajoutNoeud(tete,"You",contact);
    afficher(tete);
    tete=supprimer(tete,nom);
    afficher(tete);
    down(tete,flux);
    free(tete);
    return 0;
}

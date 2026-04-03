#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"

int main() {
    contact* tete = NULL;
    char nom[50]="Ter";
    char contact[20]="+2611212121";
    tete=ajoutNoeud(tete,nom,contact);
    tete=ajoutNoeud(tete,"You",contact);
    afficher(tete);
    tete=supprimer(tete,nom);
    afficher(tete);
    free(tete);
    return 0;
}

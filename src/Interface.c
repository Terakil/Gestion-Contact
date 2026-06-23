#include<stdio.h>
#include <stdlib.h>
#include<../include/Interface.h>

#include "Contact.h"

void init(noeud *tete) {
    int choice;
    printf("====================================================================\n");
    printf("                        CONTACT GESTION                             \n");
    printf("====================================================================\n");

    printf("                        Action à faire                              \n");
    printf("1.Add      2.Remove     3.Show Contact      4.Down as .txt");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            add(tete);
            break;
        case 2:
            removeContact(tete);
        default:
            exit(1);
    }



}

int add(struct Noeud *tete) {
    char *nom;
    char *num;
    printf("Entrer le nom a ajouter");
    if (scanf("%s",&nom)!=1)
        return EXIT_FAILURE;
    printf("Entrer le numero");
    if (scanf("%s",&num)!=1)
        return EXIT_FAILURE;
    ajoutNoeud(tete,nom,num);
}
int removeContact(noeud *tete) {
    char *nom;
    printf("Entrer le nom du contact a supprimer");
    if (scanf("%s",&nom)!=1)
        return EXIT_FAILURE;
    supprimer(tete,nom);
}

#include<stdio.h>
#include <stdlib.h>
#include "../include/Interface.h"
#include "../include/Contact.h"

int init(noeud **tete) {
    int select;
    printf("====================================================================\n");
    printf("                        CONTACT GESTION                             \n");
    printf("====================================================================\n");

    printf("                        Action à faire                              \n");
    printf("1.Add      2.Remove     3.Show Contact      4.Down as .txt\n");
    if ((scanf("%d",&select))!=1) {
        printf("invalide");
        return 1;
    };
    switch (select) {
        case 1:
            add(tete);
            break;
        case 2:
            removeContact(tete);
            break;
        default:
            exit(1);
    }
    return 0;
}
    noeud* add(struct Noeud **tete) {
        char *nom=malloc(50*sizeof(char));
        char *num=malloc(50*sizeof(char));
        printf("Entrer le nom a ajouter\n");
        scanf("%s",nom);
        printf("Entrer le numero\n");
        scanf("%s",num);
        *tete=ajoutNoeud(*tete,nom,num);
        return *tete;
}
void removeContact(noeud **tete) {
    char *nom=malloc(50*sizeof(char));
    printf("Entrer le nom du contact a supprimer");
    scanf("%s",nom);
    supprimer(*tete,nom);
    printf("Success");
}

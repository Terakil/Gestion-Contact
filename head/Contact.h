#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H
#include <stdio.h>
typedef struct Contact{
    char name[50];
    char tel[20];
}contact;
typedef struct Noeud{
    contact data;
    struct Noeud* suivant;
}noeud;

//Prototype
noeud* creerNoeud(char name[],char tel[]);
noeud* ajoutNoeud(noeud* tete,char nom[],char phone[]);
noeud* depiler(noeud* tete);
noeud* supprimer(noeud* tete,char nom[]);
noeud* getContact(noeud* tete,char nom[]);
void down(noeud* tete,FILE* flux);
void afficher(noeud* tete);
void libereListe(noeud  * tete);
#endif //CONTACT_CONTACT_H
#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H
typedef struct Contact{
    char name[50];
    char tel[20];
    struct Contact* suivant;
}contact;

//Prototype
contact* creerNoeud(char name[],char tel[]);
contact* ajoutNoeud(contact* tete,char nom[],char phone[]);
contact* depiler(contact* tete);
contact* supprimer(contact* tete,char nom[]);
contact* getContact(contact* tete,char nom[]);
void tri(contact** tete);
void down(contact* tete,FILE* flux);
void afficher(contact* tete);
void libereListe(contact* tete);
#endif //CONTACT_CONTACT_H
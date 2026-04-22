#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Contact.h"
//Creation noeud
noeud* creerNoeud(char name[],char tel[]) {
    noeud* nouveauNoeud = (noeud*)malloc(sizeof(noeud));
    if (!nouveauNoeud) {
        printf("Erreur d'allocation!!");
        exit(1);
    }
    strcpy(nouveauNoeud->data.name,name);
    strcpy(nouveauNoeud->data.tel,tel);
    nouveauNoeud->suivant=NULL;
    return nouveauNoeud;
}
//liberation de la liste
void libereListe(noeud* tete) {
    noeud* tmp=tete;
    while (tmp!=NULL) {
        tete=tete->suivant;
        free(tmp);
        tmp=tete;
    }
    tete=NULL;
}
//Ajout liste noeud
noeud* ajoutNoeud(noeud* tete,char nom[],char phone[]) {
    noeud *nouveauNoeud = creerNoeud(nom, phone);
    nouveauNoeud->suivant=tete;
    return nouveauNoeud;
}


//Enlever tete de liste
noeud* depiler(noeud* tete) {
    if (tete==NULL) {
        printf("Liste vide");
        exit (1);
    }
    char* nom=malloc(50*sizeof(char));
    noeud* tmp = tete;
    strcpy(nom,tmp->data.name);
    tete=tete->suivant;
    printf("%s a ete depiler\n",nom);
    free(nom);
    free(tmp);
    return tete;
}

/**
 *
 * @param {noeud}tete
 * @param {char}nom
 * @return {noeud}
 */

//supprimer noeud
noeud* supprimer(noeud* tete,char nom[]) {
    if (strcmp(tete->data.name,nom)==0) {
        return depiler(tete);
    }
    noeud* prec=tete;
    noeud* tmp=tete->suivant;
    char *tab=malloc(50*sizeof(char));
    while(tmp!=NULL) {
        if (strcmp(nom,tmp->data.name)==0) {
            strcpy(tab,tmp->data.name);
            prec->suivant=tmp->suivant;
            printf("%s a ete supprimer de la liste\n",tab);
            free(tmp);
            return tete;
        }
        prec=tmp;
        tmp=tmp->suivant;
    }
    return tete;
}
//avoir noeud
noeud* getContact(noeud* tete,char nom[]) {
    if (tete==NULL) {
        printf("Liste Vide");
        return NULL;
    }
    noeud* tmp=tete;
    while (tmp!=NULL) {
        if (strcmp(tmp->data.name, nom) == 0) {
            return tmp;
        }
        tmp=tmp->suivant;
    }
    return NULL;
}

//mettre les contacts dans un fichier .txt
void down(noeud* tete,FILE *flux) {
    if (tete==NULL) {
        fprintf(flux,"Liste vide");
        return;
    }
    noeud* tmp=tete;
    while (tmp!=NULL) {
        fprintf(flux,"||Nom :%25s==Contact: %15s||\n",tmp->data.name,tmp->data.tel);
        tmp=tmp->suivant;
    }
}
//affichage des contacts
void afficher(noeud* tete) {
    if (tete==NULL) {
        printf("Liste vide");
        return;
    }
    noeud* tmp=tete;
    while (tmp!=NULL) {
        printf("||Nom :%25s == Contact: %14s||\n",tmp->data.name,tmp->data.tel);
        tmp=tmp->suivant;
    }
}
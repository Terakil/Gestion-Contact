#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
//Creation contact
contact* creerNoeud(char name[],char tel[]) {
    contact* nouveauNoeud = (contact*)malloc(sizeof(contact));
    if (!nouveauNoeud) {
        printf("Erreur d'allocation!!");
        exit(1);
    }
    strcpy(nouveauNoeud->name,name);
    strcpy(nouveauNoeud->tel,tel);
    nouveauNoeud->suivant=NULL;
    return nouveauNoeud;
}
//liberation de la liste
void libereListe(contact* tete) {
    contact* tmp=tete;
    while (tmp!=NULL) {
        tete=tete->suivant;
        free(tmp);
        tmp=tete;
    }
    tete=NULL;
}
//Ajout liste contact
contact* ajoutNoeud(contact* tete,char nom[],char phone[]) {
    contact *nouveauNoeud = creerNoeud(nom, phone);
    nouveauNoeud->suivant=tete;
    return nouveauNoeud;
}


//Enlever tete de liste
contact* depiler(contact* tete) {
    if (tete==NULL) {
        printf("Liste vide");
        exit (1);
    }
    char* nom=malloc(50*sizeof(char));
    contact* tmp = tete;
    strcpy(nom,tmp->name);
    tete=tete->suivant;
    printf("%s a ete depiler\n",nom);
    free(nom);
    free(tmp);
    return tete;
}

/**
 *
 * @param {contact}tete
 * @param {char}nom
 * @return {contact}
 */

//supprimer contact
contact* supprimer(contact* tete,char nom[]) {
    if (strcmp(tete->name,nom)==0) {
        return depiler(tete);
    }
    contact* prec=tete;
    contact* tmp=tete->suivant;
    char *tab=malloc(50*sizeof(char));
    while(tmp!=NULL) {
        if (strcmp(nom,tmp->name)==0) {
            strcpy(tab,tmp->name);
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
//avoir contact
contact* getContact(contact* tete,char nom[]) {
    if (tete==NULL) {
        printf("Liste Vide");
        return NULL;
    }
    contact* tmp=tete;
    while (tmp!=NULL) {
        if (strcmp(tmp->name, nom) == 0) {
            return tmp;
        }
        tmp=tmp->suivant;
    }
    return NULL;
}

//mettre les contact dans un fichier .txt
void down(contact* tete,FILE *flux) {
    if (tete==NULL) {
        fprintf(flux,"Liste vide");
        return;
    }
    contact* tmp=tete;
    while (tmp!=NULL) {
        fprintf(flux,"||Nom :%s==Contact: %s||\n",tmp->name,tmp->tel);
        tmp=tmp->suivant;
    }
}
//affichage des contacts
void afficher(contact* tete) {
    if (tete==NULL) {
        printf("Liste vide");
        return;
    }
    contact* tmp=tete;
    while (tmp!=NULL) {
        printf("||Nom :%s==Contact: %s||\n",tmp->name,tmp->tel);
        tmp=tmp->suivant;
    }
}

/*--------------------------------------------------------------------------------
                                    ALGO DE TRI
 --------------------------------------------------------------------------------*/

//Division de la liste en 2
void divList(contact* tete,contact** a,contact** b){
    contact* lent=tete;
    contact* rapide=tete->suivant;

    while (rapide!=NULL) {
        rapide=rapide->suivant;
        if (rapide!=NULL) {
            lent=lent->suivant;
            rapide=rapide->suivant;
        }
    }
    *a=tete;
    *b=lent->suivant;
    lent->suivant=NULL;
}

//fusion trié
contact* fuse(contact*a ,contact* b) {
    if (a == NULL)return b;
    if (b == NULL)return a;

    contact* resultat=NULL;
    if (strcmp(a->name,b->name)<=0) {
        resultat=a;
        resultat->suivant=fuse(a->suivant,b);
    }else {
        resultat=b;
        resultat->suivant=fuse(a,b->suivant);
    }
    return resultat;
}

//Tri en entier

void tri(contact** tete) {
    contact* tmp=*tete;

    if (tmp==NULL || tmp->suivant==NULL)
        return;
    contact* a;
    contact* b;

    divList(*tete,&a,&b);

    tri(&a);
    tri(&b);

    *tete=fuse(a,b);
}
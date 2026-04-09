#include <stdlib.h>
#include <string.h>
#include "contact.h"

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
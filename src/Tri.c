#include <stdlib.h>
#include <string.h>
#include "../include/Contact.h"

/*--------------------------------------------------------------------------------
                                    ALGO DE TRI
 --------------------------------------------------------------------------------*/

//Division de la liste en 2
void divList(noeud* tete,noeud** a,noeud** b){
    noeud* lent=tete;
    noeud* rapide=tete->suivant;

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
noeud* fuse(noeud*a ,noeud* b) {
    if (a == NULL)return b;
    if (b == NULL)return a;

    noeud* resultat=NULL;
    if (strcmp(a->data.name,b->data.name)<=0) {
        resultat=a;
        resultat->suivant=fuse(a->suivant,b);
    }else {
        resultat=b;
        resultat->suivant=fuse(a,b->suivant);
    }
    return resultat;
}

//Tri en entier

void tri(noeud** tete) {
    noeud* tmp=*tete;

    if (tmp==NULL || tmp->suivant==NULL)
        return;
    noeud* a;
    noeud* b;

    divList(*tete,&a,&b);

    tri(&a);
    tri(&b);

    *tete=fuse(a,b);
}
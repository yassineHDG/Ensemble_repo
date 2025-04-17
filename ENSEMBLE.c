#include <stdio.h>
#include <stdlib.h>

// Structure de base d'un élément de liste chaînée
typedef struct Element {
    int donnee;
    struct Element* suiv;
} Element;

// Fonction pour créer un nouvel élément et l'ajouter en tête de liste
Element* inserer(Element* L, int x) {
    Element* nouveauElement = (Element*)malloc(sizeof(Element));
    nouveauElement->donnee = x;
    nouveauElement->suiv = L;
    L = nouveauElement ;
    return L;
}

// Fonction pour afficher une liste chaînée
void afficher(Element* L) {
    Element* tmp = L;
    while (tmp != NULL) {
        printf("%d ", tmp->donnee);
        tmp = tmp->suiv;
    }
    printf("\n");
}

// Fonction pour rechercher un élément dans une liste chaînée
int chercher(Element* L, int x) {
    Element* tmp = L;
    while (tmp != NULL) {
        if (tmp->donnee == x)
            return 1; // Élément trouvé
        tmp = tmp->suiv;
    }
    return 0; // Élément non trouvé
}

// Fonction pour trouver l'union de deux ensembles
Element* trouver_union(Element* A, Element* B) {
    Element *resultat = NULL, *tmp1 = A, *tmp2 = B;

    // Parcourir le premier ensemble
    while (tmp1 != NULL) {
        if (chercher(resultat, tmp1->donnee)==0) resultat = inserer(resultat, tmp1->donnee);
        tmp1 = tmp1->suiv;
    }

    // Parcourir le deuxième ensemble
    while (tmp2 != NULL) {
        if (chercher(resultat, tmp2->donnee)==0) resultat = inserer(resultat, tmp2->donnee);
		tmp2 = tmp2->suiv;
    }

    return resultat;
}

// Fonction pour trouver l'intersection de deux ensembles
Element* trouver_intersection(Element* A, Element* B) {
    Element *resultat = NULL, *tmp1 = A;

    // Parcourir le premier ensemble
    while (tmp1 != NULL) {
        if (chercher(B, tmp1->donnee)==1) resultat = inserer(resultat, tmp1->donnee);
        tmp1 = tmp1->suiv;
    }

    return resultat;
}

// Fonction pour trouver la différence entre deux ensembles
Element* trouver_difference(Element* A, Element* B) {
    Element *resultat = NULL, *tmp1 = A;
    // Parcourir le premier ensemble
    while (tmp1 != NULL) {
        if (chercher(B, tmp1->donnee)==0) resultat = inserer(resultat, tmp1->donnee);
        tmp1 = tmp1->suiv;
    }

    return resultat;
}

// Fonction pour trouver la différence symétrique de deux ensembles
Element* trouver_difference_symetrique(Element* A, Element* B) {
    Element *resultat = NULL, *tmp1 = A, *tmp2 = B;

    // Parcourir le premier ensemble
    while (tmp1 != NULL) {
        if (chercher(B, tmp1->donnee)==0) resultat = inserer(resultat, tmp1->donnee);
        tmp1 = tmp1->suiv;
    }

    // Parcourir le deuxième ensemble
    while (tmp2 != NULL) {
        if (chercher(A, tmp2->donnee)==0) resultat = inserer(resultat, tmp2->donnee);
        tmp2 = tmp2->suiv;
    }

    return resultat;
}

int main() {
   
Element* A = NULL;
    Element* B = NULL;	
	int n1,n2,x,i,choix;
	
	menu:
printf("\n----------------------- MENU -----------------------------\n");
// Créer un menu pour tester les différents traitements décrits dans l'exercice
printf("\t1.Insertion des elements dans les ensembles A et B\n");
printf("\t2.Affichage des ensembles apres insertion des elements\n");
printf("\t3.Union des Ensembles A et B \n");
printf("\t4.Intersection des ensembles A et B\n");
printf("\t5.Difference des ensembles A et B\n");
printf("\t6.Difference symetriques des ensembles A et B\n");
printf("\t0.finir le programme\n");
printf("\n * Choix: ");

scanf("%d", &choix);
switch (choix){
	
	
	
case 1:// Insérer des éléments dans les ensembles
    
	printf("entrer des valeurs pour l ensemble A:\n ");
    printf("entrer le nombre de valeur a inserer\n ");
    do{
    	scanf("%d",&n1);
    	if(n1<=0) printf("entrer un nombre superieur a 0");
	}while(n1<=0);
    
	for(i=0;i<n1;i++)
    {
    	printf("entrer la valeurs %d :",i+1);
    	scanf("%d",&x);
    	A = inserer(A,x);
	}
	
    
	
	printf("entrer des valeurs pour l ensemble B :\n ");
    printf("entrer le nombre de valeur a inserer\n ");
    do{
    	scanf("%d",&n2);
    	if(n2<=0) printf("entrer un nombre superieur a 0");
	}while(n2<=0);
    for(i=0;i<n2;i++)
    {
    	printf("entrer la valeurs %d :",i+1);
    	scanf("%d",&x);
    	B = inserer(B,x);
	}
break;
        
    
case 2 :// Afficher les ensembles
    printf("Ensemble A: ");
    afficher(A);
    printf("Ensemble B: ");
    afficher(B);
break;

    
case 3 :    
	printf("Union: ");
    afficher(trouver_union(A, B));
break;

case 4:    
    printf("Intersection: ");
    afficher(trouver_intersection(A, B));
break;
    
case 5 :
    printf("Difference: ");
    afficher(trouver_difference(A, B));
break;
    
case 6:
    printf("Difference symetrique: ");
    afficher(trouver_difference_symetrique(A, B));
break;

case 0 :
	printf("le programme est termine");
	goto stop;
break;

default : printf("le choix est non valide\n");
}
 goto menu;
 stop:   
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define VIDE 7
#define MAX 5			//Max de fils

				/*Arbre N-air*/
//structure du noeud
struct Noeud
{
  char cle;
  struct Noeud *fils[MAX];
};

//creer un nouveau noeud
struct Noeud * newNoeud(char cle)
{
	struct Noeud* temp = (struct Noeud*)malloc(sizeof(struct Noeud));
	temp->cle = cle;

	for(int i = 0; i < MAX; i++)	temp->fils[i] = NULL;
	return (temp);
}

//creer un arbre n-air
struct Noeud *creerForet()
{
		struct Noeud *racine = newNoeud('A');
		racine->fils[0] = newNoeud('B');
	    racine->fils[1] = newNoeud('C');
	    racine->fils[2] = newNoeud('D');
	    racine->fils[0]->fils[0] = newNoeud('E');
	    racine->fils[0]->fils[1] = newNoeud('F');
	    racine->fils[2]->fils[0] = newNoeud('G');
	    racine->fils[2]->fils[1] = newNoeud('H');
	    racine->fils[2]->fils[2] = newNoeud('I');
	    racine->fils[2]->fils[3] = newNoeud('J');
        racine->fils[0]->fils[1]->fils[0] = newNoeud('K');
	    return racine;
}
			/*Arbre n-air*/


			///*afficher arbre bianire*///
void AfficherBinaireU(struct Noeud *racine, int espace)
{
    if (racine == NULL)   return; 					
    espace += VIDE;  								//  augmenter la distance entre les niveaux

    AfficherBinaire(racine->fils[1], espace); 		// Process fils[1] premier fils

    printf("\n");    							// afficher le noeud courrent apres espace
    for (int i = VIDE; i < espace; i++) 		//pour l'espace
        printf(" ");
    printf("%c\n", racine->cle);

    AfficherBinaire(racine->fils[0], espace);   	// Process fils[0]
}

void AfficherBinaire(struct Noeud *racine)
{
   AfficherBinaireU(racine, 0); 					 // Passer espace a 0
}
			/*affichage arbre binaire */


//nombre de fils
int nb_fils(struct Noeud *racine)
{	int nb = 0;
	int i = 0;
    while(racine->fils[i] != NULL)
    {	nb++;						//pour nombre de fils
		i++;						//pour la boucle While
	}
	return nb;
}

					///*converteur n-air to Binaire*///
struct Noeud *convert(struct Noeud *racine)
{	
	if(racine == NULL)	return;

	struct Noeud *Bracine = newNoeud(racine->cle);				//noeud pour l arbre binaire dont Bracine sera la tete final de l'arbre
																
	if(racine->fils[0] == NULL)	return Bracine;

	int nbFils = nb_fils(racine);							//nombre de fils du noeud
	struct Noeud *curr = Bracine;								//pointer curr pour arbre Binaire

	int i = 0;									//i pour la boucle while
	while(i < nbFils)
		{
			struct Noeud *filsCurr = convert(racine->fils[i]);		//pointer le noeud "racine->fils[i]" de l'arbre n-air
			if(i == 0){
						curr->fils[0] = filsCurr;					//filsCurr sera le fils gauche
						curr = curr->fils[0];						//decalage du pointeur curr
					  }

			else	 {
						curr->fils[1] = filsCurr;					//filsCurr sera le fils droite
						curr = curr->fils[1];						//decalage du pointeur curr
					 }
			i++;
		}

	return Bracine;							//return l'arbre binaire presque nouveau 
}
				///*fin fonciton*///


int main()
{
	struct Noeud *racine = creerForet();				//creer arbre n-air
	struct Noeud *Bracine = convert(racine);

	AfficherBinaire(Bracine);

}



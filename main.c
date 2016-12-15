#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gene.h"
#include "Humain.h"

//CONFIG
#define DEBUG_MODE 0

#define PI 3.141592

#define X 0
#define Y 1



/*typedef struct {
	long double r; //radius
	int yeuxB;
	int yeuxV;
	int yeuxM;
} Universe;

void grow(Universe* uni) {
	uni->r *= PI;
}

void fillWorld(Universe* uni) {
	double i;
	int n;
	srand(time(NULL));

	for(i = 0; i < uni->r; ++i) {
		n = rand() % 3;
		printf("Elément numéro %.0lf : %d\n", i, n);
		switch(n) {
			case 0 :
				printf("YEUX BLEUS\n");
				uni->yeuxB++;
			break;
			case 1 :
				printf("YEUX VERTS\n");
				uni->yeuxV++;
			break;
			case 2 :
				printf("YEUX MARRONS\n");
				uni->yeuxM++;
			break;
		}
	}
}*/

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Gene sexeh;
	Gene sexef;
	Humain adam;
	Humain eve;
	Humain martin;

	if(DEBUG_MODE) printf("Création du sexe homme ... liste des allèles : X, Y\n");
	sexeh.setAlleleL(X);
	sexeh.setAlleleR(Y);

	if(DEBUG_MODE) printf("Création du sexe femme ... liste des allèles : X, X\n");
	sexef.setAlleleL(X);
	sexef.setAlleleR(X);

	printf("CREATION de ADAM avec SEXE HOMME\n");
	adam.setNextGene(sexeh);
	printf("CREATION de EVE avec SEXE FEMME\n");
	eve.setNextGene(sexef);

	printf("CREATION DE MARTIN à partir de REPRODUCTION de EVE par ADAM\n");
	martin = eve.reproduce(&adam);

	if(DEBUG_MODE) printf("AFFICHAGE de GENE SEXUEL de MARTIN\n");
	if(DEBUG_MODE) martin.printGene(0);

	printf("AFFICHAGE de SEXE de MARTIN : ");
	martin.printSexe();

	printf("\n");

	printf("GENERATION de POPULATION de TAILLE = 50\n");
	printf("\tà partir de : REPRODUCTION de EVE par ADAM\n");
	printf("\tgènes testés : SEXE");

	int i;
	int hommes = 0, femmes = 0;
	Humain* males[50];
	Humain* females[50];
	Humain firstHumans[50];

	for (i = 0; i < 50; ++i)
	{
		if(DEBUG_MODE) printf("GENERATION HUMAIN N°%d ...\n", i);
		firstHumans[i] = eve.reproduce(&adam);
		if(DEBUG_MODE) printf("SEXE : ");
		firstHumans[i].printSexe();
		if(DEBUG_MODE) printf("\n");
		if(firstHumans[i].genes[0].speaking() == 1) {
			males[hommes] = &firstHumans[i];
			hommes++;
		}
		else {
			females[femmes] = &firstHumans[i];
			femmes++;
		}
	}

	printf("\n\nFIN de GENERATION\nBILAN :\n\t%d HOMMES\n\t%d FEMMES\n", hommes, femmes);

	int n;
	int gen = 2;
	Humain generations[50][50];
	int newHomme = 0;;
	int newFemme = 0;

	for (i=0; i < femmes; ++i)
	{
		n = rand() % hommes;
		if(DEBUG_MODE) printf("FEMME N°%d SE REPRODUIT AVEC HOMME N°%d\n", i, n);
		generations[gen][i] = females[i]->reproduce(males[n]);
		if(DEBUG_MODE) printf("CREATION de N°%d (GENERATION : %d) SEXE : ", i , gen);
		generations[gen][i].printSexe();
		if(DEBUG_MODE) printf("\n");
		if(generations[gen][i].genes[0].speaking() == 1) {
			newHomme++;
		}
		else {
			newFemme++;
		}
	}
	printf("NOUVEAUX HOMMES : %d\nNOUVELLES FEMMES : %d\n", newHomme, newFemme);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Gene.h"
#include "Humain.h"

//CONFIG
#define DEBUG_MODE 1

#define CHILD_PER_FEMALE 2

#define PI 3.141592

#define X 0
#define Y 1

/*

README :

Le but de ce programme est en fait de recréer le principe
d'évolution au niveau microscopique par rapport au temps (à échelle humaine)
et de voir de quelle manière les hommes sont ammenés à évoluer.
A terme, et dans une optique où les objectifs seraient atteints, ce programme
pourrait permettre de visualiser certaines possibilités d'évolution de notre
société dans le futur avec précision.

*/

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
	time_t timer_start, timer_before, timer_now, timer_end; //un timer
	double duree = 0;

	srand(time(NULL)); //pour le rand()


	Gene sexeh; // Création du gène sexe homme, on lui assignera X et Y comme allèles (Y étant dominant)
	Gene sexef; // Création du gène sexe femme, .. X et X
	//Gene noir;
	//Gene blanc;
	//Gene brun;
	//Gene blond;
	Humain adam; // Création des deux premiers humains (aucun lien religieux ou théologique pour leurs noms)
	Humain eve;
	Humain martin;

	if(DEBUG_MODE) printf("Création du sexe homme ... liste des allèles : X, Y\n");
	sexeh.setAlleleL(X); //ici on set l'allèle gauche sur X (0)
	sexeh.setAlleleR(Y); // et ici l'allèle droit sur Y (1)

	if(DEBUG_MODE) printf("Création du sexe femme ... liste des allèles : X, X\n");
	sexef.setAlleleL(X);
	sexef.setAlleleR(X);

	/*if(DEBUG_MODE) printf("CREATION de GENE -> NOIR ... liste des allèles : N, N\n");
	sexef.setAlleleL(1);
	sexef.setAlleleR(1);

	if(DEBUG_MODE) printf("CREATION de GENE -> BLANC ... liste des allèles : B, B\n");
	sexef.setAlleleL(0);
	sexef.setAlleleR(0);*/

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

	/*printf("\n");

	printf("GENERATION de POPULATION de TAILLE = 50\n");
	printf("\tà partir de : REPRODUCTION de EVE par ADAM\n");
	printf("\tgènes testés : SEXE");*/

	int i;
	unsigned long long int hommes = 0, femmes = 0;
	/*Humain* males[500000];
	Humain* females[500000];
	Humain firstHumans[5000];*/	

	/*for (i = 0; i < 50; ++i)
	{
		if(DEBUG_MODE) printf("GENERATION HUMAIN N°%d ...\n", i);
		firstHumans[i] = eve.reproduce(&adam);
		if(DEBUG_MODE) printf("SEXE : ");
		if(DEBUG_MODE) firstHumans[i].printSexe();
		if(DEBUG_MODE) printf("\n");
		if(firstHumans[i].genes[0].speaking() == 1) {
			males[hommes] = &firstHumans[i];
			hommes++;
		}
		else {
			females[femmes] = &firstHumans[i];
			femmes++;
		}
	}*/

	printf("\n\nFIN de GENERATION\nBILAN :\n\t%llu HOMMES\n\t%llu FEMMES\n", hommes, femmes);

	//Teste si Adam est mon père
	printf("martin.isMyParent(&adam) = %d", martin.isMyParent(&adam));

	int n;
	int child = 0;
	int gen = 0;
	const int genMax = 50;
	//Humain generations[50][50];

	int done = 0;
	unsigned long long int newHomme = 0;
	unsigned long long int newFemme = 0;
	printf("Début de la création de %d génération ...\nTIMER = NOW\n", genMax);
	time(&timer_start);
	Humain baby;

	for(gen = 0; gen <= genMax; gen++) {
		time(&timer_before);
		for(done = 0; done <= femmes; done++) {
			baby.createFromReproduce(&eve, &adam);
			baby.printGene(0);
			if (baby.genes[0].speaking() == 1)
				newHomme++;
			else
				newFemme++;
		}
		time(&timer_now);
		femmes += newFemme;
		hommes += newHomme;
		printf("==============GENERATION %d=============\n", gen);
		printf("%llu FEMMES (nouveaux : %llu) \n", femmes, newFemme);
		printf("%llu HOMMES (nouveaux : %llu) \n", hommes, newHomme);
		printf("TOTAL NOUVEAUX HUMAINS : %llu\n", femmes+hommes);
		printf("DUREE : %.fs (total : %.fs) \n", difftime(timer_now, timer_before), difftime(timer_now, timer_start));
		printf("========================================\n");
		newFemme = 0;
		newHomme = 0;	
	}
	gen--;
	time(&timer_end);
	duree = difftime(timer_end, timer_start);

	printf("%llu humain (%d générations) générés en %.lf secondes.\n%llu femmes et %llu hommes ont été générés.\n",femmes+hommes, gen, duree, femmes, hommes);
	if(DEBUG_MODE) printf("= %llu millions environ\n", (femmes+hommes)/1000000);
	/* Boucle : génération de générations
	for (gen = 2; gen <= 2; ++gen)
	{

		for (i=0; i < femmes; ++i)
		{
			for(child = 0; child < CHILD_PER_FEMALE; child++) 
			{
				n = rand() % hommes;
				if(DEBUG_MODE) printf("FEMME N°%d SE REPRODUIT AVEC HOMME N°%d\n", i, n);
				generations[gen][i].createFromReproduce(females[i],males[n]);
				if(DEBUG_MODE) printf("CREATION de N°%d (GENERATION : %d) SEXE : ", i , gen);
				if(DEBUG_MODE) generations[gen][i].printSexe();
				if(DEBUG_MODE) printf("\n");
				if(generations[gen][i].genes[0].speaking() == 1) {
					//males[hommes+newHomme] = &generations[gen][i];
					newHomme++;
				}
				else {
					//females[femmes+newFemme] = &generations[gen][i];
					newFemme++;
				}
			}
		}
		hommes+=newHomme;
		femmes+=newFemme;
		printf("NOUVEAUX HOMMES : %d, NOUVELLES FEMMES : %d, TOTAL HOMMES : %d, TOTAL FEMMES : %d\n", newHomme, newFemme, hommes, femmes);
		newHomme = 0;
		newFemme = 0;
	} Fin boucle génération*/
	return 0;
}











/* FIN */
/* Le 19/12/16 : Génération de environ 50M d'humains en 5 secondes (5* paris) (génération 40)
Génération de 6MM (milliards) en 350 sec (génération 50) (précision 50.00088~)
Génération de 87MM en 5570 sec (43845550478f; 43847180493h) précision (49.99907~)

*/
/* Observations :
 - [conditions] S'il n'y a pas de restriction concernant le choix des individus
 	lors d'une reproduction (pas de limitation au couple ou de protection des couples), alors
 	le nombre d'hommes a une importance fortement négligeable si le but est d'assurer
 	une expansion de la population mondiale sur une longue période.

 	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <jansson.h>

#include "Gene.h"
#include "Humain.h"
#include "GeneFile.h"

//CONFIG
#define DEBUG_MODE 1
#define GENES_PATH "genes.json"

#define GENMAX 40 // nombre de génération à créer
#define INIT_POP_TAILLE 20 // taille de population initiale
#define CHILD_PER_FEMALE 2

#define PI 3.141592


//Valeur gènes
//{GENE}_{ALLELE}


/*

README :

Le but de ce programme est en fait de recréer le principe
d'évolution au niveau microscopique par rapport au temps (à échelle humaine)
et de voir de quelle manière les hommes sont ammenés à évoluer.
A terme, et dans une optique où les objectifs seraient atteints, ce programme
pourrait permettre de visualiser certaines possibilités d'évolution de notre
société dans le futur avec précision.

*/


int main(int argc, char const *argv[])
{
	time_t timer_start, timer_before, timer_now, timer_end; //un timer
	unsigned int i, j, n;
	unsigned int rand1, rand2;
	unsigned long long int hommes = 0, femmes = 0;
	double duree = 0;

	srand(time(NULL)); //pour le rand()

	//Population
	Humain populationInitiale[INIT_POP_TAILLE];
	GeneFile genefichier;

	char path[] = "genes.json";
	genefichier.open(path);

	//Creation des differents genes generiques

	//Création du gène sexe homme, on lui assignera X et Y comme allèles (Y étant dominant)
	//Création du gène sexe femme, .. X et X
	unsigned int nbrGenes[GENOME_LENGTH] = {2,2};
	Gene sexe[2];
	Gene sexe_homme, sexe_femme;
	//Gene couleur de peau
	Gene couleur_peau[2];
	Gene couleur_noir, couleur_blanc;
	//Gene brun;
	//Gene blond;

	Gene genome_entier[GENOME_LENGTH][50];

/*

	if(DEBUG_MODE) printf("Création du sexe homme ... liste des allèles : X, Y\n");
	sexe_homme.setAlleleL(X); //ici on set l'allèle gauche sur X (0)
	sexe_homme.setAlleleR(Y); // et ici l'allèle droit sur Y (1)

	if(DEBUG_MODE) printf("Création du sexe femme ... liste des allèles : X, X\n");
	sexe_femme.setAlleleL(X);
	sexe_femme.setAlleleR(X);

	if(DEBUG_MODE) printf("CREATION de GENE -> NOIR ... liste des allèles : N, N\n");
	couleur_noir.setAlleleL(1);
	couleur_noir.setAlleleR(1);

	if(DEBUG_MODE) printf("CREATION de GENE -> BLANC ... liste des allèles : B, B\n");
	couleur_blanc.setAlleleL(0);
	couleur_blanc.setAlleleR(0);

	printf("ASSIGNATION des GENES à leur TYPE\n");

	sexe[0] = sexe_homme;
	sexe[1] = sexe_femme;

	couleur_peau[0] = couleur_noir;
	couleur_peau[1] = couleur_blanc;
	
	for (j = 0; j < nbrGenes[i]; ++j)
	{
		genome_entier[0][j] = sexe[j];
	}
	for (j = 0; j < nbrGenes[i]; ++j)
	{
		genome_entier[0][j] = couleur_peau[j];
	}


	printf("GENERATION ALEATOIRE de POPULATION INITIALE (TAILLE %d)\n", INIT_POP_TAILLE);

	for (i = 0; i < INIT_POP_TAILLE; ++i)
	{
		for (j = 0; j < GENOME_LENGTH; ++j)
		{
			n = rand() % nbrGenes[i];
			populationInitiale[i].setNextGene(genome_entier[j][n]);
		}
	}

	unsigned int child = 0;
	unsigned int gen = 0;

	unsigned int done = 0;
	unsigned long long int newHomme = 0;
	unsigned long long int newFemme = 0;
	printf("Début de la création de %d génération ...\nTIMER = NOW\n", GENMAX);
	time(&timer_start);
	Humain baby;

	for(gen = 0; gen <= GENMAX; gen++) {
		time(&timer_before);
		for(done = 0; done <= femmes; done++) {
			rand1 = rand() % femmes;
			rand2 = rand() % hommes;
			baby.createFromReproduce(&populationInitiale[rand1], &populationInitiale[rand2]);
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
	*/
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

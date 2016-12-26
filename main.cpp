#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include <time.h>

#include "GeneFile.h"
#include "Gene.h"
#include "Humain.h"

#define NBRHUMAINS 50000


void generatePopulation(unsigned long long int taille, Humain* tab, TypeGene* genome, unsigned long long int nombreGenes) {
	int i,j,n;

	printf("GENERATION de %llu HUMAINS ALEATOIRES.\n", taille);
	tab = (Humain*) malloc(sizeof(Humain) * taille);
	//

	for(i=0; i < NBRHUMAINS; i++) {
		printf("Création humain n°%d\n", i+1);
		for(j=0; j<nombreGenes; j++) { //Pour chaque emplacement de gènes
			tab[i].genes[j].setType(genome[j].type);
			n = rand() % genome[j].taille();
			tab[i].genes[j].setAlleleL(genome[j].getNumber(n));
			n = rand() % genome[j].taille();
			tab[i].genes[j].setAlleleR(genome[j].getNumber(n));
			tab[i].genes[j].sortAlleles();
			tab[i].printGene(j);
		}
	}
}

int main () {
	time_t t_start, t_end; //pour stocker le temps
	GeneFile fichierGene; //classe qui sert à traiter le fichier JSON des gènes
	TypeGene* genome; //contient l'intégralité des gènes possibles (uniformes)
	Humain* pop; //contenant la population initiale

	int i,j,n; //variables de parcours
	char path[] = "genes.json"; //path vers le fichier des gènes

	//On initialise le timer pour pouvoir obtenir la durée de traitement
	printf("Démarrage du timer\n");
	time(&t_start);

	//On utilise srand() pour les futurs nombres aléatoires
	srand(time(NULL));

	printf("On commence par lire la liste de gènes...\n");

	//On traite le fichier de genes
	fichierGene.open(path);
	fichierGene.read();
	fichierGene.parse();
	fichierGene.giveGeneList();

	//création des variables et tableaux utiles
	const unsigned long int nombreGenes = fichierGene.getNumberOfGenes();
	genome = (TypeGene*) malloc(sizeof(TypeGene) * nombreGenes);

	//Remplissage du génome
	for(i=0; i < nombreGenes; i++) {
		genome[i] = fichierGene.getTypeGene(i);
		genome[i].printTypeGene();
	}

	generatePopulation(NBRHUMAINS, pop, genome, nombreGenes);
	time(&t_end);
	double duree = difftime(t_end, t_start);
	printf("Durée : %f secondes\n", duree);

	return 0;
}
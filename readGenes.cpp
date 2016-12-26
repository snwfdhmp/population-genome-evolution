#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include <time.h>
#include "GeneFile.h"
#include "Gene.h"
#include "Humain.h"

#define NBRHUMAINS 500

int main () {
	srand(time(NULL));
	GeneFile fichierGene;
	TypeGene* genome;
	Humain pop[NBRHUMAINS];

	int i,j,n;
	char path[] = "genes.json";

	printf("On commence par lire la liste de gènes...\n");

	
	//TypeGene couleur;
	fichierGene.open(path);
	fichierGene.read();
	fichierGene.parse();
	fichierGene.giveGeneList();

	const unsigned long int nombreGenes = fichierGene.getNumberOfGenes();
	genome = (TypeGene*) malloc(sizeof(TypeGene) * nombreGenes);

	for(i=0; i < nombreGenes; i++) {
		genome[i] = fichierGene.getTypeGene(i);
		genome[i].printTypeGene();
	}

	printf("On va créer des humains aléatoires.\nNOMBRE d'HUMAINS CREES : %u\n", NBRHUMAINS);
	for(i=0; i < NBRHUMAINS; i++) {
		printf("Création humain n°%d\n", i);
		for(j=0; j<nombreGenes; j++) {
			pop[i].genes[j].setType(genome[j].type);
			n = rand() % genome[j].taille();
			pop[i].genes[j].setAlleleL(genome[j].getNumber(n));
			n = rand() % genome[j].taille();
			pop[i].genes[j].setAlleleR(genome[j].getNumber(n));
			pop[i].genes[j].sortAlleles();
			pop[i].printGene(j);
		}
	}

	return 0;
}
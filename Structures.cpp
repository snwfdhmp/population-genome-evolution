#include "Structures.h"
#include <stdio.h>
#include <stdlib.h>

TypeGene::TypeGene(unsigned long int initType, unsigned short int initPoss, unsigned short int* initAllelesPoss) {
	int i;
	type = initType;
	possibilites = initPoss;
	allelesPossibles = (unsigned short int*) malloc(sizeof(unsigned short int) * initPoss);
	for (i = 0; i < possibilites; ++i)
	{
		allelesPossibles[i] = initAllelesPoss[i];
	}
}

unsigned short int TypeGene::getNumber(unsigned short int n) {
	return allelesPossibles[n];
}
unsigned short int TypeGene::taille() {
	return possibilites;
}

void TypeGene::printTypeGene(){
	int i;
	printf("GENE N°%lu\nTAILLE : %u\nALLELES POSSIBLES : [", type, possibilites);
	for(i=0;i<possibilites;i++) {
		printf("%d", allelesPossibles[i]);
		if(i+1 < possibilites) {
			printf(", ");
		}
	}
	printf("]\n");
}

#include "Humain.h"
#include "Gene.h"
#include <stdio.h>


//sorter

//printer
void Humain::printGene(int i) {
	printf("Gene n°%d : TYPE %d ; DOMINANT : %d ; ALLELE_D : %d\n",i, genes[i].type, genes[i].speaking(), genes[i].alleleR());
}

void Humain::printSexe() {
	if(genes[0].speaking() == 1) {
		printf("HOMME");
	}
	else {
		printf("FEMME");
	}
}
//getter

//setter
int Humain::setNextGene(Gene g) {
	genes[lastGene+1] = g;
	lastGene++;
	return lastGene;
}

//Class Methods
Humain Humain::reproduce(Humain* pere) {
	int i;
	Humain child;
	for(i = 0; i <= lastGene; i++) {
		Gene childGene;
		int motherGenes[2];
		motherGenes[0] = genes[i].alleleL();
		motherGenes[1] = genes[i].alleleR();
		int fatherGenes[2];	
		fatherGenes[0] = pere->genes[i].alleleL();
		fatherGenes[1] = pere->genes[i].alleleR();
		childGene.createFromParents(motherGenes, fatherGenes); // parameters Mother[], Father[]
		child.setNextGene(childGene);
	}
	return child;
}

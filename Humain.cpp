#include "Humain.h"
#include "Gene.h"
#include <stdio.h>

//Creaters
Humain Humain::createFromReproduce(Humain* theMother, Humain* theFather) {
	lastGene=-1;
	int i;
	mother = theMother;
	father = theFather;
	for(i = 0; i <= theMother->lastGene; i++) {
		Gene childGene;
		/* Le code suivant est lisible, mais le code utilisé sera celui d'après car il est plus rapide 
		
		motherGenes[0] = theMother->genes[i].alleleL();
		motherGenes[1] = theMother->genes[i].alleleR();
		int fatherGenes[2];	
		fatherGenes[0] = theFather->genes[i].alleleL();
		fatherGenes[1] = theFather->genes[i].alleleR();
		childGene.createFromParents(motherGenes, fatherGenes); // parameters Mother[], Father[]*/
		int motherGenes[2] = {theMother->genes[i].alleleL(),theMother->genes[i].alleleR()};
		int fatherGenes[2] = {theFather->genes[i].alleleL(),theFather->genes[i].alleleR()};

		childGene.createFromParents(motherGenes, fatherGenes);
		setNextGene(childGene);
	}
	return *this;
}

//sorter




//printer
void Humain::printGene(int i) {
	printf("Gene n°%d : TYPE %s ; DOMINANT : %d ; ALLELE_D : %d\n", i, genes[i].type_string, genes[i].speaking(), genes[i].alleleR());
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



//tester
bool Humain::isMyParent(Humain* parent) {
		return ((father == parent) || (mother == parent));
	}



//Class Methods
Humain Humain::reproduce(Humain* pere) { //Fonction obsolète
	int i;
	Humain child; 

	child.mother = this;
	child.father = pere;

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

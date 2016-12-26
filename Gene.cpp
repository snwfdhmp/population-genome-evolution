#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gene.h"


//Sorter
void Gene::sortAlleles() {
	if(alleles[0] < alleles[1]) {
		int a = alleles[0];
		alleles[0] = alleles[1];
		alleles[1] = a;
	}
}

int Gene::speaking() {
	//sortAlleles();
	return alleles[0];
}

//Printer
void Gene::printAlleles() {
	printf("Alleles : %d et %d\n", alleleL(), alleleR());
}

//Getter
int Gene::alleleL(){
	return alleles[0];
}
int Gene::alleleR(){
	return alleles[1];
}

//Setter
void Gene::setAlleleL(int a) {
	alleles[0] = a;
	sortAlleles();
}
void Gene::setAlleleR(int a) {
	alleles[1] = a;
	sortAlleles();
}
void Gene::setType(int a) {
	type_id = a;
}

//Class Methods
int Gene::createFromParents(int geneM[2], int geneF[2]){
	int u,v;

	u = rand() % 2; //a random number
	v = rand() % 2; //another random number

	alleles[0] = geneM[u]; //give random between left and right of mother to its genome
	alleles[1] = geneF[v]; //give random between .. of father ..
	sortAlleles(); //sortAlleles
	return speaking(); //return the speaking
}

//Gene::Gene() {}
#include "Gene.h"


//Sorter
void Gene::sortAlleles() {
	if(alleles[0] > alleles[1]) {
		int a = alleles[0];
		alleles[0] = alleles[1];
		alleles[1] = a;
	}
}

int Gene::speaking() {
	sortAlleles();
	return alleles[0];
}

//Printer
void printAlleles() {
	printf("Alleles : %d et %d\n", yeux.alleles[0], yeux.alleles[1]);
}

//Setter
int Gene::setAlleleG(int a) {
	alleles[0] = a;
	return alleles[0];
}
int Gene::setAlleleD(int a) {
	alleles[1] = a;
	return alleles[1];
}


//Gene::Gene() {}
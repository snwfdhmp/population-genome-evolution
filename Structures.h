#ifndef STRUCTURES_H
#define STRUCTURES_H

class TypeGene
{
public:
	unsigned long int type;
	unsigned short int possibilites;
	unsigned short int *allelesPossibles;

	TypeGene(unsigned long int initType, unsigned short int initPoss, unsigned short int* initAllelesPoss) {
		int i;
		type = initType;
		possibilites = initPoss;
		allelesPossibles = (unsigned short int*) malloc(sizeof(unsigned short int) * initPoss);
		for (i = 0; i < possibilites; ++i)
		{
			allelesPossibles[i] = initAllelesPoss[i];
		}
	}

	TypeGene();

	unsigned short int getNumber(unsigned short int n) {
		return allelesPossibles[n];
	}
	unsigned short int taille() {
		return possibilites;
	}

	void printTypeGene(){
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

};

#endif
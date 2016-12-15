#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gene.h"
#include "Humain.h"

#define PI 3.141592

#define X 0
#define Y 1

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
	Gene sexeh;
	Gene sexef;
	Humain adam;
	Humain eve;
	Humain martin;

	sexeh.setAlleleL(X);
	sexeh.setAlleleR(Y);

	sexef.setAlleleL(X);
	sexef.setAlleleR(X);

	adam.setNextGene(sexeh);
	eve.setNextGene(sexef);

	martin = eve.reproduce(&adam);

	

	return 0;
}
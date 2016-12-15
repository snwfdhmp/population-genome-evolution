#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gene.h"
//#include "Humain.h"

#define PI 3.141592

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
	Gene yeux;
	yeux.setAlleleG(1);
	yeux.setAlleleD(0);


	printf("Alleles : %d et %d\n", yeux.alleles[0], yeux.alleles[1]);
	yeux.sortAlleles();

	return 0;
}
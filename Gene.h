//types
#ifndef DEF_GENE
#define DEF_GENE


class Gene
{
public:

	//Gene();
	int type; //définit grâces aux constantes de prépocesseur 
	int alleles[2]; //tableau contenant l'ensemble des alleles

	Gene() {
		type = 0;
	}

	//Sorter
	int speaking();
	void sortAlleles();


	//Printer
	void printAlleles();

	//Getter
	int alleleL();
	int alleleR();

	//Setter
	int setAlleleL(int a);
	int setAlleleR(int a);

	//Class Methods
	int createFromParents(int geneM[2], int geneF[2]);
};
#endif
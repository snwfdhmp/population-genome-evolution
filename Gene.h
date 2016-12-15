//types
#ifndef DEF_GENE
#define DEF_GENE
#define COULEUR_YEUX 1


class Gene
{
public:

	//Gene();
	int type; //définit grâces aux constantes de prépocesseur 
	int alleles[2]; //tableau contenant l'ensemble des alleles

	//Sorter
	int speaking();
	void sortAlleles();


	//Printer
	void printAlleles();

	//Getter

	//Setter
	int setAlleleG(int a);
	int setAlleleD(int a);
};
#endif
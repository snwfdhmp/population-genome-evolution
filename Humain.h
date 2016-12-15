#include "Gene.h"

class Humain
{
public:
	Humain* father;
	Humain* mother;
	Humain* children;

	int lastGene;
	Gene genes[1];

	Humain() {
		lastGene = -1;
	}

	//sorter

	//printer
	void printGene(int i);
	void printSexe();

	//getter

	//setter
	int setNextGene(Gene g);

	//Class Methods
	Humain reproduce(Humain* pere);

};
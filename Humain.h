class Humain
{
public:
	Humain* pere;
	Humain* mere;
	Humain* enfants;

	int lastGene;
	Gene genes[1];

	Humain() {
		lastGene = -1;
	}

	//sorter

	//printer
	void printGene(int i) {
		printf("Gene n°%d : TYPE %d ; DOMINANT : %d ; ALLELE_D : %d\n",i, genes[i].type, genes[i].speaking(), genes[i].alleleR());
	}

	//getter

	//setter
	int setNextGene(Gene g) {
		genes[lastGene+1] = g;
		lastGene++;
		return lastGene;
	}

	//Class Methods
	Humain reproduce(Humain* pere) {
		int i;
		Humain child;
		for(i = 0; i <= lastGene; i++) {
			Gene childGene;
			int motherGenes = [alleleL(), alleleR()];
			int fatherGenes = [pere->alleleL(), pere->alleleR()];
			childGene.createFromParents(motherGenes, fatherGenes]); // parameters Mother[], Father[]
		}
	}

};
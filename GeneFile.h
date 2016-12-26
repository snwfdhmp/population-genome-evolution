#ifndef GENE_FILE
#define GENE_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include "Structures.h"

class GeneFile {
public:
	char path[80]; //stocke le path
	char* buffer; //stocke le contenu du fichier

	long lSize; //longueur fichier
	size_t result; 
	int i,j; //variables de parcours

	FILE* file; //fichier
	json_t* root; //La racine du json parsé
	json_error_t error; //contient les eventuelles erreurs

	int open(char* newPath);
	int read();
	int parse();
	int giveGeneList();
	int getNumberOfGenes();
	TypeGene getTypeGene(int geneIndexInFile);


};

#endif
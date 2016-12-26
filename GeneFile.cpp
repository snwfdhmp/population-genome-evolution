#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include "Structures.h"
#include "GeneFile.h"


int GeneFile::open(char* newPath) {
	strcpy(path, newPath);
	printf("OUVERTURE de %s\n", path);
	file = fopen (path , "rb");
	if (file==NULL) {fputs ("Erreur de fichier",stderr); return 1;}
	return 0;
}

int GeneFile::read() {
	fseek (file , 0 , SEEK_END);
	lSize = ftell (file);
	rewind (file);

		// alloue la memoire nécéssaire pour contenir tout le fichier
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Erreur mémoire",stderr); exit (2);}

		// copie le fichier dans le buffer
	result = fread (buffer,1,lSize,file);
	if (result != lSize) {fputs ("Erreur de lecture",stderr); exit (3);}

		/* tout le fichier est maintenant contenu dans le buffer. */

		// terminate
	fclose (file);
	return 0;
}

int GeneFile::parse() {
		//On load le buffer en tant que JSON grace a jansson
	root = json_loads(buffer, 0, &error);	

		//On teste les erreurs
	if(!root)
	{
		fprintf(stderr, "Erreur sur la ligne %d: %s\n", error.line, error.text);
		return 1;
	}

		//On peut alors vider le buffer
	free (buffer);

		//Maintenant on va tester les erreurs
	if(!json_is_array(root))
	{
		fprintf(stderr, "Erreur : root n'est pas un array\n");
		json_decref(root);
		return 1;
	}
	return 0;
}
int GeneFile::giveGeneList() {

	printf("AFFICHAGE de la LISTE DES GENES :\n");
	for(i = 0; i < json_array_size(root); i++)
	{
		json_t *data, *type_string, *type_id, *alleles;
		const char *message_text;

		data = json_array_get(root, i);
		if(!json_is_object(data))
		{
			fprintf(stderr, "error: data %d is not an object\n", i + 1);
			json_decref(root);
			return 1;
		}

		type_string=json_object_get(data, "type-string");
		type_id=json_object_get(data, "type-id");
		alleles=json_object_get(data, "values");

			/*if(!json_is_object(type))
			{
				fprintf(stderr, "error: data %d: type is not an object\n", i + 1);
				json_decref(root);
				return 1;
			}*/
		printf("TYPE : %s ID : %.f ALLELES : [", json_string_value(type_string), json_number_value(type_id));
		for (j = 0; j < json_array_size(alleles); ++j)
		{
			printf("%.f", json_number_value(json_array_get(alleles, j)));
			if(j+1 < json_array_size(alleles))
				printf(", ");
		}
		printf("]\n");

	}
	return 0;
}
int GeneFile::getNumberOfGenes() {
	return json_array_size(root);
}
TypeGene GeneFile::getTypeGene(int geneIndexInFile) {
	unsigned long int type;
	unsigned short int taille, i;
	unsigned short int* poss;
	json_t *data, *alleles;

	data = json_array_get(root, geneIndexInFile);
	alleles = json_object_get(data, "values");
	taille = json_array_size(alleles);
	type = json_number_value(json_object_get(data, "type-id"));

	poss = (unsigned short int*) malloc(sizeof(unsigned short int)*taille);

	for(i = 0; i < taille; i++) {
		poss[i] = json_number_value(json_array_get(alleles, i));
	}

	TypeGene newGene = TypeGene(type, taille, poss);
	return newGene;
}
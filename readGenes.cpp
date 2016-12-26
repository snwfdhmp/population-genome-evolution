#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>

int main () {
	FILE* pFile;
	long lSize;
	char* buffer;
	size_t result;
	json_t* root;
	json_error_t error;
	int i,j;

	pFile = fopen ( "genes.json" , "rb" );
	if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

	// copy the file into the buffer:
	result = fread (buffer,1,lSize,pFile);
	if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose (pFile);

	//On load le buffer en tant que JSON grace a jansson
	root = json_loads(buffer, 0, &error);	

	//On teste les erreurs
	if(!root)
	{
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
		return 1;
	}

	//On peut alors vider le buffer
	free (buffer);

	//Maintenant on va tester les erreurs
	if(!json_is_array(root))
	{
		fprintf(stderr, "error: root is not an array\n");
		json_decref(root);
		return 1;
	}

	printf("Liste des gènes :\n");
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
		printf("\n");
		
	}
	return 0;
}
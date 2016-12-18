#include "Gene.h"
#define GENOME_LENGTH 1


class Humain
{
//private: <- Should be private
public:
	Humain* father; //pointeur vers le père
	Humain* mother; //pointeur vers la mère
	//Humain* children; //non défini pour le moment. Censé être un tableau contenant des pointeurs vers les enfants

	int lastGene; //index du dernier gène créé
	Gene genes[GENOME_LENGTH]; // Génome (tableau contenant les gènes)

	//pointeurs vers gènes
	//int* sexe; //genes[0].speaking();

//public:
	Humain() {
		lastGene = -1;
	}

	//Creaters
	/* createFromReproduce(Humain, Humain) effectue les même traitements que
	reproduce(Humain) sauf que createFromReproduce est utilisée par l'enfant
	et modifie directement ses variables d'instance, alors que reproduce est
	utilisé par un des parents (en théorie la mère) et renvoie simplement l'enfant */
	Humain createFromReproduce(Humain* mother, Humain* father); //Cree l'humain à partir de la reproduction de M et F

	//sorter

	//printer
	void printGene(int i); // Affiche le gene à l'index i du tableau de gènes
	void printSexe(); // Affiche le sexe (interprète l'allèle dominant du gène 0 (sexuel))

	//getter

	//setter
	int setNextGene(Gene g); // Ajoute le gène au génome

	//tester
	bool isMyParent(Humain* parent);
	
	//Class Methods
	/* reproduce(Humain* pere) permet (en théorie) à n'importe quel humain de se
	reproduire avec un autre humain, et renvoie le nouvel humain nouvellement
	créé. Cependant, l'usage est : mère.reproduce(&père) (on appelle ça une reproduction M*F (mother by father))
	On pourrait imaginer une reproduction M*M (mother by mother), F*F (..)
	ou F*M (qui donnerait père.reproduce(&mère)). Mais cela ne simule pas un environnement naturel puisqu'ici
	la reproduction est directement liée à la procréation et fécondation d'individu viable.
	On peut néanmoins noter que si l'on réussit à déterminer suffisamment le génome d'un humain, on pourra utiliser
	un algorithme génétique afin de déterminer s'il existe un moyen pour les homosexuels de procréer. (brève parenthèse) */
	Humain reproduce(Humain* pere);

};
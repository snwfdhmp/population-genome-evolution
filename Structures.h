#ifndef STRUCTURES_H
#define STRUCTURES_H

class TypeGene //Classe contenant un objet du tableau JSON (Type de Gene (ex :sexe, couleur peau, etc))
{
public:
	unsigned long int type; //type_id
	unsigned short int possibilites; //nombre de possibilites
	unsigned short int *allelesPossibles; //les possibilites

	TypeGene(unsigned long int initType, unsigned short int initPoss, unsigned short int* initAllelesPoss); //constructeur
	TypeGene(); // constructeur vide

	unsigned short int getNumber(unsigned short int n); //Renvoie allelesPossibles[n]
	unsigned short int taille(); //Renvoie possibilites

	void printTypeGene(); //Decrit le TypeGene

};

#endif
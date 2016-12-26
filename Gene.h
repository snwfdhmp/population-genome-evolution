//type_ids
#ifndef DEF_GENE
#define DEF_GENE


class Gene
{
public:

	//Gene();
	int type_id; //définit grâces aux constantes de prépocesseur UPDATE : bientot définit grace au fichier JSON
	int alleles[2]; //tableau contenant l'ensemble des alleles
	char type_string[80];

	Gene() {
		type_id = 0;
	}

	//Sorter
	

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
	/* 
				Petit mot sur les rapports de domination des allèles et comment les calculer.

		NB: Ne pas hésiter à me signaler une quelconque erreur.

		Renvoie l'allèle dominant du gène, celui qui va s'exprimer.
		Explication génétique : votre ADN contient beaucoup de gènes, qui vous définissent, et contiennent chacun une valeur.
		On peut assimiler ceci à un fichier de config (en JSON par ex) où vous auriez
			'sexe':'homme'
			'couleur-yeux':'bleu'
		Sauf que l'ADN est constitué de deux chaînes et donc de deux "fichiers de config" qui peuvent être différent.
		Comment choisir alors si j'ai un fichier avec "'sexe':'homme'" et un avec "'sexe':'femme'" ? (ça arrive beaucoup plus souvent
		que vous ne pouvez l'imaginer) Et bien parmi ces deux (ou +) valeurs que peut avoir "sexe" (ou tout autre gène),
		il y en a une "plus forte" que l'autre. Par exemple pour le gène sexuel, le Y est dominant sur le X. Le X produit une femme et le Y
		un homme. C'est pour cela qu'un paire de chromosomes XX donne une femme et XY donne un homme (car le Y est plus fort que le X).
		Pas de moyen pratique pour trouver quel est le plus fort (en tout cas pas à ma connaissance). Il est donc nécéssaire de faire des recherches
		sur chaque gène afin de savoir les différents allèles qui peuvent le définir ainsi que l'ordre de domination.
		Vous pouvez noter que "sexe" sera assimilé à un gène et "homme" ou "femme" à un allèle.
		Dans mon cas d'exemple, l'individu a un gène sexuel masculin. C'est à dire que le gène sexuel possède un allèle masculin
		qui prédomine sur les autres.
		
		Dans notre phase de codage, on va donc répertorier les gènes existants ainsi que les allèles (pour l'instant dans les constantes
		de préprocesseur, plus tard dans un JSON) et leur ordre.
		J'explique l'expression "ordre" : par exemple, pour le gène sexuel, X = 0, Y = 1.

		$ On va placer ces deux allèles dans un ordre complètement aléatoire (2 possibilités ici) dans un génome.
		(le tableau vaut {0,1} actuellement)
		$ Puis sortAlleles() va les ranger dans un ordre décroissant
		(le tableau vaut {1,0} actuellement)
		$ Puis speaking() va retourner le [0] (donc 1)
		speaking() = 1

		Ainsi, on organisera de manière très simple les rapports de domination entre allèles en les rangeant simplement
		par ordre croissant et en leur attribuant une valeur entière réelle et positive. (il est conseillé mais non
		indispensable de prendre des chiffres qui se suivent (2,7 et 39 peuvent fonctionner. 39 sera le speaking())


	*/
	int speaking();  // Après avoir trié les allèles grâce à sortAlleles(), il va renvoyer le [0]
	void sortAlleles(); // Trie les allèles de sorte à avoir le speaking (dominant) à gauche (en [0]) et le recessif à droite

};
#endif
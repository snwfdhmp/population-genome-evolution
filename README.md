![https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true](https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true)

<h1>Présentation</h1>
Le but de ce programme est de recréer le principe d'évolution au niveau microscopique par rapport au temps (à échelle humaine) et de voir de quelle manière les hommes sont ammenés à évoluer en utilisant les principes de fécondation et de brassage chromosomiques.
<h3>But</h3>
A terme, et dans une optique où les objectifs seraient atteints, ce programme pourrait permettre de visualiser certaines possibilités d'évolution de notre société dans le futur avec précision.





<h2>Logs des changements</h2>

<h3> Le 27/12/16 : </h3>
- Le travail sur l'automatisation de l'ajout de gènes est terminé. Il reste quelques bugs à régler, notamment un gène qui apparait sur l'humain n°5 gène n°1 et n°3 (toujours 32767 et 490786309 -> valeurs incorrectes).
- Bug des valeurs incorrectes réglé.
- Un nouveau bug a été détecté : le nombre maximum d'humains qu'on peut générer est 40296 (sinon segfault. Nombre trouvé en faisant une simple recherche dichotomique)
- Structure du projet changée (minor changes)
- Projet nettoyé et système de fichier refait
- Bug "maximum d'humains" résolu en changeant l'allocation statique du tableau d'humains en une allocation dynamique.

<h3> IMPORTANT</h3>
Un fichier log.out a été ajouté qui contient les logs d'une session minimalisée (pour que le fichier soit plus léger à uploader) (par exemple le nombre d'humains à générer a été réduit de 90%)

<h3> Du 21 au 27/12/16 : </h3>
Travail sur l'automatisation de l'ajout des gènes. La vitesse de génération est actuellement satisfaisante (Entre 15 et 25 millions par seconde).
Le but d'ajouter l'automatisation des gènes à travers l'utilisation d'un JSON est de pouvoir aggrandir la génération à d'autres gènes que le sexe, et donc commencer à étudier l'évolution de populations selon plusieurs caractères.

<h3> Le 19/12/16 : </h3>
- La précision est actuellement de 75. L'objectif du jour sera de la rapprocher de 50 au maximum et d'accélérer la génération des humains.
- Génération de environ 50M d'humains en 5 secondes (5* paris) (génération 40)
- Génération de 6MM (milliards) en 350 sec (génération 50) (précision 50.00088~ (plus c'est proche de 50, mieux c'est)
- Génération de 87MM en 5570 sec (43845550478f; 43847180493h) précision (49.99907~)




<h1>Observations :</h1>
 - [conditions] S'il n'y a pas de restriction concernant le choix des individus
 	lors d'une reproduction (pas de limitation au couple ou de protection des couples), alors
 	le nombre d'hommes a une importance fortement négligeable si le but est d'assurer
 	une expansion de la population mondiale sur une longue période.

<h1>Remerciements</h1>
<h3>Librairies utilisées :</h3>
- jansson (décodage du JSON des gènes)
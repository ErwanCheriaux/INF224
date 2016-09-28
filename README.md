#########################################################
#		README - INF224 - Projet		#
#########################################################

projet C++ consultable a l'adresse suivante:
http://perso.telecom-paristech.fr/~elc/cpp/TP-C++.html

Etape 1:

Création d'un dépot git à l'adresse suivante:
https://github.com/KataKoeur/INF224.git
Etape terminée

Etape 2:
Utilisation de QtCreator pour programmer en C++
Ajout de la classe Multimedia avec quelques fonctionnalités de base
Etape terminée

Etape 3:
Ajout de la classe Main testant la classe Multimedia
Etape terminée

Etape 4:
Ajout des classes Image et Video uniquement en .h
Utilisation de l'héritage afin de ne pas réecrire certaine partie du code déjà présent dans la classe Multimedia
Ajout de la méthode play() aux classes Image et Video

Q:Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ? 
R:On appelle cela une méthode abstraite et cela ce déclare ainsi -> virtual void play()=0;

Q:Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?
R:La méthode de base contient à présent une méthode abstraite qui rend sont instanciation inchoérente.

Etape terminée

Etape 5:

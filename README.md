#########################################################
#		README - INF224 - Projet		#
#########################################################

projet C++ consultable a l'adresse suivante:
http://perso.telecom-paristech.fr/~elc/cpp/TP-C++.html

Etape 1:
Création d'un dépot git à l'adresse suivante:
https://github.com/KataKoeur/INF224.git
Étape terminée

Étape 2:
utilisation de QtCreator pour programmer en C++
Ajout de la classe Multimédia avec quelques fonctionnalités de base
Étape terminée

Étape 3:
ajout de la classe main testant la classe Multimédia
Étape terminée

Étape 4:
ajout des classes image et Video uniquement en .h
Utilisation de l'héritage afin de ne pas réécrire certaines parties du code déjà présent dans la classe Multimédia
Ajout de la méthode play() aux classes image et Video

Q: Comment appelle-on-se type de méthode et comment faut-il les déclarer ?
R: On appelle cela une méthode abstraite et cela se déclare ainsi -> virtual void play()=0;

Q: si vous avez fait correctement ce qui précède, il ne sera plus possible d'instances des objets de la classe de base. Pourquoi ?
R: La méthode de base contient à présent une méthode abstraite qui rend son instanciation incohérente.
Étape terminée

Etape 5:
Q:Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ? Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
R:On appelle cela le polymorphisme le fait qu'un objet possède plusieurs classes (la sienne et celle dont il hérite). Le tableau contient des pointeurs vers ces objets car l'instanciation du tableau se fait avec une *. Contrairement à Java, il faut mettre une * pour signaler qu'il sagit d'un pointeur.
Étape terminée

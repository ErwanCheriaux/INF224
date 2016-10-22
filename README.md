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
utilisation de Doxygen pour la generation de document
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
R:On appelle cela le polymorphisme le fait qu'un objet possède plusieurs classes (la sienne et celle dont il hérite). Le tableau contient des pointeurs vers ces objets car l'instanciation du tableau se fait avec une "etoile". Contrairement à Java, il faut mettre une * pour signaler qu'il sagit d'un pointeur.
Étape terminée

Etape 6:
ajout de la classe Film. Faire attention à la variable pointeur dans cette nouvelle classe.
Notamment dans les getter et setter !

Q: Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données et en particulier son tableau de durées des chapitres (qui lui est propre et ne doit dépendre que de lui) ?
R: Il faut faire une copie de chaque élément du pointeur (tableau) et ne surtout pas copier l'addresse du pointeur.

Les getter et setter ont été testé et validé oppérationnel.
Etape terminée

Etape 7:
Q: Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier et comment afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ? 
R: Il faut penser à détruire les variables pointeuses lors de la destruction des classes qui en possède.

Q: Quelle(s) classe(s) sont concernées parmi celles déjà écrites et que faut-il faire ?
R: La classe Film est conserné car la variable chapter est un pointeur.
Etape terminée

Etape 8:
ajout de la classe Group qui permet de faire une liste d'objet multimédia. Cette classe hérite directement de list.

Q:La classe groupe doit-elle forcément avoir un destructeur ou ça dépend des cas ? Expliquez. 
R:La classe groupe doit avoir un destructeur dans la mesure où elle instancie un pointeur. Dans le cas contraire, il n'est pas nécéssaire d'avoir recourt à un destructeur.

Q:On rappelle que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
R:Utiliser des pointeurs permet de partager des objets entre plusieur groupes. Ainsi si l'objet est modifié, il sera modifié pour tous les groupes. Ce qui est logique puisqu'il sagit du même objet. En Java, la solution avec les pointeurs est la seul possible puisque Java travail uniquement avec des pointeurs qui sont caché au yeux du programmeur.
Etape terminée

Etape 9:
Création d'un Smart pointer dans la classe Multimedia qui est utilisé dans la classe Group.

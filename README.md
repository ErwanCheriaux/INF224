#########################################################
#		README - INF224 - Projet		#
#########################################################

Développeur: Erwan CHERIAUX

projet C++ consultable a l'adresse suivante:
http://perso.telecom-paristech.fr/~elc/cpp/TP-C++.html

#Partie C++

##Étape 1:
Création d'un dépôt git à l'adresse suivante:
https://github.com/KataKoeur/INF224.git

Étape terminée

##Étape 2:
utilisation de QtCreator pour programmer en C++.
utilisation de Doxygen pour la génération de documents.
Ajout de la classe Multimédia avec quelques fonctionnalités de base.

Étape terminée.

##Étape 3:
ajout de la classe main testant la classe Multimédia.

Étape terminée.

##Étape 4:
ajout des classes image et Video uniquement en .h.
Utilisation de l'héritage afin de ne pas réécrire certaines parties du code déjà présent dans la classe Multimédia.
Ajout de la méthode play() aux classes image et Video.

Q: Comment appelle-on-se type de méthode et comment faut-il les déclarer ?
R: On appelle cela une méthode abstraite et cela se déclare ainsi -> virtual void play()=0;

Q: si vous avez fait correctement ce qui précède, il ne sera plus possible d'instances des objets de la classe de base. Pourquoi ?
R: La méthode de base contient à présent une méthode abstraite qui rend son instanciation incohérente.

Étape terminée.

##Étape 5:
Q:Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ? Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
R:On appelle cela le polymorphisme le fait qu'un objet possède plusieurs classes (la sienne et celle dont il hérite). Le tableau contient des pointeurs vers ces objets car l'instanciation du tableau se fait avec une "etoile". Contrairement à Java, il faut mettre une * pour signaler qu'il sagit d'un pointeur.

Étape terminée.

##Étape 6:
ajout de la classe Film. Faire attention aux pointeurs dans cette nouvelle classe.
Notamment dans les getter et setter !

Q: Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données et en particulier son tableau de durée des chapitres (qui lui est propre et ne doit dépendre que de lui) ?
R: Il faut faire une copie de chaque élément du pointeur (tableau) et ne surtout pas copier l'adresse du pointeur.

Les getters et setters ont été testé et validés oppérationnels.

Étape terminée.

##Étape 7:
Q: Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier et comment afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?
R: Il faut penser à détruire les variables pointeuses lors de la destruction des classes qui en possède.

Q: Quelle(s) classe(s) sont concernées parmi celles déjà écrites et que faut-il faire ?
R: La classe Film est consernée car la variable chapter est un pointeur.

Étape terminée.

##Étape 8:
ajout de la classe Group qui permet de faire une liste d'objets multimédias. Cette classe hérite directement de list.

Q:La classe groupe doit-elle forcément avoir un destructeur ou ça dépend des cas ? Expliquez.
R:La classe groupe doit avoir un destructeur dans la mesure où elle instancie un pointeur. Dans le cas contraire, il n'est pas nécessaire d'avoir recours à un destructeur.

Q:On rappelle que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
R:Utiliser des pointeurs permet de partager des objets entre plusieurs groupes. Ainsi si l'objet est modifié, il sera modifié pour tous les groupes. Ce qui est logique puisqu'il sagit du même objet. En Java, la solution avec les pointeurs est la seule possible puisque Java travaille uniquement avec des pointeurs qui sont cachés aux yeux du programmeur.

Étape terminée.

##Étape 9:
Création d'un Smart pointer dans la classe Multimedia qui est utilisé dans la classe Group. Il faut maintenant penser lors de la création d'objet multimédia à utiliser un smart pointer.
Lors de la suppression de tous les groupes contenant un même objet, on peut voir dans le terminal que l'objet en question se supprime.

Étape terminée.

##Étape 10:
ajout d'une classe Bdd qui est une base de données gérant la cohérence des données. Elle contient la totalité des produits multimédias et des groupes.
ajout d'une vérification contre les doublons avant l'ajout d'un nouvel objet ou groupe.

Q:On peut créer directement les objets avec new sans passer par les méthodes précédentes. Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?
R:Il faut mettre tous les constructeurs de la classe Multimedia en protected. Il faut faire de même avec toutes ses classes filles. Enfin, il ajoute l'autorisation à la classe Bdd d'accéder au constructeur avec le mot friend. Aussi, il est impossible d'instancier un objet multimédia depuis la main.

Étape terminée.

##Étape 11:
Réailsation d'un client/serveur.

Q:Sachant que cette méthode peut appartenir à n'importe quelle classe, quelle est la solution la plus simple ?
R:La solution la plus simple serait de faire apartenir cette méthode à la classe Bdd qui gère la cohérence des données.

Étape terminée.

##Étape 12:
Sérialisation de la liste d'objet multimédia.
Après plusieurs tentative d'utiliser les bibliothèque Cereal et Boost. j'obtiens toujours avec la même erreur qui me dit que le compilateur ne trouve pas les headers alors que les répertoires des headers de cereal et boost sont bien présent à la racine du projet.
J'en viens donc à sérialiser les objets multimédias à la main avec ifstream et ofstream.

Étape terminée.

##Étape 13:
Traitement des erreurs.
J'ai choisi de traiter les erreurs avec des conditions et des renvois de booléens (des int lorsqu'il y a plus de 2 erreurs différentes). Cela me permet ainsi de communiquer à l'utilisateur de l'erreur qu'il vient de commettre et de poursuivre le programme.

Étape terminée.

#Partie Swing

##Étape 1:
Création d'une fenetre principale contenant 3 boutons et d'une zone de texte.

Q:Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?
R:

Étape terminée.

##Étape 2:
Ajout d'un menu. Utilisation des Actions qui remplace les listener.

Étape terminée.

##Étape3:
Communication entre l'interface graphique (client) et le serveur.
Un bouton Help à été ajouter pour aider l'utilisateur à se servir de l'interface et pour afficher le nom des objets multimédias et groupes déja existant dans la base de données.

Étape terminée.

##Étape 4:
Ajout d'un Makefile dans le repertoir swing permettant de compiler et de lancer l'interface graphique avec la commande 'make run'.
Penser à lancer le server, avec la commande 'make run' dans le repertoir cpp, avant de lancer l'interface graphique qui est un client.

Étape terminé.

#########################################################
#              		   FIN 		                #
#########################################################

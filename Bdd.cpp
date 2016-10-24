#include "Bdd.h"


/*!
 * \brief Permet d'ajouter une Image à la Base de données
 * \param name
 * \param pathname
 * \param latitude
 * \param longitude
 * \return
 */
MultimediaPtr Bdd::add(string name, string pathname, double latitude, double longitude)
{
    MultimediaMap::iterator it;

    //Vérification que l'objet multimédia n'existe pas déjà dans la Bdd
    it = multimediaMap.find(name);
    if(it != multimediaMap.end())
    {
        cerr << "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout de l'objet "+ name +" à la Bdd" << endl;
        MultimediaPtr media = MultimediaPtr(new Image(name, pathname, latitude, longitude));
        multimediaMap[name] = media;
        return media;
    }
}


/*!
 * \brief Permet d'ajouter une Vidéo à la Base de données
 * \param name
 * \param pathname
 * \param time
 * \return
 */
MultimediaPtr Bdd::add(string name, string pathname, int time)
{
    MultimediaMap::iterator it;

    //Vérification que l'objet multimédia n'existe pas déjà dans la Bdd
    it = multimediaMap.find(name);
    if(it != multimediaMap.end())
    {
        cerr << "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout de l'objet "+ name +" à la Bdd" << endl;
        MultimediaPtr media = MultimediaPtr(new Video(name, pathname, time));
        multimediaMap[name] = media;
        return media;
    }
}


/*!
 * \brief Permet d'ajouter un Film à la Base de données
 * \param name
 * \param pathname
 * \param time
 * \param chapter
 * \param nbChapter
 * \return
 */
MultimediaPtr Bdd::add(string name, string pathname, int time, const int *chapter, int nbChapter)
{
    MultimediaMap::iterator it;

    //Vérification que l'objet multimédia n'existe pas déjà dans la Bdd
    it = multimediaMap.find(name);
    if(it != multimediaMap.end())
    {
        cerr << "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout de l'objet "+ name +" à la Bdd" << endl;
        MultimediaPtr media = MultimediaPtr(new Film(name, pathname, time, chapter, nbChapter));
        multimediaMap[name] = media;
        return media;
    }
}


/*!
 * \brief Permet d'ajouter un groupe à la Base de données
 * \param name Nom du groupe que l'on souhaite créer
 * \return
 */
GroupPtr Bdd::add(string name)
{
    GroupMap::iterator it;

    //Vérification que le groupe n'existe pas déjà dans la Bdd
    it = groupMap.find(name);
    if(it != groupMap.end())
    {
        cerr << "---> Erreur : Le groupe "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout du groupe "+ name +" à la Bdd" << endl;
        GroupPtr group = GroupPtr(new Group(name));
        groupMap[name] = group;
        return group;
    }
}


/*!
 * \brief Permet d'associer un objet multimédia avec un groupe.
 *        Ces derniers doivent déjà exister dans la Base de données.
 * \param multimediaName Nom de l'objet multimédia que l'on souhaite associer
 * \param groupName Nom du groupe dans lequel on souhaite mettre l'objet multimédia
 */
int Bdd::addMultimediaToGroup(const string multimediaName, const string groupName)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(multimediaName);
    groupIt = groupMap.find(groupName);

    //Vérification que l'objet et le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end())
    {
        cerr << "---> Erreur : "+ multimediaName +" n'existe pas dans la Bdd" << endl;
        return 1;
    }
    else if(groupIt == groupMap.end())
    {
        cerr << "---> Erreur : "+ groupName +" n'existe pas dans la Bdd" << endl;
        return 2;
    }
    else
    {
        cout << "--- l'objet multimédia "+ multimediaName +" est maintenant associé au groupe "+ groupName << endl;
        MultimediaPtr mp;
        GroupPtr gp;

        mp = multimediaMap[multimediaName];
        gp = groupMap[groupName];

        gp.get()->push_back(mp); //ajout l'objet dans le groupe
        gp.get()->unique(); //permet de supprimer les doublons
        return 0;
    }    
}


/*!
 * \brief Permet de supprimer un objet multimédia ou un groupe de la Base de données
 * \param name Objet multimédia ou groupe que l'on souhaite supprimer
 */
int Bdd::remove(const string name)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(name);
    groupIt = groupMap.find(name);

    //Vérification que l'objet ou le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end() && groupIt == groupMap.end())
    {
        cerr << "---> Erreur : "+ name +" n'existe pas dans la Bdd" << endl;
        return 0;
    }
    else if(multimediaIt != multimediaMap.end())
    {
        cout << "--- Suppression de l'objet "+ name +" de la Bdd" << endl;

        MultimediaPtr mp;
        Group * g;

        //Suppréssion de l'objet dans tous les groupes (qu'il existe ou non)
        for (GroupMap::iterator it = groupMap.begin(); it != groupMap.end(); it++ )
        {
            g = it->second.get();
            mp = multimediaMap[name];
            g->remove(mp);
        }
        multimediaMap.erase(name);
        return 1;
    }
    else
    {
        cout << "--- Suppression du groupe "+ name +" de la Bdd" << endl;
        groupMap.erase(name);
        return 2;
    }
}


/*!
 * \brief Permet de chercher un objet multimédia ou un groupe dans la Base de données
 * \param name Objet multimédia ou groupe que l'on cherche
 */
void Bdd::find(ostream& s, const string name)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(name);
    groupIt = groupMap.find(name);

    //Vérification que l'objet et/ou le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end() && groupIt == groupMap.end())
    {
        s << "--- "+ name +" n'existe pas dans la Bdd;";
    }
    if(multimediaIt != multimediaMap.end())
    {
        s << "--- Affichage de l'objet multimédia "+ name +";";
        MultimediaPtr mp;
        mp = multimediaMap[name];
        mp.get()->display(s);
    }
    if(groupIt != groupMap.end())
    {
        s << "--- Affichage du groupe "+ name +";";
        GroupPtr gp;
        gp = groupMap[name];
        gp.get()->display(s);
    }
}


/*!
 * \brief Permet de jouer un objet multimédia de la Base de données
 * \param name Objet multimédia que l'on souhaite jouer
 */
void Bdd::play(const string name)
{
    MultimediaMap::iterator multimediaIt;

    multimediaIt = multimediaMap.find(name);

    //Vérification que l'objet existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end())
    {
        cerr << "---> Erreur : "+ name +" n'existe pas dans la Bdd" << endl;
    }
    if(multimediaIt != multimediaMap.end())
    {
        cout << "--- Lecture de l'objet multimédia "+ name << endl;
        MultimediaPtr mp;
        mp = multimediaMap[name];
        mp.get()->play();
    }
}

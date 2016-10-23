#include "Bdd.h"


/*!
 * \brief Permet d'ajouter un objet multimédia à la Base de données
 * \param media Image que l'on souhaite ajouter
 * \return
 */
MultimediaPtr Bdd::add(MultimediaPtr media)
{
    MultimediaMap::iterator it;
    string name = media.get()->getName();

    //Vérification que l'objet multimédia n'existe pas déjà dans la Bdd
    it = multimediaMap.find(name);
    if(it != multimediaMap.end())
    {
        cout << "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd" << endl;
    }
    else
    {
        cout << "--- Ajout de l'objet "+ name +" à la Bdd" << endl;
        multimediaMap[name] = media;
    }
    return media;
}


/*!
 * \brief Permet d'ajouter un groupe à la Base de données
 * \param group Groupe que l'on souhaite ajouter
 * \return
 */
GroupPtr Bdd::add(GroupPtr group)
{
    GroupMap::iterator it;
    string name = group.get()->getName();

    //Vérification que le groupe n'existe pas déjà dans la Bdd
    it = groupMap.find(name);
    if(it != groupMap.end())
    {
        cout << "---> Erreur : Le groupe "+ name +" existe déjà dans la Bdd" << endl;
    }
    else
    {
        cout << "--- Ajout du groupe "+ name +" à la Bdd" << endl;
        groupMap[name] = group;
    }
    return group;
}


/*!
 * \brief Permet de supprimer un objet multimédia ou un groupe de la Base de données
 * \param name Objet multimédia ou groupe que l'on souhaite supprimer
 */
void Bdd::remove(const string name)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(name);
    groupIt = groupMap.find(name);

    //Vérification que l'objet ou le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end() && groupIt == groupMap.end())
    {
        cout << "---> Erreur : "+ name +" n'existe pas dans la Bdd" << endl;
    }
    else if(multimediaIt != multimediaMap.end())
    {
        cout << "--- Suppression de l'objet "+ name +" de la Bdd" << endl;
        multimediaMap.erase(name);
    }
    else if(groupIt != groupMap.end())
    {
        cout << "--- Suppression du groupe "+ name +" de la Bdd" << endl;
        groupMap.erase(name);
    }
}


/*!
 * \brief Permet de chercher un objet multimédia ou un groupe dans la Base de données
 * \param name Objet multimédia ou groupe que l'on cherche
 */
void Bdd::find(const string name)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(name);
    groupIt = groupMap.find(name);

    //Vérification que l'objet et/ou le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end() && groupIt == groupMap.end())
    {
        cout << "--- "+ name +" n'existe pas dans la Bdd" << endl;
    }
    if(multimediaIt != multimediaMap.end())
    {
        cout << "--- Affichage de l'objet multimédia "+ name << endl;
        MultimediaPtr mp;
        mp = multimediaMap[name];
        mp.get()->display(cout);
    }
    if(groupIt != groupMap.end())
    {
        cout << "--- Affichage du groupe "+ name << endl;
        GroupPtr gp;
        gp = groupMap[name];
        gp.get()->display(cout);
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
        cout << "---> Erreur : "+ name +" n'existe pas dans la Bdd" << endl;
    }
    if(multimediaIt != multimediaMap.end())
    {
        cout << "--- Lecture de l'objet multimédia "+ name << endl;
        MultimediaPtr mp;
        mp = multimediaMap[name];
        mp.get()->play();
    }
}

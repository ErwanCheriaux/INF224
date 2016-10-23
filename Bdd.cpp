#include "Bdd.h"


/*!
 * \brief Permet d'ajouter une Image à la Base de données
 * \param media Image que l'on souhaite ajouter
 * \return
 */
MultimediaPtr Bdd::add(MultimediaPtr media)
{
    MultimediaMap::iterator it;
    string name = media.get()->getName();

    //Vérification que l'objet multimédia n'éxiste pas déjà dans la Bdd
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

    //Vérification que le groupe n'éxiste pas déjà dans la Bdd
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


void Bdd::remove(const string name)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(name);
    groupIt = groupMap.find(name);

    //Vérification que l'objet et/ou le groupe éxiste bien dans la Bdd
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


void Bdd::find(const string name)
{

}


void Bdd::play(const string name)
{

}

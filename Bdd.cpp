#include "Bdd.h"


/*!
 * \brief Permet d'ajouter une Image à la Base de données
 * \param media Image que l'on souhaite ajouter
 * \return
 */
MultimediaPtr Bdd::add(MultimediaPtr media)
{
    cout << "--- Ajout de l'objet "+ media.get()->getName() +" à la Bdd" << endl;
    return media;
}


/*!
 * \brief Permet d'ajouter un groupe à la Base de données
 * \param group Groupe que l'on souhaite ajouter
 * \return
 */
GroupPtr Bdd::add(GroupPtr group)
{
    cout << "--- Ajout du groupe "+ group.get()->getName() +" à la Bdd" << endl;
    return group;
}


void Bdd::remove(const string name)
{

}


void Bdd::find(const string name)
{

}


void Bdd::play(const string name)
{

}

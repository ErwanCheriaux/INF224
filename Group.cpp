#include "Group.h"


/*!
 * \brief Constructeur par défaut
 */
Group::Group()
{
    _name = "";
}


/*!
 * \brief Classe contenant une liste d'objet multimédia (vidéo, image, ...)
 * \param _name Nom du groupe
 */
Group::Group(string name)
{
    _name = name;
}

/*!
 * \brief Affiche dans la console les informations de tous les produits de la liste
 * \param s choix de la sortie pour l'affichage (cout -> terminal)
 */
void Group::display(ostream& s) const
{
    for(Group::const_iterator it = begin(); it != end(); ++it)
        (*it)->display(s);
}

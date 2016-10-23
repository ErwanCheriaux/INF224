#include "Multimedia.h"


/*!
 * \brief Constructeur par défaut
 */
Multimedia::Multimedia()
{
    _name = "";
    _pathname = "";
}


/*!
 * \brief Classe de base de tout objet multimédia (vidéo, image, ...)
 * \param _name Nom du produit multimédia
 * \param _pathname Chemin relatif du produit multimédia
 */
Multimedia::Multimedia(string name, string pathname)
{
    _name = name;
    _pathname = pathname;
}


/*!
 * \brief Affiche dans la console les informations sur le produit multimédia
 * \param s choix de la sortie pour l'affichage (cout -> terminal)
 */
void Multimedia::display(ostream& s) const
{
    s << "name:" << getName() << "\n" << "pathname:" << getPathname() << endl;
}

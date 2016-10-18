#include "Multimedia.h"


/*!
 * \brief Multimedia::Multimedia Classe de base de tout type de multimédia (vidéo, image, ...)
 */
Multimedia::Multimedia()
{
    name = "";
    pathname = "";
}


/*!
 * \brief Multimedia::Multimedia Classe de base de tout type de multimédia (vidéo, image, ...)
 * \param _name Nom du produit multimédia
 * \param _pathname Chemin relatif du produit multimédia
 */
Multimedia::Multimedia(string _name, string _pathname)
{
    name = _name;
    pathname = _pathname;
}


/*!
 * \brief Multimedia::display Affiche dans la console les informations sur le produit multimédia
 * \param s cout
 */
void Multimedia::display(ostream& s) const
{
    s << "name:" << name << "\n" << "pathname:" << pathname << endl;
}

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
 * \brief Permet d'écrire les objets sérialisé dans un fichier texte
 * \param f Fichier texte
 */
void Multimedia::write(ostream & f)
{
    f << classname() << "\n" << _name << "\n" << _pathname << "\n";
}


/*!
 * \brief Permet de lire les objets sérialisés dans un fichier texte
 * \param f Fichier texte
 */
void Multimedia::read(istream & f)
{
    getline(f, _name);
    getline(f, _pathname);
}


/*!
 * \brief Affiche dans la console les informations sur le produit multimédias
 * \param s choix de la sortie pour l'affichage (cout -> terminal)
 */
void Multimedia::display(ostream& s) const
{
    s << "name:" << getName() << ";" << "pathname:" << getPathname() +";";
}

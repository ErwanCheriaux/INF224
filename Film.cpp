#include "Film.h"
#include "Video.h"


/*!
 * \brief Constructeur de la classe Film héritant de Vidéo et Multumédia
 *        Permet de jouer un film possèdant plusieur chapitre
 * \param name Nom de la vidéo
 * \param pathname Chemin relatif de la vidéo
 * \param time Durée de la vidéo en minute
 * \param chapter Tableau contenant le temps où commence chaques chapitres
 * \param nbChapter Nombre de chapitre dans le film
 */
Film::Film(string name, string pathname, int time, const int *chapter, int nbChapter):
    Video(name, pathname, time) {setChapter(chapter, nbChapter);}


/*!
 * \brief Instancie un nouvel objet avec les valeurs de f
 * \param f Objet que l'on souhaite copier
 */
Film::Film(const Film& f): Video(f.getName(), f.getPathname(), f.getTime())
    {_chapter = f.getChapter(_nbChapter);} //Recuperation des valeurs du pointeur de f


/*!
 * \brief L'opération = devient une copie intélligente
 * \param f Objet que l'on souhaite copier
 * \return
 */
Film& Film::operator=(const Film& f)
{
    this->setName(f.getName());
    this->setPathname(f.getPathname());
    this->setTime(f.getTime());

    delete this->_chapter;
    this->_chapter = f.getChapter(this->_nbChapter);

    return *this;
}


/*!
 * \brief Renvoie une copie du tableau chapter avec son nombre d'élément nbChapter
 * \param nbChapter Nombre d'élément dans le tableau qui sera retourné
 * \return chapter Tableau contenant le temps de début de chaque chapitre
 */
int * Film::getChapter(int &nbChapter) const
{
    int * tab = new int [_nbChapter]; //Instanciation du nouveau tableau
    nbChapter = _nbChapter; //On recupere le nombre de case du tableau

    for(int i=0; i < _nbChapter; i++) //On recopie élément par élément
        tab[i] = _chapter[i];

    return tab;
}


/*!
 * \brief Permet de changer le tableau chapter et son nombre d'élément nbChapter
 * \param chapter Tableau contenant le temps de début de chaque chapitre
 * \param nbChapter Nombre d'élément dans le tableau qui sera retourné
 */
void Film::setChapter(const int *chapter, int nbChapter)
{
    delete _chapter;
    _chapter = new int [nbChapter]; //Instanciation du nouveau tableau
    _nbChapter = nbChapter;

    for(int i=0; i < nbChapter; i++) //On recopie élément par élément
        _chapter[i] = chapter[i];
}


/*!
 * \brief Affiche sous forme de liste le tableau chapter ainsi que le nombre de chapitre.
 * \param s choix de la sortie pour l'affichage (cout -> terminal)
 */
void Film::displayChapter(ostream& s) const
{
    string str = "";
    for(int i=0; i < _nbChapter; i++)
    {
        str = str + "Chapitre " + to_string(i) + ": " + to_string(_chapter[i]) + "\n";
    }
    str = "nbChapter: " + to_string(_nbChapter) + "\n" + str;
    s << str << endl;
}

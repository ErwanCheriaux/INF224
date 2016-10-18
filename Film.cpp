#include "Film.h"
#include "Video.h"


/*!
 * \brief Film::Film Constructeur de la classe Film héritant de Vidéo et Multumédia
 *              Permet de jouer un film possèdant plusieur chapitre
 * \param _name Nom de la vidéo
 * \param _pathname Chemin relatif de la vidéo
 * \param _time Durée de la vidéo en minute
 * \param _chapter Tableau contenant le temps de début de chaque chapitre
 * \param _nbChapter Nombre de chapitre dans le film
 */
Film::Film(string _name, string _pathname, int _time, const int *_chapter, int _nbChapter):
    Video(_name, _pathname, _time) {setChapter(_chapter, _nbChapter);}


/*!
 * \brief Film::getChapter Renvoie une copie du tableau _chapter avec son nombre d'élément _nbCharpter
 * \param index Nombre d'élément dans le tableau qui sera retourné
 * \return _chapter Tableau contenant le temps de début de chaque chapitre
 */
int * Film::getChapter(int &index) const
{
    int * tab = new int [nbChapter]; //Instanciation du nouveau tableau
    index = nbChapter; //On recupere le nombre de case du tableau

    for(int i=0; i < nbChapter; i++) //On recopie élément par élément
        tab[i] = chapter[i];

    return tab;
}


/*!
 * \brief Film::setChapter Permet de changer le tableau _chapter et son nombre d'élément _nbChapter
 * \param _chapter Tableau contenant le temps de début de chaque chapitre
 * \param _nbChapter Nombre d'élément dans le tableau qui sera retourné
 */
void Film::setChapter(const int *_chapter, int _nbChapter)
{
    delete chapter;
    chapter = new int [nbChapter]; //Instanciation du nouveau tableau
    nbChapter = _nbChapter;

    for(int i=0; i < nbChapter; i++) //On recopie élément par élément
        chapter[i] = _chapter[i];
}


/*!
 * \brief Film::displayChapter Affiche sous forme de liste le tableau _chapter ainsi que le nombre de chapitre.
 * \param s cout
 */
void Film::displayChapter(ostream& s) const
{
    string str = "";
    for(int i=0; i < nbChapter; i++)
    {
        str = str + "Chapitre " + to_string(i) + ": " + to_string(chapter[i]) + "\n";
    }
    str = "nbChapter: " + to_string(nbChapter) + "\n" + str;
    s << str << endl;
}

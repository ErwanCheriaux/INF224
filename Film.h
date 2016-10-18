#ifndef FILM_H
#define FILM_H

#include "Video.h"

#include <string>
#include <cstring>
#include <iostream>
using namespace std;

/*!
 * \brief La classe Film hérite de Vidéo et Multumédia
 *        Elle permet de jouer un film possèdant plusieur chapitre
 */
class Film : public Video
{
    private:
        int * _chapter;
        int _nbChapter;

    public:
        //constructeur
        Film(): _chapter(nullptr), _nbChapter(0) {}
        Film(string name, string pathname, int time, const int *chapter, int nbChapter);

        //destructeur
        virtual ~Film() {delete _chapter; cout << "---Destruction de " + getName() + "---\n" << endl;}

        //copie
        Film(const Film& f);
        Film& operator=(const Film& f);

        //getter
        virtual int getNbChapter() const {return _nbChapter;}
        virtual int * getChapter(int &nbChapter) const;

        //setter
        virtual void setChapter(const int * chapter, int nbChapter);

        //methode
        virtual void displayChapter(ostream& s) const;
};

#endif // FILM_H

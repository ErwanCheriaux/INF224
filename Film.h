#ifndef FILM_H
#define FILM_H

#include "Video.h"

#include <string>
#include <cstring>
#include <iostream>
using namespace std;

/*!
 * \brief The Film class Hérite de Vidéo et Multumédia
 *        Permet de jouer un film possèdant plusieur chapitre
 */
class Film : public Video
{
    private:
        int * chapter;
        int nbChapter;

    public:
        //constructeur
        Film(): chapter(nullptr), nbChapter(0) {}
        Film(string _name, string _pathname, int _time, const int *_chapter, int _nbChapter);

        //getter
        virtual int getNbChapter() const {return nbChapter;}
        virtual int * getChapter(int &index) const;

        //setter
        virtual void setChapter(const int * _chapter, int _nbChapter);

        //methode
        virtual void displayChapter(ostream& s) const;
};

#endif // FILM_H

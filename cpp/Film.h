#ifndef FILM_H
#define FILM_H

#include "Video.h"


/*!
 * \brief La classe Film hérite de Vidéo et Multumédia
 *        Elle permet de jouer un film possèdant plusieur chapitre
 */
class Film : public Video
{
    friend class Bdd;

    private:
        int * _chapter;
        int _nbChapter;

    protected:
        //constructeur
        Film(): _chapter(nullptr), _nbChapter(0) {}
        Film(string name, string pathname, int time, const int *chapter, int nbChapter);

    public:
        //destructeur
        virtual ~Film() {delete _chapter;}

        //copie
        Film(const Film& f);
        Film& operator=(const Film& f);

        //getter
        virtual int getNbChapter() const {return _nbChapter;}
        virtual int * getChapter(int &nbChapter) const;

        //setter
        virtual void setChapter(const int * chapter, int nbChapter);

        //sérialisation
        const char* classname() const override {return "Film";}

        void write(ostream & f) override
        {
            Video::write(f);
            f << *_chapter << "\n" << _nbChapter << "\n";
        }

        void read(istream & f) override
        {
            Video::read(f);
            f >> *_chapter >> _nbChapter;
        }

        //methode
        virtual void displayChapter(ostream& s) const;
};

#endif // FILM_H

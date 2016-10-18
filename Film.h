#ifndef FILM_H
#define FILM_H

#include "Video.h"

#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Film : public Video
{
    private:
        int * chapter;
        int nbChapter;

    public:
        Film(): chapter(nullptr), nbChapter(0) {}
        Film(string _name, string _pathname, int _time, const int *_chapter, int _nbChapter);


        virtual int getNbChapter() const {return nbChapter;}
        virtual int * getChapter(int &index) const;

        virtual void setChapter(const int * _chapter, int _nbChapter);

        virtual void displayChapter(ostream& s) const;
};

#endif // FILM_H

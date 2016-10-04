#ifndef FILM_H
#define FILM_H

#endif // FILM_H


class Film : public Video
{
    private:
        int * chapter;
        int nbChapter;

    public:
        Film(): chapter(nullptr), nbChapter(0) {}
        Film(string _name, string _pathname, int _time, const int *_chapter, int _nbChapter);


        virtual const int * getChapter() const {return chapter;}
        virtual int getNbChapter() const {return nbChapter;}

        virtual void setChapter(const int * _chapter, int _nbChapter)
        {
            nbChapter = _nbChapter;
            for(int i=0; i< nbChapter; i++)
                chapter[i] = _chapter[i];
        }

        virtual void displayChapter(ostream& s) const;
}

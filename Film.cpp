#include "Film.h"
#include "Video.h"

//Constructeur
Film::Film(string _name, string _pathname, int _time, const int *_chapter, int _nbChapter):
    Video(_name, _pathname, _time) {setChapter(_chapter, _nbChapter);}

void Film::setChapter(const int *_chapter, int _nbChapter)
{
    chapter = new int [nbChapter]; //Instanciation du nouveau tableau
    nbChapter = _nbChapter;

    for(int i=0; i < nbChapter; i++) //On recopie élément par élément
        chapter[i] = _chapter[i];
}

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

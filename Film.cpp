#include "Film.h"

Film::Film(string _name, string _pathname, int _time, const int *_chapter, int _nbChapter):
    Video(_name, _pathname, _time), nbChapter(_nbChapter)
{
    for(int i=0; i< nbChapter; i++)
        chapter[i] = _chapter[i];
}

void Film::displayChapter(ostream& s) const
{
    string str = "";
    for(int i=0; i<nbChapter; i++)
    {
        str = str + "Chapitre " + i + ": " + chapter[i] + "\n";
    }
    str = "nbChapter: "+ nbChapter +"\n"+ str;
    s << str << endl;
}

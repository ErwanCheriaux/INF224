#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"

int main()
{
    int i = 4;
    int * tab = new int[i];
    for(int j = 0; j<i; j++)
    {
        tab[j] = i*10;
    }

    Film * film1= new Film();
    Film * film2= new Film("famille", "dossierPerso/film/", 10, tab, i);

    film1->display(cout);
    film1->displayChapter(cout);
    film2->display(cout);
    film2->displayChapter(cout);
}

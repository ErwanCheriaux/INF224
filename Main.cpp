#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"

/*!
 * \brief main: Test le reste du programme !
 * \return
 */
int main()
{
    int i = 4;
    int * tab = new int[i];
    for(int j = 0; j<i; j++)
    {
        tab[j] = j*10;
    }

    Film * film1= new Film();
    film1->display(cout);
    film1->displayChapter(cout);


    Film * film2= new Film("famille", "dossierPerso/film/", 10, tab, i);
    film2->display(cout);
    film2->displayChapter(cout);
}

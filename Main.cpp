#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"

/*!
 * \file main.c
 * \brief Programme de tests.
 * \author Erwan CHERIAUX
 * \version 0.1
 * \date 18 octobre 2016
 *
 * Programme de test du logiciel d'une set-top box multimédia
 *
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


    Film * film3= new Film(*film1);
    film3->display(cout);
    film3->displayChapter(cout);

    film1= film2;
    film1->display(cout);
    film1->displayChapter(cout);


    delete film1;
    delete film2;
    delete film3;
}

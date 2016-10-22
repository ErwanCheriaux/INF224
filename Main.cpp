#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

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
    Group *g = new Group("Mes Documents");

    g->push_back(new Video("famille1", "dossierPerso/film/", 10));
    g->push_back(new Video("famille2", "dossierPerso/film/", 15));
    g->push_back(new Video("famille best of", "dossierPerso/film/", 5));

    g->display(cout);
}

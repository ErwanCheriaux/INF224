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
    Group *gImage = new Group("Mes Images");
    Group *gVideo = new Group("Mes Videos");
    Group *gDocument = new Group("Mes Documents");

    Video * f1 = new Video("famille1", "dossierPerso/film/", 10);
    Video * f2 = new Video("famille2", "dossierPerso/film/", 15);
    Video * f3 = new Video("famille best of", "dossierPerso/film/", 5);

    Image * i1 = new Image("famille1", "dossierPerso/photo/", 640, 480);
    Image * i2 = new Image("famille2", "dossierPerso/photo/", 640, 480);

    gVideo->push_back(f1);
    gVideo->push_back(f2);
    gVideo->push_back(f3);

    gImage->push_back(i1);
    gImage->push_back(i2);

    gDocument->push_back(f1);
    gDocument->push_back(f2);
    gDocument->push_back(f3);
    gDocument->push_back(i1);
    gDocument->push_back(i2);

    //Modification d'une video apres ajout dans les groupes
    f1->setName("famille1_Version_1.2");

    cout << "-----Groupe Image-----\n" <<endl;
    gImage->display(cout);

    cout << "-----Groupe Video-----\n" <<endl;
    gVideo->display(cout);

    cout << "-----Groupe Document-----\n" <<endl;
    gDocument->display(cout);

    delete gImage;

    cout << "-----Groupe Document apres la suppression du groupe image-----\n" <<endl;
    gDocument->display(cout);
}

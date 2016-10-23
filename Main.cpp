#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Bdd.h"

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
    Bdd * bdd = new Bdd();
    GroupPtr vGroup;
    MultimediaPtr vid;

    vGroup = bdd->add("Mes Videos");

    vid = bdd->add("video1", "dossierPerso/film/video1.avi", 10);
    vid = bdd->add("video2", "dossierPerso/film/video2.avi", 15);
    vid = bdd->add("video best of", "dossierPerso/film/video_best_of.avi", 5);
    vid = bdd->add("Logo ENST", "./image/Logo_Télécom_ParisTech.png", 640, 480);

    bdd->remove("video2");
    bdd->remove("video3");

    bdd->find("video1");
    bdd->find("video2");
    bdd->find("Mes Videos");
}

/*
Group *gImage = new Group("Mes Images");
Group *gVideo = new Group("Mes Videos");
Group *gDocument = new Group("Mes Documents");

MultimediaPtr f1(new Video("video1", "dossierPerso/film/video1.avi", 10));
MultimediaPtr f2(new Video("video2", "dossierPerso/film/video2.avi", 15));
MultimediaPtr f3(new Video("video best of", "dossierPerso/film/video_best_of.avi", 5));

MultimediaPtr i1(new Image("image1", "dossierPerso/photo/image1.jpg", 640, 480));
MultimediaPtr i2(new Image("image2", "dossierPerso/photo/image2.jpg", 640, 480));

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

delete gDocument;

cout << "-----Groupe Video apres la suppression du groupe document-----\n" <<endl;
gVideo->display(cout);
*/

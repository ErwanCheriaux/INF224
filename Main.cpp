#include "Bdd.h"
#include "tcpserver.h"


#include <cctype>
#include <stdexcept>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cppu;

/*!
 * \file main.c
 * \brief Programme de tests.
 * \author Erwan CHERIAUX
 * \version 0.3
 * \date 24 octobre 2016
 *
 * Serveur du logiciel d'une set-top box multimédia
 *
 */

const int PORT = 3331;

class MyBase
{
    private:
        Bdd * bdd = new Bdd();

    public:
       /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
        * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
        * puisse y accéder.
        *
        * Arguments:
        * - 'request' contient la requête
        * - 'response' sert à indiquer la réponse qui sera renvoyée au client
        * - si la fonction renvoie false la connexion est close.
        *
        * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
        * un thread par client).
        *
        * Pour eviter les problemes de concurrence on peut créer un verrou en creant
        * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
        * si la fonction modifie les donnees.
        */
    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
        cerr << "\nRequest: '" << request << "'" << endl;

        // 1) pour decouper la requête:
        // on peut par exemple utiliser stringstream et getline()
        stringstream requestStream(request);
        string       requestString;

        getline(requestStream, requestString, ' '); //On copie le premier mot dans requestString (les mots sont délimité par des espaces)


        // 2) faire le traitement:
        // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
        // - sinon juste: TCPLock lock(cnx);

        if(requestString == "addImage") //Ajout d'une image dans la Bdd
        {

        }
        else if(requestString == "addVideo") //Ajout d'une vidéo dans la Bdd
        {

        }
        else if(requestString == "addFilm") //Ajout d'un film dans la Bdd
        {

        }
        else if(requestString == "addGroup") //Ajout d'un groupe dans la Bdd
        {

        }
        else if(requestString == "addMultimediaToGroup") //Association d'un objet multimédia avec un groupe
        {

        }
        else if(requestString == "remove") //Suppression d'un objet multimédia ou d'un groupe
        {

        }
        else if(requestString == "find") //Recherche un objet multimédia ou un groupe
        {

        }
        else if(requestString == "play") //Joue un objet multimédia
        {

        }
        else //Instruction inexistante
        {
            response = "Erreur : Instruction inexistante !!!";
        }

        // 3) retourner la reponse au client:
        // - pour l'instant ca retourne juste OK suivi de la requête
        // - pour retourner quelque chose de plus utile on peut appeler la methode print()
        //   des objets ou des groupes en lui passant en argument un stringstream
        // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
        //   ils servent à délimiter les messages entre le serveur et le client

        cerr << "response: " << response << endl;

        // renvoyer false si on veut clore la connexion avec le client
        return true;
    }
};


int main(int argc, char* argv[])
{
    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    shared_ptr<MyBase> base(new MyBase());

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*base, &MyBase::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
    }

    return 0;
}

/*
Bdd * bdd = new Bdd();
GroupPtr vGroup;
MultimediaPtr vid;

vGroup = bdd->add("Mes Videos");
vGroup = bdd->add("Mes Documents");

vid = bdd->add("video1", "dossierPerso/film/video1.avi", 10);
vid = bdd->add("video2", "dossierPerso/film/video2.avi", 15);
vid = bdd->add("video best of", "dossierPerso/film/video_best_of.avi", 5);
vid = bdd->add("Logo ENST", "./image/Logo_Télécom_ParisTech.png", 640, 480);

bdd->addMultimediaToGroup("video1", "Mes Videos");
bdd->addMultimediaToGroup("video2", "Mes Videos");
bdd->addMultimediaToGroup("video best of", "Mes Videos");

bdd->addMultimediaToGroup("video1", "Mes Documents");
bdd->addMultimediaToGroup("video2", "Mes Documents");
bdd->addMultimediaToGroup("video best of", "Mes Documents");
bdd->addMultimediaToGroup("Logo ENST", "Mes Documents");

bdd->find("Mes Videos");
bdd->find("Mes Documents");

bdd->remove("video2");

bdd->find("Mes Videos");
bdd->find("Mes Documents");
*/

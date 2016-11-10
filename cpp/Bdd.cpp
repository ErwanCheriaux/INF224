#include "Bdd.h"


/*!
 * \brief Permet d'ajouter une Image à la Base de données
 * \param name
 * \param pathname
 * \param latitude
 * \param longitude
 * \return
 */
MultimediaPtr Bdd::add(string name, string pathname, double latitude, double longitude)
{
    MultimediaMap::iterator it;

    //Vérification que l'objet multimédia n'existe pas déjà dans la Bdd
    it = multimediaMap.find(name);
    if(it != multimediaMap.end())
    {
        cerr << "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout de l'objet "+ name +" à la Bdd" << endl;
        MultimediaPtr media = MultimediaPtr(new Image(name, pathname, latitude, longitude));
        multimediaMap[name] = media;
        return media;
    }
}


/*!
 * \brief Permet d'ajouter une Vidéo à la Base de données
 * \param name
 * \param pathname
 * \param time
 * \return
 */
MultimediaPtr Bdd::add(string name, string pathname, int time)
{
    MultimediaMap::iterator it;

    //Vérification que l'objet multimédia n'existe pas déjà dans la Bdd
    it = multimediaMap.find(name);
    if(it != multimediaMap.end())
    {
        cerr << "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout de l'objet "+ name +" à la Bdd" << endl;
        MultimediaPtr media = MultimediaPtr(new Video(name, pathname, time));
        multimediaMap[name] = media;
        return media;
    }
}


/*!
 * \brief Permet d'ajouter un Film à la Base de données
 * \param name
 * \param pathname
 * \param time
 * \param chapter
 * \param nbChapter
 * \return
 */
MultimediaPtr Bdd::add(string name, string pathname, int time, const int *chapter, int nbChapter)
{
    MultimediaMap::iterator it;

    //Vérification que l'objet multimédia n'existe pas déjà dans la Bdd
    it = multimediaMap.find(name);
    if(it != multimediaMap.end())
    {
        cerr << "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout de l'objet "+ name +" à la Bdd" << endl;
        MultimediaPtr media = MultimediaPtr(new Film(name, pathname, time, chapter, nbChapter));
        multimediaMap[name] = media;
        return media;
    }
}


/*!
 * \brief Permet d'ajouter un groupe à la Base de données
 * \param name Nom du groupe que l'on souhaite créer
 * \return
 */
GroupPtr Bdd::add(string name)
{
    GroupMap::iterator it;

    //Vérification que le groupe n'existe pas déjà dans la Bdd
    it = groupMap.find(name);
    if(it != groupMap.end())
    {
        cerr << "---> Erreur : Le groupe "+ name +" existe déjà dans la Bdd" << endl;
        return nullptr;
    }
    else
    {
        cout << "--- Ajout du groupe "+ name +" à la Bdd" << endl;
        GroupPtr group = GroupPtr(new Group(name));
        groupMap[name] = group;
        return group;
    }
}


/*!
 * \brief Permet d'associer un objet multimédia avec un groupe.
 *        Ces derniers doivent déjà exister dans la Base de données.
 * \param multimediaName Nom de l'objet multimédia que l'on souhaite associer
 * \param groupName Nom du groupe dans lequel on souhaite mettre l'objet multimédia
 */
int Bdd::addMultimediaToGroup(const string multimediaName, const string groupName)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(multimediaName);
    groupIt = groupMap.find(groupName);

    //Vérification que l'objet et le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end())
    {
        cerr << "---> Erreur : "+ multimediaName +" n'existe pas dans la Bdd" << endl;
        return 1;
    }
    else if(groupIt == groupMap.end())
    {
        cerr << "---> Erreur : "+ groupName +" n'existe pas dans la Bdd" << endl;
        return 2;
    }
    else
    {
        cout << "--- l'objet multimédia "+ multimediaName +" est maintenant associé au groupe "+ groupName << endl;
        MultimediaPtr mp;
        GroupPtr gp;

        mp = multimediaMap[multimediaName];
        gp = groupMap[groupName];

        gp.get()->push_back(mp); //ajout l'objet dans le groupe
        gp.get()->unique(); //permet de supprimer les doublons
        return 0;
    }
}


/*!
 * \brief Permet de supprimer un objet multimédia ou un groupe de la Base de données
 * \param name Objet multimédia ou groupe que l'on souhaite supprimer
 */
int Bdd::remove(const string name)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(name);
    groupIt = groupMap.find(name);

    //Vérification que l'objet ou le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end() && groupIt == groupMap.end())
    {
        cerr << "---> Erreur : "+ name +" n'existe pas dans la Bdd" << endl;
        return 0;
    }
    else if(multimediaIt != multimediaMap.end())
    {
        cout << "--- Suppression de l'objet "+ name +" de la Bdd" << endl;

        MultimediaPtr mp;
        Group * g;

        //Suppréssion de l'objet dans tous les groupes (qu'il existe ou non)
        for (GroupMap::iterator it = groupMap.begin(); it != groupMap.end(); it++ )
        {
            g = it->second.get();
            mp = multimediaMap[name];
            g->remove(mp);
        }
        multimediaMap.erase(name);
        return 1;
    }
    else
    {
        cout << "--- Suppression du groupe "+ name +" de la Bdd" << endl;
        groupMap.erase(name);
        return 2;
    }
}


/*!
 * \brief Permet de chercher un objet multimédia ou un groupe dans la Base de données
 * \param name Objet multimédia ou groupe que l'on cherche
 */
void Bdd::find(ostream& s, const string name)
{
    MultimediaMap::iterator multimediaIt;
    GroupMap::iterator groupIt;

    multimediaIt = multimediaMap.find(name);
    groupIt = groupMap.find(name);

    //Vérification que l'objet et/ou le groupe existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end() && groupIt == groupMap.end())
    {
        s << "--- "+ name +" n'existe pas dans la Bdd;";
    }
    if(multimediaIt != multimediaMap.end())
    {
        s << "--- Affichage de l'objet multimédia "+ name +";";
        MultimediaPtr mp;
        mp = multimediaMap[name];
        mp.get()->display(s);
    }
    if(groupIt != groupMap.end())
    {
        s << "--- Affichage du groupe "+ name +";";
        GroupPtr gp;
        gp = groupMap[name];
        gp.get()->display(s);
    }
}


/*!
 * \brief Permet de jouer un objet multimédia de la Base de données
 * \param name Objet multimédia que l'on souhaite jouer
 */
void Bdd::play(const string name)
{
    MultimediaMap::iterator multimediaIt;

    multimediaIt = multimediaMap.find(name);

    //Vérification que l'objet existe bien dans la Bdd
    if(multimediaIt == multimediaMap.end())
    {
        cerr << "---> Erreur : "+ name +" n'existe pas dans la Bdd" << endl;
    }
    if(multimediaIt != multimediaMap.end())
    {
        cout << "--- Lecture de l'objet multimédia "+ name << endl;
        MultimediaPtr mp;
        mp = multimediaMap[name];
        mp.get()->play();
    }
}


/*!
 * \brief Permet de remplire la Base de données avec divers objets multimédias et groupe.
 *        Cela permet ainsi d'aller plus vite pour débugger.
 */
void Bdd::initBdd()
{
    add("mesVideos");
    add("mesDocuments");

    add("video1", "dossierPerso/film/video1.avi", 10);
    add("video2", "dossierPerso/film/video2.avi", 15);
    add("video_best_of", "dossierPerso/film/video_best_of.avi", 5);
    add("Logo_ENST", "./image/Logo_Télécom_ParisTech.png", 640, 480);

    addMultimediaToGroup("video1", "mesVideos");
    addMultimediaToGroup("video2", "mesVideos");
    addMultimediaToGroup("video_best_of", "mesVideos");

    addMultimediaToGroup("video1", "mesDocuments");
    addMultimediaToGroup("video2", "mesDocuments");
    addMultimediaToGroup("video_best_of", "mesDocuments");
    addMultimediaToGroup("Logo_ENST", "mesDocuments");
}


/*!
 * \brief Affiche tous les objets multimédia.
 * \param s
 */
void Bdd::displayAll(ostream& s)
{
    MultimediaPtr media;

    for (MultimediaMap::iterator it = multimediaMap.begin(); it != multimediaMap.end(); ++it)
    {
        media = multimediaMap[it->first];
        media->display(s);
    }
}


/*!
 * \brief Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
 *        Ca doit etre une methode de la classe qui gere les données, afin qu'elle puisse y accéder.
 * \param cnx Permet d'activer ou non un verrou pour ne pas laisser plusieurs clients modifier la Bdd en même temps
 * \param request contient la requête
 * \param response sert à indiquer la réponse qui sera renvoyée au client, si la fonction renvoie false la connexion est close.
 * \return
 */
bool Bdd::processRequest(TCPConnection& cnx, const string& request, string& response)
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

    if(requestString == "help") //Affiche les instructions possibles
    {
        TCPLock lock(cnx, false);
        stringstream responseStream;
        responseStream << "--- Help;- init;- addImage;- addVideo;- addFilm;- addTo;- remove;- find;- play;";
        getline(responseStream, response);
    }
    else if(requestString == "init") //Initialise la Bdd avec des objets multimédias et des groupes
    {
        TCPLock lock(cnx, true);
        initBdd();
        response = "--- Initialisation terminée";
    }
    else if(requestString == "addImage") //Ajout d'une image dans la Bdd
    {
        TCPLock lock(cnx, true);
        getline(requestStream, requestString, ' ');
        string name = requestString;
        getline(requestStream, requestString, ' ');
        string pathname = requestString;

        double latitude;
        double longitude;

        requestStream >> latitude;
        requestStream >> longitude;

        if(add(name, pathname, latitude, longitude) != nullptr)
            response = "--- Ajout de l'objet "+ name +" à la Bdd";
        else
            response = "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd";
    }
    else if(requestString == "addVideo") //Ajout d'une vidéo dans la Bdd
    {
        TCPLock lock(cnx, true);
        getline(requestStream, requestString, ' ');
        string name = requestString;
        getline(requestStream, requestString, ' ');
        string pathname = requestString;

        int time;

        requestStream >> time;

        if(add(name, pathname, time) != nullptr)
            response = "--- Ajout de l'objet "+ name +" à la Bdd";
        else
            response = "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd";
    }
    else if(requestString == "addFilm") //Ajout d'un film dans la Bdd
    {
        TCPLock lock(cnx, true);
        getline(requestStream, requestString, ' ');
        string name = requestString;
        getline(requestStream, requestString, ' ');
        string pathname = requestString;

        int time;
        int *chapter = nullptr;
        int nbChapter;

        requestStream >> time;
        //requestStream >> chapter;
        requestStream >> nbChapter;

        if(add(name, pathname, time, chapter, nbChapter) != nullptr)
            response = "--- Ajout de l'objet "+ name +" à la Bdd";
        else
            response = "---> Erreur : L'objet "+ name +" existe déjà dans la Bdd";
    }
    else if(requestString == "addGroup") //Ajout d'un groupe dans la Bdd
    {
        TCPLock lock(cnx, true);
        getline(requestStream, requestString, ' ');
        string name = requestString;

        if(add(name) != nullptr)
            response = "--- Ajout du groupe "+ name +" à la Bdd";
        else
            response = "---> Erreur : Le groupe "+ name +" existe déjà dans la Bdd";
    }
    else if(requestString == "addTo") //Association d'un objet multimédia avec un groupe
    {
        TCPLock lock(cnx, true);
        getline(requestStream, requestString, ' ');
        string multimediaName = requestString;
        getline(requestStream, requestString, ' ');
        string groupName = requestString;

        int res = addMultimediaToGroup(multimediaName, groupName);
        if(res == 0)
            response = "--- L'objet multimédia "+ multimediaName +" est maintenant associé au groupe "+ groupName;
        else if(res == 1)
            response = "---> Erreur : "+ multimediaName +" n'existe pas dans la Bdd";
        else if(res == 2)
            response = "---> Erreur : "+ groupName +" n'existe pas dans la Bdd";
    }
    else if(requestString == "remove") //Suppression d'un objet multimédia ou d'un groupe
    {
        TCPLock lock(cnx, true);
        getline(requestStream, requestString, ' ');
        string name = requestString;

        int res = remove(name);
        if(res == 0)
            response = "---> Erreur : "+ name +" n'existe pas dans la Bdd";
        else if(res == 1)
            response = "--- Suppression de l'objet "+ name +" de la Bdd";
        else if(res == 2)
            response = "--- Suppression du groupe "+ name +" de la Bdd";
    }
    else if(requestString == "find") //Recherche un objet multimédia ou un groupe
    {
        TCPLock lock(cnx, false);
        stringstream responseStream;

        getline(requestStream, requestString, ' ');
        string name = requestString;

        find(responseStream, name);
        getline(responseStream, response);
    }
    else if(requestString == "play") //Joue un objet multimédia
    {
        TCPLock lock(cnx, false);
        getline(requestStream, requestString, ' ');
        string name = requestString;

        play(name);
        response = "Lecture de l'objet "+ name +" en cours";
    }
    else //Instruction inexistante
    {
        TCPLock lock(cnx, false);
        stringstream responseStream;
        responseStream << "---> Erreur : Instruction inexistante !!!;- init;- addImage;- addVideo;- addFilm;- addTo;- remove;- find;- play;";
        getline(responseStream, response);
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


/*!
 * \brief save
 * \param fileName
 * \param objects
 * \return
 */
bool Bdd::save(const string & fileName)
{
    ofstream f;
    MultimediaPtr media;
    f.open(fileName);
    if (!f.is_open())
    {
        cerr << "Can't open file " << fileName << endl;
        return false;
    }
    for (MultimediaMap::iterator it = multimediaMap.begin(); it != multimediaMap.end(); ++it)
    {
        media = multimediaMap[it->first];
        media->write(f);
    }
    return true;
}


/*!
 * \brief load
 * \param fileName
 * \param objects
 * \return
 */
bool Bdd::load(const string & fileName)
{
    ifstream f;
    f.open(fileName);
    if (!f.is_open())
    {
        cerr << "Can't open file " << fileName << endl;
        return false;
    }
    while (f)
    {
        MultimediaPtr media;
        media->read(f);
        // pas d’erreur et pas en fin de fichier
        if (f.fail())
        {
            // erreur de lecture
            cerr << "Read error in " << fileName << endl;
            return false;
        }
        //else objects.push_back(media);
    }
    return true;
}

#ifndef BDD_H
#define BDD_H

#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "tcpserver.h"

#include <map>
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <vector>

#include <cereal/archives/binary.hpp>
#include <sstream>
#include <fstream>

using namespace cppu;

typedef shared_ptr<Multimedia> MultimediaPtr;
typedef shared_ptr<Group> GroupPtr;

typedef map<const string, MultimediaPtr> MultimediaMap;
typedef map<const string, GroupPtr> GroupMap;


/*!
 * \brief La classe Bdd est une base de données gérant la cohérence des données
 *        Elle contient la totalité des produits multimédias et des groupes
 */
class Bdd
{
    private:
        MultimediaMap multimediaMap;
        GroupMap groupMap;

    public:
        //constructeur
        Bdd(){cout << "=== BDD créé ===\n" << endl; initBdd();}

        //destructeur
        virtual ~Bdd(){cout << "---> Destruction de la BDD\n" << endl;}

        //methode

        virtual GroupPtr add(string name);

        //image
        virtual MultimediaPtr add(string name, string pathname, double latitude, double longitude);
        //vidéo
        virtual MultimediaPtr add(string name, string pathname, int time);
        //film
        virtual MultimediaPtr add(string name, string pathname, int time, const int *chapter, int nbChapter);

        virtual int addMultimediaToGroup(const string multimediaName, const string groupName);

        virtual int remove(const string name);

        virtual void find(ostream& s, const string name);

        virtual void play(const string name);

        virtual void initBdd();
        virtual bool processRequest(TCPConnection& cnx, const string& request, string& response);

        //virtual bool save(const string & fileName, const vector<Multimedia *> & objects);
        //virtual bool load(const string & fileName, vector<Multimedia *> & objects);

        /*!
         * \brief save
         * \param fileName
         * \return
         */
        virtual save(const string & fileName)
        {
          stringstream ss; // any stream can be used
          cereal::BinaryOutputArchive oarchive(ss); // Create an output archive
          MultimediaPtr media = MultimediaPtr(new Image(image, mesImages/image.jpg, 15, 15));
          oarchive(media); // Write the data to the archive
        }

        /*!
         * \brief load
         * \param fileName
         * \return
         */
        virtual void load(const string & fileName)
        {
          stringstream ss; // any stream can be used
          cereal::BinaryInputArchive iarchive(ss); // Create an input archive
          MultimediaPtr media;
          iarchive(media); // Read the data from the archive
        }
};

#endif // BDD_H

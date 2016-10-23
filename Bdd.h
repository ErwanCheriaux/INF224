#ifndef BDD_H
#define BDD_H

#include "Multimedia.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

#include <map>
#include <string>
using namespace std;

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
        Bdd(){cout << "=== BDD créé ===\n" << endl;}

        //destructeur
        virtual ~Bdd(){cout << "---> Destruction de la BDD\n" << endl;}

        //methode
        virtual MultimediaPtr add(MultimediaPtr media);
        virtual GroupPtr      add(GroupPtr group);

        virtual void remove(const string name);

        virtual void find(const string name);

        virtual void play(const string name);
};

#endif // BDD_H

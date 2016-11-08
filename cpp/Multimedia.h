#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

//#include <cereal/types/unordered_map.hpp>
//#include <cereal/types/memory.hpp>
//#include <cereal/archives/binary.hpp>
#include <fstream>

using namespace std;


/*!
 * \brief La classe Multimedia est la classe de base de tout objet multimédia (vidéo, image, ...)
 */
class Multimedia
{
    friend class Bdd;

    private:
        string _name;
        string _pathname;

    protected:
        //constructeur
        Multimedia();
        Multimedia(string name, string pathname);

    public:
        //destructeur
        virtual ~Multimedia() {cout << "---> Destruction de " + getName() << endl;}

        //getter
        virtual string getName() const {return _name;}
        virtual string getPathname() const {return _pathname;}

        //setter
        virtual void setName(string name){_name = name;}
        virtual void setPathname(string pathname){_pathname = pathname;}

        //sérialisation
        virtual const char* classname() const {return "Multimedia";}

        // This method lets cereal know which data members to serialize
        template<class Archive>
        void serialize(Archive & archive)
        {
          archive(_name, _pathname); // serialize things by passing them to the archive
        }

        /*!
         * \brief Permet d'écrire les objets sérialisé dans un fichier texte f
         * \param f Fichier texte
         */
        virtual void write(ostream & f)
        {
            f << _name << "\n" << _pathname << "\n";
        }

        /*!
         * \brief Permet de lire les objets sérialisé dans un fichier texte f
         * \param f Fichier texte
         */
        virtual void read(istream & f)
        {
            getline(f, _name);
            string name;
            getline(f, name);
            _name = stoi(name);

            getline(f, _pathname);
            string pathname;
            getline(f, pathname);
            _pathname = stoi(pathname);

            //f >> _name >> _pathname;
        }

        //methode abstraite
        virtual void play()=0;

        //methode
        virtual void display(ostream& s) const;
};

#endif // MULTIMEDIA_H

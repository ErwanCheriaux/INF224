#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
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

        /*!
         * \brief Permet d'écrire les objets sérialisé dans un fichier texte f
         * \param f Fichier texte
         */
        virtual void write(ostream & f){f << _name << "\n" << _pathname << "\n";}

        /*!
         * \brief Permet de lire les objets sérialisé dans un fichier texte f
         * \param f Fichier texte
         */
        virtual void read(istream & f){f >> _name >> _pathname;}

        //methode abstraite
        virtual void play()=0;

        //methode
        virtual void display(ostream& s) const;
};

#endif // MULTIMEDIA_H

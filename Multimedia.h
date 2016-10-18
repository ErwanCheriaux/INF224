#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <cstring>
#include <iostream>
using namespace std;


/*!
 * \brief La classe Multimedia est la classe de base de tout type de multimédia (vidéo, image, ...)
 */
class Multimedia
{
    private:
        string _name;
        string _pathname;

    public:
        //constructeur
        Multimedia();
        Multimedia(string name, string pathname);

        //destructeur
        //virtual ~Multimedia();

        //getter
        virtual string getName() const {return _name;}
        virtual string getPathname() const {return _pathname;}

        //setter
        virtual void setName(string name){_name = name;}
        virtual void setPathname(string pathname){_pathname = pathname;}

        //methode abstraite
        virtual void play()=0;

        //methode
        virtual void display(ostream& s) const;
};

#endif // MULTIMEDIA_H

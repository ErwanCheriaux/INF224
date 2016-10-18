#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <cstring>
#include <iostream>
using namespace std;


/*!
 * \brief The Multimedia class Classe de base de tout type de multimédia (vidéo, image, ...)
 */
class Multimedia
{
    private:
        string name;
        string pathname;

    public:
        //constructeur
        Multimedia();
        Multimedia(string _name, string _pathname);

        //destructeur
        //virtual ~Multimedia();

        //getter
        virtual string getName() const {return name;}
        virtual string getPathname() const {return pathname;}

        //setter
        virtual void setName(string _name){name = _name;}
        virtual void setPathname(string _pathname){pathname = _pathname;}

        //methode abstraite
        virtual void play()=0;

        //methode
        virtual void display(ostream& s) const;
};

#endif // MULTIMEDIA_H

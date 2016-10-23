#ifndef GROUP_H
#define GROUP_H

#include "Multimedia.h"

#include <list>
#include <memory>

typedef shared_ptr<Multimedia> MultimediaPtr;

/*!
 * \brief La classe Group est une liste contenant des produits multimédias (vidéo, image, ...)
 */
class Group : public list<MultimediaPtr>
{
    private:
        string _name;

    public:
        //constructeur
        Group();
        Group(string name);

        //destructeur
        virtual ~Group() {cout << "---> Destruction de " + getName() << endl;}

        //getter
        virtual string getName() const {return _name;}

        //setter
        virtual void setName(string name){_name = name;}

        //methode
        virtual void display(ostream& s) const;
};

#endif // GROUP_H

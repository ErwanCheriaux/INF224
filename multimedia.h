#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
using namespace std;

class Multimedia
{
    private:
        string name;
        string pathname;

    public:
        Multimedia();
        Multimedia(string _name, string _pathname);

        //virtual ~Multimedia();

        virtual string getName() const {return name;}
        virtual string getPathname() const {return pathname;}

        virtual void setName(string _name){name = _name;}
        virtual void setPathname(string _pathname){pathname = _pathname;}

        virtual void display(ostream& s) const;
};

#endif // MULTIMEDIA_H

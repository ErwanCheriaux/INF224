#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

/*!
 * \brief La classe Video hérite de multimédia
 *        Elle contient tout type de vidéo
 */
class Video : public Multimedia
{
    private:
        int _time;   // durée de la vidéo

    public:
        //constructeur
        Video() : _time(0) {}
        Video(string name, string pathname, int time):
            Multimedia(name, pathname), _time(time) {}

        //destructeur
        virtual ~Video() {cout << "---Destruction de " + getName() + "---\n" << endl;}

        //getter
        virtual int getTime() const {return _time;}

        //setter
        virtual void setTime(int time){_time = time;}

        //methode

        /*!
         * \brief Permet de jouer la vidéo avec le logiciel "mpv"
         */
        virtual void play()
        {
            string str = "mpv "+ getPathname() + getName() +" &";
            system(str.c_str());
        }

        virtual void display(ostream& s) const override
        {Multimedia::display(s); s << "time:" << getTime() << endl;}
};

#endif // VIDEO_H

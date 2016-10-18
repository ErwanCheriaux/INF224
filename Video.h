#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

/*!
 * \brief The Video class Herite de multimédia
 *        Permet de contenire tout type de vidéo
 */
class Video : public Multimedia
{
    private:
        int time;   // durée de la vidéo

    public:
        Video() : time(0) {}
        Video(string _name, string _pathname, int _time):
            Multimedia(_name, _pathname), time(_time) {}

        virtual int getTime() const {return time;}

        virtual void setTime(int _time){time = _time;}

        virtual void play()
        {
            string str = "mpv "+ getPathname() + getName() +" &";
            system(str.c_str());
        }

        virtual void display(ostream& s) const override
        {Multimedia::display(s); s << "time:" << time << endl;}
};

#endif // VIDEO_H

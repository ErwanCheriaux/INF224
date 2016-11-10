#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"


/*!
 * \brief La classe Video hérite de multimédia
 *        Elle contient tout type de vidéo
 */
class Video : public Multimedia
{
    friend class Bdd;

    private:
        int _time;   // durée de la vidéo

    protected:
        //constructeur
        Video() : _time(0) {}
        Video(string name, string pathname, int time):
            Multimedia(name, pathname), _time(time) {}

    public:
        //destructeur
        virtual ~Video() {}

        //getter
        virtual int getTime() const {return _time;}

        //setter
        virtual void setTime(int time){_time = time;}

        //sérialisation
        const char* classname() const override {return "Video";}

        void write(ostream & f) override
        {
            Multimedia::write(f);
            f << _time << "\n";
        }

        void read(istream & f) override
        {
            Multimedia::read(f);
            f >> _time;
        }

        //methode

        /*!
         * \brief Permet de jouer la vidéo avec le logiciel "mpv"
         */
        virtual void play()
        {
            string str = "mpv "+ getPathname()+" &";
            system(str.c_str());
        }

        virtual void display(ostream& s) const override
        {Multimedia::display(s); s << "time:" << getTime() << ";";}
};

#endif // VIDEO_H

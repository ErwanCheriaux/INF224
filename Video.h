#ifndef VIDEO_H
#define VIDEO_H

//#include "multimedia.h"

#endif // VIDEO_H


class Video : public Multimedia
{
    private:
        int time;   // durée de la vidéo

    public:
        Video(){time=0;}
        Video(int _time){time = _time;}

        virtual int getTime() const {return time;}

        virtual void setTime(int _time){time = _time;}

        virtual void display(ostream& s) const override
        {s << "time:" << time << endl;}
};

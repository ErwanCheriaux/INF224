#ifndef IMAGE_H
#define IMAGE_H

//#include "multimedia.h"

#endif // IMAGE_H

class Image : public Multimedia
{
    private:
        double latitude;    // coordonnée de l'image
        double longitude;

    public:
        Image(): latitude(0), longitude(0) {}
        Image(string _name, string _pathname, double _latitude, double _longitude):
            Multimedia(_name, _pathname), latitude(_latitude), longitude(_longitude) {}

        virtual double getLatitude() const {return latitude;}
        virtual double getLongitude() const {return longitude;}

        virtual void setLatitude(double _latitude){latitude = _latitude;}
        virtual void setLongitude(double _longitude){longitude = _longitude;}

        virtual void display(ostream& s) const override
        {Multimedia::display(s); s << "latitude:" << latitude << "\n" << "longitude:" << longitude << endl;}
};

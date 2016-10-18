#ifndef IMAGE_H
#define IMAGE_H

#include "Multimedia.h"

/*!
 * \brief The Image class Hérite de multimédia
 *        Permet de contenire tout type d'image
 */
class Image : public Multimedia
{
    private:
        double latitude;    // coordonnée de l'image
        double longitude;

    public:
        //construteur
        Image(): latitude(0), longitude(0) {}
        Image(string _name, string _pathname, double _latitude, double _longitude):
            Multimedia(_name, _pathname), latitude(_latitude), longitude(_longitude) {}

        //getter
        virtual double getLatitude() const {return latitude;}
        virtual double getLongitude() const {return longitude;}

        //setter
        virtual void setLatitude(double _latitude){latitude = _latitude;}
        virtual void setLongitude(double _longitude){longitude = _longitude;}

        //methode

        /*!
         * \brief play Permet de jouer une image avec le logiciel "imageJ"
         */
        virtual void play()
        {
            string str = "imagej "+ getPathname() + getName() +" &";
            system(str.c_str());
        }

        virtual void display(ostream& s) const override
        {Multimedia::display(s); s << "latitude:" << latitude << "\n" << "longitude:" << longitude << endl;}
};

#endif // IMAGE_H

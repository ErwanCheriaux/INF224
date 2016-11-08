#ifndef IMAGE_H
#define IMAGE_H

#include "Multimedia.h"


/*!
 * \brief La classe Image hérite de multimédia
 *        Elle contient tout type d'image
 */
class Image : public Multimedia
{
    friend class Bdd;

    private:
        // coordonnées de l'image
        double _latitude;
        double _longitude;

    protected:
        //construteur
        Image(): _latitude(0), _longitude(0) {}
        Image(string name, string pathname, double latitude, double longitude):
            Multimedia(name, pathname), _latitude(latitude), _longitude(longitude) {}

    public:
        //destructeur
        virtual ~Image() {}

        //getter
        virtual double getLatitude() const {return _latitude;}
        virtual double getLongitude() const {return _longitude;}

        //setter
        virtual void setLatitude(double latitude){_latitude = latitude;}
        virtual void setLongitude(double longitude){_longitude = longitude;}

        //sérialisation
        const char* classname() const override {return "Image";}

        void write(ostream & f) override
        {
            Multimedia::write(f);
            f << _latitude << "\n" << _longitude << "\n";
        }

        void read(istream & f) override
        {
            Multimedia::read(f);
            f >> _latitude >> _longitude;
        }

        //methode

        /*!
         * \brief Permet de jouer une image avec le logiciel "imageJ"
         */
        virtual void play()
        {
            string str = "imagej "+ getPathname() +" &";
            system(str.c_str());
        }

        virtual void display(ostream& s) const override
        {Multimedia::display(s); s << "latitude:" << getLatitude() << ";" << "longitude:" << getLongitude() << ";";}

        //sérialisation
        template<class Archive>
        void serialize(Archive & archive)
        {
          archive(_latitude, _longitude);
        }
};

#endif // IMAGE_H

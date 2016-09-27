#include "Multimedia.h"
#include "Image.h"
#include "Video.h"

int main()
{
    Multimedia *media = new Multimedia("Caravane Palace", "Magasin/DVD/");

    Image *ima= new Image("Joconde", "Magasin/Peinture/", 15, 12);
    Video *vid = new Video("Vacances de ski", "Maison/Vacances/Hiver/", 150);

    media->display(cout);
    ima->display(cout);
    vid->display(cout);
}

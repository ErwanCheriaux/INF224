#include "Multimedia.h"
#include "Image.h"
#include "Video.h"

int main()
{
    Multimedia *media = new Multimedia("Caravane Palace", "Magasin/DVD/");

    Image *ima= new Image();
    Video *vid = new Video();

    //Image *ima= new Image("Joconde", "Magasin/Peinture/");
    //Video *vid = new Video("Vacances de ski", "Maison/Vacances/Hiver/");

    media->display(cout);
    ima->display(cout);
    vid->display(cout);
}

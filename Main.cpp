#include "Multimedia.h"
#include "Image.h"
#include "Video.h"

int main()
{
    Image *ima = new Image("Logo_Télécom_ParisTech.png", "./image/", 12, 21);

    ima->display(cout);
    ima->play();
}

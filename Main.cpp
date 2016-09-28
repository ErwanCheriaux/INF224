#include "Multimedia.h"
#include "Image.h"
#include "Video.h"

int main()
{
    Multimedia *magasin[8];
    magasin[0] = new Image("famille1", "dossierPerso/image/", 10, 25.4);
    magasin[1] = new Image("famille2", "dossierPerso/image/", 10, 25.4);
    magasin[2] = new Image("famille3", "dossierPerso/image/", 10, 25.4);
    magasin[3] = new Image("famille4", "dossierPerso/image/", 10, 25.4);
    magasin[4] = new Video("famille1", "dossierPerso/video/", 30);
    magasin[5] = new Video("famille2", "dossierPerso/video/", 30);
    magasin[6] = new Video("famille3", "dossierPerso/video/", 30);
    magasin[7] = new Video("famille4", "dossierPerso/video/", 30);

    for(int i=0; i<8; i++)
    {
        magasin[i]->display(cout);
        cout << "\n" << endl;
    }
}

#include "Multimedia.h"

Multimedia::Multimedia()
{
    name = "";
    pathname = "";
}

Multimedia::Multimedia(string _name, string _pathname)
{
    name = _name;
    pathname = _pathname;
}

void Multimedia::display(ostream& s) const
{
    s << "name:" << name << "\n" << "pathname:" << pathname << endl;
}

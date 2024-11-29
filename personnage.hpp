#ifndef _PERSONNAGE_HPP_
#define _PERSONNAGE_HPP_

#include "objetgraphiquemobile.hpp"

using namespace std;


class Personnage : public ObjetGraphiqueMobile{

    // type = 4
    public :
    Personnage(int i, int j);
    void afficher() const;
};


#endif


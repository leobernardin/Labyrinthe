#ifndef OBJETGRAPHIQUEMOBILE_HPP_
#define OBJETGRAPHIQUEMOBILE_HPP_

#include "objetgraphique.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;


class ObjetGraphiqueMobile : public ObjetGraphique  {

    public :
    ObjetGraphiqueMobile(int i, int j, int t);
    void deplacerDroite();
    void deplacerGauche();
    void deplacerBas();
    void deplacerHaut();

};


#endif



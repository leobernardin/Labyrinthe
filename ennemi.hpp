#ifndef ENNEMI_HPP_
#define ENNEMI_HPP_
#include "objetgraphiquemobile.hpp"

class Ennemi : public ObjetGraphiqueMobile{

    // type = 5
    public :
    Ennemi(int i, int j);
    void afficher() const;
};
#endif


#ifndef _SORTIE_HPP_
#define _SORTIE_HPP_

#include "objetgraphiquefixe.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;


class Sortie : public ObjetGraphiqueFixe {

    // type = 3
    public :
    Sortie(int i, int j);
    void afficher() const;
};


#endif


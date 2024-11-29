#include "personnage.hpp"
#include "objetgraphiquemobile.hpp"

Personnage::Personnage(int i,int j):ObjetGraphiqueMobile(i,j,4){
}

void Personnage::afficher() const{
    cout << "P";
}



#include "ennemi.hpp"
#include "objetgraphiquemobile.hpp"

Ennemi::Ennemi(int i,int j):ObjetGraphiqueMobile(i,j,5){
}

void Ennemi::afficher() const{
    cout << "E";
}





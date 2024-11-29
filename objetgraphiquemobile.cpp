#include "objetgraphiquemobile.hpp"
#include "objetgraphique.hpp"

ObjetGraphiqueMobile::ObjetGraphiqueMobile(int i,int j,int t):ObjetGraphique(i,j,t){

};


void ObjetGraphiqueMobile::deplacerDroite(){
    m_j++;
}

void ObjetGraphiqueMobile::deplacerGauche(){
    m_j--;
}

void ObjetGraphiqueMobile::deplacerBas(){
    m_i++;
}

void ObjetGraphiqueMobile::deplacerHaut(){
    m_i--;
}


#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include "objetgraphiquefixe.hpp"
#include "objetgraphiquemobile.hpp"


#include <iostream>
#include <stdexcept>

using namespace std;


class Plateau {

    protected :
        int m_nbl;
        int m_nbc;
        ObjetGraphiqueFixe ***m_plateau;

    public :
        //Plateau();                     // Constructeur par d�faut
        //Plateau(const Plateau& p);     // Constructeur de copie
        Plateau(int l , int c);          // Constructeur param�tr�
        //~Plateau();                    // Destructeur

        void setCase(int i, int j, ObjetGraphiqueFixe* o);
        ObjetGraphiqueFixe* getCase(int i, int j) const;
        void afficher() const;
        void afficher(ObjetGraphiqueMobile& p, ObjetGraphiqueMobile& e) const;

        //surcharge de l'operateur "==" dans Plateau
        bool operator==(const Plateau& other) const;
};



#endif

#ifndef _LABYRINTHE_HPP_
#define _LABYRINTHE_HPP_

#include "plateau.hpp"
#include "personnage.hpp"
#include "ennemi.hpp"
#include "sortie.hpp" //peut etre a enlever

using namespace std;

class Labyrinthe{

    protected :

        int m_nbl, m_nbc;
        Plateau* m_plateau;
        Personnage* m_personnage;
        Ennemi* m_ennemi;
        Sortie* m_sortie;

        // methodes :

    public :

        // constructeur :
        Labyrinthe(int l, int c);
        //Labyrinthe(const labyrinthe&l);
        Labyrinthe(); //Constructeur pour lire fichiers
        ~Labyrinthe(); //Destructeur

        // methodes :
        void afficher() const;
        void deplacerPersoDroite();
        void deplacerPersoGauche();
        void deplacerPersoHaut();
        void deplacerPersoBas();
        //Ennemi :
		void deplacerEnnemi();

        int fini() const;
        bool EstDansPlateau(int i, int j) const;

        //surcharge de l'operateur "==" a corriger dans cpp
        //bool operator==(const Labyrinthe& other) const;

};

class ExceptionMouvement{
    public:
        string message;
        ExceptionMouvement(string m =""){message=m;}
};


#endif

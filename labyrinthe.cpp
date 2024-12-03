#include "labyrinthe.hpp"
#include "personnage.hpp"
#include <cstdlib> // pour random
#include "sortie.hpp" // peut etre a enlever

//akuete


Labyrinthe :: Labyrinthe(int l, int c){

    m_nbl = l;
    m_nbc = c;
    m_plateau = new Plateau(m_nbl,m_nbc);
    m_personnage = new Personnage(1,6);
    m_sortie = new Sortie(m_nbl-1,7);
    m_ennemi = new Ennemi(5,8);
}

Labyrinthe :: Labyrinthe(){ // va nous servir pour lire les fichiers

    int m_nbc = 2;
    int m_nbl = 2;
	m_plateau = new Plateau();
    m_personnage = new Personnage(1,0);
    m_sortie = new Sortie(2,0);
    m_ennemi = new Ennemi(0,1);

}

// Constructeur de recopie a faire
Labyrinthe :: Labyrinthe(const Labyrinthe&l){
	m_nbc = l.m_nbc ;
    m_nbl = l.m_nbl;
    m_plateau = l.m_plateau;
    
    int Per_i = l.m_personnage->getI();
    int Per_j = l.m_personnage->getJ();
    
    int Sortie_i = l.m_sortie->getI();
    int Sortie_j = l.m_sortie->getJ();
    
	int Ennemi_i = l.m_ennemi->getI();
    int Ennemi_j = l.m_ennemi->getJ();
    
    m_personnage = new Personnage(Per_i, Per_j);
    m_sortie = new Sortie(Sortie_i, Sortie_j);
    m_ennemi = new Ennemi(Ennemi_i, Ennemi_j);
    
}


Labyrinthe :: ~Labyrinthe(){

    delete[] m_plateau;
    delete[] m_personnage;
    delete[] m_ennemi;
    delete[] m_sortie;
}


void Labyrinthe :: deplacerPersoDroite(){

    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j +1)->getType();

    if ((m_personnage->m_i == m_ennemi->m_i) && (m_personnage->m_j +1 == m_ennemi->m_j)){
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}

    if(EstDansPlateau(m_personnage->m_i,m_personnage->m_j +1) && (type == 2 || type == 3) && ((m_personnage->m_i != m_ennemi->m_i) || (m_personnage->m_j +1 != m_ennemi->m_j))) {
        m_personnage->deplacerDroite();

	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present.");
	}

}

void Labyrinthe :: deplacerPersoGauche(){

    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j-1)->getType();

    if ((m_personnage->m_i == m_ennemi->m_i) && (m_personnage->m_j -1 == m_ennemi->m_j)){
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}

    if(EstDansPlateau(m_personnage->m_i,m_personnage->m_j -1) && (type == 2 || type == 3) && ((m_personnage->m_i != m_ennemi->m_i) ||(m_personnage->m_j -1 != m_ennemi->m_j))) {
        m_personnage->deplacerGauche();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present.");
	}

}



void Labyrinthe :: deplacerPersoHaut(){

    int type = m_plateau->getCase(m_personnage->m_i-1,m_personnage->m_j)->getType();

    if ((m_personnage->m_i -1 == m_ennemi->m_i) && (m_personnage->m_j == m_ennemi->m_j)){
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}

    if(EstDansPlateau(m_personnage->m_i -1,m_personnage->m_j) && (type == 2 || type == 3) && ((m_personnage->m_i -1 != m_ennemi->m_i) || (m_personnage->m_j != m_ennemi->m_j))) {
        m_personnage->deplacerHaut();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present.");
	}
}


void Labyrinthe :: deplacerPersoBas(){

    int type = m_plateau->getCase(m_personnage->m_i+1,m_personnage->m_j)->getType();

    if ((m_personnage->m_i +1 == m_ennemi->m_i) && (m_personnage->m_j == m_ennemi->m_j)){
        throw ExceptionMouvement("Impossible de se deplacer ici, l'ennemi est present.");
	}


    if(EstDansPlateau(m_personnage->m_i+1,m_personnage->m_j) && (type == 2 || type == 3) && ((m_personnage->m_i +1 != m_ennemi->m_i) || (m_personnage->m_j != m_ennemi->m_j))) {
        m_personnage->deplacerBas();
	}
	if(type == 1){
		throw ExceptionMouvement("Impossible de se deplacer ici, un mur est present.");
	}
}

// ajouter conditon pour que l'enemi bouge toujours. ou pas.
void Labyrinthe :: deplacerEnnemi(){

	int random;
	int booleen = 0;

	while (booleen == 0) {

        random = rand() %4;

        if(random == 0){ // Mouvement à droite
            int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j +1)->getType();

            if(EstDansPlateau(m_ennemi->m_i,m_ennemi->m_j -1) && (type == 2 || type == 4)) {
                m_ennemi->deplacerDroite();
                booleen = 1;
            }
        }

        else if(random == 1){ // A gauche
            int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j -1)->getType();

            if(EstDansPlateau(m_ennemi->m_i,m_ennemi->m_j +1) && (type == 2 || type == 4)) {
                m_ennemi->deplacerGauche();
                booleen = 1;
            }
        }

        else if(random == 2){ // en haut
            int type = m_plateau->getCase(m_ennemi->m_i-1,m_ennemi->m_j)->getType();

            if(EstDansPlateau(m_ennemi->m_i - 1,m_ennemi->m_j) && (type == 2 || type == 4)) {
                m_ennemi->deplacerHaut();
                booleen = 1;
            }

        }

        else if(random == 3){ // en Bas
            int type = m_plateau->getCase(m_ennemi->m_i+1,m_ennemi->m_j)->getType();

            if(EstDansPlateau(m_ennemi->m_i +1,m_ennemi->m_j) && (type == 2 || type == 4)) {
                m_ennemi->deplacerBas();
                booleen = 1;
            }

        }
	}


}

// renvoie 1 si perso arrive a Sortie. Sinon renvoie 2 si l'ennemi le rattrape.

int Labyrinthe :: fini() const{

	int fini = 0;
    if(m_personnage->m_i == m_sortie->m_i && m_personnage->m_j == m_sortie->m_j){
        fini = 1;
        return fini;
    }
    else if (m_personnage->m_i == m_ennemi->m_i && m_personnage->m_j == m_ennemi->m_j){
        fini = 2;
        return fini;
    }
    return fini;

}


bool Labyrinthe :: EstDansPlateau(int i,int j) const{

    if(i< m_nbl && j< m_nbc && i>=0 && j>= 0){
        return true;
    }
}

void Labyrinthe :: afficher() const {

    m_plateau->afficher(*m_personnage, *m_ennemi);
}

// surharge de l'operateur "==" a corriger

/*bool Labyrinthe::operator==(const Labyrinthe& other) const {

    if (m_nbl == other.m_nbl && m_nbc == other.m_nbc){
        for(int i = 0; i<m_nbl; i++){
                for(int j = 0; j<m_nbc; j++){
                    if ()
                }

        }
    }
    return false;
}
*/

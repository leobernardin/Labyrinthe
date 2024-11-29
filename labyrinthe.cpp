#include "labyrinthe.hpp"
#include "personnage.hpp"
#include <cstdlib> // pour random
#include "sortie.hpp" // peut etre a enlever



Labyrinthe :: Labyrinthe(int l, int c){
    m_nbl = l;
    m_nbc = c;
    m_plateau = new Plateau(m_nbl,m_nbc);
    m_personnage = new Personnage(1,6);
    m_sortie = new Sortie(m_nbl-1,7);
    m_ennemi = new Ennemi(3,4);
}

/*Labyrinthe :: Labyrinthe(int l = 0, int c = 0, *plateau = nullptr, *personnage = nullptr){
    m_nbc = c;
    m_nbl = l;
    m_plateau = plateau;
    m_personnage =personnage;

}
*/

/*Labyrinthe :: ~Labyrinthe(){
    delete[] m_plateau*;
    delete[] m_personnage*;

}*/

void Labyrinthe :: deplacerPersoDroite(){

    //int i = m_personnage.getI();
    //int j = m_personnage.getJ();
    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j +1)->getType();

    if(EstDansPlateau(m_personnage->m_i,m_personnage->m_j +1) && (type == 2 || type == 3)) {
        m_personnage->deplacerDroite();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}

}

void Labyrinthe :: deplacerPersoGauche(){

    //int i = m_personnage.getI();
    //int j = m_personnage.getJ();
    int type = m_plateau->getCase(m_personnage->m_i,m_personnage->m_j-1)->getType();

    if(EstDansPlateau(m_personnage->m_i,m_personnage->m_j -1) && (type == 2 || type == 3)) {
        m_personnage->deplacerGauche();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}

}



void Labyrinthe :: deplacerPersoHaut(){

    //int i = m_personnage.getI();
    //int j = m_personnage.getJ();
    int type = m_plateau->getCase(m_personnage->m_i-1,m_personnage->m_j)->getType();

    if(EstDansPlateau(m_personnage->m_i -1,m_personnage->m_j) && (type == 2 || type == 3)) {
        m_personnage->deplacerHaut();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}

}


void Labyrinthe :: deplacerPersoBas(){

    //int i = m_personnage.getI();
    //int j = m_personnage.getJ();
    int type = m_plateau->getCase(m_personnage->m_i+1,m_personnage->m_j)->getType();

    if(EstDansPlateau(m_personnage->m_i+1,m_personnage->m_j) && (type == 2 || type == 3)) {
        m_personnage->deplacerBas();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement, Mur");
	}

}

// ajouter conditon pour que l'enemi bouge toujours. ou pas.
void Labyrinthe :: deplacerEnnemi(){

	int random;
	random = rand() %4;
	if(random == 0){ // Mouvement à droite
	int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j +1)->getType();

    if(EstDansPlateau(m_ennemi->m_i,m_ennemi->m_j -1) && (type == 2 || type == 3)) {
        m_ennemi->deplacerDroite();
		}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement Ennemi, Mur");
		}
	}
	else if(random == 1){ // A gauche
	int type = m_plateau->getCase(m_ennemi->m_i,m_ennemi->m_j -1)->getType();

    if(EstDansPlateau(m_ennemi->m_i,m_ennemi->m_j +1) && (type == 2 || type == 3)) {
        m_ennemi->deplacerGauche();
		}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement Ennemi, Mur");
		}
	}
	else if(random == 2){ // en haut
	int type = m_plateau->getCase(m_ennemi->m_i-1,m_ennemi->m_j)->getType();

    if(EstDansPlateau(m_ennemi->m_i - 1,m_ennemi->m_j) && (type == 2 || type == 3)) {
        m_ennemi->deplacerHaut();
		}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement Ennemi, Mur");
		}

	}

	else if(random == 3){ // en Bas
	int type = m_plateau->getCase(m_ennemi->m_i+1,m_ennemi->m_j)->getType();

    if(EstDansPlateau(m_ennemi->m_i +1,m_ennemi->m_j) && (type == 2 || type == 3)) {
        m_ennemi->deplacerBas();
	}
	if(type == 1){
		throw ExceptionMouvement("Pas de mouvement Ennemi, Mur");
		}

	}


}






bool Labyrinthe :: fini() const{
	bool finit = false;
    if(m_personnage->m_i == m_sortie->m_i && m_personnage->m_j == m_sortie->m_j){
        finit = true;
		return finit;
    }
    else{
    	return false;
}
}

bool Labyrinthe :: fini2() const{
	bool finit = false;
    if(m_personnage->m_i == m_ennemi->m_i && m_personnage->m_j == m_ennemi->m_j){
        finit = true;
		return finit;
    }
    else{
    	return false;
}
}


bool Labyrinthe :: EstDansPlateau(int i,int j) const{
    if(i< m_nbl && j< m_nbc && i>=0 && j>= 0){
        return true;
    }
}

void Labyrinthe :: afficher() const {
    m_plateau->afficher(*m_personnage, *m_ennemi);
}

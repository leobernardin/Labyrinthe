#include "plateau.hpp"
#include "labyrinthe.hpp"
#include "mur.hpp"
#include "couloir.hpp"
#include "sortie.hpp"
#include "ennemi.hpp"


Plateau :: Plateau(int l, int c){
    m_nbl = l;
    m_nbc = c;
    m_plateau = new ObjetGraphiqueFixe**[m_nbl];

    for (int i =0; i<m_nbl; i++){
        m_plateau[i] = new ObjetGraphiqueFixe*[m_nbc];
    }

    for(int i = 0; i<m_nbl; i++){
        for(int j=0; j<m_nbc; j++){
                if(i==0 || i==m_nbl-1 || j==0 || j==m_nbc-1){
                    setCase(i,j,new Mur(i,j));
                }
                else if(i==2 && j!=2 && j!= 6 &&j!=8){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==4 && j!=1 && j!= 7 && j!= 10){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==6 && j!=7&& j!= 3 && j!= 5&& j!= 9){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==8 && j!=2 && j!= 9){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(i==8 && j!=2 && j!= 9){
                	  setCase(i,j, new Mur(i,j));
				}
				else if(j==8 && (i==5|| i ==6 || i== 7 || i ==8 || i==9)){
                	  setCase(i,j, new Mur(i,j));
				}
                else{
                    setCase(i,j, new Couloir(i,j));
                }
        }
    }

    setCase(m_nbl-1,7, new Sortie(m_nbl-1,7));


}

void Plateau :: setCase(int i, int j, ObjetGraphiqueFixe* o){
    m_plateau[i][j] = o;
}

ObjetGraphiqueFixe* Plateau :: getCase(int i, int j) const{
    if ((i >= 0) && (i < m_nbl) && (j >= 0) && (j < m_nbc)) {
        return m_plateau[i][j];
    } else {
        return NULL;
    }
}


void Plateau :: afficher(ObjetGraphiqueMobile&p,ObjetGraphiqueMobile&e ) const{

    int l = p.getI();
    int c = p.getJ();
	int l1 = e.getI();
    int c1 = e.getJ();
        for(int i = 0; i<m_nbl; i++){
            for(int j=0; j<m_nbc; j++){
                if(i == l && c==j && p.getType() == 4){
                    p.afficher();
                    }
                if(i == l1 && c1==j && e.getType() == 5){
                    e.afficher();
                    }
                else{
                    getCase(i,j)->afficher();
                }

            }
            cout << endl;
        }
}

void Plateau :: afficher() const{
    for(int i = 0; i<m_nbl; i++){
        for(int j=0; j<m_nbc; j++){
            getCase(i,j)->afficher();
        }
        cout << endl;
    }

}

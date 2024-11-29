#include "objetgraphique.hpp"



ObjetGraphique::ObjetGraphique(int i, int j, int t){
    m_i = i;
    m_j = j;
    m_type = t;
}

ObjetGraphique::ObjetGraphique(const ObjetGraphique& o){
    m_i = o.m_i;
    m_j = o.m_j;
    m_type = o.m_type;
}


int ObjetGraphique::getType() const {
    return m_type;
}

int ObjetGraphique::getI() const {
    return m_i;
}

int ObjetGraphique::getJ() const {
    return m_j;
}

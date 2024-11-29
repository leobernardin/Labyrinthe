#ifndef _OBJETGRAPHIQUE_HPP_
#define _OBJETGRAPHIQUE_HPP_

#include <iostream>
#include <stdexcept>


class ObjetGraphique{

    public :
    int m_i, m_j, m_type;

    public:

    ObjetGraphique(int i=0, int j=0, int t=0);
    ObjetGraphique(const ObjetGraphique& o);

    int getType() const;
    int getI() const;
    int getJ() const;
    virtual void afficher() const = 0;
};

using std::cout;

#endif

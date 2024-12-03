#include "labyrinthe.hpp"
#include "plateau.hpp"
#include "personnage.hpp"
#include "objetgraphique.hpp"
#include "objetgraphiquefixe.hpp"
#include "objetgraphiquemobile.hpp"
#include "mur.hpp"
#include "couloir.hpp"
#include "sortie.hpp"

#include <iostream>


//Ca marche ?

int main(){


   
    
    //pour tester les constructeurs : 
    /*
    Labyrinthe l(11,11);
    cout<<"Labyrinthe 1 : \n";
    l.afficher();
    //constructeur defaut
	Labyrinthe l2;
    cout<<"Labyrinthe 2 : \n";
    l2.afficher();
    
    Labyrinthe l3;
    cout<<"Labyrinthe 3 apres copie du labyrinthe 1 : \n";
    l3 = l;
    l3.afficher();
    */
	
	//main principal
	Labyrinthe l(11,11);
	l.afficher();
    char reponse;

    while (l.fini() == 0){

        cout << "Quelle action voulez-vous faire ? (d : droite, g : gauche, h : haut, b : bas)" << endl;
        cin >> reponse;

        switch (reponse) {

            case 'd' :
            try{
                l.deplacerPersoDroite();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
                //deplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
				l.afficher();
                break;

            case 'g' :
            try{
                l.deplacerPersoGauche();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
                //deplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
                l.afficher();
                break;

            case 'h' :
            try{
                l.deplacerPersoHaut();
            }catch (ExceptionMouvement& ex){
				cerr << ex.message << endl;
			}
                                //deplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
                l.afficher();
                break;

            case 'b' :
                try{
                l.deplacerPersoBas();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
            	                //deplacement ennemi :
            try{
                l.deplacerEnnemi();
            }catch (ExceptionMouvement& ex){
					cerr << ex.message << endl;
				}
				cout<<"Apres deplacement Ennemi : \n";
                l.afficher();
                break;

            default :
                cout << "Choix Invalide. Reessayez. \n";
        }
    }

	if(l.fini() == 1){
		cout << "La partie est finie. Vous avez atteint la sortie." << endl;

	}
	else if(l.fini() == 2){
		cout << "Vous avez Perdu. L'ennemi vous a trouve " << endl;

	}

}

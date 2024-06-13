/////////////////////////////////////////////////////////////////////////////
//Fichier JeuSerpentsEtEchelles.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file JeuSerpentsEtEchelles.cpp
 * \brief Ce fichier contient une implémentation de la classe JeuSerpentsEtEchelles
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2024
 */


#include "JeuSerpentsEtEchelles.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

namespace tp1
{

    /**
     * @brief Constructeur par défaut de la classe JeuSerpentsEtEchelles.
     */
    JeuSerpentsEtEchelles::JeuSerpentsEtEchelles()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    /**
     * @brief Joue le jeu de serpents et échelles pour un nombre maximum de tours.
     * @param maximumDeTours Le nombre maximum de tours à jouer.
     * @return Le résultat du jeu (nombre de tours réalisés et nom du gagnant).
     */
    Resultat JeuSerpentsEtEchelles::jouer(unsigned int maximumDeTours) {
        int numeroDeCarteCourante = 0;
        for (unsigned int tour = 1; tour <= maximumDeTours; ++tour) {
            unsigned int nombreDeJoueurs = m_joueurs.taille();

            for (unsigned int i = 0; i < nombreDeJoueurs; ++i)
            {
                Joueur joueurCourant = m_joueurs.defiler();

                numeroDeCarteCourante = (numeroDeCarteCourante == m_choix.taille()) ? 1 : numeroDeCarteCourante + 1;

                Case::Couleur couleurActuelle = m_choix.element(numeroDeCarteCourante);

                if (joueurCourant.position.existeCaseSuivante(couleurActuelle))
                {
                    joueurCourant.position.caseSuivante(couleurActuelle);

                    if (joueurCourant.position.caseCourante().decoration == Case::Serpent) {
                        numeroDeCarteCourante = (numeroDeCarteCourante == m_choix.taille()) ? 1 : numeroDeCarteCourante + 1;

                        while (joueurCourant.position.existeCasePrecedente(m_choix.element(numeroDeCarteCourante)) &&
                               joueurCourant.position.positionCourante() != 1) {
                            joueurCourant.position.casePrecedente(m_choix.element(numeroDeCarteCourante));
                        }

                    } else if (joueurCourant.position.caseCourante().decoration == Case::Echelle) {
                        numeroDeCarteCourante = (numeroDeCarteCourante == m_choix.taille()) ? 1 : numeroDeCarteCourante + 1;

                        while (joueurCourant.position.existeCaseSuivante(m_choix.element(numeroDeCarteCourante))) {
                            joueurCourant.position.caseSuivante(m_choix.element(numeroDeCarteCourante));
                        }
                    }

                    if (joueurCourant.position.estADerniereCase()) {
                        return {tour, joueurCourant.nom};
                    }
                }
                m_joueurs.enfiler(joueurCourant);
            }
        }
        return {maximumDeTours};
    }

    /**
     * @brief Efface le jeu en vidant les listes de cases, choix et joueurs.
     */
    void JeuSerpentsEtEchelles::effacer()
    {
        while (m_cases.taille() > 0)
            m_cases.enleverCase(1);
        while (m_choix.taille() > 0)
            m_choix.enleverPos(1);
        while (m_joueurs.taille() > 0)
            m_joueurs.defiler();
    }

    /**
     * @brief Ajoute une case au jeu.
     * @param _case La case à ajouter.
     */
    void JeuSerpentsEtEchelles::ajouterCase(Case &_case)
    {
        m_cases.ajouterCaseALaFin(_case);
    }

    /**
     * @brief Ajoute un choix de couleur au jeu.
     * @param couleur La couleur à ajouter.
     */
    void JeuSerpentsEtEchelles::ajouterChoix(Case::Couleur couleur)
    {
        m_choix.ajouterFin(couleur);
    }

    /**
     * @brief Ajoute un joueur au jeu.
     * @param joueur Le joueur à ajouter.
     */
    void JeuSerpentsEtEchelles::ajouterJoueur(Joueur joueur)
    {
        m_joueurs.enfiler(joueur);
    }

    /**
     * @brief Retourne un itérateur pointant vers la première case du jeu.
     * @return L'itérateur de la première case.
     */
    ListeDeCases::Iterateur JeuSerpentsEtEchelles::premiereCase()
    {
        return m_cases.debut();
    }

    /**
     * @brief Surcharge de l'opérateur << pour afficher un joueur.
     * @param os Le flux de sortie.
     * @param joueur Le joueur à afficher.
     * @return Le flux de sortie.
     */
    ostream& operator<<(ostream& os, const Joueur & joueur)
    {
        os << joueur.nom << " : " << joueur.position.positionCourante();
        return os;
    }

    /**
     * @brief Affiche les résultats du jeu.
     * @param gagnant Le résultat du jeu (nombre de tours réalisés et nom du gagnant).
     */
    void JeuSerpentsEtEchelles::afficheResultats(Resultat gagnant)
    {
        if (gagnant.nom != "")
            cout << "Gagnant : " << gagnant.nom << endl;
        else
            cout << "Aucun gagnant" << endl;
        cout << "Nombre de tours realises : " << gagnant.nombreDeTours << endl;
        cout << "Position des joueurs : " << endl;
        cout << m_joueurs << endl;

        cout << "Plateau de jeu:" << endl;
        cout << m_cases << endl;

        cout << "Liste de choix:" << endl;
        cout << m_choix << endl;
    }

}
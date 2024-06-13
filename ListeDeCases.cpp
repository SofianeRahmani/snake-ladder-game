/////////////////////////////////////////////////////////////////////////////
//Fichier ListeDeCases.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeDeCases.cpp
 * \brief Ce fichier contient une implémentation de la classe ListeDeCases
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2024
 */

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "ListeDeCases.h"

using std::string;
using std::ostringstream;
using std::out_of_range;
using std::range_error;

namespace tp1
{
    /**
     * @brief Constructeur par défaut de la classe ListeDeCases.
     */
    ListeDeCases::ListeDeCases() : m_debut(nullptr), m_fin(nullptr), m_taille(0) {}

    /**
     * @brief Destructeur de la classe ListeDeCases.
     * Libère la mémoire allouée pour chaque noeud.
     */
    ListeDeCases::~ListeDeCases()
    {
        Noeud* current = m_debut;
        while (current != nullptr)
        {
            Noeud* temp = current;
            current = current->m_suivant;
            delete temp;
        }
    }

    /**
     * @brief Retourne la taille de la liste.
     * @return La taille de la liste.
     */
    int ListeDeCases::taille() const
    {
        return m_taille;
    }

    /**
     * @brief Vérifie si la liste est vide.
     * @return true si la liste est vide, false sinon.
     */
    bool ListeDeCases::estVide() const
    {
        return m_taille == 0;
    }

    /**
     * @brief Ajoute une case à une position spécifique de la liste.
     * @param uneCase La case à ajouter.
     * @param position La position où ajouter la case.
     * @throws std::range_error Si la position est invalide (hors bornes).
     */
    void ListeDeCases::ajouterCase(const Case& uneCase, int position)
    {
        if (position < 0 || position > m_taille)
        {
            throw std::range_error("Ajout impossible: Position invalide (hors-bornes).");
        }

        Noeud* nouveauNoeud = new Noeud(uneCase);
        if (m_taille == 0)
        {
            m_debut = m_fin = nouveauNoeud;
        }
        else if (position == 0)
        {
            nouveauNoeud->m_suivant = m_debut;
            m_debut->m_precedent = nouveauNoeud;
            m_debut = nouveauNoeud;
        }
        else if (position == m_taille)
        {
            nouveauNoeud->m_precedent = m_fin;
            m_fin->m_suivant = nouveauNoeud;
            m_fin = nouveauNoeud;
        }
        else
        {
            Noeud* positionNoeudActuelle = noeudAt(position);
            nouveauNoeud->m_suivant = positionNoeudActuelle;
            nouveauNoeud->m_precedent = positionNoeudActuelle->m_precedent;
            positionNoeudActuelle->m_precedent->m_suivant = nouveauNoeud;
            positionNoeudActuelle->m_precedent = nouveauNoeud;
        }

        m_taille++;
    }

    /**
     * @brief Ajoute une case à la fin de la liste.
     * @param uneCase La case à ajouter.
     */
    void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
    {
        ajouterCase(uneCase, m_taille);
    }

    /**
     * @brief Enlève une case à une position spécifique de la liste.
     * @param position La position de la case à enlever.
     * @throws std::range_error Si la position est invalide (hors bornes) ou si le noeud à effacer est nullptr.
     */
    void ListeDeCases::enleverCase(int position)
    {
        if (position < 0 || position > m_taille)
        {
            throw std::range_error("Liste De Cases Effacement impossible: Position invalide (hors-bornes).");
        }

        Noeud* aEffacer = noeudAt(position);
        if (aEffacer == nullptr)
        {
            throw std::range_error("Erreur: Noeud à effacer est nullptr pour la position: ");
        }
        if (aEffacer->m_precedent != nullptr)
        {
            aEffacer->m_precedent->m_suivant = aEffacer->m_suivant;
        }
        else
        {
            m_debut = aEffacer->m_suivant;
        }

        if (aEffacer->m_suivant != nullptr)
        {
            aEffacer->m_suivant->m_precedent = aEffacer->m_precedent;
        }
        else
        {
            m_fin = aEffacer->m_precedent;
        }

        delete aEffacer;

        --m_taille;
    }

    /**
     * @brief Retourne une référence constante à la case à une position donnée.
     * @param position La position de la case.
     * @return La référence constante à la case.
     * @throws std::range_error Si la position est invalide (hors bornes).
     */
    const Case& ListeDeCases::caseA(int position) const
    {
        if (position >= m_taille) throw std::range_error("Lecture impossible: Position invalide (hors-bornes).");
        return noeudAt(position)->m_case;
    }

    /**
     * @brief Retourne un pointeur vers le noeud à une position donnée.
     * @param position La position du noeud.
     * @return Le pointeur vers le noeud.
     * @throws std::logic_error Si la position est invalide.
     */
    ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const
    {
        if (position < 0 || position > m_taille)
        {
            throw std::logic_error("Erreur: Position invalide dans noeudAt");
        }

        Noeud* adresseMemoire = m_debut;
        for (int i = 1; i < position; ++i)
        {
            adresseMemoire = adresseMemoire->m_suivant;
        }
        return adresseMemoire;
    }

    /**
     * @brief Retourne un itérateur pointant vers le début de la liste.
     * @return L'itérateur.
     */
    ListeDeCases::Iterateur ListeDeCases::debut() const
    {
        return Iterateur(*this);
    }

    /**
     * @brief Constructeur de l'itérateur de ListeDeCases.
     * @param liste La liste sur laquelle l'itérateur va itérer.
     */
    ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste) :
            m_liste(liste), m_courant(liste.m_debut)
    {
    }

    /**
     * @brief Destructeur de l'itérateur de ListeDeCases.
     */
    ListeDeCases::Iterateur::~Iterateur()
    {
        m_courant = 0;
    }

    /**
     * @brief Retourne une référence constante à la case courante pointée par l'itérateur.
     * @return La référence constante à la case courante.
     */
    const Case& ListeDeCases::Iterateur::caseCourante() const
    {
        return m_courant->m_case;
    }

    /**
     * @brief Vérifie s'il existe une case suivante dans la liste.
     * @return true s'il existe une case suivante, false sinon.
     */
    bool ListeDeCases::Iterateur::existeCaseSuivante() const
    {
        return (m_courant != 0 && m_courant->m_suivant != 0);
    }

    /**
     * @brief Opérateur d'incrémentation pour avancer l'itérateur à la case suivante.
     * @return Référence à l'itérateur.
     * @throws out_of_range Si l'itérateur ne peut pas avancer à une case suivante.
     */
    ListeDeCases::Iterateur& ListeDeCases::Iterateur::operator ++()
    {
        if (existeCaseSuivante())
        {
            m_courant = m_courant->m_suivant;
        }
        else
        {
            m_courant = 0;
            throw out_of_range("L'iterateur ne peut pas aller à une case suivante.");
        }
        return *this;
    }

    /**
     * @brief Retourne un pointeur vers le noeud suivant ayant une certaine couleur.
     * @param couleur La couleur recherchée.
     * @param distance Référence pour retourner la distance jusqu'au noeud suivant de la couleur recherchée.
     * @return Pointeur vers le noeud suivant de la couleur recherchée.
     */
    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const
    {
        distance = 0;
        if (m_courant == 0)
        {
            return 0;
        }

        ListeDeCases::Noeud* suivant = m_courant->m_suivant;
        while (noeudMauvaiseCouleur(suivant, couleur))
        {
            suivant = suivant->m_suivant;
            distance++;
        }
        return suivant;
    }

    /**
     * @brief Vérifie si un noeud a une couleur différente de celle recherchée.
     * @param noeud Le noeud à vérifier.
     * @param couleur La couleur recherchée.
     * @return true si le noeud a une couleur différente, false sinon.
     */
    bool ListeDeCases::Iterateur::noeudMauvaiseCouleur(ListeDeCases::Noeud *noeud, Case::Couleur couleur) const
    {
        return (noeud != 0 && noeud->m_case.couleur != couleur);
    }

    /**
     * @brief Avance l'itérateur à la case suivante ayant une certaine couleur.
     * @param couleur La couleur recherchée.
     * @throws out_of_range Si l'itérateur ne peut pas avancer à une case suivante de la couleur recherchée.
     */
    void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur)
    {
        int distance = 0;
        m_courant = noeudSuivant(couleur, distance);
        if (m_courant == 0)
        {
            ostringstream message;
            message << "L'iterateur ne peut pas aller à une case suivante de couleur " << couleur << ".";
            throw out_of_range(message.str());
        }
    }

    /**
     * @brief Vérifie s'il existe une case suivante ayant une certaine couleur.
     * @param couleur La couleur recherchée.
     * @return true s'il existe une case suivante de la couleur recherchée, false sinon.
     */
    bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const
    {
        int distance = 0;
        return noeudSuivant(couleur, distance) != 0;
    }

    /**
     * @brief Retourne un pointeur vers le noeud précédent ayant une certaine couleur.
     * @param couleur La couleur recherchée.
     * @param distance Référence pour retourner la distance jusqu'au noeud précédent de la couleur recherchée.
     * @return Pointeur vers le noeud précédent de la couleur recherchée.
     */
    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const
    {
        distance = 0;
        if (m_courant == 0)
        {
            return 0;
        }

        ListeDeCases::Noeud* precedent = m_courant->m_precedent;
        while (noeudMauvaiseCouleur(precedent, couleur))
        {
            precedent = precedent->m_precedent;
            distance++;
        }
        return precedent;
    }

    /**
     * @brief Recule l'itérateur à la case précédente ayant une certaine couleur.
     * @param couleur La couleur recherchée.
     * @throws out_of_range Si l'itérateur ne peut pas reculer à une case précédente de la couleur recherchée.
     */
    void ListeDeCases::Iterateur::casePrecedente(Case::Couleur couleur)
    {
        int distance;
        m_courant = noeudPrecedent(couleur, distance);
        if (m_courant == 0)
        {
            ostringstream message;
            message << "L'iterateur ne peut pas aller à une case precedente de couleur " << couleur << ".";
            throw out_of_range(message.str());
        }
    }

    /**
     * @brief Vérifie s'il existe une case précédente ayant une certaine couleur.
     * @param couleur La couleur recherchée.
     * @return true s'il existe une case précédente de la couleur recherchée, false sinon.
     */
    bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const
    {
        int distance = 0;
        return noeudPrecedent(couleur, distance) != 0;
    }

    /**
     * @brief Retourne la position courante de l'itérateur dans la liste.
     * @return La position courante.
     * @throws range_error Si la liste est vide.
     */
    int ListeDeCases::Iterateur::positionCourante() const
    {
        Noeud *courant = m_liste.m_debut;
        if (courant == 0)
            throw range_error("positionCourante: La liste est vide");

        int i = 1;
        while (courant != m_courant)
        {
            courant = courant->m_suivant;
            i++;
        }
        return i;
    }

    /**
     * @brief Vérifie si l'itérateur est à la dernière case de la liste.
     * @return true si l'itérateur est à la dernière case, false sinon.
     */
    bool ListeDeCases::Iterateur::estADerniereCase() const
    {
        return m_courant == m_liste.m_fin && m_courant != 0;
    }

    /**
     * @brief Surcharge de l'opérateur << pour afficher la liste de cases.
     * @param os Le flux de sortie.
     * @param liste La liste de cases à afficher.
     * @return Le flux de sortie.
     */
    std::ostream& operator<<(std::ostream& os, const ListeDeCases & liste)
    {
        if (liste.estVide())
        {
            os << "Liste de cases vide";
        }
        else
        {
            ListeDeCases::Iterateur iter = liste.debut();
            while (!iter.estADerniereCase())
            {
                os << iter.caseCourante() << "; ";
                ++iter;
            }
            os << iter.caseCourante();
        }

        return os;
    }

}
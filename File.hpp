/////////////////////////////////////////////////////////////////////////////
//Fichier File.hpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file File.hpp
 * \brief Ce fichier contient une implémentation générique de la classe File
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2024
 */

#include "File.h"
#include "ListeCirculaire.h"

namespace tp1
{
    /**
     * @brief Constructeur par défaut de la classe File.
     * Initialise la liste circulaire utilisée pour stocker les éléments de la file.
     */
    template<typename T>
    File<T>::File() : liste()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    /**
     * @brief Ajoute un élément à la fin de la file.
     * @param element L'élément à ajouter.
     */
    template<typename T>
    void File<T>::enfiler(const T& element)
    {
        liste.ajouterFin(element);
    }

    /**
     * @brief Retire et retourne l'élément au début de la file.
     * @return L'élément retiré de la file.
     * @throws std::logic_error Si la file est vide.
     */
    template<typename T>
    T File<T>::defiler()
    {
        if (liste.estVide())
        {
            throw std::logic_error("La liste est vide");
        }
        T valeur = liste.element(1);
        liste.enleverPos(1);
        return valeur;
    }

    /**
     * @brief Retourne la taille de la file.
     * @return La taille de la file.
     */
    template<typename T>
    unsigned int File<T>::taille()
    {
        return liste.taille();
    }

    /**
     * @brief Surcharge de l'opérateur << pour afficher la file.
     * @param os Le flux de sortie.
     * @param file La file à afficher.
     * @return Le flux de sortie.
     */
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const File<T>& file)
    {
        os << file.liste;
        return os;
    }

}

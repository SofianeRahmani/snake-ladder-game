/////////////////////////////////////////////////////////////////////////////
//Fichier Case.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Case.cpp
 * \brief Ce fichier contient une implémentation de la classe Case
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2024
 */
#include "Case.h"

namespace tp1
{

    /**
     * @brief Constructeur de la classe Case.
     * @param couleur La couleur de la case.
     * @param decoration La décoration de la case.
     */
    Case::Case(Case::Couleur couleur, Case::Decoration decoration): couleur(couleur), decoration(decoration) {} // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).

    /**
     * @brief Destructeur de la classe Case.
     */
    Case::~Case()
    {
        // Réfléchissez s'il faut faire quelque chose !
    }

    /**
     * @brief Convertit une décoration en sa représentation sous forme de lettre.
     * @param decoration La décoration à convertir.
     * @return Une chaîne de caractères représentant la décoration.
     */
    std::string decorationEnLettre(Case::Decoration decoration)
    {
        switch (decoration)
        {
            case Case::Serpent:
                return "S";
            case Case::Echelle:
                return "E";
            default:
                return "A";
        }
    }

    /**
     * @brief Surcharge de l'opérateur << pour afficher une case.
     * @param os Le flux de sortie.
     * @param uneCase La case à afficher.
     * @return Le flux de sortie.
     */
    std::ostream& operator<<(std::ostream& os, const Case & uneCase)
    {
        os << "(" << uneCase.couleur << "," << decorationEnLettre(uneCase.decoration) << ")";

        return os;
    }

}

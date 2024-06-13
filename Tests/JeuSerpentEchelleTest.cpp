#include <gtest/gtest.h>
#include "JeuSerpentsEtEchelles.h"

using namespace tp1;

class JeuSerpentsEtEchellesTest : public ::testing::Test {
protected:
    JeuSerpentsEtEchelles jeu;

    void SetUp() override {
        Case case1(Case::Rouge, Case::Aucune);
        Case case2(Case::Bleu, Case::Aucune);
        Case case3(Case::Vert, Case::Aucune);
        Case case4(Case::Rouge, Case::Serpent);
        Case case5(Case::Bleu, Case::Echelle);
        Case case6(Case::Vert, Case::Aucune);
        Case case7(Case::Rouge, Case::Aucune);
        Case case8(Case::Bleu, Case::Aucune);
        Case case9(Case::Vert, Case::Aucune);
        Case case10(Case::Rouge, Case::Aucune);

        jeu.ajouterCase(case1);
        jeu.ajouterCase(case2);
        jeu.ajouterCase(case3);
        jeu.ajouterCase(case4);
        jeu.ajouterCase(case5);
        jeu.ajouterCase(case6);
        jeu.ajouterCase(case7);
        jeu.ajouterCase(case8);
        jeu.ajouterCase(case9);
        jeu.ajouterCase(case10);

        jeu.ajouterChoix(Case::Rouge);
        jeu.ajouterChoix(Case::Bleu);
        jeu.ajouterChoix(Case::Vert);

        ListeDeCases::Iterateur iter1 = jeu.premiereCase();
        ListeDeCases::Iterateur iter2 = jeu.premiereCase();
        Joueur joueur1(iter1, "Alice");
        Joueur joueur2(iter2, "Bob");
        jeu.ajouterJoueur(joueur1);
        jeu.ajouterJoueur(joueur2);
    }
};

TEST_F(JeuSerpentsEtEchellesTest, TestJoueurAtteintDerniereCase)
{
    Resultat resultat = jeu.jouer(10);
    EXPECT_EQ(resultat.nom, "Alice");
    EXPECT_LE(resultat.nombreDeTours, 10);
}

TEST_F(JeuSerpentsEtEchellesTest, TestAucunGagnant) {
    Resultat resultat = jeu.jouer(1);
    EXPECT_EQ(resultat.nom, "");
    EXPECT_EQ(resultat.nombreDeTours, 1);
}

TEST_F(JeuSerpentsEtEchellesTest, TestSerpent) {
    Case case1(Case::Rouge, Case::Aucune);
    Case case2(Case::Bleu, Case::Serpent);
    Case case3(Case::Vert, Case::Aucune);
    Case case4(Case::Rouge, Case::Aucune);
    jeu.effacer();
    jeu.ajouterCase(case1);
    jeu.ajouterCase(case2);
    jeu.ajouterCase(case3);
    jeu.ajouterCase(case4);

    jeu.ajouterChoix(Case::Rouge);
    jeu.ajouterChoix(Case::Bleu);
    jeu.ajouterChoix(Case::Vert);

    ListeDeCases::Iterateur iter = jeu.premiereCase();
    Joueur joueur(iter, "Charlie");
    jeu.ajouterJoueur(joueur);

    Resultat resultat = jeu.jouer(3);
    EXPECT_EQ(resultat.nom, "");
    EXPECT_EQ(resultat.nombreDeTours, 3);
    EXPECT_EQ(joueur.position.positionCourante(), 1);
}

TEST_F(JeuSerpentsEtEchellesTest, TestEchelle) {
    Case case1(Case::Rouge, Case::Aucune);
    Case case2(Case::Bleu, Case::Aucune);
    Case case3(Case::Vert, Case::Echelle);
    Case case4(Case::Rouge, Case::Aucune);
    jeu.effacer();
    jeu.ajouterCase(case1);
    jeu.ajouterCase(case2);
    jeu.ajouterCase(case3);
    jeu.ajouterCase(case4);

    jeu.ajouterChoix(Case::Rouge);
    jeu.ajouterChoix(Case::Bleu);
    jeu.ajouterChoix(Case::Vert);

    ListeDeCases::Iterateur iter = jeu.premiereCase();
    Joueur joueur(iter, "Dave");
    jeu.ajouterJoueur(joueur);

    Resultat resultat = jeu.jouer(3);
    EXPECT_EQ(resultat.nom, "");
    EXPECT_EQ(resultat.nombreDeTours, 3);
    EXPECT_EQ(joueur.position.positionCourante(), 4);
}

TEST_F(JeuSerpentsEtEchellesTest, TestAffichageResultats) {
    Resultat resultat = jeu.jouer(10);
    testing::internal::CaptureStdout();
    jeu.afficheResultats(resultat);
    std::string output = testing::internal::GetCapturedStdout();

    if (!resultat.nom.empty()) {
        EXPECT_NE(output.find("Gagnant : " + resultat.nom), std::string::npos);
    } else {
        EXPECT_NE(output.find("Aucun gagnant"), std::string::npos);
    }
    EXPECT_NE(output.find("Nombre de tours realises : " + std::to_string(resultat.nombreDeTours)), std::string::npos);
    EXPECT_NE(output.find("Position des joueurs :"), std::string::npos);
    EXPECT_NE(output.find("Plateau de jeu:"), std::string::npos);
    EXPECT_NE(output.find("Liste de choix:"), std::string::npos);
}

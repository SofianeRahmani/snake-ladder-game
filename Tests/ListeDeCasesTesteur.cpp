//
// Created by srahmani on 2024-05-30.
//
#include"ListeDeCases.h"
#include "gtest/gtest.h"
#include "Case.h"

using namespace tp1;


class ListeDeCasesTest : public ::testing::Test {
protected:
    ListeDeCases liste;
    Case case1;
    Case case2;
    Case case3;

    void SetUp() override  {
        case1 = Case(Case::Rouge, Case::Serpent);
        case2 = Case(Case::Bleu, Case::Echelle);
        case3 = Case(Case::Vert, Case::Aucune);
    }
};

TEST_F(ListeDeCasesTest, TestTaille) {
    EXPECT_TRUE(liste.taille() == 0);
    EXPECT_EQ(liste.taille(), 0);
    liste.ajouterCaseALaFin(case1);
    EXPECT_EQ(liste.taille(), 1);
}

TEST_F(ListeDeCasesTest, TestEstVide) {
EXPECT_TRUE(liste.estVide());
liste.ajouterCaseALaFin(case1);
EXPECT_FALSE(liste.estVide());
}

TEST_F(ListeDeCasesTest, TestAjouterCase) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
EXPECT_EQ(liste.taille(), 2);
EXPECT_EQ(liste.caseA(0).couleur, case1.couleur);
EXPECT_EQ(liste.caseA(0).decoration, case1.decoration);
EXPECT_EQ(liste.caseA(1).couleur, case2.couleur);
EXPECT_EQ(liste.caseA(1).decoration, case2.decoration);
}

TEST_F(ListeDeCasesTest, TestAjouterCaseInvalidPosition) {
EXPECT_THROW(liste.ajouterCase(case1, -1), std::range_error);
EXPECT_THROW(liste.ajouterCase(case1, 1), std::range_error);
}

TEST_F(ListeDeCasesTest, TestEnleverCase) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
liste.enleverCase(0);
EXPECT_EQ(liste.taille(), 1);
EXPECT_EQ(liste.caseA(0).couleur, case2.couleur);
EXPECT_EQ(liste.caseA(0).decoration, case2.decoration);
}

TEST_F(ListeDeCasesTest, TestEnleverCaseInvalidPosition) {
EXPECT_THROW(liste.enleverCase(0), std::range_error);
}

TEST_F(ListeDeCasesTest, TestCaseA) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
EXPECT_EQ(liste.caseA(0).couleur, case1.couleur);
EXPECT_EQ(liste.caseA(0).decoration, case1.decoration);
EXPECT_EQ(liste.caseA(1).couleur, case2.couleur);
EXPECT_EQ(liste.caseA(1).decoration, case2.decoration);
}

TEST_F(ListeDeCasesTest, TestCaseAInvalidPosition) {
EXPECT_THROW(liste.caseA(0), std::range_error);
liste.ajouterCaseALaFin(case1);
EXPECT_THROW(liste.caseA(1), std::range_error);
}

TEST_F(ListeDeCasesTest, TestIterateurDebut) {
liste.ajouterCaseALaFin(case1);
auto it = liste.debut();
EXPECT_EQ(it.caseCourante().couleur, case1.couleur);
EXPECT_EQ(it.caseCourante().decoration, case1.decoration);
}

TEST_F(ListeDeCasesTest, TestIterateurIncrement) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
auto it = liste.debut();
++it;
EXPECT_EQ(it.caseCourante().couleur, case2.couleur);
EXPECT_EQ(it.caseCourante().decoration, case2.decoration);
}

TEST_F(ListeDeCasesTest, TestIterateurIncrementOutOfRange) {
liste.ajouterCaseALaFin(case1);
auto it = liste.debut();
EXPECT_THROW(++it, std::out_of_range);
}

TEST_F(ListeDeCasesTest, TestIterateurCaseSuivante) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
auto it = liste.debut();
it.caseSuivante(Case::Bleu); // Assuming case1 is not Bleu, case2 is Bleu
EXPECT_EQ(it.caseCourante().couleur, case2.couleur);
EXPECT_EQ(it.caseCourante().decoration, case2.decoration);
}

TEST_F(ListeDeCasesTest, TestIterateurCaseSuivanteOutOfRange) {
liste.ajouterCaseALaFin(case1);
auto it = liste.debut();
EXPECT_THROW(it.caseSuivante(Case::Bleu), std::out_of_range);
}

TEST_F(ListeDeCasesTest, TestIterateurCasePrecedente) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
auto it = liste.debut();
++it;
it.casePrecedente(Case::Rouge); // Assuming case1 is Rouge
EXPECT_EQ(it.caseCourante().couleur, case1.couleur);
EXPECT_EQ(it.caseCourante().decoration, case1.decoration);
}

TEST_F(ListeDeCasesTest, TestIterateurCasePrecedenteOutOfRange) {
liste.ajouterCaseALaFin(case1);
auto it = liste.debut();
EXPECT_THROW(it.casePrecedente(Case::Bleu), std::out_of_range);
}

TEST_F(ListeDeCasesTest, TestIterateurExisteCaseSuivante) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
auto it = liste.debut();
EXPECT_TRUE(it.existeCaseSuivante());
++it;
EXPECT_FALSE(it.existeCaseSuivante());
}

TEST_F(ListeDeCasesTest, TestIterateurExisteCasePrecedente) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
auto it = liste.debut();
++it;
//EXPECT_TRUE(it.existeCasePrecedente());
}

TEST_F(ListeDeCasesTest, TestIterateurPositionCourante) {
liste.ajouterCaseALaFin(case1);
liste.ajouterCaseALaFin(case2);
auto it = liste.debut();
EXPECT_EQ(it.positionCourante(), 1);
++it;
EXPECT_EQ(it.positionCourante(), 2);
}

TEST_F(ListeDeCasesTest, TestIterateurEstADerniereCase) {
liste.ajouterCaseALaFin(case1);
auto it = liste.debut();
EXPECT_TRUE(it.estADerniereCase());
}


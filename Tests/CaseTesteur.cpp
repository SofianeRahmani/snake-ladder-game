//
// Created by srahmani on 2024-05-30.
//
#include "gtest/gtest.h"
#include "Case.h"
#include <sstream>

using namespace tp1;

TEST(CaseTest, ConstructorTest) {
Case c(Case::Rouge, Case::Serpent);
EXPECT_EQ(c.couleur, Case::Rouge);
EXPECT_EQ(c.decoration, Case::Serpent);

Case d(Case::Vert, Case::Echelle);
EXPECT_EQ(d.couleur, Case::Vert);
EXPECT_EQ(d.decoration, Case::Echelle);

Case e(Case::Bleu, Case::Aucune);
EXPECT_EQ(e.couleur, Case::Bleu);
EXPECT_EQ(e.decoration, Case::Aucune);
}

TEST(CaseTest, DestructorTest) {
Case* c = new Case(Case::Jaune, Case::Aucune);
EXPECT_NO_THROW(delete c);
}

// TEST(CaseTest, DecorationEnLettreTest) {
//     EXPECT_EQ(decorationEnLettre(Case::Serpent), "S");
//     EXPECT_EQ(decorationEnLettre(Case::Echelle), "E");
//     EXPECT_EQ(decorationEnLettre(Case::Aucune), "A");
// }

TEST(CaseTest, OutputOperatorTest) {
Case c(Case::Rouge, Case::Serpent);
std::ostringstream os;
os << c;
EXPECT_EQ(os.str(), "(0,S)");

Case d(Case::Vert, Case::Echelle);
std::ostringstream os2;
os2 << d;
EXPECT_EQ(os2.str(), "(1,E)");

Case e(Case::Bleu, Case::Aucune);
std::ostringstream os3;
os3 << e;
EXPECT_EQ(os3.str(), "(2,A)");
}

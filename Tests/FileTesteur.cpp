//
// Created by srahmani on 2024-05-30.
//
#include <gtest/gtest.h>
#include "File.h"
#include <stdexcept>
#include <sstream>

using namespace tp1;

TEST(FileTest, TestFileVide)
{
    File<int> file;
    EXPECT_EQ(file.taille(), 0);
    EXPECT_THROW(file.defiler(), std::logic_error);
}

TEST(FileTest, TestEnfiler)
{
    File<int> file;
    file.enfiler(1);
    EXPECT_EQ(file.taille(), 1);
    file.enfiler(2);
    EXPECT_EQ(file.taille(), 2);
    EXPECT_EQ(file.defiler(), 1);
    EXPECT_EQ(file.taille(), 1);
    EXPECT_EQ(file.defiler(), 2);
    EXPECT_EQ(file.taille(), 0);
}

TEST(FileTest, TestDefiler)
{
    File<int> file;
    file.enfiler(1);
    file.enfiler(2);
    file.enfiler(3);
    EXPECT_EQ(file.defiler(), 1);
    EXPECT_EQ(file.defiler(), 2);
    EXPECT_EQ(file.defiler(), 3);
    EXPECT_EQ(file.taille(), 0);
    EXPECT_THROW(file.defiler(), std::logic_error);
}

TEST(FileTest, TestTaille)
{
    File<int> file;
    EXPECT_EQ(file.taille(), 0);
    file.enfiler(1);
    EXPECT_EQ(file.taille(), 1);
    file.enfiler(2);
    EXPECT_EQ(file.taille(), 2);
    file.defiler();
    EXPECT_EQ(file.taille(), 1);
    file.defiler();
    EXPECT_EQ(file.taille(), 0);
}

TEST(FileTest, TestAffichage)
{
    File<int> file;
    file.enfiler(1);
    file.enfiler(2);
    file.enfiler(3);
    std::ostringstream os;
    os << file;
    EXPECT_EQ(os.str(), "1; 2; 3");
}
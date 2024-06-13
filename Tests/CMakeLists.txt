add_executable(ListeDeCasesTesteur ListeDeCasesTesteur.cpp ${PROJECT_SOURCE_DIR}/ListeDeCases.cpp ${PROJECT_SOURCE_DIR}/Case.cpp)
add_executable(CaseTesteur CaseTesteur.cpp ${PROJECT_SOURCE_DIR}/Case.cpp)
add_executable(FileTesteur FileTesteur.cpp ${PROJECT_SOURCE_DIR}/File.hpp ${PROJECT_SOURCE_DIR}/ListeCirculaire.hpp)
add_executable(JeuSerpentEchelleTest JeuSerpentEchelleTest.cpp ${PROJECT_SOURCE_DIR}/JeuSerpentsEtEchelles.cpp ${PROJECT_SOURCE_DIR}/File.hpp ${PROJECT_SOURCE_DIR}/ListeCirculaire.hpp ${PROJECT_SOURCE_DIR}/ListeDeCases.cpp ${PROJECT_SOURCE_DIR}/Case.cpp)

target_include_directories(ListeDeCasesTesteur PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(CaseTesteur PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(FileTesteur PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(JeuSerpentEchelleTest PRIVATE ${PROJECT_SOURCE_DIR})


target_link_libraries(ListeDeCasesTesteur
        gtest_main
        gtest
        pthread
)

target_link_libraries(CaseTesteur
        gtest_main
        gtest
        pthread
)
target_link_libraries(FileTesteur
        gtest_main
        gtest
        pthread
)
target_link_libraries(JeuSerpentEchelleTest
        gtest_main
        gtest
        pthread
)

include(googletest)
gtest_discover_tests(ListeDeCasesTesteur)
gtest_discover_tests(CaseTesteur)
gtest_discover_tests(FileTesteur)
gtest_discover_tests(JeuSerpentEchelleTest)


if(EXISTS "C:/temp/CodeTP1/cmake-build-debug/Tests/CaseTesteur[1]_tests.cmake")
  include("C:/temp/CodeTP1/cmake-build-debug/Tests/CaseTesteur[1]_tests.cmake")
else()
  add_test(CaseTesteur_NOT_BUILT CaseTesteur_NOT_BUILT)
endif()

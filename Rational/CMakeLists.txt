add_library(Rational STATIC "Rational.cpp" "Rational.hpp")
target_include_directories(Rational PUBLIC ".")
target_link_libraries(Rational PRIVATE Polynomial)

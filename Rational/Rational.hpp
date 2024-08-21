#pragma once

#include <Polynomial.hpp>

class Rational
{
  public:
    Rational();
    Rational(const Polynomial &nom, const Polynomial &denom);
    Rational(const Rational &rational);
    Rational &operator=(const Rational &rational);

    void Print() const;
    const Polynomial &GetNom() const;
    const Polynomial &GetDenom() const;

    Rational operator+(const Rational &rational) const;
    Rational operator-(const Rational &rational) const;
    Rational operator*(const Rational &rational) const;

  private:
    Polynomial _nom;
    Polynomial _denom;
};

std::ostream &operator<<(std::ostream &os, const Rational &rational);

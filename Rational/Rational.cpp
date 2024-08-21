#include "Rational.hpp"

#include <iostream>

Rational::Rational()
{
    _denom.SetCoeff(0, 1.0);
}

Rational::Rational(const Polynomial &nom, const Polynomial &denom) : _nom(nom), _denom(denom)
{
}

Rational::Rational(const Rational &rational) : _nom(rational.GetNom()), _denom(rational.GetDenom())
{
}

Rational &Rational::operator=(const Rational &rational)
{
    if (this == &rational)
        return *this;
    _nom = rational.GetNom();
    _denom = rational.GetDenom();
    return *this;
}

void Rational::Print() const
{
    std::cout << *this;
}

const Polynomial &Rational::GetNom() const
{
    return _nom;
}

const Polynomial &Rational::GetDenom() const
{
    return _denom;
}

Rational Rational::operator+(const Rational &rational) const
{
    const auto &a = this->GetNom();
    const auto &b = this->GetDenom();
    const auto &c = rational.GetNom();
    const auto &d = rational.GetDenom();
    return Rational{a * d + b * c, b * d};
}

Rational Rational::operator-(const Rational &rational) const
{
    const auto &a = this->GetNom();
    const auto &b = this->GetDenom();
    const auto &c = rational.GetNom();
    const auto &d = rational.GetDenom();
    return Rational{a * d - b * c, b * d};
}

Rational Rational::operator*(const Rational &rational) const
{
    const auto &a = this->GetNom();
    const auto &b = this->GetDenom();
    const auto &c = rational.GetNom();
    const auto &d = rational.GetDenom();
    return Rational{a * c, b * d};
}

std::ostream &operator<<(std::ostream &os, const Rational &rational)
{
    os << rational.GetNom();
    os << "--------------------------\n";
    os << rational.GetDenom();
    return os;
}

#include "Polynomial.hpp"

#include <algorithm>
#include <cassert>
#include <cstring>

std::size_t Polynomial::s_maxDegree{0};

Polynomial::Polynomial(const std::size_t degree) : _degree(degree)
{
    _coefficients = new double[degree + 1]();
}

Polynomial::Polynomial(const double *const coefficients, const std::size_t degree) : Polynomial(degree)
{
    std::memcpy(_coefficients, coefficients, sizeof(double) * (_degree + 1));
    Polynomial::s_maxDegree = std::max(Polynomial::s_maxDegree, this->GetDegree(true));
}

Polynomial::Polynomial(const Polynomial &polynomial) : Polynomial(polynomial._coefficients, polynomial._degree)
{
}

Polynomial &Polynomial::operator=(const Polynomial &polynomial)
{
    if (&polynomial == this)
        return *this;
    delete[] _coefficients;
    const_cast<std::size_t &>(_degree) = polynomial._degree;
    _coefficients = new double[polynomial._degree + 1]();
    std::memcpy(_coefficients, polynomial._coefficients, sizeof(double) * (_degree + 1));
    return *this;
}

Polynomial::~Polynomial()
{
    delete[] _coefficients;
    _coefficients = nullptr;
}

std::size_t Polynomial::GetDegree(const bool real) const
{
    if (!real)
        return _degree;
    for (std::size_t i{_degree}; i; --i)
    {
        if ((*this)[i] != 0.0)
            return i;
    }
    return 0;
}

void Polynomial::SetCoeff(const std::size_t degree, const double coefficient)
{
    assert(degree <= this->GetDegree(false));
    (*this)[degree] = coefficient;
    if (coefficient != 0.0 && degree > Polynomial::s_maxDegree)
        Polynomial::s_maxDegree = degree;
}

double &Polynomial::operator[](const std::size_t i)
{
    assert(i <= this->GetDegree(false));
    return _coefficients[i];
}

double Polynomial::operator[](const std::size_t i) const
{
    assert(i <= this->GetDegree(false));
    return _coefficients[i];
}

Polynomial Polynomial::operator+(const Polynomial &polynomial) const
{
    const std::size_t thisDegree{this->GetDegree(true)};
    const std::size_t otherDegree{polynomial.GetDegree(true)};
    const std::size_t plusDegree{std::max(thisDegree, otherDegree)};
    Polynomial res{plusDegree};
    for (std::size_t i{0}; i <= plusDegree; ++i)
    {
        const double a = i <= thisDegree ? (*this)[i] : 0.0;
        const double b = i <= otherDegree ? polynomial[i] : 0.0;
        res.SetCoeff(i, a + b);
    }
    return res;
}

Polynomial Polynomial::operator+(const double k) const
{
    Polynomial res{*this};
    res.SetCoeff(0, res[0] + k);
    return res;
}

Polynomial Polynomial::operator-(const Polynomial &polynomial) const
{
    return *this + (polynomial * -1);
}

Polynomial Polynomial::operator-(const double k) const
{
    return *this + (-k);
}

Polynomial Polynomial::operator*(const Polynomial &polynomial) const
{
    const std::size_t thisDegree{this->GetDegree(true)};
    const std::size_t otherDegree{polynomial.GetDegree(true)};
    const std::size_t multDegree{thisDegree + otherDegree};
    Polynomial res{multDegree};
    for (std::size_t i{0}; i <= thisDegree; ++i)
    {
        for (std::size_t j{0}; j <= otherDegree; ++j)
        {
            const std::size_t multDegree{i + j};
            const double multCoefficient{(*this)[i] * polynomial[j] + res[multDegree]};
            res[multDegree] = multCoefficient;
        }
    }
    for (std::size_t i{0}; i <= multDegree; ++i)
    {
        res.SetCoeff(i, res[i]);
    }
    return res;
}

Polynomial Polynomial::operator*(const double k) const
{
    Polynomial res{*this};
    for (std::size_t i{0}; i <= res._degree; ++i)
    {
        res.SetCoeff(i, res[i] * k);
    }
    return res;
}

std::size_t Polynomial::GetMaxDegree()
{
    return Polynomial::s_maxDegree;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial)
{
    os << "Polynomial = " << polynomial[0];
    const std::size_t realDegree = polynomial.GetDegree(true);
    for (std::size_t i{1}; i <= realDegree; ++i)
    {
        os << "+(" << polynomial[i] << ")*X^" << i;
    }
    return os << std::endl;
}

Polynomial operator+(const double k, const Polynomial &polynomial)
{
    return polynomial + k;
}

Polynomial operator-(const double k, const Polynomial &polynomial)
{
    return k + (-1 * polynomial);
}

Polynomial operator*(const double k, const Polynomial &polynomial)
{
    return polynomial * k;
}

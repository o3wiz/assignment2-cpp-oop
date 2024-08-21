#pragma once

#include <cstddef>
#include <ostream>

class Polynomial
{
    friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial);
    friend Polynomial operator+(const double k, const Polynomial &polynomial);
    friend Polynomial operator-(const double k, const Polynomial &polynomial);
    friend Polynomial operator*(const double k, const Polynomial &polynomial);

  public:
    Polynomial(const std::size_t degree = 0);
    Polynomial(const double *const coefficients, const std::size_t degree);
    Polynomial(const Polynomial &polynomial);
    Polynomial &operator=(const Polynomial &polynomial);
    ~Polynomial();

    std::size_t GetDegree(const bool real) const;
    void SetCoeff(const std::size_t degree, const double coefficient);

    double &operator[](const std::size_t i);
    double operator[](const std::size_t i) const;

    Polynomial operator+(const Polynomial &polynomial) const;
    Polynomial operator+(const double k) const;
    Polynomial operator-(const Polynomial &polynomial) const;
    Polynomial operator-(const double k) const;
    Polynomial operator*(const Polynomial &polynomial) const;
    Polynomial operator*(const double k) const;

    static std::size_t GetMaxDegree();

  private:
    static std::size_t s_maxDegree;
    double *_coefficients{nullptr};
    const std::size_t _degree{0};
};

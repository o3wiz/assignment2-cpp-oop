#include <Polynomial.hpp>
#include <Rational.hpp>
#include <iostream>
using namespace std;

void testPolynomial()
{
    cout << "----- start testPolynomial ---------" << endl;
    cout << "test0 :" << Polynomial::GetMaxDegree() << endl;
    Polynomial p1;
    cout << "test1: " << p1;
    Polynomial p2(16);
    p2.SetCoeff(2, 0.4);
    cout << "test2: " << p2 << "degree=" << p2.GetDegree(false) << endl;
    double c[5] = {0.1, 0.2, 0, 11.5, 1.3};
    Polynomial p3(c, 4);
    cout << "test3: " << p3;
    p2.SetCoeff(2, 0.0);
    cout << "test4: " << p2;
    p2 = (p1 + 2.5 * p3 - 0.9 * p3) * p3;
    ;
    cout << "test5 " << p2 << endl;
    cout << "test6 :maxDegree = " << Polynomial::GetMaxDegree() << endl;
    cout << "______________" << endl;
}
void testRational()
{
    cout << "----- start testRational ---------" << endl;
    cout << "test7" << endl;
    Rational r1;
    r1.Print();
    cout << r1;
    double c[] = {0, 2, 2, 3, 4, 5};
    Polynomial p1(c, 5);
    c[0] = 1.2;
    Polynomial p2(c, 3);
    Rational r2(p1, p2);
    cout << "test8" << endl;
    r2.Print();
    cout << endl << r2 << endl;
    cout << "test9" << endl;
    cout << "Nom = " << r2.GetNom();
    cout << "Denom = " << r2.GetDenom();
    Rational r3 = r2 * r2 + r2;
    cout << "test10 : r3 = " << endl << r3 << endl;
    double d[21] = {0};
    d[0] = 1;
    Polynomial p3(d, 20);
    Rational r4(p3, p3);
    r4 = (r2 + r4) * r2;
    cout << "test11 : r4 = " << endl << r4 << endl;
    cout << "test12 :maxDegree = " << Polynomial::GetMaxDegree() << endl;
    cout << "__________________________" << endl;
}

int main()
{
    testPolynomial();
    testRational();
}

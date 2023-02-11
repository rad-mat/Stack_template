#include "Complex.h"
#include <cmath>

Complex::Complex( double re, double im )
{
    setComplex( re, im );
}

Complex::Complex( const Complex& c )
{
    *this = c;
}

const Complex operator-( const Complex& c )
{
    return Complex( -c.getRe(), -c.getIm() );
}

const Complex operator+( const Complex& c1, const Complex& c2 )
{
    Complex res( c1 );
    return res += c2;;
}

const Complex operator-( const Complex& c1, const Complex& c2 )
{
    Complex res( c1 );
    return res -= c2;\
}

const Complex operator*( const Complex& c1, const Complex& c2 )
{
    Complex res( c1 );
    return res *= c2;
}

const Complex operator/( const Complex& c1, const Complex& c2 )
{
    Complex res( c1 );
    return res /= c2;
}

Complex& Complex::operator+=( const Complex& c )
{
    setComplex( getRe() + c.getRe(), getIm() + c.getIm() );
    return *this;
}

Complex& Complex::operator-=( const Complex& c )
{
    setComplex( getRe() - c.getRe(), getIm() - c.getIm() );
    return *this;
}

Complex& Complex::operator*=( const Complex& c ) 
{
    setComplex( getRe() * c.getRe() - getIm() * c.getIm(), getRe() * c.getIm() + getIm() * c.getRe() );
    return *this;
}

Complex& Complex::operator/=( const Complex& c )
{
    if( c.getRe() == 0 && c.getIm() == 0 )
    {
        std::cerr << "Dzielenie przez zero!\n";
        return *this;
    }
    setComplex( ( getRe() * c.getRe() + getIm() * c.getIm() ) / c.sqr(), ( getIm() * c.getRe() - getRe() * c.getIm() ) / c.sqr() );
    return *this;
}

Complex& Complex::operator=( const Complex& c )
{
    setComplex( c.getRe(), c.getIm() );
    return *this;
}

bool operator==( const Complex& c1, const Complex& c2 )
{
    return c1.getRe() == c2.getRe() && c1.getIm() == c2.getIm();
}

bool operator!=( const Complex& c1, const Complex& c2  )
{
    return !( c1 == c2 );
}

std::istream& operator>>( std::istream& in, Complex& c )
{
    double temp;
    in >> temp; c.setRe( temp );
    in >> temp; c.setIm( temp );
    return in;
}

std::ostream& operator<<( std::ostream& out, const Complex& c )
{
    out << '(' << c.getRe() << ", " << c.getIm() << ')';
    return out;
}

const Complex Complex::Coupled()
{
    return Complex( getRe(), -getIm() );
}

double Complex::Z()
{
    return sqrt( sqr() );
}

Complex::operator double()
{
    return getRe();
}

Complex::operator int()
{
    return (int)getRe();
}

double Complex::sqr() const
{
    return getRe()*getRe() + getIm()*getIm();
}

#pragma once
#include <iostream>

class Complex
{
public:
    Complex( double re = 0, double im = 0 );
    Complex( const Complex& c );
    
    friend const Complex operator-( const Complex& c );
    friend const Complex operator+( const Complex& c1, const Complex& c2 );
    friend const Complex operator-( const Complex& c1, const Complex& c2 );
    friend const Complex operator*( const Complex& c1, const Complex& c2 );
    friend const Complex operator/( const Complex& c1, const Complex& c2 );
    Complex& operator+=( const Complex& c );
    Complex& operator-=( const Complex& c );
    Complex& operator*=( const Complex& c ); 
    Complex& operator/=( const Complex& c );
    Complex& operator=( const Complex& c );
    friend bool operator==( const Complex& c1, const Complex& c2 );
    friend bool operator!=( const Complex& c1, const Complex& c2 );

    friend std::istream& operator>>( std::istream& in, Complex& c );
    friend std::ostream& operator<<( std::ostream& out, const Complex& c );

    const Complex Coupled();
    double Z();

    operator double();
    operator int();

    inline void setRe( double re );
    inline void setIm( double im );
    inline void setComplex( double re, double im );

    inline double getRe() const;
    inline double getIm() const;

private:
    double m_Re;
    double m_Im;
    double sqr() const;
};

inline void Complex::setRe( double re )
{
    m_Re = re;
}

inline void Complex::setIm( double im )
{
    m_Im = im;
}

inline void Complex::setComplex( double re, double im )
{
    setRe( re );
    setIm( im );
}

inline double Complex::getRe() const
{
    return m_Re;
}

inline double Complex::getIm() const
{
    return m_Im;
}
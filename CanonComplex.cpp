#include "CanonComplex.h"

CanonComplex::CanonComplex( const Complex& c ) : Complex( c )
{
}

std::ostream& operator<<( std::ostream& out, const CanonComplex& c )
{
    out << c.getRe();
    if( c.getIm() >= 0 ) out << '+';
    out << c.getIm() << 'i';
    return out;
}
#pragma once
#include "Complex.h"

class CanonComplex : public Complex
{
public:
    CanonComplex( const Complex& c );
    friend std::ostream& operator<<( std::ostream& out, const CanonComplex& c );
};


#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <string>

class Fraction{
private:
    int numerator, denominator;
    int LCM( int x, int y ); //lowest common multiplier
    int GCD( int x, int y ); //greatest common divisor
public:
    Fraction();
    Fraction( int n );
    Fraction( int n, int d );

    std::string to_string();
    double get_double();

    Fraction operator!();
    Fraction operator+( Fraction arg );
    Fraction operator-( Fraction arg );
    Fraction operator*( Fraction arg );
    Fraction operator/( Fraction arg );
    Fraction& operator+=( Fraction arg );
};

std::ostream& operator<<( std::ostream &ostr, Fraction &f );
#endif
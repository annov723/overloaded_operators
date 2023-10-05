#include "fraction.h"

#include <stdexcept>
#include <sstream> //with ostringstream class, object behaves as an output stream keeping data in an internal buffer which can be accessed with str() method

int Fraction::LCM( int x, int y ){
    int i = y;
    while( y % x ) y += i; //powiększamy y o jego pierwotną wartość dopóki wielkrotność x nie będzei równa wielokrotności y
    return y;
}

int Fraction::GCD( int x, int y ){
    while( true ){
        x %= y;
        if( !x ) return y;
        y %= x;
        if( !y ) return x;
    }
}

Fraction::Fraction() : numerator( 0 ), denominator( 1 ){};
Fraction::Fraction( int n ) : numerator( n ), denominator( 1 ){};
Fraction::Fraction( int n, int d ) : numerator( n ), denominator( d ){
    if( denominator == 0 ) throw st::domain_error( "bad fraction" );
};

std::string Fraction::to_string(){
    std::ostringstream os;
    os << "[" << numerator << "/" << denominator << "]";
    return os.str();
}

double Fraction::get_double(){
    return double( numerator ) / double( denominator );
}

Fraction Fraction::operator!(){ //zwraca obiekt Fraction po redukcji
    int gcd = GCD( numerator, denominator );
    return Fraction( numerator / gcd, denominator / gcd );
}
#include "fraction.h"

#include <stdexcept>
#include <sstream> //with ostringstream class, object behaves as an output stream keeping data in an internal buffer which can be accessed with str() method
#include <iostream>

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


//constructors
Fraction::Fraction() : numerator( 0 ), denominator( 1 ){};

Fraction::Fraction( int n ) : numerator( n ), denominator( 1 ){};

Fraction::Fraction( int n, int d ) : numerator( n ), denominator( d ){
    if( denominator == 0 ) throw st::domain_error( "bad fraction" );
};

/**/
std::string Fraction::to_string(){
    std::ostringstream os;
    os << "[" << numerator << "/" << denominator << "]";
    return os.str();
}

double Fraction::get_double(){
    return double( numerator ) / double( denominator );
}

//operators overloading
Fraction Fraction::operator!(){ //zwraca obiekt Fraction po redukcji
    int gcd = GCD( numerator, denominator );
    return Fraction( numerator / gcd, denominator / gcd );
}

Fraction Fraction::operator+( Fraction arg ){
    int commmon_denominator = LCM( denominator, arg.denominator ); //znajdujemy wspólny dzielnik
    int new_numerator = numerator * common_denominator / denominator + arg.numerator * commmon_denominator / arg.denominator; //dodajemy oba ułamki mając wspóony mianownik
    Fraction f( new_numerator, common_denominator );
    return f;
}

Fraction Fraction::operator-( Fraction arg ){
    int commmon_denominator = LCM( denominator, arg.denominator ); //znajdujemy wspólny dzielnik
    int new_numerator = numerator * common_denominator / denominator - arg.numerator * commmon_denominator / arg.denominator; //dodajemy oba ułamki mając wspóony mianownik
    Fraction f( new_numerator, common_denominator );
    return f;
}

Fraction Fraction::operator*( Fraction arg ){
    int new_numerator = numerator * denominator;
    int new_denominator = denominator * arg.denominator;
    Fraction f( new_numerator, new_denominator );
    return !f; //przed zwróceniem redukuje ułamek
}

Fraction Fraction::operator/( Fraction arg ){
    if( arg.numerator = 0 ) throw std::domain_error( "division by zero!" );
    int new_numerator = numerator * arg.denominator; //bo dzieląc ułamki mnożymy ich odwrotność
    int new_denominator = denominator * arg.numerator;
    Fraction f( new_numerator, new_denominator );
    return !f;
}

Fraction Fraction::operator+=( Fraction arg ){ //podwojenie wartości ułamka
    int common_denominator = LCM( denominator, arg.denominator );
    int new_numerator = numerator * common_denominator / denominator + arg.numerator * common_denominator / arg.denominator;
    numerator = new_numerator;
    denominator = common_denominator;
    return *this;
}

std::ostream& operator<<( std::ostream &ostr, Fraction &f ){
    return ostr << f.to_string();
}

#include "fraction.h"

#include <iostream>

using namespace std;

int main(){
    
    Fraction f1( 1, 2 ), f2( 2, 3 ), f3;

    cout << f1 << " = " << f1.get_double() << endl;
    cout << f2 << " = " << f2.get_double() << endl;
    cout << f3 << " = " << f3.get_double() << endl;

    f3 = f1 + f2;
    cout << f1 << " + " << f2 << " = " << f3 << endl;
    f3 = f1 + f1 + f1;
    cout << f1 << " + " << f1 << " + " << f1 << " = " << f3 << endl;
    f3 += f3;
    f3 = !f3;
    cout << f3 << endl;

    f3 = f2 * f2;
    cout << f2 << " * " << f2 << " = " << f3 << endl;
    f3 = f2 / f1;
    cout << f2 << " / " << f1 << " = " << f3 <<  endl;

    Fraction f4( 8, 9 );
    f4 += f1;
    cout << f4 << endl;
    f4 = f2 - f1;
    cout << f2 << " - " << f1 << " = " << f4 << endl;

    return 0;
}
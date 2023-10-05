#include <iostream>
#include <vector>

using namespace std;

class Arr{
private:
    int a, b, c, d;

public:
    Arr(){
        a = b = c = d = 0;
    };

    int& operator[]( int index ){
        switch( index ){
            case 1: return a;
            case 2: return b;
            case 3: return c;
            case 4: return d;
            default: throw range_error( "bad index" );
        }
    }

    int operator()( int a, int b ){
        return a > b ? a : b;
    }
    int operator()( int a, int b, int c ){
        return a > b ? ( a > c ? a : c ) : ( b > c ? b : c );
    }
};

class P{
public:
    int no;
    P( int n ) : no( n ){};
    P() : no( 0 ){};

    string operator&(){
        string res = "";
        switch( no ){
            case 0: res = "alpha";
            case 1: res = "beta";
            case 2: res = "gamma";
        }
        return res;
    }
};

P& operator*( string s ){
    P *p;
    if( !s.compare( "alpha" ) ) p = new P( 0 );
    else if( !s.compare( "beta" ) ) p = new P( 1 );
    else if( !s.compare( "gamma" ) ) p = new P( 2 );
    else p = new P( -1 );
    return *p;
}

int main(){
    Arr arr;
    for( int i = 1; i <= 4; i++ ) arr[i] = i * i;
    for( int i = 4; i > 0; i-- ) cout << arr[i] << endl;
    cout << arr( 1, 2 ) << arr( 1, 2, 3 ) << endl;

    P p1( 2 );

    string s = &p1;
    P p2 = *s;
    cout << s << p2.no << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class V{
public:
    vector<float> vec;

    V( float a0 = 0.f, float a1 = 0.f ){
        vec.push_back( a0 );
        vec.push_back( a1 );
    }

    V operator+( V &arg ){ //obiekt klasy V
        V res;
        for( int i = 0; i < 2; i++ ) res.vec[i] = vec[i] + arg.vec[i];
        return res; //zwracany jest nowy wektor, którego kolejne wartości to sumy 2 wektorów tej klasy
    }
};

class VV{
public:
    vector<int> vec;

    VV( int a0 = 0, int a1 = 0){
        vec.push_back( a0 );
        vec.push_back( a1 );
    }

    VV operator>>( int arg ){
        VV res( vec[0], vec[1] ); //tworzymy kopię wektora z klasy

        for( int i = 0; i < 2; i++ ) res.vec[i] >>= arg; //przesunięcie binarne
        return res;
    }

    VV& operator=( VV &arg ){ //to obiekt po prawej stronie, od którego pobieramy dane do obiektu po lewej
        for( int i =0; i < 2; i++ ) vec[i] = arg.vec[1 - i];
        return *this; //zwraca cały obiekt VV
    }

    bool operator==( VV &arg ){
        for( int i = 0; i < 2; i++ ) if( vec[i] != arg.vec[i] ) return false;
        return true;
    }

    bool operator&&( VV &arg ){
        return abs( vec[0] ) + abs( vec[1] ) > 0 && abs( arg.vec[0]) + abs( arg.vec[1] ) > 0;
    }

    VV& operator+=( VV &arg ){
        for( int i = 0; i < 2; i++ ) vec[i] += arg.vec[i];
        return *this; //zwracamy ten! obiekt
    }

    VV& operator++(){ //zwiększamy wielkość każdej komóki o 1
        for( int i = 0; i < 2; i++ ) vec[i]++;
        return *this;
    }

    VV operator--( int nothing ){
        VV v( vec[0], vec[1] );
        for( int i = 0; i < 2; i++ ) --vec[i];
        return v;
    }

};

float operator*( V &left, V &right ){
    float res = 0.0;
    for( int i = 0; i < 2; i++ ) res += left.vec[i] * right.vec[i];
    return res; //zwracany jest iloczyn mnożenia elementów dwóch wektorów
}

int operator~( VV &arg ){ //ten operator nie ma nic po lewej nigdy, so tylko obiekt się daje po prawej i tyle
    int res = 1;

    for( int i = 0; i < 2; i++ ) res *= arg.vec[i];
    return res; //zwraca iloczyn wszystkich elementów wektora
}

bool operator>( VV &l, VV &r ){
    return l.vec[0] + l.vec[1] > r.vec[0] + r.vec[1];
}

bool operator!( VV &v ){
    return v.vec[0] * v.vec[1] != 0;
}

VV& operator+( VV &left, VV &right ){
    VV *res = new VV( 0, 0 );
    for( int i = 0; i < 2; i++ ) res->vec[i] = left.vec[i] + right.vec[i];
    return *res;
}



int main(){
    V v1( 0.0f, 1.0f ), v2( 1.0f, 0.0f ), v3( 0.0f, 0.0f );
    float x;

    v3 = v1 + v2;
    x = v1 * v2;
    cout << v3.vec[0] << v3.vec[1] << endl;
    cout << x << endl;

    cout << endl;

    VV v( 15, 7 );
    //to działa jak nie ma = overloading
    //v = v >> 1; //przesunięcie bitowe wszystkich elementów wektora obiektu v
    cout << v.vec[0] << v.vec[1] << endl;
    cout << ~v <<  endl;

    VV v4;
    v4 = v;
    cout << v4.vec[0] << v4.vec[1] << endl;

    VV s1( 4, 8 ), s2( 3, 7 );
    cout << ( s1 == s2 ? "true" : "false" ) << endl;
    cout << ( s1 > s2 ? "true" : "false" ) << endl;
    cout << ( s1 && s2 ? "true" : "false" ) << endl;
    cout << ( !v ? "true" : "false" ) << endl;

    cout << endl;
    v = s1 + s2; //+ to sumowanie tych samych komórek wektorów, = zmienia miejsca liczb w nowym wektorze
    cout << v.vec[0] << v.vec[1] << endl;
    ( v = s1 ) += v;
    cout << v.vec[0] << v.vec[1] << endl;

    cout << endl;
    ++v;
    cout << v.vec[0] << v.vec[1] << endl;
    v--;
    cout << v.vec[0] << v.vec[1] << endl;

    return 0;
}
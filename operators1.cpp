#include <iostream>

using namespace std;

class Stack{
private:
    int *stackstore;
    int SP;
public:
    Stack( int size = 100 ){
        stackstore = new int[size];
        SP = 0;
    }
    ~Stack(){
        delete [] stackstore;
    }
    void push( int value ){
        stackstore[SP++] = value;
    }
    int pop(){
        return stackstore[--SP];
    }
    //Stack& operator<< ( int v ); //#1
    //Stack& operator>> ( int &v );

    int& operator[] ( int index );
};

/*Stack& Stack::operator<< ( int v ){ //#1
    push( v );
    return *this;
}
Stack& Stack::operator>> ( int &v ){
    v = pop();
    return *this;
}*/

//operator overloading jest poza klasą to trzeba wpisać i element sprzed operatora (Stack &s) i ten po (int v)
//                     w klasie to wpisujemy tylko element po operatorze
Stack& operator<< ( Stack &s, int v ){ //#2
    s.push( v );
    return s;
}

Stack& operator>> ( Stack &s, int &v ){
    v = s.pop();
    return s;
}

int& Stack::operator[] ( int index ){
    if( index > 0 || index <= -SP ) throw std::range_error( "out of stack" );
    return stackstore[SP + index - 1]; //shows the number on the top of the stack
}



enum weekday{ SUN, MON, TUE, WED, THU, FRI, SAT };
weekday operator+ ( weekday day, int days ){
    return static_cast<weekday>( ( static_cast<int>( day ) + days ) % 7 );
}

ostream& operator<< ( ostream &strm, weekday day ){
    switch( day ){
        case SUN: strm << "SUNDAY"; break;
        case MON: strm << "MONDAY"; break;
        case TUE: strm << "TURESDAY"; break;
        case WED: strm << "WEDNESDAY"; break;
        case THU: strm << "THURSDAY"; break;
        case FRI: strm << "FRIDAY"; break;
        case SAT: strm << "SATURDAY"; break;
        default: strm << "Somewhen..."; break;
    }   
    return strm;
}

int main(){

    int i = 2, j;
    Stack stk; 

    stk << 1 << 2 * i;
    cout << stk[0] << stk[-1] << endl;
    stk[0] = stk[-1] = 0;
    stk >> j >> i;
    cout << j << endl << i << endl;

    weekday d = SAT;
    d = d + 15;
    cout << d << endl;

    return 0;
}
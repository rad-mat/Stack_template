#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<char> stos;
    cout << "Czy stos jest pusty? " << boolalpha << stos.isEmpty() << endl;
    
    cout << "\t*** WKLADANIE NA STOS ***\n";
    try
    {
        stos.push( 'a' );
        stos.push( '5' );
        stos.push( '#' );
    }
    catch( StackException err )
    {
        cerr << err.getReason();
    }
    
    cout << "Czy stos jest pusty? " << boolalpha << stos.isEmpty() << endl;
    
    cout << "\t*** SCIAGANIE ZE STOSU (stos niepusty) ***\n";
    try
    {
        cout << "Na gorze stosu: " << stos.top() << endl;
        cout << "Sciagam: " << stos.pop() << endl;
        cout << "Na gorze stosu: " << stos.top() << endl;
        cout << "Sciagam: " << stos.pop() << endl;
        cout << "Sciagam: " << stos.pop() << endl;
    }
    catch( StackException err )
    {
        cerr << err.getReason();
    }
    cout << "Czy stos jest pusty? " << boolalpha << stos.isEmpty() << endl;
    
    cout << "\t*** SCIAGANIE ZE STOSU (stos pusty) ***\n";
    try
    {
        cout << "Na gorze stosu: " << stos.top() << endl;
        cout << "Sciagam: " << stos.pop() << endl;
    }
    catch( StackException err )
    {
        cerr << err.getReason();
    }

    return 0;
}
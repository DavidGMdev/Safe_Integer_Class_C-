#include <bits/stdc++.h>

using namespace std ;

class safe_int {

    private :
        // Needed To store and make gurnateed conversion
        string x ; 
        int y ; 

        // Private internal process

            // To validate no non-numeric chrachters found in the input value 
            bool validator( string x ) {
                int n = x.size() ;
                for ( int i = 0 ; i < n ; i++ ) { if ( ! isdigit( x[i] ) ) return false ; }
                return true;
            }

            // To convert in case of the validator return it's possible to convert
            int converter ( bool v , string x ) {
                if (v) return stoi(x) ;
                else return 0 ;
            }

            // To proccess both funtions together [ validationg until get trust 'save' value and then do converting ]
            int safe_integer_entery () {
                string x ; int y ;
                while (cin >> x , !validator(x) ) { cout << "Please enter a valid integer value ::: "; }
                y = converter( validator(x) , x ) ;
                return y ;
            }


    public :
        // No constructors or destructor needed till now 

        // Insertion and extraction operators s
            friend istream & operator >> ( istream & in , safe_int & obj ) {
                while (in >> obj.x , !obj.validator(obj.x) ) {cout << "ERROR !! Please enter a valid integer value ::: ";}
                obj.y = obj.converter( obj.validator(obj.x) , obj.x ) ;
                return in ; 
            }
            friend ostream & operator << ( ostream & out , safe_int const & obj ) {
                out << obj.y ;
                return out ; 
            }

        // convert from save int mode to normal primative int 
        int get_pure_int_value () {
            return y ;
        }
};

// convert from save int mode to normal primative int 
int get_pure_int_value (safe_int & obj) {

    // case nested return [ accessing private data] 
    // take care putting const in prameter is not allowed :) 
    return ( obj.get_pure_int_value() ) ;

} 

int main() {
    safe_int clients ;
    cout << "Please enter no of clients :: " << endl ;
    cin >> clients ; 
    cout << clients << endl ;
    int y = get_pure_int_value(clients) ; 
    cout << y + 1 << endl ;
}


/*
    // all numerical operations provided 
    // all operator overloading provided
    // template <T> for int , float , long , double etc..
    // all inner operations l.h.s or r.h.s define
    // operations done on Templates not only safe_integers

*/
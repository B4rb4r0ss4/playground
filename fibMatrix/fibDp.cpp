#include <bits/stdc++.h> 
using namespace std;
typedef __int128 ll;
const int SIZE = 1e8;
std::ostream&
operator<<( std::ostream& dest, __int128 value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    ll fibLast = 0;
    ll fibBefore = 1;
    for(int i=2; i<=n; i++) {
        ll cur = fibLast + fibBefore;
        fibLast = fibBefore;
        fibBefore = cur;
    }
    cout<<fibBefore;
    
}

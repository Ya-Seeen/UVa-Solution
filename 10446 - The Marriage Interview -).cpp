#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int RNG = 1000003;
const int RNGT = RNG*4;
const int MOD1 = 1e9+7;
const int MOD2 = 1e9+87;
const double pi = 2 * acos( 0.0 );

inline int _Int(){ int x; scanf( "%d", &x ); return x; }
inline LL _LLi(){ LL x; scanf( "%lld", &x ); return x; }
void pruts(){ puts( "-1" ); exit( EXIT_SUCCESS ); }

int dirX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dirY[] = { 0, 1, 0, -1, 1, -1, -1, 1 };
int rX[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int rY[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

template < class T > T tri_Area( T x1, T y1, T x2, T y2, T x3, T y3 ){
        return abs( x1*( y2-y3 ) - y1*( x2-x3 ) + ( x2*y3-x3*y2 ) );
};
template < class T > T Distance( T x1, T y1, T x2, T y2 ){
        return sqrt( ( x1-x2 ) * ( x1-x2 ) + ( y1-y2 ) * ( y1-y2 ) );
};
template < class T > T bigMod( T n, T p, T m ){
        if( p == 0 )return 1; if( p&1 )return ( n*bigMod( n, p-1, m ) )%m; T x = bigMod( n, p/2, m ); return ( x*x )%m;
};
int Case;
int sset( int N, int pos ){ return N=N|( 1<<pos ); }
bool check( int N, int pos ){ return ( bool )( N&( 1<<pos ) ); }
int reset( int N, int pos ){ return N=N&~( 1<<pos ); }
/**************************************###########################################***************************************
***************************************##    MD. YA-SEEN ARAFAT(MuradTaakla)    ##***************************************
***************************************##    CSE, University of Asia Pacific    ##***************************************
***************************************###########################################***************************************/

uLL dp[ 65 ][ 65 ], cnt;

uLL call_dp( int n, int m ){
        if( n <= 1 )return 0;
        uLL &R = dp[ n ][ m ];
        if( R != -1 )return R;
        R = 0;
        for( int i = 1; i <= m; i++ )R += 1+call_dp( n-i, m );
        return R;
}

void Hunger(){
        int n, m;
        memset( dp, -1, sizeof dp );
        while( scanf( "%d %d", &n, &m ) == 2 ){
                if( n > 60 )break;
                uLL ans = call_dp( n, m );
                printf( "Case %d: %llu\n", ++Case, ans+1LL );
        }
}

int main(){
        #ifndef ONLINE_JUDGE
        //        freopen("in.txt", "r", stdin);
        //        freopen("n.txt", "w", stdout);
        #endif
//        int t = _Int();
//        for( Case = 1; Case <= t; Case++ )
        Hunger();
        return 0;
}

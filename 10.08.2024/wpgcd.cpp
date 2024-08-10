#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ;


signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }

    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}

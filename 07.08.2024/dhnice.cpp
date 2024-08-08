#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 100005

int n ;
int a[MAXN] , f[MAXN] ;

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
    FORD(i,n,0) {
    	f[i] = f[i + 1] + 1 ; 
    	if(i + a[i] <= n) mini(f[i] , f[i + a[i] + 1]) ; 
    }
    cout << f[0] ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
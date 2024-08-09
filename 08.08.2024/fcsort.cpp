#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }


signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    int n ; 
    cin >> n ;
    vector<int> a ;
    a.resize(n+2,0) ; 
    vector<int> dp ;
    dp.resize(n+2,0) ;
    FOR(i,1,n) cin >> a[i] ; 
    int mx = 0 ; 
    FOR(i,1,n) {
    	dp[a[i]] = dp[a[i]-1] + 1 ; 
    	maxi(mx,dp[a[i]]) ; 
    }	
    cout << n - mx ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
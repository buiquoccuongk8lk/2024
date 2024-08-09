#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 100005

int n ;
int a[MAXN] , dp[MAXN][2] ;

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
    memset(dp,-0x3f,sizeof dp) ; 
    dp[n+1][0] = 0 ;
    FORD(i,n,1) {
    	dp[i][0] = a[i] + dp[i+1][0] ;
    	dp[i][1] = a[i] + dp[i+1][1] ; 
    	if(i < n) maxi(dp[i][1],dp[i+2][0] - a[i] - a[i+1]) ; 
    }
    cout << dp[1][1] ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }

int n , k ;
int a[25][25] ; 
int dp[1 << 20] ;

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> k ;
    FOR(i,1,n)FOR(j,1,n)cin>>a[i][j] ; 
    memset(dp,0x3f3f,sizeof dp) ; 
    dp[(1<<n)-1] = 0 ;
    int ans = 2e9 ; 
    FORD(mask,(1<<n)-1,(1<<k)-1) {
    	vector<int> ones ; 
    	FOR(j,0,n-1) if((mask >> j) & 1) ones.push_back(j) ; 
    	for(auto i : ones) {
    		for(auto j : ones) {
    			if(i!=j) {
    				mini(dp[mask ^ (1 << i)],dp[mask] + a[i+1][j+1]) ; 
    			}
    		}
    	}
    }
    FOR(mask,(1<<k)-1,(1<<n)-1) if(__builtin_popcount(mask) <= k) mini(ans,dp[mask]) ; 
    cout << ans ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
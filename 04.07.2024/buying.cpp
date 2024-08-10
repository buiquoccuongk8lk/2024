#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;
const int oo = 2e9 ;

template <class X,class Y> bool minimize(X &x,const Y &y) {
	if(x > y) {
		x = y ; 
		return 1 ; 
	} return 0 ; 
}

int n ;
int x[maxn] , y[maxn] , z[maxn] ; 

namespace sub1 {

	int dp[205][205][205] ; 

	void solve(void) {
		FOR(i,0,n) FOR(t2,0,n) FOR(t3,0,n) dp[i][t2][t3] = oo ; 

		dp[1][0][0] = x[1] ; 
		dp[1][1][0] = y[1] ;
		dp[1][0][1] = z[1] ;  

		FOR(i,1,n-1) {
			FOR(t2,0,n-1) FOR(t3,0,n-1) if(dp[i][t2][t3] < oo) {
				int val = dp[i][t2][t3] ; 
				minimize(dp[i+1][t2][t3],val + x[i+1]) ; 
				minimize(dp[i+1][t2+1][t3],val + y[i+1] - t2) ; 
				minimize(dp[i+1][t2][t3+1],val + z[i+1] - t3) ;  
			}
		}	

		ll ans = oo ; 
		FOR(t2,0,n) FOR(t3,0,n) minimize(ans,dp[n][t2][t3]) ; 
		cout << ans ; 
	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n ; 
    FOR(i,1,n) cin >> x[i] >> y[i] >> z[i] ; 
    sub1::solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}
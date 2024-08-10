#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;
const int mod = 1e9 + 7 ;
int n ;
int a[maxn] ;
int dp[2005][2005] ;

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,1,n) FOR(j,i,n) dp[i][j] = 1 ;
    FOR(i,1,n) {
    	FOR(j,1,i-1) {
    		FOR(k,1,j-1) {
    			if( (a[k] - a[j]) * (a[j] - a[i]) >= 0 ) {
    				dp[i][j] = (dp[i][j] + dp[j][k])%mod ; 
    			}
    		}
    	}
    }
    //FOR(i,1,n) FOR(j,   
    ll ans = 0 ;
    FOR(i,1,n) FOR(j,1,n) ans = (ans + dp[i][j])%mod ; 
    cout << ans ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}
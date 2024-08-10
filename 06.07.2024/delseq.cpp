#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e3 + 5 ;
const int LO = __lg(maxn) + 4 ; 
const ll inf = 1e18 ; 

int n ; 
int a[maxn] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

ll dp[maxn][(1<<LO)] ;
int maxi[maxn][maxn] ; 

void process(void) {

	int k = __lg(n) + 2 ;

	//FOR(i,0,n) FOR(mask,0,(1<<k)-1) dp[i][mask] = -inf ; 

	dp[0][0] = 0 ; 
	FOR(mask,0,(1<<k)-1) dp[0][mask] = 0 ; 

	FOR(i,1,n) {
		FOR(mask,0,(1<<k)-1) {
			dp[i][mask] = max(dp[i][mask] , dp[i-1][mask] + a[i]) ; 
			FOR(j,0,k-1) {
				if( (mask >> j) & 1 ) {
					int prev_mask = mask ^ (1 << j) ; 
					if(i >= (1<<j)) {
						dp[i][mask] = max(dp[i][mask] , dp[i - (1<<j)][prev_mask]) ; 
					}
				}
			}	
		}
	}

	ll ans = 0 ;

	FOR(i,0,n) FOR(mask,0,(1<<k)-1) ans = max(ans,dp[i][mask]) ; 

	cout << ans ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ;
    process() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}
#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int max_mitsurii = 1e5 + 5 ;

int n,k ; 
vector<int> g[max_mitsurii] ;

void mitsuri_read(void) {
	cin >> n >> k ;
	FOR(i,1,n-1) {
		int u,v ; 
		cin >> u >> v ; 
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
}

namespace mitsuri1 {

	int dp[max_mitsurii][3] ; 

	void dfs(int u,int par) {
		dp[u][1] = 1 ; 
		int ma1 = 1 ;
		int ma2 = 0 ;
		for(auto v : g[u]) {
			if(v==par) continue ; 
			dfs(v,u) ; 
			ma1+=dp[v][1] ; 
			ma2+=dp[v][0] ;
		}
		dp[u][0] = max(ma1,ma2) ; 
		dp[u][1] = ma2 ; 
 	}

	void solve(void) {
		dfs(1,1) ; 
		cout << max(dp[1][1],dp[1][0]) ; 
	}

}

namespace mitsuri2 {	

	vector<vector<int>>dp ; 
	int ans = 0 ; 
	ll temp[max_mitsurii] ; 

	void dfs(int u,int par) {
		dp[u][0] = 1 ;
		for(auto v : g[u]) {
			if(v==par) continue ; 
			dfs(v,u) ;
		}
		bool ok = false ; 
		for(int v : g[u]) {
			if(v==par) continue ; 
			dp[u][0]+=dp[v][k-1] ;
			if(!ok) {
				ok = 1 ; 
				FOR(j,1,k) dp[u][j] = dp[v][j-1] ; 
			} else {
				FOR(j,1,k) {
					temp[j] = max(dp[u][j] + dp[v][max(j-1,k-j-1)],dp[v][j-1] + dp[u][max(j,k-j)]) ; 
				}
				FOR(j,1,k) {
					dp[u][j] = temp[j] ; 
					temp[j] = 0 ; 
				}
			}
		}
		FORD(j,k-1,0) {
			dp[u][j] = max(dp[u][j],dp[u][j+1]) ; 
			ans = max(ans,dp[u][j]) ;
		} 
	}
	void solve(void) {
		dp.resize(n+2,vector<int>(k+2,0)) ; 
		dfs(1,1) ;	
		cout << ans ; 
	}
	
}

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    mitsuri_read() ;
    if(k==2) mitsuri1::solve() ;
    else mitsuri2::solve() ;  
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}
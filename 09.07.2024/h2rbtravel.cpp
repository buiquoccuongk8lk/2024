#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 1e5 + 5 ;
const int LO = __lg(maxn) + 1 ;

int n ;
vector<ii> g[maxn] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n-1) {
		int u,v,w ; 
		cin >> u >> v >> w ; 
		g[u].pb({v,w}) ; 
		g[v].pb({u,w}) ; 
	}
}

namespace sub1 {

	int P[maxn][LO] , h[maxn] , h1[maxn] , h2[maxn] ;

	void dfs(int u,int par) {
		for(auto [v,w] : g[u]) {
			if(v==par) continue ; 
			h[v] = h[u] + 1 ;
			h1[v] = h1[u] + (w==0) ; 
			h2[v] = h2[u] + (w==1) ; 
			P[v][0] = u ;
			dfs(v,u) ;
		}
	}

	int lca(int u,int v) {
		if(h[u]<h[v]) swap(u,v) ; 
		int z = __lg(h[u]) ; 
		FORD(s,z,0) {
			if((h[u]-h[v])>=(1<<s)) u = P[u][s] ; 
		}
		if(u==v) return u ; 
		FORD(s,z,0) if(P[u][s]!=P[v][s]) {
			u = P[u][s] ; 
			v = P[v][s] ; 
		}
		return P[u][0] ; 
	}

	int calc(int u,int v,int h[]) {
		return h[u] + h[v] - 2*h[lca(u,v)] ; 
	}

	void solve(void) {
		dfs(1,1) ; 
		for(int j(1) ; (1<<j) <= n ; j++) {
			FOR(i,1,n) {
				P[i][j] = P[P[i][j-1]][j-1] ; 
			}
		}
		int ans = 0 ;
		FOR(s,1,n) FOR(t,s+1,n) {
			FOR(v,1,n) if(v!=s and v!=t and calc(v,s,h)+calc(v,t,h)==calc(s,t,h)) {
				if(calc(v,s,h1)==calc(v,s,h2) and calc(v,t,h1)==calc(v,t,h2)) {
					ans++ ; 
					//cout << s <<' ' << v <<' ' << t << endl ;
					break ; 
				}
			}
		}
		cout << ans ; 
	}
}

namespace sub2 {


	void solve(void) {

		
	}	

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ;
    sub1::solve() ; 
    cout << endl ; 
    sub2::solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}
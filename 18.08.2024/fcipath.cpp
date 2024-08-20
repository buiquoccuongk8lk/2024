#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()

#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 250005 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 
const int LO = __lg(MAXN) + 1 ;

int n , q ; 
vi adj[MAXN] ;
int sz[MAXN] ; // số lượng đỉnh trong cay gốc u 
int g[MAXN] ; // số lượng đường đi đi qua đỉnh u trong cây gốc u
int f[MAXN] ; // số lượng đường đi qua cha của u mà không đi qua u
int pf[MAXN] ; // mảng cộng dồng của f từ gốc đến u
int par[MAXN] , P[MAXN][LO] , h[MAXN] ;

void init() {
	cin >> n >> q ; 
	FOR(i,1,n-1) {
		int u , v ; cin >> u >> v ; 
		adj[u].pb(v) ; adj[v].pb(u) ; 
 	}
}

void dfs1(int u) {
	sz[u] = g[u] = 1 ;
	for(auto v : adj[u]) {
		if(v==par[u]) continue ; 
		par[v] = u ; 
		P[v][0] = u ; 	
		h[v] = h[u] + 1 ;
		dfs1(v) ; 
		g[u]+= sz[u] * sz[v] ; 
		sz[u]+= sz[v] ; 
	}
	for(auto v : adj[u]) {
		if(v==par[u]) continue ; 
		f[v] = g[u] - sz[v] * (sz[u] - sz[v]) ; 
	}
}

void dfs2(int u) {
	for(auto v : adj[u]) {
		if(v==par[u]) continue ; 
		pf[v] = pf[u] + f[v] ; 
		dfs2(v) ; 
	} 
}

struct {
	void init() {
		for(int j(1) ; (1<<j) <= n ; j++) FOR(i,1,n) {
			P[i][j] = P[P[i][j-1]][j-1] ; 
		}
	}
	ii lca(int u,int v) {
		if(h[u]<h[v])swap(u,v) ; 
		int z = __lg(h[u]) ; 
		FORD(s,z,0) if(h[P[u][s]]>h[v]) {
			u = P[u][s] ; 
		}
		if(v==par[u]) return {u , v} ; 
		if(h[u]>h[v]) u = par[u] ;
		FORD(s,z,0) if(P[u][s]!=P[v][s]) {
			u = P[u][s] ; 
			v = P[v][s] ; 
		}
		return {u , v} ; 
	}
} LCA ;

void solve() {	
	dfs1(1) ; 	
	dfs2(1) ; 
	LCA.init() ; 
	while(q--) {
		int u , v ; cin >> u >> v ; 
		int ans = 0 ; 
		if(u==v) {
			ans = g[u] + sz[u] * (n - sz[u]) ; 
		} else {
			if(h[u]<h[v])swap(u,v) ; 
			ii p = LCA.lca(u,v) ; 
			int a = p.fi , b = p.se ; 
			// /cout << a << ' ' << b << endl ;
			if(b==par[a]) { 
				ans = g[u] + pf[u] - pf[a] + g[v] + (n-sz[v])*sz[v] - sz[a]*(n-sz[a]);
			} else {
				int k = par[a] ; 
	      		ans = g[u] + g[v] + pf[u] - pf[a] + pf[v] - pf[b] 
	        	+ g[k] + (n-sz[k])*sz[k] - sz[a]*(n-sz[a]) - sz[b]*(n-sz[a]-sz[b]);
			}
		}
		cout << ans << endl ;
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }	
    init() ; solve() ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
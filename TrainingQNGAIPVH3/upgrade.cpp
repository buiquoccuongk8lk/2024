/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 1e5 + 5 ;
const int LO = __lg(N) + 1 ;

int n , m ;
struct Edges {
	int u , v ; 
	ll w ; 
} e[N] ; 
vii g[N] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) cin >> e[i].u >> e[i].v >> e[i].w ; 
}

struct DisjoinSet {
	int par[N] ;
	int acs(int u) {
		if(u==par[u]) return u ;
		else return par[u] = acs(par[u]) ; 
	}
	bool join(int u,int v) {
		int x = acs(u) , y = acs(v) ; 
		if(x==y) return 0 ;
		par[y] = x ;
		return 1 ; 
	}
} dsu ; 

struct LCA {
	int P[N][LO] , mi[N][LO] , h[N] ; 

	void dfs(int u) {
		for(auto x : g[u]) {
			int v = x.fi , w = x.se ;
			if(v==P[u][0]) continue ; 
			P[v][0] = u ; 
			mi[v][0] = w ; 
			h[v] = h[u] + 1 ;
			dfs(v) ; 
		}
	} 

	int get(int u,int v) {
		if(u==v) return 0 ;
		if(h[u] < h[v])swap(u,v) ; 
		int mn = 2e9 ; 
		int z = __lg(h[u]) ; 
		FORD(s,z,0) if((h[u]-h[v])>=(1<<s)) {
			mini(mn,mi[u][s]) ;
			u = P[u][s] ; 
		}
		if(u==v) return mn ; 
		FORD(s,z,0) if(P[u][s]!=P[v][s]) {
			mini(mn,mi[u][s]) ; 
			mini(mn,mi[v][s]) ;  
			u = P[u][s] , v = P[v][s] ; 
		}
		mini(mn,mi[u][0]) ; 
		mini(mn,mi[v][0]) ;  
		return mn ; 
	}

	void init() {
		dfs(1) ; 
		for(int j = 1 ; (1 << j) - 1 <= n ; j++) {
			FOR(i,1,n) {
				int x = P[i][j-1] ; 
				P[i][j] = P[x][j-1] ; 
				mi[i][j] = min(mi[i][j-1],mi[x][j-1]) ; 
			}
		}
	}
} lca ; 

void solve() {	
	sort(e+1,e+1+m,[](Edges u,Edges v) {
		return u.w > v.w ; 
	}) ; 
	FOR(i,1,n) dsu.par[i] = i ;
	vi nmst ;
	FOR(i,1,m) {
		if(dsu.join(e[i].u,e[i].v)) {
			g[e[i].u].pb({e[i].v,e[i].w}) ; g[e[i].v].pb({e[i].u,e[i].w}) ; 
		} else nmst.pb(i) ; 
	}
	lca.init() ; 
	ll ans = 0 ;
	for(auto id : nmst) {
		int u = e[id].u , v = e[id].v ;
		ll w = e[id].w ; 
		ll new_w = lca.get(u,v) ;
		if(new_w > w) ans+= new_w - w ;
	}
	cout << ans ;
}	

signed main() {
    #define task "upgrade"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
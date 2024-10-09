// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
typedef pair<ll,int> pli ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 3e5 + 5 ;
const int LO = __lg(MAXN) + 1 ; 
const ll inf = 1e18 ;

int n , m , q ; 
struct KE {
	int v ;
	ll w ;
} ;
vector<KE> g[MAXN] , adj[MAXN] ; 
int P[MAXN][LO] , h[MAXN] ;
struct Edges {
	int u , v ;
	ll w ; 
} e[MAXN] ;
vi nmst ;
ll dist[MAXN][60] , f[MAXN] ;

void init() {
	cin >> n >> m ;
	FOR(i,1,m) {
		int u,v ; ll w ; cin >> u >> v >> w ; 
		e[i] = {u , v , w} ; 
		adj[u].pb(KE{v,w}) ; adj[v].pb(KE{u,w}) ; 
	}
	cin >> q ; 
}

struct DSU {
	int par[MAXN] ; 
	void reset() {
		FOR(i,1,n) par[i] = i ; 
	}
	int acs(int u) {
		if(u==par[u]) return u ;
		return par[u] = acs(par[u]) ; 
	} 
	bool join(int u,int v) {
		int x = acs(u) , y = acs(v) ; 
		if(x==y) return 0 ;
		par[y] = x ;
		return 1 ; 
	}
} dsu ; 

struct LCA {
	void dfs(int u) {
		for(auto x : g[u]) {
			int v = x.v ; ll w = x.w ; 
			if(v==P[u][0]) continue ; 
			P[v][0] = u ;
			h[v] = h[u] + 1 ; 
			f[v] = f[u] + w ; 
			dfs(v) ; 
		}
	}
	void init() {
		dfs(1) ;
		for(int j(1) ; (1 << j) <= n ; j++) 
			FOR(i,1,n) 
				P[i][j] = P[P[i][j-1]][j-1] ; 
	}
	int cc(int u,int v) {
		if(h[u]<h[v])swap(u,v) ; 
		int z = __lg(h[u]) ; 
		FORD(s,z,0) if((h[u]-h[v])>=(1<<s)) {
			u = P[u][s] ; 
		}
		if(u==v) return u ;
		FORD(s,z,0) if(P[u][s]!=P[v][s]) {
			u = P[u][s] ;
			v = P[v][s] ; 
		}
		return P[u][0] ;
	}
	ll DIST(int u,int v) {
		return f[u] + f[v] - 1ll * 2 * f[cc(u,v)] ; 
	}
} lca ;

void solve() {
	sort(e+1,e+1+m,[](Edges u,Edges v) {
		return u.w < v.w ; 
	}) ; 
	dsu.reset() ;	
	FOR(i,1,m) {
		int u = e[i].u , v = e[i].v ; 
		ll w = e[i].w ;  
		if(dsu.join(u,v)) {
			g[u].pb(KE{v,w}) ; g[v].pb(KE{u,w}) ; 
		} else {
			nmst.pb(u) ; 
			nmst.pb(v) ; 	 
		}
	}
	nmst.resize(unique(all(nmst))-nmst.begin()) ;
	FOR(i,0,nmst.size()-1) {
		priority_queue<pli,vector<pli>,greater<pli>>pq ; 
		FOR(j,1,n) dist[j][i] = inf ; 
		dist[nmst[i]][i] = 0 ;
		pq.push({0,nmst[i]}) ; 
		while(!pq.empty()) {
			int u = pq.top().se ;
			ll cost = pq.top().fi ; 
			pq.pop() ; 
			if(cost > dist[u][i]) continue ; 
			for(auto x : adj[u]) {
				int v = x.v ; ll w = x.w ; 
				if(mini(dist[v][i],dist[u][i]+w)) pq.push({dist[v][i],v}) ; 
			}
		}
	} 
	lca.init() ;
	while(q--) {
		int u , v ; cin >> u >> v ; 
		ll ans = lca.DIST(u,v) ; 
		FOR(i,0,nmst.size()-1) mini(ans,dist[u][i]+dist[v][i]) ; 
		cout << ans << '\n' ; 
 	}
}	

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
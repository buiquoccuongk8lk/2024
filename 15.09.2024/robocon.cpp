// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
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
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 
#define pli pair<ll,int>

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 1e5 + 5 ;
const ll inf = 2e9 ;
const int LO = __lg(MAXN) + 1 ;

int n , m , k , q ; 
vector<pair<int,ll>> g[MAXN] , adj[MAXN] ;
ll dist[MAXN] ;
struct Edges {
	int u , v ;
	ll w ; 
} e[MAXN] ;

void init() {
	cin >> n >> m >> k >> q ; 
	FOR(i,1,m) {
		int u , v ; ll w ; cin >> u >> v >> w ; 
		g[u].pb(ii(v,w)) ; g[v].pb(ii(u,w)) ; 
		e[i] = { u , v , w } ; 
	}
}

void dijkstra() {
	FOR(i,1,n) dist[i] = inf ;
	priority_queue<pli,vector<pli>,greater<pli>> pq ; 
	FOR(i,1,k) {
		dist[i] = 0 ; 
		pq.push({ 0 , i }) ; 
	}
	while(!pq.empty()) {
		ll cost = pq.top().fi ; 
		int u = pq.top().se ; 
		pq.pop() ; 
		if(cost > dist[u]) continue ;
		for(auto x : g[u]) {
			int v = x.fi ; ll w = x.se ;
			if(mini(dist[v],1ll*dist[u]+w)) pq.push({dist[v],v}) ; 
		}
	}
}

struct DSU {
	int par[MAXN] ; 
	void reset() {
		FOR(i,1,n) par[i] = i ; 
	}
	int acs(int u) {
		if(u==par[u]) return u ;
		else return par[u] = acs(par[u]) ;
	}
	bool join(int u,int v) {
		int x = acs(u) , y = acs(v) ; 
		if(x == y) return 0 ;
		par[y] = x ;
		return 1 ; 
	}
} dsu ; 

struct LCA {
	int P[MAXN][LO] , h[MAXN] ;
	ll ma[MAXN][LO] ;

	void dfs(int u) {
		for(auto x : adj[u]) {
			int v = x.fi ; ll w = x.se ;
			if(v==P[u][0]) continue ; 
			h[v] = h[u] + 1 ;
			P[v][0] = u ;
			ma[v][0] = w ; 
			dfs(v) ; 
		}
	}

	ll cost(int u,int v) {
		if(h[u]<h[v])swap(u,v) ;
		ll res = 0 ;
		int z = __lg(h[u]) ; 
		FORD(s,z,0) if((h[u]-h[v])>=(1<<s)) {
			maxi(res,ma[u][s]) ; 
			u = P[u][s] ; 
		}
		if(u == v) return res ; 
		FORD(s,z,0) if(P[u][s]!=P[v][s]) {
			maxi(res,ma[u][s]) ; 
			maxi(res,ma[v][s]) ; 
			u = P[u][s] , v = P[v][s] ; 
 		}
 		maxi(res,max(ma[u][0],ma[v][0])) ; 
 		return res ;
	}

	void init() {
		dfs(1) ;
		for(int j(1) ; (1 << j) <= n ; j++) FOR(i,1,n) {
			int x = P[i][j-1] ; 
			P[i][j] = P[x][j-1] ; 
			ma[i][j] = max(ma[i][j-1],ma[x][j-1]) ; 
 		}
	}
} lca ; 

void solve() {
	dijkstra() ;
	FOR(i,1,m) {
		int u = e[i].u , v = e[i].v ; 
		e[i].w+= dist[u] + dist[v] ; 
	}	
	dsu.reset() ;
	sort(e+1,e+1+m,[](Edges u,Edges v) {
		return u.w < v.w ; 
	}) ; 
	FOR(i,1,m) if(dsu.join(e[i].u,e[i].v)) {
		adj[e[i].u].pb(ii(e[i].v,e[i].w)) ; 
		adj[e[i].v].pb(ii(e[i].u,e[i].w)) ; 
	}
	lca.init() ;
	while(q--) {
		int u , v ; cin >> u >> v ; 
		cout << lca.cost(u,v) << '\n' ;
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
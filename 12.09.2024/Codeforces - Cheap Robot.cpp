// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
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
#define pil pair<ll,ll>

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 3e5 + 5 ;
const ll inf = 1e18 ;
const int LO = __lg(MAXN) + 1 ;

int n,m,k,q ;
struct Edges {
	int u,v ; 
	ll w ; 
} e[MAXN] ;
int P[MAXN][LO] ;
ll ma[MAXN][LO],near[MAXN],h[MAXN] ;
struct KE {
	int v ;
	ll w ; 
} ;
vector<KE> g[MAXN] ;

void init() {
	cin >> n >> m >> k >> q ; 
	FOR(i,1,m) {
		int u,v ; 
		ll w ; cin >> u >> v >> w ; 
		e[i] = { u , v , w } ;
		g[u].pb(KE{v,w}) ; g[v].pb(KE{u,w}) ; 
	}
}

void dijkstra() {
	priority_queue<pil,vector<pil>,greater<pil>>pq ; 
	FOR(i,1,n) near[i] = inf ; 
	FOR(i,1,k) {
		near[i] = 0 ; 
		pq.push({0,i}) ; 
	}
	while(!pq.empty()) {
		int u = pq.top().se ; 
		ll cost = pq.top().fi ; 
		pq.pop() ; 
		if(cost > near[u]) continue ; 
		for(auto x : g[u]) {
			int v = x.v ;
			ll w = x.w ;
			if(mini(near[v],1ll*near[u]+1ll*w)) pq.push({near[v],v}) ; 
		}
	}
}

void dfs(int u) {
	for(auto x : g[u]) {
		int v = x.v ; 
		ll w = x.w ; 
		if(v==P[u][0]) continue ; 
		P[v][0] = u ; 
		h[v] = h[u] + 1 ;
		ma[v][0] = w ; 
		dfs(v) ; 
	}
}

ll LCA(int u,int v) {
	if(h[u]<h[v])swap(u,v) ; 
	int z = __lg(h[u]) ;
	ll mx = 0 ; 
	FORD(s,z,0) if((h[u]-h[v])>=(1<<s)) {
		maxi(mx,ma[u][s]) ; 
		u = P[u][s] ; 
	}
	if(u==v) return mx ;
	FORD(s,z,0) if(P[u][s]!=P[v][s]) {
		maxi(mx,ma[u][s]) ; 
		maxi(mx,ma[v][s]) ; 
		u = P[u][s] ; 
		v = P[v][s] ; 
	}
	maxi(mx,ma[u][0]) ;
	maxi(mx,ma[v][0]) ;
	return mx ; 
}

int par[MAXN] ;

int acs(int u) {
	if(u==par[u])return u ;
	return par[u] = acs(par[u]) ; 
}

bool join(int u,int v) {
	int x = acs(u) , y = acs(v) ; 
	if(x==y) return 0 ;
	par[y] = x ; 
	return 1 ; 
}

void solve() {
	dijkstra() ; 
	FOR(i,1,n) g[i].clear() ;
	FOR(i,1,m) { 
		int u = e[i].u , v = e[i].v ; 
		ll w = near[u] + near[v] + e[i].w ;
		e[i].w = w ;
 	}
 	sort(e+1,e+1+m,[](Edges u,Edges v) {
 		return u.w < v.w ; 
 	}) ; 	
 	FOR(i,1,n) par[i] = i ;
 	FOR(i,1,m) if(join(e[i].u,e[i].v)) {
 		g[e[i].u].pb(KE{e[i].v,e[i].w}) ; 
 		g[e[i].v].pb(KE{e[i].u,e[i].w}) ; 
  	}
  	dfs(1) ; 
  	for(int j(1) ; (1ll << j) <= n ; j++) FOR(i,1,n) {
  		int x = P[i][j-1] ; 
  		P[i][j] = P[x][j-1] ;
  		ma[i][j] = max(ma[i][j-1],ma[x][j-1]) ;
  	}
  	while(q--) {
  		int u,v ; cin >> u >> v ; 
  		cout << LCA(u,v) << '\n' ; 
  	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
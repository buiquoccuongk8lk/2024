#include <bits/stdc++.h>
#define int long long
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
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ; 
#define MAXN 100005

int n , m , k ;
struct Edges {
	int u , v , w ; 
} e[MAXN] ;
vii g[MAXN] ;
vi spec ; 
int near[MAXN] , dist[MAXN] ;

void init() {
	cin >> n >> m ;
	FOR(i,1,m) cin >> e[i].u >> e[i].v >> e[i].w ; 
	FOR(i,1,m) {
		g[e[i].u].pb(ii(e[i].v,e[i].w)) ; 
		g[e[i].v].pb(ii(e[i].u,e[i].w)) ; 
	}
	cin >> k ; 
	FOR(i,1,k) {
		int u ; cin >> u ;
		spec.pb(u) ;
	}
}

void dijkstra() {
	priority_queue<ii,vector<ii>,greater<ii>>pq ;
	FOR(i,1,n) dist[i] = 1e18 ; 
	for(auto x : spec) {
		dist[x] = 0 ; 
		pq.push({dist[x],x}) ; 
		near[x] = x ; 
	}
	while(!pq.empty()) {
		int u = pq.top().se ; 
		int c = pq.top().fi ; 
		pq.pop() ; 
		for(auto x : g[u]) {
			int v = x.fi , w = x.se ; 
			if(mini(dist[v],c+w)) {
				pq.push({dist[v],v}) ; 
				near[v] = near[u] ; 
			}
		}
	}
}

struct {
	int par[MAXN] ;
	void init_DSU(void) {
		for(int i(1) ; i <= n ; i++) par[i] = i ;
	}
	int acs(int u){
		if(par[u]==u) return u ; 
		return par[u] = acs(par[u]) ; 
	}
	bool join(int u,int v) {
		int x = acs(u) ; 
		int y = acs(v) ;
		if(x==y) return 0 ;
		if(x!=y) {
			par[x] = y ;
		}
		return 1 ; 
	}
} dsu ; 

void solve() {
	dijkstra() ;	
	FOR(i,1,m) {
		e[i].w += dist[e[i].u] + dist[e[i].v] ; 
		e[i].u = near[e[i].u] ; 
		e[i].v = near[e[i].v] ; 
	}
	dsu.init_DSU() ;
	sort(e+1,e+1+m,[](Edges u,Edges v) {
		return u.w < v.w ; 
	}) ; 
	int ans = dist[1] ; 
	FOR(i,1,m) if(dsu.join(e[i].u,e[i].v)) ans+= e[i].w ;
	cout << ans ; 
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
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

const int N = 505 ;
const int LO = __lg(N) + 1 ;

int n , m ;
struct Edges {
	int u , v , w ; 
} e[505 * 505] ; 
int w[N] ; 
vii g[N] ; 

void init() {
	cin >> n >> m ; 
	FOR(i,1,n) cin >> w[i] ; 
	FOR(i,1,m) cin >> e[i].u >> e[i].v >> e[i].w ;
	FOR(i,1,m) {
		g[e[i].u].pb({e[i].v , e[i].w}) ;
		g[e[i].v].pb({e[i].u , e[i].w}) ; 
	}
	sort(e+1,e+1+m,[](Edges u,Edges v) {
		return u.w < v.w ; 
	}) ; 
}

namespace subtask_1 {
	void solve() {
		FOR(i,1,n) cout << n - 1 << ' ' ; 
	}
}

namespace subtask_2 {
	struct DisjoinSet {
		int lab[N] ;
		int find(int x) {
			if(lab[x] < 0) return x ; 
			else return lab[x] = find(lab[x]) ; 
		}
		bool join(int u,int v) {
			int x = find(u) , y = find(v) ; 
			if(x == y) return 0 ; 
			if(lab[x] > lab[y]) swap(x,y) ; 
			lab[x]+= lab[y] ; 
			lab[y] = x ; 
			return 1 ; 
		}
	} dsu ; 
	
	struct LCA {
		int h[N] , P[N][LO] , ma[N][LO] ; 

		void dfs(int u) {
			for(auto [v,w] : g[u]) {
				if(v==P[u][0]) continue ; 
				P[v][0] = u ; 
				ma[v][0] = w ;
				h[v] = h[u] + 1 ; 
				dfs(v) ; 
			}
		}

		int get_max(int u,int v) {
			if(h[u] < h[v]) swap(u,v) ; 
			int z = __lg(h[u]) ;
			int mx = 0 ; 
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

		void init() {
			dfs(1) ;
			for(int j = 1 ; (1 << j) <= n ; j++) {
				FOR(i,1,n) {
					int x = P[i][j-1] ;
					P[i][j] = P[x][j-1] ; 
					ma[i][j] = max(ma[i][j-1],ma[x][j-1]) ; 
				}
			}
		}
	} lca ;

	void solve() {
		FOR(i,1,n) g[i].clear() ;
		FOR(i,1,n) dsu.lab[i] = - 1 ; 
		FOR(i,1,m) if(dsu.join(e[i].u,e[i].v)) {
			g[e[i].u].pb({e[i].v , e[i].w}) ; 
			g[e[i].v].pb({e[i].u , e[i].w}) ; 
		}
		lca.init() ; 	
		FOR(i,1,n) {
			ll ans = 0 ; 
			FOR(j,1,n) if(i!=j) ans+= 1ll * lca.get_max(i,j) ;
			cout << ans << ' ' ; 
		}
	}
}

namespace subtask_3 {

	struct DisjoinSet {
		int lab[N] ;
		int find(int x) {
			if(lab[x] < 0) return x ; 
			else return lab[x] = find(lab[x]) ; 
		}
		bool join(int u,int v) {
			int x = find(u) , y = find(v) ; 
			if(x == y) return 0 ; 
			if(lab[x] > lab[y]) swap(x,y) ; 
			lab[x]+= lab[y] ; 
			lab[y] = x ; 
			return 1 ; 
		}
	} dsu ; 
	
	struct LCA {
		int h[N] , P[N][LO] , ma[N][LO] ; 

		void dfs(int u) {
			for(auto [v,w] : g[u]) {
				if(v==P[u][0]) continue ; 
				P[v][0] = u ; 
				ma[v][0] = w ;
				h[v] = h[u] + 1 ; 
				dfs(v) ; 
			}
		}

		int get_max(int u,int v) {
			if(h[u] < h[v]) swap(u,v) ; 
			int z = __lg(h[u]) ;
			int mx = 0 ; 
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

		void init() {
			dfs(1) ;
			for(int j = 1 ; (1 << j) <= n ; j++) {
				FOR(i,1,n) {
					int x = P[i][j-1] ;
					P[i][j] = P[x][j-1] ; 
					ma[i][j] = max(ma[i][j-1],ma[x][j-1]) ; 
				}
			}
		}
	} lca ;

	void solve() {
		FOR(i,1,n) g[i].clear() ; 
		FOR(i,1,m) {
			e[i].w = max(w[e[i].u],w[e[i].v]) ; 	
		}
		sort(e+1,e+1+m,[](Edges u,Edges v) {
			return u.w < v.w ; 
		}) ; 
		FOR(i,1,n) dsu.lab[i] = - 1 ; 
		FOR(i,1,m) if(dsu.join(e[i].u,e[i].v)) {
			g[e[i].u].pb({e[i].v , e[i].w}) ; 
			g[e[i].v].pb({e[i].u , e[i].w}) ; 
		}
		lca.init() ; 	
		FOR(i,1,n) {
			ll ans = 0 ; 
			FOR(j,1,n) if(i!=j) ans+= 1ll * lca.get_max(i,j) ;
			cout << ans << ' ' ; 
		}
	}
}

namespace subtask_4 {
	struct DisjoinSet {
		int lab[N] ;
		int find(int x) {
			if(lab[x] < 0) return x ; 
			else return lab[x] = find(lab[x]) ; 
		}
		bool join(int u,int v) {
			int x = find(u) , y = find(v) ; 
			if(x == y) return 0 ; 
			if(lab[x] > lab[y]) swap(x,y) ; 
			lab[x]+= lab[y] ; 
			lab[y] = x ; 
			return 1 ; 
		}
	} dsu ; 

	bool mark[N] ;
	ll dist[N] ; 
	
	struct LCA {
		int h[N] , P[N][LO] , ma[N][LO] ; 

		void dfs(int u) {
			for(auto [v,w] : g[u]) {
				if(v==P[u][0]) continue ; 
				P[v][0] = u ; 
				ma[v][0] = w ;
				h[v] = h[u] + 1 ; 
				dfs(v) ; 
			}
		}

		int get_max(int u,int v) {
			if(h[u] < h[v]) swap(u,v) ; 
			int z = __lg(h[u]) ;
			int mx = 0 ; 
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

		void init(int st) {
			memset(P,0,sizeof P) ; 
			memset(h,0,sizeof h) ;
			memset(ma,0,sizeof ma) ;
			dfs(st) ;
			for(int j = 1 ; (1 << j) <= n ; j++) {
				FOR(i,1,n) {
					int x = P[i][j-1] ;
					P[i][j] = P[x][j-1] ; 
					ma[i][j] = max(ma[i][j-1],ma[x][j-1]) ; 
				}
			}
		}
	} lca ;

	void solve() {
		vi V ; 
		FOR(i,1,n) V.pb(w[i]) ; 
		sort(all(V)) ; 
		V.resize(unique(all(V))-V.begin()) ; 
		int VAL = V.size() ; 
		FOR(i,1,n) g[i].clear() ;

		FOR(i,1,n) {
			int pos = lower_bound(all(V),w[i]) - V.begin() ; 
			ll ans = 0 ; 

			FOR(j,1,n) dist[j] = 1e18 ;

			FOR(val,pos,VAL-1) {
				vi cur_node ; 
				FOR(node,1,n) if(w[node] <= V[val]) {
					cur_node.pb(node) ; 
					mark[node] = 1 ; 
				}

				vi cur_edge ;
				FOR(j,1,m) {
					int u = e[j].u , v = e[j].v ; 
					if(mark[u] && mark[v]) cur_edge.pb(j) ; 
				}

				FOR(node,1,n) dsu.lab[node] = - 1 ;
				for(auto id : cur_edge) {
					int u = e[id].u , v = e[id].v , w = e[id].w ; 
					if(dsu.join(u,v)) {
						g[u].pb({v , w}) ; g[v].pb({u , w}) ;
					}
				}	

				lca.init(i) ; 

				FOR(j,1,n) if(dsu.find(i)==dsu.find(j)) {
					dist[j] = min( dist[j] , 1ll * V[val] * lca.get_max(i , j) ) ;
				}

				FOR(node,1,n) g[node].clear() ; 
				FOR(node,1,n) mark[node] = 0 ;
			}

			FOR(j,1,n) ans+= dist[j] ; 
			cout << ans << ' ' ;
		}
	}
}

namespace subtask_5 {

	struct DisjoinSet {
 		int lab[N] ; 
 		int find(int x) {
 			if(lab[x] < 0) return x ; 
 			else return lab[x] = find(lab[x]) ; 
 		}
 		bool join(int u,int v) {
 			int x = find(u) , y = find(v) ; 
 			if(x == y) return 0 ; 
 			if(lab[x] > lab[y]) swap(x,y) ; 
 			lab[x]+= lab[y] ; 
 			lab[y] = x ; 
 			return 1 ; 
 		}
	} dsu ; 

	ll f[N][N] ;

	int root , VAL ; 

	void dfs(int u,int par,int d) {
		for(auto [v,w] : g[u]) {
			if(v==par) continue ; 
			mini(f[root][v],1ll * max(d,w) * VAL) ;
			dfs(v,u,max(d,w)) ; 
		}
	}

	void solve() {
		FOR(i,1,n) g[i].clear() ;
		memset(f,0x3f,sizeof f) ;

		vi V ; 
		FOR(i,1,n) V.pb(w[i]) ; 
		sort(all(V)) ; 
		V.resize(unique(all(V))-V.begin()) ;

		for(auto val : V) {
			FOR(i,1,n) g[i].clear() ; 
			FOR(i,1,n) dsu.lab[i] = - 1 ; 

			FOR(j,1,m) {
				int u = e[j].u , v = e[j].v , ts = e[j].w ; 
				if(w[u] <= val && w[v] <= val) {
					if(dsu.join(u,v)) {
						g[u].pb({v , ts}) ; 
						g[v].pb({u , ts}) ; 
					}
				} 	
			}

			FOR(i,1,n) if(w[i] <= val) {
				root = i ;
				VAL = val ;
				dfs(i,i,0) ; 
			}
		}

		FOR(i,1,n) {
			ll ans = 0 ;
			f[i][i] = 0 ;
			FOR(j,1,n) ans+= f[i][j] ; 
			cout << ans << ' ' ; 
		}
	}
}

signed main() {
    #define task "mmgraph"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    int theta ; cin >> theta ; 
    init() ;
    if(theta==1) return subtask_1::solve(),0 ; 
    if(theta==2) return subtask_2::solve(),0 ;
    if(theta==3) return subtask_3::solve(),0 ;
    if(theta==4) return subtask_4::solve(),0 ; 
    if(theta==5) return subtask_5::solve(),0 ; 
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
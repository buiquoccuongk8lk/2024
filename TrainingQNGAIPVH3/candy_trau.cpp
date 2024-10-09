/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
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
#define endl '\n'
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ; } return false ; }
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ; } return false ; }

const int N = 2e5 + 5 ; 
const int mod = 1e9 + 7 ; 

int n , m ;
vii g[505] ;
struct Edges {
	int u , v , w ; 
} e[10005] ; 

void init() {	
	cin >> n >> m ; 
	FOR(i,1,m) {
		int u , v , w ; cin >> u >> v >> w ; 
		e[i] = {u , v , w} ; 
		g[u].pb(ii(v,w)) ; g[v].pb(ii(u,w)) ; 
	}
}

namespace subtask_1 {
	ll dist[505][505] , f[505][505] , new_dist[505][505] ; 
	
	struct KE {
		int v , w , id ; 
	} ;
	vector<KE> adj[505] ; 
	 
	void dijkstra(int st,int ed) {	
		priority_queue<pli,vector<pli>,greater<pli>> pq ; 
		FOR(j,1,n) dist[st][j] = 1e18 ;
		 
		dist[st][st] = 0 ; 
		pq.push({0 , st}) ;
		
		while(!pq.empty()) {
			auto [cost,u] = pq.top() ; 
			pq.pop() ; 
			if(cost > dist[st][u]) continue ; 
			for(auto [v,w] : g[u]) {
				if(mini(dist[st][v],cost+w)) {
					pq.push({cost + w,v}) ; 
				} 
			}
		}
	}
	
	void solve() {
		FOR(i,1,n) dijkstra(i,0) ; 
		
		FOR(i,1,m) {
			auto[u,v,w] = e[i] ; 
			adj[u].push_back({v,w,i}) ; adj[v].push_back({u,w,i}) ; 
		}
		
		FOR(i,1,m) {
			priority_queue<pli,vector<pli>,greater<pli>> pq ; 
			FOR(u,1,n) FOR(v,1,n) new_dist[u][v] = 1e18 ; 
			
			FOR(j,1,n) {
				new_dist[j][j] = 0 ; 
				pq.push({0 , j}) ; 
				while(!pq.empty()) {
					auto [cost,u] = pq.top();  
					pq.pop() ; 
					if(cost > new_dist[j][u]) continue ; 
					for(auto [v,w,id] : adj[u]) if(id!=i) {
						if(mini(new_dist[j][v],cost+w)) {
							pq.push({cost+w,v}) ; 
						}
					}
				}
			}	
			
			int ans = 0 ; 
			FOR(u,1,n) FOR(v,u+1,n) {
				if(new_dist[u][v] > dist[u][v]) ans++ ; 
			}
			cout << ans << endl ; 
		}
	}
}

namespace subtask_2 {
	ll dist[505][505] , f[505][505] ;
	 
	void dijkstra(int st,int ed) {	
		priority_queue<pli,vector<pli>,greater<pli>> pq ; 
		FOR(j,1,n) dist[st][j] = 1e18 ;
		 
		dist[st][st] = 0 ; 
		f[st][st] = 1 ; 
		pq.push({0 , st}) ;
			
		ll cost ; 
		int u ; 
		
		while(!pq.empty()) {
			u = pq.top().second ; cost = pq.top().first ; 
			pq.pop() ; 
			if(cost > dist[st][u]) continue ; 
			if(u==ed) break ; 
			for(auto [v,w] : g[u]) {
				if(mini(dist[st][v],cost+w)) {
					pq.push({cost + w,v}) ; 
					f[st][v] = f[st][u] ; 
				} else if(dist[st][v]==cost+w) {
					f[st][v] = (f[st][v] + f[st][u]) ; 
				}
			}
		}
	}
	
	int x , y , w ; 
	
	void solve() {
		FOR(i,1,n) dijkstra(i,0) ; 

		FOR(i,1,m) {
			x = e[i].u , y = e[i].v , w = e[i].w ; 
			int ans = 0 ; 
			FOR(u,1,n) FOR(v,u+1,n) {
				if(dist[u][x] + dist[v][y] + w == dist[u][v]) {
					if(1ll * f[u][x] * f[v][y] == f[u][v]) {
						ans++ ; 
					}
				} else if(dist[u][y] + dist[v][x] + w == dist[u][v]) {
					if(1ll * f[u][y] * f[v][x] == f[u][v]) {
						ans++ ; 
					}
				}
	 		}
			cout << ans << endl ;
		}
	}	
}

namespace subtask_3 {
	struct KE {
		int v , w , id ; 
	} ; 
	vector<KE> adj[N] ;

	int ans[N] ;

	ll dist[505][505] , f[505][505] ;
	bool vis[505] ; 
	 
	void dijkstra(int st,int ed) {	
		priority_queue<pli,vector<pli>,greater<pli>> pq ; 
		FOR(j,1,n) dist[st][j] = 1e18 ;
		 
		dist[st][st] = 0 ; 
		f[st][st] = 1 ; 
		pq.push({0 , st}) ;
			
		ll cost ; 
		int u ; 
		
		while(!pq.empty()) {
			u = pq.top().second ; cost = pq.top().first ; 
			pq.pop() ; 
			if(cost > dist[st][u]) continue ; 
			if(u==ed) break ; 
			for(auto [v,w] : g[u]) {
				if(mini(dist[st][v],cost+w)) {
					pq.push({cost + w,v}) ; 
					f[st][v] = f[st][u] ; 
				} else if(dist[st][v]==cost+w) {
					f[st][v] = (f[st][v] + f[st][u]) ; 
				}
			}
		}
	}

	void dfs(int u,int oldID,int x,int y) {
		vis[oldID] = 1 ; 
		for(auto [v , w , id] : adj[u]) {
			if(vis[id]) continue ; 
			if(dist[u][x] + w + dist[v][y] == dist[x][y]) {
				if(f[u][x] * f[v][y] == f[x][y]) {; 
					ans[id]++ ; 
				}
			} else if(dist[u][y] + w + dist[v][x] == dist[x][y]) {
				if(f[u][y] * f[v][x] == f[x][y]) {
					ans[id]++ ; 
				}
			}
			dfs(v,id,x,y) ;
		}
	}

	void solve() {
		FOR(i,1,n) dijkstra(i,0) ;

		FOR(i,1,m) {
			auto [u,v,w] = e[i] ; 
			adj[u].pb({v , w , i}) ; adj[v].pb({u , w , i}) ; 
		}

		FOR(i,1,n) FOR(j,i+1,n) {
			memset(vis,0,sizeof vis) ; 
			dfs(i,0,i,j) ; 
		}
		FOR(i,1,m) cout << ans[i] << endl ;
	}
}

signed main() {
    #define task "candy"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".ans","w",stdout) ; 
    }
    init() ;
    return subtask_2::solve(),0 ;
    subtask_3::solve() ; 
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
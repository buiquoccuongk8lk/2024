/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
typedef pair<long long,int> pli ;
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

const int N = 2e5 + 5 ;
const int oo = 2e9 ;
const ll inf = 1e18 ; 

int n , m;
vii g[N] ; 
struct Edges {
	int u , v , w ; 
} e[N] ; 

void init() {
	cin >> n >> m ;
	FOR(i,1,n) g[i].clear() ;  
	FOR(i,1,m) {
		int u , v , w ; cin >> u >> v >> w ;
		g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
		e[i] = {u , v , w} ; 
	}
}

namespace subtask_1 {
	int dist[N] ;
	void solve() {	
		FOR(i,1,n) dist[i] = oo ;
		dist[1] = 0 ;
		queue<int> q ; 
		q.push(1) ; 
		while(!q.empty()) {
			int u = q.front() ; 
			q.pop() ;
			if(u == n) break ;
			for(auto [v,w] : g[u]) {
				if(mini(dist[v],dist[u]+w))
					q.push(v) ; 
			}
		}
		cout << dist[n] << ' ' ;
	}
}

namespace subtask_2 {
	ll dist[N][3] ;
	ll ans = inf ;

	struct PQ {
		int u , t ; 
		ll cost ; 
		bool operator <(const PQ &x) const {
			return cost > x.cost ; 
		}
	} ; 

	void dijkstra(int c) {
		priority_queue<PQ,vector<PQ>> pq ; 
		FOR(i,1,n) FOR(t,0,1) dist[i][t] = inf ;
		dist[1][0] = 0 ; 
		pq.push({1 , 0 , 0}) ; 
		while(!pq.empty()) {
			auto [u,t,cost] = pq.top() ; 
			pq.pop() ; 
			if(cost > dist[u][t]) continue ;
			if(u == n && t == 1) break ;
			for(auto [v,w] : g[u]) if(w >= c) {
				if(mini(dist[v][t | (w == c)],cost + w * c)) {
					pq.push({v , t | (w == c) , cost + w * c}) ; 
				}
			}
		}
		mini(ans,dist[n][1]) ; 
	}

	void solve() {
		ans = inf ;
		FOR(c,1,100) dijkstra(c) ; 
		cout << ans << ' ' ; 
	}	
}

namespace subtask_3 {
	ll dist1[N] , dist2[N] ; 
	
	struct PQ {
		int u ; 
		ll cost ; 
	} ; 
	struct cmp {
		bool operator () (PQ x,PQ y) {
			return x.cost > y.cost ; 
		}
	} ; 
		
	void dijkstra(int st,ll dist[],int lim) {
		priority_queue<PQ,vector<PQ>,cmp>pq ; 
		FOR(i,1,n) dist[i] = 1e12 ; 
		
		dist[st] = 0 ; 
		pq.push({st , 0}) ; 
		
		while(!pq.empty()) {
			int u = pq.top().u ; 
			ll cost = pq.top().cost ; 
			pq.pop() ; 
			if(cost > dist[u]) continue ; 
			for(auto [v,w] : g[u]) if(w >= lim) {
				if(mini(dist[v],cost+w)) {
					pq.push({v,cost+w}) ; 
				}
			}
		}
	}
	
	void solve() {	
		ll ans = 1e18 ; 
		dijkstra(1,dist1,0) ; 
		dijkstra(n,dist2,0) ;
		FOR(i,1,m) {
			auto [u,v,w] = e[i] ; 
			if(dist1[u] < inf && dist2[v] < inf) 
				mini(ans, 1ll * (dist1[u] + w + dist2[v]) * w) ; 
			if(dist1[v] < inf && dist2[u] < inf)
				mini(ans, 1ll * (dist1[v] + w + dist2[u]) * w) ;  
		}
		cout << ans << ' ' ; 
	}
}

signed main() {
    #define task "graph"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    int theta , tc ;
    cin >> theta >> tc ;
    while(tc--) {
    	init() ;
    	if(theta==1) subtask_1::solve() ;
    	if(theta==2) subtask_2::solve() ;
    	if(theta==3) subtask_3::solve() ; 
	}
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
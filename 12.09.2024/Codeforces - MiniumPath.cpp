// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
typedef pair<int,ll> pil ;
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

const int MAXN = 2e5 + 5 ;
const ll inf = 1e18 ; 

int n , m ;
vector<pil> g[MAXN] ; 
ll dist[MAXN][2][2] ; 

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) {
		int u , v ; ll w ; cin >> u >> v >> w ; 
		g[u].pb(pil(v,w)) ; g[v].pb(pil(u,w)) ; 
	}
}

struct DL {
	int dinh , tt1 , tt2 ;
	ll cost ; 
	bool operator <(const DL &e) const {
		return cost > e.cost ; 
	}
} ; 
	
void solve() {
	priority_queue<DL,vector<DL>>pq ; 
	memset(dist,0x3f,sizeof dist) ; 
	dist[1][0][0] = 0 ; 
	pq.push({1 , 0 , 0 , 0}) ; 
	while(!pq.empty()) {
		int u = pq.top().dinh ; 
		int t1 = pq.top().tt1 ; 
		int t2 = pq.top().tt2 ; 
		ll cost = pq.top().cost ; 
		pq.pop() ; 
		if(cost > dist[u][t1][t2]) continue ; 
		for(auto x : g[u]) {
			int v = x.fi ; ll w = x.se ; 
			if(t1==0 && t2==0) {
				if(mini(dist[v][t1][t2],dist[u][t1][t2]+w)) 
					pq.push({v,t1,t2,cost+w}) ; 

				if(mini(dist[v][1][t2],dist[u][t1][t2])) 
					pq.push({v,1,t2,cost}) ; 

				if(mini(dist[v][t1][1],dist[u][t1][t2]+2*w))
					pq.push({v,t1,1,cost+2*w}) ; 

				if(mini(dist[v][1][1],dist[u][t1][t2]+w))
					pq.push({v,1,1,cost+w}) ; 
			}
			if(t1==1 && t2==1) {
				if(mini(dist[v][t1][t2],dist[u][t1][t2]+w))
					pq.push({v,t1,t2,cost+w}) ; 
			}
			if(t1==1 && t2==0) {
				if(mini(dist[v][1][t2],dist[u][t1][t2]+w)) 
					pq.push({v,1,t2,cost+w}) ; 

				if(mini(dist[v][1][1],dist[u][t1][t2]+2*w)) 
					pq.push({v,1,1,cost+2*w}) ;
			}
			if(t1==0 && t2==1) {
				if(mini(dist[v][t1][t2],dist[u][t1][t2]+w))
					pq.push({v,t1,t2,cost+w}) ; 

				if(mini(dist[v][1][t2],dist[u][t1][t2])) 
					pq.push({v,1,t2,cost}) ; 
			}
		}
	}

	FOR(i,2,n) cout << dist[i][1][1] << ' ' ; 
}

signed main() {
    #define task "minmax"
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
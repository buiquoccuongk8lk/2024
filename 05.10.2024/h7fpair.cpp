/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;
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

int n, m, k ;
int a[N] ; 
vector <pair<int,long long>> g[N] ;
bool isOn[N] ;

void init() {
	cin >> n >> m >> k ; 
	FOR(i, 1, k) cin >> a[i] ; 
	FOR(i, 1, k) isOn[a[i]] = 1 ; 
	FOR(i, 1, m) {
		int u, v, w ; cin >> u >> v >> w ; 
		g[u].pb({v, w}) ; g[v].pb({u, w}) ; 
	}
}

ll dist[N] ; 
pil near[N] ; 

void dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist) ; 
	dist[st] = 0 ; 
	priority_queue<pli, vector<pli>, greater<pli>> pq ; 
	pq.push({0, st}) ; 
	
	while(!pq.empty()) {
		auto [cost, u] = pq.top() ; 
		pq.pop() ; 
		if(cost > dist[u]) continue ; 
		
		for(auto [v, w] : g[u]) {
			if(mini(dist[v], cost + w)) {
				pq.push({cost + w, v}) ;
				 
				if(isOn[v] && near[v].se > cost + w) {
					near[v].se = cost + w ; 
					near[v].fi = st ; 
				}
			}
		}
	}
}

void solve() {
	FOR(i, 1, n) near[i] = {- 1 , 2e9} ; 
	FOR(i, 1, sqrt(k)) dijkstra(a[i]) ; 
	FOR(i, 1, k) cout << near[a[i]].fi << " " ;
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
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
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
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 3e5 + 5 ;
const int LO = __lg(MAXN) + 1 ;

int n , q ;
int color[MAXN] ;
vi g[MAXN] ;
int in[MAXN] , h[MAXN] ;
vi nList , hList ;
int timeDFS ;
int ans[MAXN] ;
set<ii> col[MAXN] ;

void init() {
	cin >> n ;
	FOR(i,1,n-1) {
		int u , v ;
		cin >> u >> v ; 
		g[u].pb(v) ; g[v].pb(u) ;
	}
	FOR(i,1,n) cin >> color[i] ;
	cin >> q ;
}

void dfs(int u,int par) {
	nList.pb(u) ; hList.pb(h[u]) ; 
	in[u] = ++timeDFS ;
	for(auto v : g[u]) {
		if(v==par) continue ;
		h[v] = h[u] + 1 ; 
		dfs(v,u) ; 
		nList.pb(u) ; hList.pb(h[u]) ;
	}
	++timeDFS ;
}

struct SpareTable {
	int rmq[MAXN][LO] ;
	int merge(int i,int j) {
		return (hList[i] < hList[j] ? i : j) ;
	}
	void build() {
		int m = hList.size() - 1 ;
		FOR(i,1,m) rmq[i][0] = i ; 
		for(int j = 1 ; (1<<j) <= m ; j++) {
			for(int i = 1 ; i + (1 << j) - 1 <= m ; i++) {
				rmq[i][j] = merge(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ;
			}
		}
	}
	int query(int l,int r) {
		int k = __lg(r-l+1) ; 
		return merge(rmq[l][k],rmq[r-(1<<k)+1][k]) ; 
	}
} rmq ;

int LCA(int u,int v) {
	if(in[u] > in[v]) swap(u,v) ; 
	return nList[rmq.query(in[u],in[v])] ;
}

void Add(int u,int c) {
	col[c].insert({in[u],u}) ;
	auto it = col[c].lower_bound({in[u],u}) ;
	
	int prv = (it == col[c].begin() ? col[c].rbegin() -> second : prev(it) -> second) ; 
	int nxt = (next(it) == col[c].end() ? col[c].begin() -> second : next(it) -> second) ;

	ans[c]+= h[LCA(prv,nxt)] - h[LCA(prv,u)] - h[LCA(nxt,u)] ;
	ans[c]+= h[u] ;
}

void Erase(int u,int c) {
	auto it = col[c].lower_bound({in[u],u}) ;

	int prv = (it == col[c].begin() ? col[c].rbegin() -> second : prev(it) -> second) ; 
	int nxt = (next(it) == col[c].end() ? col[c].begin() -> second : next(it) -> second) ;

	ans[c]+= -h[LCA(prv,nxt)] + h[LCA(prv,u)] + h[LCA(nxt,u)] ; 
	ans[c]-= h[u] ;

	col[c].erase(*it) ;
}

void solve() {
	nList.pb(0) ; hList.pb(0) ;
	dfs(1,0) ;
	rmq.build() ;	
	FOR(i,1,n) Add(i,color[i]) ;
	while(q--) {
		char t ; 
		cin >> t ;
		if(t == 'Q') {
			int x ; cin >> x ; 
			cout << (col[x].size() ? ans[x] : -1) << '\n' ;
		} else {
			int u , x ;
			cin >> u >> x ; 
			Erase(u,color[u]) ; 
			Add(u,x) ;
			color[u] = x ;
		}
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
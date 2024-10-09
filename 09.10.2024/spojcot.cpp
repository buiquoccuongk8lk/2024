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
const int LG = __lg(N) + 3 ; 

int n, q ; 
int a[N] ;
vi g[N], POS[N] ; 
int deCompress[N] ; 

void init() {
	cin >> n >> q ; 
	FOR(i, 1, n) cin >> a[i] ; 
	
	FOR(i, 1, n - 1) {
		int u, v ; cin >> u >> v ; 
		g[u].push_back(v) ; g[v].push_back(u) ; 
	}
}

void Compress() {
	vi V ; 
	FOR(i, 1, n) V.pb(a[i]) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V)) - V.begin()) ; 
	FOR(i, 1, n) {
		int p = lower_bound(all(V), a[i]) - V.begin() + 1 ; 
		deCompress[p] = a[i] ; 
		a[i] = p ; 
	}
}

int st[N * LG + 10], L[N * LG + 10], R[N * LG + 10], H[N * LG + 10] ; 
int node = 0 ; 

int up(int old, int l, int r, int pos, int val) {
	int cur = ++ node ; 
	
	if(l == r) {
		st[cur] = st[old] + val ; 
		return cur ; 
	}
	
	int mid = (l + r) >> 1 ; 
	
	if(pos <= mid) {
		R[cur] = R[old] ; 
		L[cur] = up(L[old], l, mid, pos, val) ; 
	} else {
		L[cur] = L[old] ; 
		R[cur] = up(R[old], mid + 1, r, pos, val) ; 
	}
	
	st[cur] = st[L[cur]] + st[R[cur]] ; 
	return cur ; 
}

int get(int id, int l, int r, int u, int v) {
	if(l > v || r < u) return 0 ; 
	if(l >= u && r <= v) return st[id] ; 
	int mid = (l + r) >> 1 ; 
	return get(L[id], l, mid, u, v) + get(R[id], mid + 1, r, u, v) ; 
}

int par[N], sz[N], head[N], cur[N], pos[N], h[N] ;  
int timeDFS, crt ; 

void dfs_sz(int u) {
	sz[u] = 1 ; 
	for(int v : g[u]) {
		if(v == par[u]) continue ; 
		par[v] = u ; 
		h[v] = h[u] + 1 ; 
		dfs_sz(v) ; 
		sz[u]+= sz[v] ; 
	}
}

void dfs_hld(int u) {
	if(!head[crt]) head[crt] = u ; 
	pos[u] = ++ timeDFS ; 
	cur[u] = crt ; 
	
	int nxt = - 1 ; 
	for(int v : g[u]) {
		if(v == par[u]) continue ; 
		if(nxt == - 1 || sz[v] > sz[nxt]) nxt = v ; 
	}
	
	if(nxt != - 1) dfs_hld(nxt) ;
 	for(int v : g[u]) {
 		if(v == par[u] || v == nxt) continue ; 
 		crt++ ; 
 		dfs_hld(v) ; 
 	}
}

int lca(int u, int v) {
	while(cur[u]!=cur[v]) {
		if(cur[u] > cur[v]) u = par[head[cur[u]]] ; 
		else v = par[head[cur[v]]] ; 
	}
	if(h[u] < h[v]) return u ; 
	else return v ; 
}

int qry(int id, int u, int v) {
	int p = lca(u, v) ; 
	int res = 0 ; 
	
	while(cur[u] != cur[p]) {
		res+= get(H[id], 1, n, pos[head[cur[u]]], pos[u]) ;
		u = par[head[cur[u]]] ;  
	}
	
	while(cur[v] != cur[p]) {
		res+= get(H[id], 1, n, pos[head[cur[v]]], pos[v]) ; 
		v = par[head[cur[v]]] ; 
	}
	
	if(pos[u] < pos[v]) res+= get(H[id], 1, n, pos[u], pos[v]) ; 
	else res+= get(H[id], 1, n, pos[v], pos[u]) ; 
	
	return res ; 
}

void solve() {
	Compress() ; 
	dfs_sz(1) ; 
	dfs_hld(1) ; 
	FOR(i, 1, n) POS[a[i]].pb(i) ; 	
		
	FOR(i, 1, n) {
		H[i] = H[i - 1] ; 
		for(int v : POS[i]) {
			H[i] = up(H[i], 1, n, pos[v], 1) ; 
		} 
	}
	
	while(q--) {
		int u, v, k ; cin >> u >> v >> k ; 
		int l = 1, r = n, res = - 1 ;
		while(l <= r) {
			int mid = (l + r) >> 1 ; 
			if(qry(mid, u, v) >= k) res = mid, r = mid - 1 ; 
			else l = mid + 1 ; 
		}
		cout << deCompress[res] << endl ;
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
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
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
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}
const int MAXN = 2e5 + 5 ;

int n , q ;
vi g[MAXN] ;
int a[MAXN] ; 
int val[MAXN] , par[MAXN] , head[MAXN] , cur[MAXN] , IN[MAXN] , OUT[MAXN] , sz[MAXN] , arr[MAXN] ;
int crt , timeDFS ;  
int h[MAXN] ;


void init() {
	cin >> n >> q ; 
	FOR(i,1,n-1) {
		int u , v ; cin >> u >> v ; 
		g[u].pb(v) ; g[v].pb(u) ; 
	}
}

void dfs_sz(int u) {
	sz[u] = 1 ; 
	for(auto v : g[u]) {
		if(par[u]==v) continue ; 
		par[v] = u ;  
		h[v] = h[u] + 1 ;
		dfs_sz(v) ; 
		sz[u]+= sz[v] ; 
	}
}

void dfs_hld(int u) {
	if(!head[crt]) {
		head[crt] = u ; 
	}
	IN[u] = ++timeDFS ; 
	arr[IN[u]] = u ; 
	cur[u] = crt ;
	int nxt = -1 ; 

	for(auto v : g[u]) {
		if(par[u] == v) continue ; 
		if(nxt==-1 || sz[v] > sz[nxt]) nxt = v ; 
	}

	if(nxt!=-1) dfs_hld(nxt) ; 

	for(auto v : g[u]) {
		if(par[u] == v || v == nxt) continue ; 
		++crt ; 
		dfs_hld(v) ; 
	}
	OUT[u] = timeDFS ; 
}

int lazy[4*MAXN] , st[4*MAXN] ; 

void build(int id,int l,int r) {
	if(l==r) {
		st[id] = a[arr[l]] ; 
		return ; 
	}
	int mid = (l+r)/2 ; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ;
}

void down(int id,int l,int r) {
	if(lazy[id]==0) return ; 
	int mid = (l+r)/2 ; 

	st[id<<1]+= (mid-l+1)*lazy[id] ;
	st[id<<1|1]+= (r-mid)*lazy[id] ;

	lazy[id<<1]+= lazy[id] ; 
	lazy[id<<1|1]+= lazy[id] ;

	lazy[id] = 0 ;
}

int getSub(int id,int l,int r,int u,int v) {
	if(l > v || r < u) return 0 ; 
	if(l >= u && r <= v) return st[id] ; 
	int mid = (l+r)/2 ; 
	down(id,l,r) ; 
	return getSub(id<<1,l,mid,u,v)+getSub(id<<1|1,mid+1,r,u,v) ; 
}

int lca(int u,int v) {
	if(u==v) return u ; 
	while(cur[u]!=cur[v]) {
		if(cur[u]>cur[v]) u = par[head[cur[u]]] ; 
		else v = par[head[cur[v]]] ; 
	}
	if(h[u]<h[v]) return u ;
	else return v ; 
}

void update(int id,int l,int r,int u,int v,int val) {
	if(l > v || r < u) return ; 
	if(l >= u && r <= v) {
		st[id]+= (r-l+1)*val ; 
		lazy[id]+= val ; 
		return ; 
	}
	int mid = (l+r)/2 ;
	down(id,l,r) ; 
	update(id<<1,l,mid,u,v,val) ; 
	update(id<<1|1,mid+1,r,u,v,val) ; 
	st[id] = st[id<<1] + st[id<<1|1] ;
}

void up(int u,int v,int val) {
	int p = lca(u,v) ; 
	while(cur[u]!=cur[p]) {
		update(1,1,n,IN[head[cur[u]]],IN[u],val) ; 
		u = par[head[cur[u]]] ; 
	}
	while(cur[v]!=cur[p]) {
		update(1,1,n,IN[head[cur[v]]],IN[v],val) ; 
		v = par[head[cur[v]]] ; 
	}
	if(h[u]<h[v]) update(1,1,n,IN[u],IN[v],val) ; 
	else update(1,1,n,IN[v],IN[u],val) ;
}


void solve() {
	dfs_sz(1) ;
	dfs_hld(1) ;
	build(1,1,n) ;
	while(q--) {
		int t ; cin >> t ; 
		if(t==1) {
			int u ; cin >> u ; 
			cout << getSub(1,1,n,IN[u],OUT[u]) << '\n' ;
		}
		if(t==2) {
			int u ; cin >> u; 
			cout << getSub(1,1,n,IN[u],IN[u]) << '\n' ;
		}
		if(t==3) {
			int u,v,x;cin>>u>>v>>x ; 
			up(u,v,x) ;
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
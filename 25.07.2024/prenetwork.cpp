/*[продолжатьипродолжать]*/
/* ---------------------- *
 *   * Code by watbor     *
 *                        *
--------------------------*/

#include <bits/stdc++.h>
using namespace std ; 

#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , q ; 
vii g[N] ; 
struct Edges {
	int u , v , w ; 
} e[N] ; 
int val[N] , par[N] , head[N] , cur[N] , pos[N] , sz[N] , arr[N] ;
int in[N] , out[N] , h[N] , POS[N] ; 
int crt , timeDFS ;  

void init(void) {
	cin >> n >> q ; 
	FOR(i,1,n-1) {
		int u , v , w ; 
		cin >> u >> v >> w ; 
		g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
		e[i] = {u , v , w} ; 
	}
}

void dfs_sz(int u) {
	sz[u] = 1 ; 
	for(auto x : g[u]) {
		int v = x.fi ; 
		if(par[u]==v) continue ; 
		par[v] = u ;  
		h[v] = h[u] + 1 ;
		dfs_sz(x.fi) ; 
		sz[u]+= sz[x.fi] ; 
	}
}

void dfs_hld(int u) {
	if(!head[crt]) {
		head[crt] = u ; 
	}
	pos[u] = ++timeDFS ; 
	arr[pos[u]] = u ; 
	cur[u] = crt ;
	int nxt = -1 ; 

	for(auto x : g[u]) {
		int v = x.fi ; 
		if(par[u] == v) continue ; 
		if(nxt==-1 || sz[v] > sz[nxt]) nxt = v ; 
	}

	if(nxt!=-1) dfs_hld(nxt) ; 

	for(auto x : g[u]) {
		int v = x.fi ; 
		if(par[u] == v || v == nxt) continue ; 
		++crt ; 
		dfs_hld(v) ; 
	}
}
struct {
	vector<int> st[4*N] ; 

	vi merge(vi a,vi b) {
		vi ans ; 
		for(auto x : a) ans.pb(x) ;
		for(auto x : b) ans.pb(x) ; 
		sort(all(ans)) ; 
		return ans ; 
	}

	void build(int id,int l,int r) {
		if(l==r) {
			st[id].push_back(val[arr[l]]) ; 
			return ; 
		}
		int mid = (l+r)>>1 ; 
		build(id<<1,l,mid) ; 
		build(id<<1|1,mid+1,r) ; 
		st[id] = merge(st[id<<1],st[id<<1|1]) ;
	}

	int get(int id,int l,int r,int u,int v,int val) {
		if(l > v || r < u) return 0 ; 
		if(l >= u && r <= v) return upper_bound(all(st[id]),val) - st[id].begin() ; 
		int mid = (l+r)>>1 ; 
		return get(id<<1,l,mid,u,v,val) + get(id<<1|1,mid+1,r,u,v,val) ; 
	}

	int LCA(int u,int v) {
		while(cur[u]!=cur[v]) {
			if(cur[u] > cur[v]) u = par[head[cur[u]]] ; 
			else v = par[head[cur[v]]] ; 
		}
		if(h[u] < h[v]) return u ; 
		return v ;
	}

	int qry(int u,int v,int val) {
		int res = 0 ; 
		int lca = LCA(u,v) ; 

		while(cur[u]!=cur[lca]) {
			res+= get(1,1,n,pos[head[cur[u]]],pos[u],val) ; 
			u = par[head[cur[u]]] ; 
		}

		while(cur[v]!=cur[lca]) {
			res+= get(1,1,n,pos[head[cur[v]]],pos[v],val) ; 
			v = par[head[cur[v]]] ; 
		}

		if(pos[u] > pos[v]) {
			res+= get(1,1,n,pos[v]+1,pos[u],val) ; 
		} else if(pos[u] < pos[v]) {
			res+= get(1,1,n,pos[u]+1,pos[v],val) ; 
		}
		return res ; 
	}
} hld_tree ; 

void dfs(int u,int par) {
	in[u] = ++timeDFS ;
	POS[in[u]] = val[u] ;  
	for(auto x : g[u]) {
		int v = x.fi ; 
		if(v==par) continue ; 
		h[v] = h[u] + 1 ; 
		dfs(v,u) ; 
	}
	out[u] = timeDFS ; 
}

struct {
	vector<int> st[4*N] ;

	vi merge(vi a,vi b) {
		vi ans ; 
		for(auto x : a) ans.pb(x) ;
		for(auto x : b) ans.pb(x) ; 
		sort(all(ans)) ; 
		return ans ; 
	}

	void build(int id,int l,int r) {
		if(l==r) {
			st[id].push_back(POS[l]) ; 
			return ; 
		}
		int mid = (l+r)>>1 ; 
		build(id<<1,l,mid) ; 
		build(id<<1|1,mid+1,r) ; 
		st[id] = merge(st[id<<1],st[id<<1|1]) ;
	}

	int get(int id,int l,int r,int u,int v,int val) {
		if(l > v || r < u) return 0 ; 
		if(l >= u && r <= v) return upper_bound(all(st[id]),val) - st[id].begin() ; 
		int mid = (l+r)>>1 ; 
		return get(id<<1,l,mid,u,v,val) + get(id<<1|1,mid+1,r,u,v,val) ; 
	}


} tree ; 

void solve(void) {
	dfs_sz(1) ; 
	FOR(i,1,n-1) {
		if(par[e[i].v]==e[i].u) {
			val[e[i].v] = e[i].w ; 
		} else {
			val[e[i].u] = e[i].w ; 
		}
	}
	dfs_hld(1) ; 
	hld_tree.build(1,1,n) ; 
	timeDFS = 0 ;
	dfs(1,1) ; 
	tree.build(1,1,n) ;
	while(q--) {
		char T ; cin >> T ;
		if(T=='P') {
			int u , v , c ; cin >> u >> v >> c ; 
			cout << hld_tree.qry(u,v,c) << '\n' ; 
		} else {
			int k , c ; cin >> k >> c ; 
			int v = e[k].v , u = e[k].u ; 
			if(h[v]>h[u]) cout << tree.get(1,1,n,in[v]+1,out[v],c) << '\n' ;
			else cout << tree.get(1,1,n,in[1] + 1,out[1],c) - tree.get(1,1,n,in[u] + 1,out[u],c) << '\n' ; 
		}
	}
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}
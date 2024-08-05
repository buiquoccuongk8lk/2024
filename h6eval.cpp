/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

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
const int LO = __lg(N) + 1 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 1e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m ;
struct Edges {
	int u , v , w , id ; 
} e[(int)1e6+5] ; 
vii g[N] ; 
vi nmst , mst ;
int ans[(int)1e6+5] ; 

void init() {
	cin >> n >> m ;
	FOR(i,1,m) {
		int u , v , w ; cin >> u >> v >> w ;
		e[i] = {u,v,w,i} ; 
	}
}

struct {
	int lab[N] ;
	void reset(void) {
		FOR(i,1,n)lab[i] = -1 ;
	}
	int find(int x) {
		return lab[x] < 0 ? x : lab[x] = find(lab[x]) ; 
	}
	bool join(int u,int v) {
		int x = find(u) ; int y = find(v) ;
		if(x==y) return 0 ;
		if(lab[x] > lab[y]) swap(x,y) ;
		lab[x]+=lab[y] ;
		lab[y] = x ;
		return 1 ;
	}
} dsu ;

struct {
	int P[N][LO] , maxi[N][LO] , h[N] ;
	void dfs(int u,int par) {
		for(auto [v,w] : g[u]) if(v!=par) {
			h[v] = h[u] + 1 ; 
			P[v][0] = u ;
			maxi[v][0] = w ;
			dfs(v,u) ; 
		}
	}
	void init(void) {
		dfs(1,1) ;
		for(int j(1) ; (1<<j) <= n ; j++) {
			FOR(i,1,n) {
				int x = P[i][j-1] ; 
				P[i][j] = P[x][j-1] ; 
				maxi[i][j] = max(maxi[i][j-1],maxi[x][j-1]) ; 
			}
		}
	}
	int get(int u,int v) {
		if(u==v) return 0 ; 
		int ret = 0 ;
		if(h[u]<h[v])swap(u,v) ; 
		int z = __lg(h[u]) ; 
		FORD(s,z,0) if((h[u]-h[v])>=(1<<s)) {
			ret = max(ret,maxi[u][s]) ; 
			u = P[u][s] ; 
		}
		if(u==v) return ret ; 
		FORD(s,z,0) if(P[u][s]!=P[v][s]) {
			ret = max(ret,maxi[u][s]) ; 
			ret = max(ret,maxi[v][s]) ; 
			u = P[u][s] ; 
			v = P[v][s] ; 
		}
		ret = max(ret,maxi[u][0]) ; 
		ret = max(ret,maxi[v][0]) ;
		return ret ; 
	}
} lca ;

struct {
	int sz[N] , h[N] , par[N] , cur[N] , pos[N] , arr[N] , head[N] ;
	int st[4*N] , lazy[4*N] ;  
	int timeDFS , crt ; 
	void dfs_sz(int u) {
		sz[u] = 1 ; 
		for(auto [v,w] : g[u]) {
			if(v==par[u]) continue ; 
			par[v] = u ;
			h[v] = h[u] + 1 ; 
			dfs_sz(v) ; 
			sz[u]+=sz[v] ; 
		}
	}
	void dfs_hld(int u) {
		if(head[crt]==0) head[crt] = u ;
		pos[u] = ++timeDFS ; 	
		arr[pos[u]] = u ;
		cur[u] = crt ; 

		int nxt = -1 ; 
		for(auto [v,w] : g[u]) if(v!=par[u]) {
			if(nxt==-1 || sz[v] > sz[nxt]) nxt = v ; 
		}

		if(nxt!=-1) dfs_hld(nxt) ;

		for(auto [v,w] : g[u]) if(v!=par[u] && v!=nxt) {
			crt++ ; 
			dfs_hld(v) ; 
		}	
	}
	void down(int id) {
		if(lazy[id]==oo) return ; 
		int &val = lazy[id] ; 
		minimize(st[id<<1],val) ; 
		minimize(st[id<<1|1],val) ; 
		minimize(lazy[id<<1],val) ; 
		minimize(lazy[id<<1|1],val) ; 
		val = oo ; 
	}	
	void update(int id,int l,int r,int u,int v,int val) {
		if(l > v || r < u) return ; 
		if(l >= u && r <= v) {
			minimize(st[id],val) ; 
			minimize(lazy[id],val) ; 
			return ; 
		}
		int mid = (l+r)>>1 ; 
		down(id) ; 
		update(id<<1,l,mid,u,v,val) ; 
		update(id<<1|1,mid+1,r,u,v,val) ; 
		st[id] = min(st[id<<1],st[id<<1|1]) ; 
	}
	int get(int id,int l,int r,int u,int v) {
		if(l > v || r < u) return oo ; 
		if(l >= u && r <= v) return st[id] ; 
		int mid = (l+r)>>1 ; 
		down(id) ; 
		return min(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v)) ; 
	}
	int find(int u,int v) {
		while(cur[u] != cur[v]) {
			if(cur[u] > cur[v]) {
				u = par[head[cur[u]]] ; 
			} else {
				v = par[head[cur[v]]] ; 
			}
		}
		if(h[u]<h[v]) return u ; 
		else return v ; 
	}	
	void up(int u,int v,int val) {
		int lca = find(u,v) ; 
		while(cur[u]!=cur[lca]) {
			update(1,1,n,pos[head[cur[u]]],pos[u],val) ; 
			u = par[head[cur[u]]] ; 
		}
		while(cur[v]!=cur[lca]) {
			update(1,1,n,pos[head[cur[v]]],pos[v],val) ; 
			v = par[head[cur[v]]] ; 
		}
		if(pos[u] < pos[v]) update(1,1,n,pos[u]+1,pos[v],val) ; 
		else if(pos[v] < pos[u]) update(1,1,n,pos[v]+1,pos[u],val) ; 
	}
	int qry(int u,int v) {
		int lca = find(u,v) ;
		int mi = oo ;
		while(cur[u]!=cur[lca]) {
			mi = min(mi,get(1,1,n,pos[head[cur[u]]],pos[u])) ; 
			u = par[head[cur[u]]] ; 
		}
		while(cur[v]!=cur[lca]) {
			mi = min(mi,get(1,1,n,pos[head[cur[v]]],pos[v])) ; 
			v = par[head[cur[v]]] ; 
		}
		if(pos[u] < pos[v]) mi = min(mi,get(1,1,n,pos[u]+1,pos[v])) ; 
		else if(pos[v] < pos[u]) mi = min(mi,get(1,1,n,pos[v]+1,pos[u])) ; 
		return mi ; 
	}
	void init() {
		dfs_sz(1) ; dfs_hld(1) ; 	
		FOR(i,1,4*n) lazy[i] = st[i] = oo ;
	}
} hld ;

void solve() {
	sort(e+1,e+1+m,[](Edges u,Edges v) {
		return u.w < v.w ; 
	}) ; 
	dsu.reset() ; 
	FOR(i,1,m) {
		auto [u,v,w,id] = e[i] ; 
		if(dsu.join(u,v)) {
			mst.pb(i) ; 
		} else nmst.pb(i) ; 
	}
	for(auto id : mst) {
		auto [u,v,w,i] = e[id] ;
		g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
	}
	lca.init() ; 
	for(auto id : nmst) {
		auto [u,v,w,i] = e[id] ;
		ans[i] = lca.get(u,v) ; 
	}
	hld.init() ; 
	for(auto id : nmst) {
		auto [u,v,w,i] = e[id] ;
		hld.up(u,v,w) ; 
	}
	for(auto id : mst) {
		auto [u,v,w,i] = e[id] ; 
		ans[i] = hld.qry(u,v) ; 
	}
	FOR(i,1,m) cout << ans[i] << '\n' ; 
}

signed main() {
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
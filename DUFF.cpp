/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

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

int n , m , q ; 
vi G[N] ; 

int par[N] , head[N] , cur[N] , sz[N] , h[N] , pos[N] , arr[N] ;
int timeDFS , crt ;
vi val[N] , st[4*N] ; 

void init(void) {
	cin >> n >> m >> q ; 
	FOR(i,1,n-1) {
		int u,v ;
		cin >> u >> v ; 
		G[u].pb(v) ; G[v].pb(u) ; 
	}
}

void dfs_sz(int u) {
	sz[u] = 1 ; 
	for(auto v : G[u]) {
		if(v==par[u]) continue ; 
		h[v] = h[u] + 1 ; 
		par[v] = u ; 
		dfs_sz(v) ; 
		sz[u]+=sz[v] ; 
	}
}

void dfs_hld(int u) {
	if(head[crt]==0) {
		head[crt] = u ; 
	}
	pos[u] = ++timeDFS ; 
	arr[pos[u]] = u ; 	
	cur[u] = crt ; 

	int nxt = -1 ; 
	for(auto v : G[u]) {
		if(v==par[u]) continue ; 
		if(nxt==-1 || sz[v] > sz[nxt]) nxt = v ; 
	}

	if(nxt!=-1) dfs_hld(nxt) ; 

	for(auto v : G[u]) {
		if(v==par[u] || v==nxt) continue ; 
		++crt ; 
		dfs_hld(v) ; 
	}
}

vi merge(vi a,vi b) {
	vi ans ; 
	int i = 0 ; 
	int j = 0 ;
	int u = sz(a) - 1 ; 
	int v = sz(b) - 1 ; 

	while(i <= u and j <= v) {
		if(a[i] < b[j]){
			ans.pb(a[i])  ;
			i++ ; 
		} else {
			ans.pb(b[j]) ; 
			j++ ; 
		}
	}
	if(i > u) FOR(k,j,v) ans.pb(b[k]) ; 
	if(j > v) FOR(k,i,u) ans.pb(a[k]) ; 

	return ans ; 
}

void build(int id,int l,int r) {
	if(l==r) {
		for(auto x : val[arr[l]]) {
			st[id].pb(x) ; 
		}
		return ; 
	}
	int mid = (l+r)>>1 ; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ; 
	st[id] = merge(st[id<<1],st[id<<1|1]) ; 
}

vi get(int id,int l,int r,int u,int v) {
	if(l > v or r < u) { vi emp ;  return emp ; } 
	if(l >= u and r <= v) return st[id] ; 
	int mid = (l+r)>>1 ; 
	return merge( get(id<<1,l,mid,u,v) ,  get(id<<1|1,mid+1,r,u,v) ) ; 
}

int LCA(int u,int v) {
	while(cur[u]!=cur[v]) {
		if(cur[u] > cur[v]) u = par[head[cur[u]]] ; 
		else v = par[head[cur[v]]] ; 
	}

	if(h[u] < h[v]) return u ; 
	return v ;
}

vi qry(int u,int v) {
	vi ans ;  
	int lca = LCA(u,v) ; 

	while(cur[u]!=cur[lca]) {
		ans = merge(ans , get(1,1,n,pos[head[cur[u]]],pos[u]) ) ; 
		u = par[head[cur[u]]] ; 
	}

	while(cur[v]!=cur[lca]) {
		ans = merge(ans , get(1,1,n,pos[head[cur[v]]],pos[v]) ) ; 
		v = par[head[cur[v]]] ; 
	}

	if(h[u] < h[v]) ans = merge(ans , get(1,1,n,pos[u],pos[v]) ) ; 
	else ans = merge(ans , get(1,1,n,pos[v],pos[u]) ) ; 

	return ans ; 
}

void process(void) {

    dfs_sz(1) ; 
    dfs_hld(1) ; 

    FOR(i,1,m) {
    	int x ; 
    	cin >> x ; 
    	val[x].push_back(i) ; 
    }

    FOR(i,1,n) sort(all(val[i])) ; 

    build(1,1,n) ;

    while(q--) {
    	int u,v,k ;
    	cin >> u >> v >> k ; 
    	vi ans = qry(u,v) ; 
    	cout << min(sz(ans),k) << ' ' ;
    	FOR(j,0,min(sz(ans),k)-1) cout << ans[j] << ' ' ;
    	cout << endl ;
    }

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}
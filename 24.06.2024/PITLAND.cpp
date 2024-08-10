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

const int N = 1e6 + 5 ;
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

int n , m ;
struct Edge {
	int u , v , w ; 
	void input(int i) {
		cin >> u >> v >> w ; 
	}
	bool operator <(const Edge &e) const {
		return w > e.w ;
	}
}edges[N] , choose[N] ; 
vii G[N] ; 
int par[N] ; 
int P[N][LO] ,mini[N][LO] , h[N] ;


void init(void) {
	cin >> n >> m ;
	FOR(i,1,m) {
		edges[i].input(i) ; 
	}
}

int acs(int u) {
	if(u==par[u]) return u ;
	return par[u] = acs(par[u]) ; 
}

void joint(int u,int v) {
	int x = acs(u) ; 
	int y = acs(v) ; 
	if(x!=y) {
		par[y] = x ; 
	}
}

void DFS(int u,int par) {
	for(auto x : G[u]) {
		int v = x.fi ; 
		int w = x.se ; 
		if(v==par) continue ; 
		h[v] = h[u] + 1 ; 
		P[v][0] = u ; 
		mini[v][0] =w ; 
		DFS(v,u) ;
	}
}

int lca(int u,int v) {
	if(h[u]<h[v]) swap(u,v) ; 
	int z = __lg(h[u])  ;
	int ret = 2e9 ;
	FORD(s,z,0) {
		if( (h[u] - h[v]) >= (1<<s) ) {
			minimize(ret,mini[u][s]) ; 
			u = P[u][s] ; 
		}
	}
	if(u==v) return ret ; 
	FORD(s,z,0) {
		if(P[v][s]!=P[u][s]) {
			minimize(ret,mini[u][s]) ; 
			minimize(ret,mini[v][s]) ; 
			u = P[u][s] ; 
			v = P[v][s] ; 
		}
	}
	minimize(ret,mini[u][0]) ; 
	minimize(ret,mini[v][0]) ; 
	return ret ;
}

bool mark[N] ;

void process(void) {
    sort(edges+1,edges+1+m) ; 

    FOR(i,1,n) par[i] = i ;
    int sz = 0 ;

    FOR(i,1,m) {
    	if(acs(edges[i].u)!=acs(edges[i].v)) {
    		joint(edges[i].u,edges[i].v) ; 
    		G[edges[i].u].pb({edges[i].v,edges[i].w}) ; 
    		G[edges[i].v].pb({edges[i].u,edges[i].w}) ;
    		sz++ ; 
    		choose[sz] = {edges[i].u , edges[i].v , edges[i].w} ; 
    	}
    }
    DFS(1,1) ; 
    for(int j(1) ; (1<<j) <= n ; j++) {
    	FOR(i,1,n) {
    		int x = P[i][j-1] ; 
    		P[i][j] = P[x][j-1] ; 
    		mini[i][j] = min(mini[i][j-1] , mini[x][j-1]) ;
     	}
    } 
    ll ans = 0 ;
   	FOR(i,1,m) {
   		int mini = lca(edges[i].u,edges[i].v) ; 
   		if(mini >= edges[i].w) {
   			ans+=mini - edges[i].w ; 
   		}
   	}
   	cout << ans ;
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
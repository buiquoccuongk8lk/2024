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

int n ;

struct Edges {
	int u,v,w ; 
} E[N] ;

struct ke {
	int v,w ; 
} ; 

vector<ke> G[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n-1) {
		cin >> E[i].u >> E[i].v >> E[i].w ; 
		G[E[i].u].pb({E[i].v,E[i].w}) ; 
		G[E[i].v].pb({E[i].u,E[i].w}) ; 
	}
}

int sz[N] , cur[N] , head[N] , pos[N] , par[N] , arr[N] ;
int timeDFS , crt ; 
int lazy[4*N] , st[4*N] ; 

void dfs(int u) {
	sz[u] = 1 ;
	for(auto [v,w] : G[u]) {
		if(v == par[u]) continue ; 
		par[v] = u ; 
		dfs(v) ; 
		sz[u]+=sz[v] ; 
	}
}

void hld(int u) {
	if(head[u]==0) {
		head[u] = crt ; 
	}
	++timeDFS ; 
	pos[u] = timeDFS ; 
	arr[pos[u]] = u ; 
	cur[u] = crt ; 
	int nxt = -1 ; 
	for(auto [v,w] : G[u]) {
		if(v == par[u]) continue ; 
		if(nxt == -1 || sz[v] > sz[nxt]) nxt = v ; 
	}
	if(nxt!=-1) hld(nxt) ; 
	for(auto [v,w] : G[u]) {
		if(v == par[u] || v == nxt) continue ; 
		++crt ; 
		hld(v) ; 
	}
}

void down(int id) {
	if(lazy[id] & 1) {

		st[id<<1] = -st[id<<1] ; 
		st[id<<1|1] = -st[id<<1|1] ; 

		lazy[id<<1] = 1 ;
		lazy[id<<1|1] = 1 ;  
	}
	lazy[id] = 0 ; 
}

void update(int id,int l,int r,int u,int v,int val)

void process(void) {	

    dfs(1) ; 
    hld(1) ; 


}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int t ; cin >> t ;
    while(t--) {
    	init() ; 
    	process() ; 
	}
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}
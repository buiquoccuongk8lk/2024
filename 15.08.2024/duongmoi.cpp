#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ; 
#define MAXN 200005

int n , m ;
ii e[MAXN] ;
vi g[MAXN] ; 

void init() {
	cin >> n >> m ;
	FOR(i,1,m) {
		int u , v ; cin >> u >> v ;
		g[u].pb(v) ;  
		e[i] = ii(u,v) ;
	}
}

int low[MAXN] , num[MAXN] , sccID[MAXN] , vis[MAXN] , k[MAXN] , nc[MAXN] , f[MAXN] , p[MAXN] ; 
int timeDFS , scc , ans , ssc ;
deque<int> dq ;
int sz[MAXN] ;
set<int> se[MAXN];

void tarjan(int u,int par) {
	low[u] = num[u] = ++timeDFS ;
	dq.pb(u) ; 
	for(auto v : g[u]) {
		if(vis[v]) continue ; 
		if(num[v] > 0) mini(low[u],num[v]) ; 
		else {
			p[v] = u ;
			tarjan(v,u) ; 
			mini(low[u],low[v]) ;
		}
	}
	if(low[u]==num[u]) {
		scc++ ; 
		int x ; 
		do {
			x = dq.back() ;
			sccID[x] = scc ; 
			vis[x] = 1 ;
			dq.pop_back() ;
		} while(x!=u) ;
	}
}


void solve() {
	FOR(i,1,n)if(!num[i])tarjan(i,i) ;
	FOR(i,1,m) {	
		int u = e[i].fi , v = e[i].se ;  
		int x = sccID[u] , y = sccID[v] ; 
		if(x==y && u!=v && se[u].find(v)==se[u].end()) {
			se[u].insert(v) ; 
			f[x]++ ;
		}
	} 
	FOR(i,1,n) sz[sccID[i]]++ ; 
	int ans = 0 ; 
	FOR(i,1,scc) ans+= sz[i] * (sz[i] - 1) - f[i] ; 
	cout << ans ; 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
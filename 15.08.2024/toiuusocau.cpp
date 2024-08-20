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
#define MAXN 100005

int n , m ;
vi g[MAXN] ;
ii e[MAXN] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) {
		int u , v ; cin >> u >> v ; 
		e[i] = {u , v} ; 
		g[u].pb(v) ; g[v].pb(u) ; 
	}
} 

int low[MAXN] , num[MAXN] , sccID[MAXN] , vis[MAXN] , h[MAXN] , par[MAXN] ;
int timeDFS , scc ;
deque<int> dq ;

void tarjan(int u) {
	low[u] = num[u] = ++timeDFS ;
	dq.pb(u) ; 
	for(auto v : g[u]) {
		if(vis[v] or v==par[u]) continue ; 
		if(num[v] > 0) mini(low[u],num[v]) ; 
		else {
			par[v] = u ;
			tarjan(v) ; 
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

void dfs(int u) {
	vis[u] = 1 ;
	for(auto v : g[u]) {
		if(vis[v]) continue ; 
		h[v] = h[u] + 1 ;
		dfs(v) ; 
	}
} 
 
void solve() {
	FOR(i,1,n)if(!num[i])tarjan(i) ; 
	FOR(i,1,n)g[i].clear() ; 		
	FOR(i,1,m) {
		int x = sccID[e[i].fi] , y = sccID[e[i].se] ; 
		if(x==y) continue ;
		g[x].pb(y) ; g[y].pb(x) ; 
	} 
	memset(vis,0,sizeof vis) ; 
	dfs(1) ;
	int root1 = 0 , ma = 0 ; 
	FOR(i,1,scc)if(maxi(ma,h[i])) root1 = i ; 
	memset(vis,0,sizeof vis) ; 
	memset(h,0,sizeof h) ; 
	dfs(root1) ; 
	ma = *max_element(h+1,h+1+scc) ; 
	cout << scc - (ma + 1) ; 
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
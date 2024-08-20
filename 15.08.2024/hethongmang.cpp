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
#define MAXN 50005

int n , m , K , L ;
vi g[MAXN] ; 
int isA[MAXN] , isB[MAXN] ; 

void init() {
	cin >> n >> m >> K >> L ;
	FOR(i,1,K) {
		int x ; cin >> x ; isA[x] = 1 ; 
	} 
	FOR(i,1,L) {
		int x ; cin >> x ; isB[x] = 1 ;
	}
	FOR(i,1,m) {
		int u , v ; cin >> u >> v ; 
		g[u].pb(v) ; g[v].pb(u) ; 
	}
}

int low[MAXN] , num[MAXN] , sccID[MAXN] , vis[MAXN] ; 
int fA[MAXN] , fB[MAXN] ;

int timeDFS , scc , ans ;
deque<int> dq ;

void tarjan(int u,int par) {
	low[u] = num[u] = ++timeDFS ;
	dq.pb(u) ; 
	fA[u] = isA[u] , fB[u] = isB[u] ;
	for(auto v : g[u]) {
		if(vis[v] || v==par) continue ; 
		if(num[v] > 0) mini(low[u],num[v]) ; 
		else {
			tarjan(v,u) ; 
			mini(low[u],low[v]) ;
			fA[u]+= fA[v] ; 
			fB[u]+= fB[v] ;
			if(low[v] > num[u]) {
				if(fA[v]==0 || fA[v]==K || fB[v]==0 || fB[v] == L) ans++ ; 
			}
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
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

int n , m ;
ii e[MAXN] ;

void init() {
	cin >> n >> m ;
	FOR(i,1,m) cin >> e[i].fi >> e[i].se ; 
}

int par[MAXN],sz[MAXN] ;

void init_DSU(void) {
	for(int i(1) ; i <= n ; i++) par[i] = i , sz[i] = 1 ; 
}

int acs(int u){
	if(par[u]==u) return u ; 
	return par[u] =
	 acs(par[u]) ; 
}

int ans = 1 ;
int ssc  ;

void join(int u,int v) {
	int x = acs(u) ; 
	int y = acs(v) ;
	if(x!=y) {
		par[x] = y ;
		sz[y]+= sz[x] ;
		ssc-- ;
		maxi(ans,sz[y]) ; 
	}
}

void solve() {	
	ssc = n ; 
	init_DSU() ;
	FOR(i,1,m) {
		join(e[i].fi,e[i].se) ; 
		cout << ssc << ' ' << ans << '\n' ; 
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
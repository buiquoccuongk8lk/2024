/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 5e5 + 5 ; 

int n, m, q ; 
pii e[N], Q[N] ;
int ans[N] ;
vi Quer[N] ; 
int L[N], R[N] ; 

void init() {
	cin >> n >> m >> q ; 
	FOR(i, 1, m) cin >> e[i].fi >> e[i].se ;
	FOR(i, 1, q) cin >> Q[i].fi >> Q[i].se ;  
}

struct DisjointSet {
	int par[N] ; 
	
	int acs(int u) {
		if(u == par[u]) return u ; 
		else return par[u] = acs(par[u]) ; 
	}
	
	bool joint(int u, int v) {
		int x = acs(u), y = acs(v) ; 
		if(x == y) return 0 ; 
		par[y] = x ; 
		return 1 ; 
	}
} dsu ; 

void solve() {
	FOR(i, 1, q) L[i] = 1, R[i] = m ;
	memset(ans, - 1, sizeof ans) ; 

	while(1) {
		bool ok = 0 ; 
		FOR(i, 1, n) dsu.par[i] = i ; 
		FOR(i, 1, m) Quer[i].clear() ; 
		
		FOR(i, 1, q) if(L[i] <= R[i]) {
			ok = 1 ; 
			Quer[(L[i] + R[i])/2].pb(i) ; 
		}
		
		if(!ok) break ; 
		
		FOR(i, 1, m) {
			if(i != 0) dsu.joint(e[i].fi, e[i].se) ;
			for(int id : Quer[i]) {
				if(dsu.acs(Q[id].fi) == dsu.acs(Q[id].se)) ans[id] = i, R[id] = i - 1 ; 
				else L[id] = i + 1 ; 
			}
		}
	}
	
	
	FOR(i, 1, q) cout << ans[i] << endl ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
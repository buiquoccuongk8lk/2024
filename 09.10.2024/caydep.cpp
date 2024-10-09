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

const int N = 1e5 + 5 ; 

int n ; 
ll L[N], R[N] ;
vi g[N] ;

void init() {
	cin >> n ; 
	FOR(i, 1, n) cin >> L[i] >> R[i] ; 

	FOR(i, 1, n - 1) {
		int u, v ; cin >> u >> v ; 
		g[u].pb(v) ; g[v].pb(u) ; 
	}
}

ll dp[N][3] ; 

void dfs(int u, int p) {
	for(int v : g[u]) {
		if(v == p) continue ; 
		dfs(v, u) ; 
		dp[u][0] = max(dp[u][0], dp[v][1] + abs(R[v] - L[u])) ; 
		dp[u][0] = max(dp[u][0], dp[v][0] + abs(L[v] - L[u])) ; 
		dp[u][1] = max(dp[u][1], dp[v][0] + abs(L[v] - R[u])) ; 
		dp[u][1] = max(dp[u][1], dp[v][1] + abs(R[v] - R[u])) ; 
	}
}

void solve() {
	dfs(1, 1) ; 
	ll ans = 0 ;
	FOR(i, 1, n) maxi(ans, max(dp[i][0], dp[i][1])) ; 
	cout << ans ; 
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
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
const int mod = 1e9 + 7 ;

int n ; 
vii g[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n-1) {
		int u,v,w;cin>>u>>v>>w ; 
		g[u].pb(ii(v,w));g[v].pb(ii(u,w)) ;
	}
}

int dp[MAXN] ;
int res = 0 ;

void dfs(int u,int par) {
	for(auto x : g[u]) {
		int v = x.fi , w = x.se ; 
		if(v==par)continue ; 
		dfs(v,u) ; 
		res = (res + dp[v]) % mod ; 
		res = (res + (dp[v] * w%mod + w)*dp[u]%mod) % mod ;
		dp[u] = (dp[u] + dp[v] * w % mod + w) % mod ; 
	}
}

void solve() {
	dfs(1,1) ;
	cout << (res+dp[1])%mod ;
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
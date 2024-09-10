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

const int MAXN = 2005 ;

int n , S ;
int V[MAXN] , C[MAXN] ; 
int dp[MAXN][MAXN] ;
vi g[MAXN] ;

void init() {
	cin >> n >> S ; 
	FOR(i,2,n)cin >> V[i] ; 
	FOR(i,2,n)cin >> C[i] ; 
	FOR(i,1,n-1) {
		int u,v ; cin >> u >> v ; 
		g[u].pb(v) ; g[v].pb(u) ;
	}
}

void dfs(int u,int par) {
	dp[u][C[u]] = V[u] ; 
	for(auto v : g[u]) {
		if(v==par) continue ; 
		dfs(v,u) ;
		FORD(i,S,C[u]) {
			FOR(j,0,i-C[u]) maxi(dp[u][i],dp[u][i-j]+dp[v][j]) ;
		}
	}
}

void solve() {	
	memset(dp,-0x3f,sizeof dp) ;
	dfs(1,1) ; 
	int ans = 0 ;
	FOR(i,0,S)maxi(ans,dp[1][i]) ;
	cout << ans ;
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
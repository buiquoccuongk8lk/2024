#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

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

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 1e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

vi g[MAXN] ;
int n , a[MAXN] , tmp[4] , dp[MAXN][3] ;

void dfs(int u) {
	dp[u][a[u]] = 1 ;
	for(auto v : g[u]) {
		dfs(v) ; 
		tmp[1] = dp[u][1] * (dp[v][0] + dp[v][1])%mod ; 
		tmp[1] = (tmp[1] + (dp[u][0]*dp[v][1])%mod )%mod ;
		tmp[0] = dp[u][0] * (dp[v][0] + dp[v][1])%mod ; 
		dp[u][1] = tmp[1] ; 
		dp[u][0] = tmp[0] ; 
	} 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n ;
    FOR(i,2,n) {
    	int p ; cin >> p ; p++ ; 
    	g[p].pb(i) ; 
    }
    FOR(i,1,n) cin >> a[i] ; 
    dfs(1) ; 
    cout << dp[1][1] ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
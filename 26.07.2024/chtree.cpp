/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

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

const int N = 5e3 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
int a[N] ; 
vi g[N] ;
ll dp[N][2*N] , sum_node[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n-1) {
		int u , v ; cin >> u >> v ; 
		g[u].pb(v) ; g[v].pb(u) ; 
	}
}

void dfs1(int u,int par) {
	sum_node[u] = 1 ;
	for(auto v : g[u]) {
		if(v==par) continue ; 
		dfs1(v,u) ; 
		sum_node[u]+= sum_node[v] ; 
	}
}

void dfs2(int u,int par) {
	int nc = 0 , v1 = 0 , v2 = 0 ; 
	for(auto v : g[u]) {
		if(v==par) continue ; 
		nc++ ; 
		if(nc==1) v1 = v ; 
		if(nc==2) v2 = v ; 
		dfs2(v,u) ; 
	}
	if(nc==0) {
		minimize(dp[u][0],abs(a[u]-0)) ;
		minimize(dp[u][1],abs(a[u]-1)) ;  
	}
	if(nc==1) {	
		FOR(s,0,min(sum_node[u],sum_node[v1])) {
			minimize(dp[u][s],dp[v1][s] + abs(s - a[u])) ; 
		}
	} 
	if(nc==2) {
		FOR(s,0,sum_node[u]) {
			FOR(s1,0,min(1ll*s,sum_node[v1])) {
				int s2 = s - s1 ; 
				if(s2 > sum_node[v2]) continue ; 
				minimize(dp[u][s],dp[v1][s1] + dp[v2][s2] + abs(s-a[u])) ; 
			}
		}
	}
}

void solve(void) {
	dfs1(1,1) ; 
	FOR(i,1,n) FOR(j,0,sum_node[1]) dp[i][j] = inf ;
	ll ans = inf ; 
	dfs2(1,1) ; 
	FOR(j,0,sum_node[1]) minimize(ans,dp[1][j]) ;
	cout << ans ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; 
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}
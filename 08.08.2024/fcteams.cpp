#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 2505
const double eps = 1e-9 ; 

int n , k ;
struct DL {
	int s , v , p ; 
} a[MAXN] ; 
int sz[MAXN] ;
vector<int> g[MAXN] ;
bool vis[MAXN] ;
double dp[MAXN][MAXN] ;

void init() {
	cin >> k >> n ; 
	k++ ; 
	FOR(i,1,n) cin >> a[i].s >> a[i].v >> a[i].p ; 
	FOR(i,1,n) g[a[i].p].push_back(i) ; 
}

void dp_on_tree(int u,double mid) {
	fill(dp[u], dp[u]+min(k, sz[u])+1,-1e100);
	dp[u][0] = 0 ; 
	dp[u][1] = (u ? (double)a[u].v - (double)mid*a[u].s : 0) ; 
	int last = 1 ;
	for(auto v : g[u]) {
		dp_on_tree(v,mid) ; 
		for (int i = min(last,min(k, sz[u])) ; i >= 1; i--) {
	    	for (int j = 0; j <= min(k, sz[v]) && i+j <= min(k, sz[u]); j++) {
	    		dp[u][i+j] = max(dp[u][i+j],dp[u][i] + dp[v][j]);
	    		last = max(last, i+j);
	      	}
	    }
	}
}


bool check(double mid) {
	dp_on_tree(0,mid) ; 
	return (dp[0][k] >= 0.0) ; 
}

void solve() {
	FORD(i,n,0) {
		sz[i] = 1 ; 
		for(auto v : g[i]) sz[i]+= sz[v] ; 
	}	
	double l = 0 , r = 1e9 , ans = 0 ;
	while(l <= r) {
		double mid = (l+r)/2 ; 
		if(check(mid)) ans = mid , l = mid + eps ; 
		else r = mid - eps ; 
	}
	cout << setprecision(3) << fixed << ans ;
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
/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define endl '\n'
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ; } return false ; }
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ; } return false ; }

const int N = 105 ; 

int n , m ;
ii a[N] , b[N] ; 

void init() {	
	cin >> n ;
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ; 
	cin >> m ; 
	FOR(i,1,m) cin >> b[i].fi >> b[i].se ; 
}

int ccw(ii a,ii b,ii c) {
	return (b.fi - a.fi) * (c.se - b.se) - (b.se - a.se) * (c.fi - b.fi) ;  
}

int dist(ii a,ii b) {
	return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se) ; 
}

double dp[N][N] , C[N][N] ;  

bool check(int i,int j) {
	FOR(t,1,n) if(ccw(b[i],b[j],a[t]) <= 0) return 0 ; 
	return 1 ; 
}

void solve() {
	memset(dp,0x3f,sizeof dp) ;
	
	FOR(i,1,m) FOR(j,1,m) {
		if(i!=j && check(i,j)) {
			dp[i][j] = sqrt(dist(b[i],b[j])) ;
			C[i][j] = dp[i][j] ;  
		}
		else dp[i][j] = C[i][j] = 2e9 ; 
	}
	
	FOR(t,1,m) FOR(i,1,m) FOR(j,1,m) 
		dp[i][j] = min(dp[i][j],dp[i][t] + dp[t][j]) ; 
	
	double ans = 1e18 ; 
	FOR(i,1,m) FOR(j,1,m) mini(ans,dp[i][j] + C[j][i]) ; 
	cout << fixed << ' ' << setprecision(2) << ans ; 
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
// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
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

int n , m ;
ll a[505][505] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ;
}

ll dp[505][1<<15] ;
vi ones[1 << 15] ;

void solve() {
	memset(dp,0x3f,sizeof dp) ;
	FOR(mask,0,(1<<m)-1) {
		FOR(j,0,m-1) if((mask>>j)&1) ones[mask].pb(j) ;
	}
	dp[0][0] = 0 ; 
	FOR(i,1,n) FOR(mask,0,(1<<m)-1) {
	 	dp[i][mask] = min(dp[i][mask],dp[i-1][mask]) ; 
		for(auto x : ones[mask]) {
			mini(dp[i][mask],dp[i-1][mask^(1 << x)]+a[i][x+1]) ; 
		}
	}
	cout << dp[n][(1<<m)-1] ;
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
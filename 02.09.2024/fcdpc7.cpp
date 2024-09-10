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

const int MAXN = 3e5 + 5 ;

int n ;
ll x ;
ll a[MAXN] ;

void init() {
	cin >> n >> x ;
	FOR(i,1,n) cin >> a[i] ;
}

ll dp[MAXN][3] ;

void solve() {
	memset(dp,-0x3f,sizeof dp) ;
	dp[0][0] = 0 ;
	FOR(i,1,n) {
		dp[i][0] = max({1ll * 0,a[i],dp[i-1][0]+a[i]}) ; 
		dp[i][1] = max({dp[i-1][0] + a[i]*x , dp[i-1][1] + a[i]*x }) ;
		dp[i][2] = max({dp[i-1][1] + a[i],dp[i-1][0] + a[i] , dp[i-1][2] + a[i]}) ;  
	}
	ll ans = 0 ;
	FOR(i,1,n) {
		maxi(ans,max({dp[i][0],dp[i][1],dp[i][2]})) ; 
	}
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
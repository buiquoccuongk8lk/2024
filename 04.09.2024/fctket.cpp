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

const int MAXN = 5e3 + 5 ;

int n , p , q ;
int a[MAXN] ;

void init() {
	cin >> n >> p >> q ; 
	FOR(i,1,n) cin >> a[i] ;
	sort(a+1,a+1+n) ; 
}

int dp[MAXN][MAXN] ;

bool check(int w) {
	FOR(i,0,n) FOR(j,0,min(n,q)) dp[i][j] = 2e9 ;
	dp[0][0] = 0 ;
	dp[1][0] = 1 ;
	dp[1][1] = 0 ;
	FOR(i,2,n) {
		int l = 1 , r = i , v1 = i ;
		while(l <= r) {
			int mid = (l+r)/2 ; 
			if(a[mid] >= a[i] - 2 * w + 1) v1 = mid , r = mid - 1 ; 
			else l = mid + 1 ;
		}
		l = 1 , r = i ;
		int v2 = i ;
		while(l <= r) {
			int mid = (l+r)/2 ; 
			if(a[mid] >= a[i] - w + 1) v2 = mid , r = mid - 1 ; 
			else l = mid + 1 ; 
		}
		FOR(j,0,min({i,q})) {	
			if(j >= 1) mini(dp[i][j],dp[v1-1][j-1]) ;
			mini(dp[i][j],dp[v2-1][j] + 1) ;
		}
	}
	int ans = 2e9 ;
	FOR(j,0,q) mini(ans,dp[n][j]) ;
	return (ans <= p) ;
}

void solve() {
	int l = 1 , r = 1e9 , ans = -1 ; 
	while(l <= r) {
		int mid = (l+r)/2 ; 
		if(check(mid)) ans = mid , r = mid - 1 ;
		else l = mid + 1 ;
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
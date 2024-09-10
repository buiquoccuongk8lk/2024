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

const int MAXN = 2e5 + 5 ;
const int MAXK = 205 ;

int n , m , k ;
ll a[MAXN] ; 

void init() {
	cin >> n >> m >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
}
namespace sub2 {
	ll dp[MAXN][4] ;
	void solve2() {
		dp[0][0&1] = 0 ;
		ll ans = 0 ;
		FOR(j,1,k) {
			deque<int> dq ;
			FOR(i,1,n) {
				while(!dq.empty() && dq.front() < i - m) dq.pop_front() ; 
				if(dq.size()) dp[i][j&1] = dp[dq.front()][(j-1)&1] + 1LL * a[i] * j ;
				while(!dq.empty() && dp[dq.back()][(j-1)&1] <= dp[i][(j-1)&1]) dq.pop_back() ;
				dq.pb(i) ;
				if(j==k) maxi(ans,dp[i][j&1]) ;
			}
			FOR(i,1,n) dp[i][(j-1)&1] = -2e9 ;
		}	
		cout << ans ;
	}
}
namespace sub1 {
	ll dp[2005][2005] ;
	void solve1() {
		FOR(i,0,n)FOR(j,0,k) dp[i][j] = -1e18 ;
		dp[0][0] = 0 ;
		FOR(i,1,n) dp[i][1] = a[i] ; 
		FOR(i,1,n) FOR(j,1,min(i,k)) {
			FOR(v,max(1,i-m),i-1) maxi(dp[i][j],dp[v][j-1]+j*a[i]) ; 
		}
		ll ans = 0 ; 
		FOR(i,1,n) maxi(ans,dp[i][k]) ;
		cout << ans ;
	}
}


signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
   /*	if(n <= 2000) sub1::solve1() ;
    else*/ sub2::solve2() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */
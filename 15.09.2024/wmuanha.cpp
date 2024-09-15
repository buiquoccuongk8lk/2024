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
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 1e3 * 1e3 + 5 ;

int prime[MAXN + 5] ;
int n , k ;
int a[MAXN] , dp[MAXN] ;

void init() {
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void Sieve() {
	FOR(i,2,1e6) prime[i] = 1 ; 
	FOR(i,2,sqrt(1e6)) {
		for(int j = i * i ; j <= MAXN ; j+=i) prime[j] = 0 ; 
	}
}

void solve() {
	Sieve() ;	 
	if(k == 0) {
		int ans = 0 ; 
		int S = 0 ;
		FOR(i,1,n)S+= a[i] ;
		dp[0] = 1 ;
		FOR(i,1,n) FORD(j,S,0) if(j >= a[i]) {
			dp[j] = max(dp[j],dp[j-a[i]]) ; 
		}
		FOR(i,1,S) if(dp[i] && prime[i]) ans++ ; 
		cout << ans ; 
	} else {
		int ans = 2e9 ;

		int S = 0 ;
		FOR(i,1,n) S+= a[i] ;

		FOR(i,1,n) {
			int sum = 0 ;
			memset(dp,0,sizeof dp) ; 
			dp[0] = 1 ;
			vi cur ; 
			FOR(j,1,n) if(i!=j) cur.pb(j) ; 
			FOR(j,0,cur.size()-1) FORD(x,S,0) if(x >= a[cur[j]]) {
				maxi(dp[x],dp[x-a[cur[j]]]) ; 
			}
			FOR(j,1,S) if(prime[j] && dp[j]) sum++ ; 
			mini(ans,sum) ; 
		}

		cout << ans ;
	}
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
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */
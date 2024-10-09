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

const int N = 505 ; 

int n , k ;
ll a[N] ; 
ll dp[4][N][N] , pre[N][N] , suf[N][N] ;
ll deCompress[N] ;  
int VAL ; 

void init() {	
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void Compress() {
	vi V ; 
	FOR(i,1,n) V.pb(a[i]) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ; 
	FOR(i,1,n) {
		int p = lower_bound(all(V),a[i]) - V.begin() + 1 ; 
		deCompress[p] = a[i] ; 
		a[i] = p ;
	}
	VAL = V.size() ; 
}

void solve1() {
	ll ans = 0 ; 
	FOR(i,1,n) if(a[i] > a[i-1]) ans+= a[i] - a[i-1] ; 
	cout << ans ; 
}

void solve2() {
	memset(dp,0x3f,sizeof dp) ; 
	Compress() ; 
	dp[1][0][a[1]] = deCompress[a[1]] ;
	FOR(i,1,VAL) dp[1][i != a[1]][i] = deCompress[i] ; 
	
	FOR(i,2,n) {
		FOR(j,0,k) {
			pre[j][1] = dp[(i-1)&1][j][1] - deCompress[1] ; 
			FOR(val,2,VAL) {
				pre[j][val] = min(pre[j][val-1],dp[(i-1)&1][j][val] - deCompress[val]) ; 
			}
		}
		
		FOR(j,0,k) {
			suf[j][VAL] = dp[(i-1)&1][j][VAL] ; 
			FORD(val,VAL-1,1) {
				suf[j][val] = min(suf[j][val+1],dp[(i-1)&1][j][val]) ; 
			}
		}
		
		FOR(j,0,k) FOR(val,1,VAL) dp[i&1][j][val] = 1e14 ; 
			
		FOR(j,0,k) FOR(val1,1,VAL) {
			if(val1 > a[i]) 
				dp[i&1][j][a[i]] = min(dp[i&1][j][a[i]],dp[(i-1)&1][j][val1]) ; 
			else 
				dp[i&1][j][a[i]] = min(dp[i&1][j][a[i]],dp[(i-1)&1][j][val1] + deCompress[a[i]] - deCompress[val1]) ; 
		}
		
		FOR(j,1,k) FOR(val2,1,VAL) if(val2!=a[i]) {
			if(val2 > 1) dp[i&1][j][val2] = min(dp[i&1][j][val2],pre[j-1][val2-1] + deCompress[val2]) ; 
			dp[i&1][j][val2] = min(dp[i&1][j][val2],suf[j-1][val2]) ; 
		}
	}
	
	ll ans = 1e18 ; 
	FOR(val,1,VAL) mini(ans,dp[n&1][k][val]) ; 
	cout << ans ; 
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
    solve2() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
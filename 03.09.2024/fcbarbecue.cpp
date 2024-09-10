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
const int mod = 1e9 + 7 ;

int n ;
ii a[MAXN] ;
int fact[MAXN] , inv_fact[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ;
}

int LT(int x,int y) {
	if(y==0) return 1 ; 
	if(y==1) return x ; 
	int c = LT(x,y/2) % mod ; 
	if(y&1) return 1ll * c * c % mod * x % mod ; 
	else return 1ll * c * c % mod ;
}

int C(int n,int k) {
	return 1ll * fact[n] * inv_fact[n-k] % mod * inv_fact[k] % mod ;
}

void build_Comb() {	
	fact[0] = 1 ; 
	FOR(i,1,1e5) fact[i] = (1ll * fact[i-1] * i) % mod ;
	inv_fact[(int)1e5] = LT(fact[(int)1e5],mod-2) ;
	FORD(i,1e5-1,1) inv_fact[i] = 1ll * inv_fact[i+1] * (i+1) % mod ;
}

void solve1() {
	build_Comb() ; 
	int ans = 0 ; 
	FOR(i,1,n) FOR(j,i+1,n) {
		int sum = a[i].fi + a[i].se + a[j].fi + a[j].se ;
		int meat = a[i].fi + a[j].fi ;
		ans = (ans + C(sum,meat) % mod) % mod ;
	}	
	cout << ans ; 
}

int dp[3*2000][3*2000] ;

void solve2() {
	build_Comb() ;
	FOR(i,1,n) {
		dp[1000 - a[i].fi][1000 - a[i].se]++ ; 
	}
	FOR(i,0,2*1000) FOR(j,0,2*1000) {
		if(j >= 1) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod ;
		if(i >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod ;
	}
	int ans = 0 ;
	FOR(i,1,n) {
		ans = (ans + dp[a[i].fi + 1000][a[i].se + 1000]) % mod ;
		ans = (ans - C(2*(a[i].fi + a[i].se),2*a[i].fi) % mod + mod) % mod ; 
	}
	cout << 1ll * ans * LT(2,mod-2) % mod ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
  	//if(n <= 2000) solve1() ;
  	solve2() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */
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

const int mod = 1e9 + 7 ;

int n , k ;
string s ;

void init() {
	cin >> n >> k ; 
	cin >> s ; s = '*' + s ;
}

namespace sub23 {
	int dp[2005][2005] ;

	void solve() {
		dp[0][0] = 1 ; 
		FOR(i,1,n) FOR(j,1,n) {
			if(s[i] == s[j]) dp[i][j] = (1 + dp[i-1][j-1]) % mod ; 
			dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mod) % mod ;
		}
		cout << ( dp[n][n] + 1 ) % mod ;
	}
}

namespace sub4 {
	int dp[105][105][105] ;

	void solve() {
		FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) {
			if(s[i] == s[j] && s[j] == s[k]) dp[i][j][k] = (1 + dp[i-1][j-1][k-1]) % mod ; 
			dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1] - dp[i-1][j-1][k] - dp[i][j-1][k-1] - dp[i-1][j][k-1] + dp[i-1][j-1][k-1] + 1ll * mod * mod) % mod;
		}
		cout << (1 + dp[n][n][n]) % mod ;
	}

}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    if(k == 1) {
    	int ans = 1 ; 
    	FOR(i,1,n) ans = (ans + ans) % mod ;
    	cout << ans ; 
    	return 0 ; 
    }
    if(k == 2) sub23::solve() ;
    else sub4::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */
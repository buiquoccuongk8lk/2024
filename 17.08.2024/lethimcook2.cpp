#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()

#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 1e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n ;
int a[MAXN] ; 
int dp[105][10005] ;

void init() {
	cin >> n ;
	FOR(i,1,n) cin >> a[i] ;
}

void solve() {
	FOR(i,0,n)FOR(j,0,1e4) dp[i][j] = -inf ;
	dp[0][0] = 0 ; 
	FOR(i,1,n) FOR(j,0,1e4) {
		maxi(dp[i][j],dp[i-1][j]) ; 
		if(j + a[i] <= 1e4) maxi(dp[i][j+a[i]],dp[i-1][j] + a[i]) ; 
		maxi(dp[i][abs(j-a[i])],dp[i-1][j]) ; 
	}
	cout << dp[n][0] ;
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
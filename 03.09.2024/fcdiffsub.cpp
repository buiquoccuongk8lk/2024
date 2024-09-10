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

const int MAXN = 5e3 + 5 ;

int n , k ;
int a[MAXN] ;

void init() {
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] ;
}

int dp[MAXN][MAXN] ;

void solve() {
	int ans = 0 ; 
	FOR(i,1,n) FOR(j,1,n) if(a[i]!=a[j]) dp[i][j]++ ;
	FOR(i,1,n) FOR(j,1,n) dp[i][j]+= dp[i-1][j-1] ;
	FOR(i,k,n) FOR(j,k,n) maxi(ans,dp[i][j]-dp[i-k][j-k]) ;
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
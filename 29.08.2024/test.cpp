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
const int MAXN = 1505 ;

int n ;
ii st ;
int a[MAXN][MAXN] ;

void init() {
	cin >> n >> st.fi >> st.se ; 
	FOR(i,1,n)FOR(j,1,n)cin>>a[i][j] ;
}

int dp[MAXN][MAXN] ;

int Can(int i,int j) {
	if(j + 1 <= n) {
		FOR(nxt_i,1,n) if(abs(nxt_i-i)>1 && a[nxt_i][j+1] > a[i][j]) return 1 ;  
	}
	if(j - 1 >= 1) {
		FOR(nxt_i,1,n) if(abs(nxt_i-i)>1 && a[nxt_i][j-1] > a[i][j]) return 1 ; 
	}
	if(i + 1 <= n) {
		FOR(nxt_j,1,n) if(abs(nxt_j-j)>1 && a[i+1][nxt_j] > a[i][j]) return 1 ;
	}
	if(i - 1 >= 1) {
		FOR(nxt_j,1,n) if(abs(nxt_j-j)>1 && a[i-1][nxt_j] > a[i][j]) return 1 ;
	}
	return 1 ; 
}

int calc(int i,int j) {
	if(!Can(i,j)) return 0 ; 
	if(dp[i][j]!=-1) return dp[i][j] ;
	int &val = dp[i][j] ; 
	val = 1 ; 
	if(j + 1 <= n) {
		FOR(nxt_i,1,n) if(abs(nxt_i-i)>1 && a[nxt_i][j+1] > a[i][j]) {
			maxi(val,calc(nxt_i,j+1)+1) ;
		}
	}
	if(j - 1 >= 1) {
		FOR(nxt_i,1,n) if(abs(nxt_i-i)>1 && a[nxt_i][j-1] > a[i][j]) {
			maxi(val,calc(nxt_i,j-1)+1) ;
		}
	}
	if(i + 1 <= n) {
		FOR(nxt_j,1,n) if(abs(nxt_j-j)>1 && a[i+1][nxt_j] > a[i][j]) {
			maxi(val,calc(i+1,nxt_j)+1) ;
		}
	}
	if(i - 1 >= 1) {
		FOR(nxt_j,1,n) if(abs(nxt_j-j)>1 && a[i-1][nxt_j] > a[i][j]) {
			maxi(val,calc(i-1,nxt_j)+1) ;
		}
	}
	return val ; 
}

void solve() {
	memset(dp,-1,sizeof dp) ;
	cout << calc(st.fi,st.se) ;
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
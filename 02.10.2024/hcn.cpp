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

const int N = 1e3 + 5 ; 

int n , m ; 
int a[N][N] , f[N][N] ; 

void init() {	
	cin >> n >> m ; 
	FOR(i,1,n) FOR(j,1,m) {
		char x ; cin >> x ; 
		a[i][j] = (x == '.' ? 0 : 1) ; 
	}
	FOR(i,1,n) FOR(j,1,m) 
		f[i][j] = f[i-1][j] + f[i][j-1] + a[i][j] - f[i-1][j-1] ; 
}

int HCN(int x,int y,int u,int v) {
	return f[u][v] - f[u][y-1] - f[x-1][v] + f[x-1][y-1] ; 
}

int ans[N][N] ; 

void solve1() {
	FOR(x,1,n) FOR(y,1,m) {
		FOR(u,x,n) FOR(v,y,m) {
			if(HCN(x,y,u,v)==0) ans[u-x+1][v-y+1]++ ; 
		}
	}	
	FOR(i,1,n) {
		FOR(j,1,m) cout << ans[i][j] << ' ' ;
		cout << endl ;
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
    solve1() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
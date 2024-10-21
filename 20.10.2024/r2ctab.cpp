/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define uni(a) sort(all(a)), a.resize(unique(all(a))-a.begin()) 
#define MASK(a) (1ll << a) 

int gcd(int x, int y) {return __gcd(x, y) ;}
int lg(int x) {return __lg(x) ;}
int lcm(int x, int y) {return x / __gcd(x, y) * y ;}

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 2e5 + 5, M = 5e3 + 5, LG = __lg(N) + 1, base = 311 ;
const int oo = 2e9, sm = 1e9 + 7, mod1 = 1e9 + 7, mod2 = 1e9 + 3 ;
const long long inf = 1e18 ;

int n ;
int a[105][105], b[105][105], c[105][105] ; 

void init() {
	cin >> n ; 
	FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j] ; 
	FOR(i, 1, n) FOR(j, 1, n) cin >> b[i][j] ; 
}

void solve() {
	FOR(i, 1, n) FOR(j, 1, n) if(a[i][j] == 0) {
		if(b[i][j] != 0) {
			cout << - 1 ;
			return ;  
		}
	}
	FOR(i, 1, n) FOR(j, 1, n) if(b[i][j] == 0) {
		if(a[i][j] != 0) {
			cout << - 1 ;
			return ; 
		}
	}	
	int ans = 2e9 ; 

	FOR(mask1, 0, (1 << n) - 1) FOR(mask2, 0, (1 << n) - 1) {
		FOR(i, 1, n) FOR(j, 1, n) c[i][j] = a[i][j] ;

		FOR(row, 0, n - 1) if((BIT(mask1, row))) {
			FOR(j, 1, n) {
				if(c[row + 1][j] == -1) c[row + 1][j] = 1 ;
				else if(c[row + 1][j] == 1) c[row + 1][j] = - 1 ; 
			}
		}
		
		FOR(col, 0, n - 1) if(BIT(mask2, col)) {
			FOR(i, 1, n) {
				if(c[i][col + 1] == -1) c[i][col + 1] = 1 ; 
				else if(c[i][col + 1] == 1) c[i][col + 1] = - 1 ; 
			}
		}
		bool ok = 1 ;
		FOR(i, 1, n) FOR(j, 1, n) {
			if(c[i][j] != b[i][j]) {
				ok = 0 ;
				break ; 
			}
		}
		if(ok) mini(ans, __builtin_popcount(mask1) + __builtin_popcount(mask2)) ; 
	}
	
	cout << ans ; 
}

signed main() {
    #define task "r2ctab"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
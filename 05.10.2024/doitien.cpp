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
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 6e3 + 5 ;

int n , S ; 
pair <int,int> a[N] ; 

void init() {
	cin >> n >> S ; 
	FOR(i, 1, n) cin >> a[i].fi >> a[i].se ;
}

const int mod = 1e9 + 7 ;

void add(int &x, const int y) {
	x+= y ; 
	if(x >= mod) x-= mod ; 
}

int f[N] ; // goi dp0[i] la so cach doi i dong khi xet 1 ... i - 1
int g[N] ; // goi dp1[i] la so cach doi i dong khi xet tai i 

void solve() {
	f[0] = 1 ; 
	
	FOR(i, 1, n) {
		FOR(j, 0, S) {
			g[j] = f[j] ; 
			
			if(j >= a[i].se) add(g[j], g[j - a[i].se]) ;
			 
			if(j >= ( a[i].fi + 1 ) * a[i].se ) 
				g[j] = (g[j] - f[j - (a[i].fi + 1) * a[i].se] + mod) % mod ; 
		}
		swap(g, f) ; 
	}
	
	cout << f[S] ; 
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
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
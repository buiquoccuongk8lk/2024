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
#define fi first
#define se second
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int mod = 1e9 + 7 ;
const int N = 5e5 + 5 ;

int n ;
ll a[N] ; 
ll f[N] ; 

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void solve() {
	ll ans = 0 ;
	FOR(i,1,n) FOR(j,i+1,n) {
		ans = (ans + a[i] * a[j] % mod * (n - j + 1) * i % mod) % mod ;
	}
	cout << ans << endl ;
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
    f[1] = 0 ; 
    f[2] = 1 ; 
    f[3] = 2 ; 
    FOR(i,4,N-5) f[i] = f[i-1] + 2 ;
    int tc ; cin >> tc ;
    while(tc--) {
    	init() ;
    	solve() ;
	}
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
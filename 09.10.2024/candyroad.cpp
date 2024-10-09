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

const int N = 2e5 + 5 ;
const int mod = 998244353 ;

void add(ll &x, const ll y) {
	x+= y ;
	if(x >= mod) x-= mod ;
}

int n, m ; 
int a[N] ;
unordered_map <int,int> cnt ;

void init() {
	cin >> n >> m ; 
	FOR(i, 1, n) cin >> a[i] ; 
}

void solve1() {
	ll ans = 0 ;
	FOR(i, 1, n) {
		ll sum = 0 ; 
		FOR(j, 1, m) cnt[j] = 0 ;
		FOR(j, 1, m) if(cnt[j] == 0) {
			cnt[j] = 1 ; 
			sum = (sum + j) % mod ; 
		}
		FOR(j, 1, m) cnt[j] = 0 ;
		FOR(j, i, n) {
			if(cnt[a[j]] == 0) {
				cnt[a[j]] = 1 ; 
				sum = (sum - a[j] + mod) % mod ; 
			}
			ans = (ans + sum) % mod ;
		}
	}
	cout << ans ;
}

void solve2() {

}

signed main() {
    #define task "candyroad"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    // solve1() ;
    solve2() ; 
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
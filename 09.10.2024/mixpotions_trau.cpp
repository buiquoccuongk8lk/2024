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

const int N = 1e6 + 5 ;

int n ; ll k ;
ll a[N] ;

void init() {
	cin >> n >> k ;
	FOR(i, 1, n) cin >> a[i] ;
}

namespace subtask_1 {
	bool check() {
		return n <= 5e3 ; 
	}

	void solve() {
		vector <ll> v ; 
		FOR(i, 1, n) FOR(j, i + 1, n) v.push_back(a[i] ^ a[j]) ;
		sort(all(v)) ; 
		cout << v[k - 1] ;
	}
}

namespace subtask_2 {
	const int N2 = 1e5 + 5 ;

	int trie[N2 * 55][3] ;
	ll f[N2 * 55] ;
	int node = 1 ;

	void add(ll x) {
		int root = 1 ;
		FORD(i, 32, 0) {
			int bit = (x >> i) & 1 ;
			if(trie[root][bit] == -1) trie[root][bit] = ++node ; 
			root = trie[root][bit] ; 
			f[root]++ ; 
		}
	}

	ll get(ll x, ll k) {
		int root = 1 ; 
		ll res = 0 ;
		FORD(i, 32, 0) {
			int bit_x = (x >> i) & 1, bit_k = (k >> i) & 1 ;
			if(bit_k == 1) {
				if(trie[root][1 ^ bit_x] == - 1) return res ; 
				root = trie[root][1 ^ bit_x] ; 
			} else {
				if(trie[root][1 ^ bit_x] != - 1) res+= f[trie[root][1 ^ bit_x]] ;
				if(trie[root][bit_x] == -1) return res ; 
				root = trie[root][bit_x] ;
			}
			if(i == 0) res+= f[root] ; 
		}
		return res ;
	}

	ll count(ll T) {
		memset(trie, -1, sizeof trie) ; 
		ll cnt = 0 ; 
		FOR(i, 1, n) {
			cnt+= get(a[i], T) ; 
			add(a[i]) ; 
		}

		return n * (n - 1) / 2 - cnt ; 
	}

	void solve() {
		ll l = 0 , r = 1e18, res = - 1 ;
		while(l <= r) {
			ll mid = (l + r) >> 1 ; 
			if(count(mid) < k) res = mid, l = mid + 1 ; 
			else r = mid - 1 ; 
		}
		cout << res ; 
	}
}

signed main() {
    #define task "mixpotions"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".ans","w",stdout) ; 
    }
    init() ;
   	if(subtask_1::check()) return subtask_1::solve(),0 ;
    // return subtask_2::solve(),0 ; 
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 
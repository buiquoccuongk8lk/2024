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

int n, t, k, s, q ;
int a[N] ;

void init() {
	cin >> n >> t >> s >> k ;
	FOR(i, 1, n) cin >> a[i] ;
	cin >> q ;
}

namespace subtask_1 {
	bool check() {return n <= 100 && *max_element(a + 1, a + 1 + n) <= 100 ;}

	int tmp[N] ;

	void solve() {
		sort(a + 1, a + 1 + n) ;

		while(q--) {
			int h ; cin >> h ;

			ll ans = inf ;

			FOR(sl, 0, a[n]) {
				ll sum = 0 ;

				FOR(i, 1, n) tmp[i] = a[i] ;

				FOR(j, 1, sl) {
					int cnt = 0 ;
					FOR(i, 1, n) {
						if(tmp[i] <= 0) {
							cnt++ ;
						}
						tmp[i]-- ;
					}
					sum+= s + 1ll * k * cnt ;
				}

				FOR(i, 1, n) if(tmp[i] > h) {
					sum+= 1ll * (tmp[i] - h) * t ;
				}
				mini(ans, sum) ;
			}

			cout << ans << " " ;
		}
	}
}

namespace subtask_2 {
	bool check() {return k == 0;}

	long long pre[N] ;

	void solve() {
		sort(a + 1, a + 1 + n) ;
		FOR(i, 1, n) pre[i] = pre[i - 1] + a[i] ;

		while(q--) {
			int h ; cin >> h ;

			if(a[n] <= h) {
				cout << 0 << " " ;
			} else {
				int cnt = (s / t) + (s % t != 0) ;

				int posBig = upper_bound(a + 1, a + 1 + n, h) - a ;

				ll sum = 0;

				if(n - posBig + 1 < cnt) {
					sum = 1ll * (pre[n] - pre[posBig - 1] - 1ll * (n - posBig + 1) * h) * t ;
				} else {
					int j = n - cnt + 1 ;

					sum = 1ll * (pre[n] - pre[j] - 1ll * (cnt - 1) * a[j]) * t ;
					sum+= 1ll * max(0, a[j] - h) * s ;
				}

				cout << sum << " " ;
			}
		}
	}
}

namespace subtask_3 {
	ll cnt[N] ; // số lượng cửa có độ cao x
	ll res[N] ; // chi phí ít nhất để các cửa có độ cao <= x
	ll suf[N] ; // tổng độ cao tất cả các cửa có độ cao >= x
	ll b[N] ; // số lượng các cửa có độ cao >= x

	ll cp(int x) {
		return 1ll * (suf[x] - 1ll * b[x] * x) * t ; 
	}

	void solve() {
		sort(a + 1, a + 1 + n) ; 

		FOR(i, 1, n) cnt[a[i]]++ ; 
		
		FORD(i, 1e5, 0) {
			b[i] = b[i + 1] + cnt[i] ;
			suf[i] = suf[i + 1] + 1ll * cnt[i] * i ; 
		}

		int v = 0 ; 
		int r = cnt[0] ; 
		ll sum = 0 ;

		FORD(i, 1e5, 0) {
			if(sum + cp(i + v) > sum + s + 1ll * k * r + cp(i + v + 1)) {
				sum+= s + 1ll * k * r ;
				v++ ; 
				r+= cnt[v] ; 
			}	

			res[i] = sum + cp(i + v) ;
		}		

		while(q--) {
			int h ; cin >> h ;
			cout << res[h] << " " ; 
		}	
	}
}

signed main() {
    #define task "r1storm"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ;
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }
    init() ;
   	// if(subtask_1::check()) return subtask_1::solve(), 0 ;
   	// return subtask_2::solve(), 0 ;
   	return subtask_3::solve(), 0 ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}
/* Watbor */
